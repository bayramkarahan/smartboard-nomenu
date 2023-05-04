#include "tooltahta.h"

toolTahta::toolTahta(int w, int h, QWidget *parent):QWidget()
{
    setFixedSize(w,h);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    //setWindowFlags(Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_StaticContents);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_NoSystemBackground, false);
    // qDebug()<<"pentuval:"<<penTuval.width()<<penTuval.height();
    resizeImage(&penTuval,QSize(width(),height()),qRgba(0, 0,0 ,0));
    //qDebug()<<"pentuval:"<<penTuval.width()<<penTuval.height();
    //qDebug()<<"toolTahta:"<<width()<<height();
    drawStatus=false;
    gv=new QGraphicsView(this);
    gv->hide();
    gv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //gv->setAttribute(Qt::WA_TranslucentBackground);
    gv->viewport()->setAutoFillBackground(false);
   // gv->setStyleSheet("background-color:rgb(0,0,240,255);");
    gv->setRenderHint(QPainter::Antialiasing);
    gv->setFixedSize(this->width(),this->height());
    scene = new Scene(gv);
    gv->setScene(scene);
    scene->setSceneRect(this->pos().x(),this->pos().y(), this->width(),this->height());
    scene->sceneGridYatay=false;
    scene->sceneGridDikey=false;
    scene->sceneGuzelYazi=false;
    gridLines = new GridLines (this->width(), this->height(),10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,QColor(0,0,0,0), QColor(0,0,0,0));
    QPixmap bkgnd=gridLines->PixItem(gridLines,width(),height());
    QPalette palet;
    palet.setBrush(QPalette::Window,bkgnd);
    setPalette(palet);

}
void toolTahta::mousePressEvent(QMouseEvent *event)
{
    /*  qDebug()<<"tooltahta mouse press";
   qDebug()<<"penDrawingMain:"<<penDrawingMain;
   qDebug()<<"drawStatus:"<<drawStatus;
*/
  if(penDrawingMain)
        {
     // qDebug()<<"tooltahta mouse press";
            if ((event->buttons() & Qt::LeftButton)) {
            drawStatus=true;
            lastPoint = event->pos();
            startPoint=event->pos();
           // drawingMain = true;
            msx=event->pos().x();
            msy=event->pos().y();
            mex=event->pos().x();
            mey=event->pos().y();
           // wpoints<<event->pos();
            }
    }

}
void toolTahta::mouseMoveEvent(QMouseEvent *event)
{
    /*qDebug()<<"tooltahta mouse move";
    qDebug()<<"penDrawingMain:"<<penDrawingMain;
    qDebug()<<"drawStatus:"<<drawStatus;
    */
    if(drawStatus)
    {
        if ((event->buttons() & Qt::LeftButton) && penDrawingMain==true) {
              drawLineTo(event->pos());
            msx=(msx>event->pos().x())?event->pos().x():msx;
            msy=(msy>event->pos().y())?event->pos().y():msy;
            mex=(mex<event->pos().x())?event->pos().x():mex;
            mey=(mey<event->pos().y())?event->pos().y():mey;
           // wpoints<<event->pos();

      }
       // update();
   }
}
void toolTahta::mouseReleaseEvent(QMouseEvent *event)
{
  /*  qDebug()<<"tooltahta mouse release";
    qDebug()<<"penDrawingMain:"<<penDrawingMain;
    qDebug()<<"drawStatus:"<<drawStatus;
*/

    if (event->button() == Qt::LeftButton && drawStatus&&penDrawingMain) {
        drawStatus=false;
        int myPenSize=4;
        // wpoints<<event->pos();
        // wpoints.clear();
        msx=(msx>event->pos().x())?event->pos().x():msx;
        msy=(msy>event->pos().y())?event->pos().y():msy;
        mex=(mex<event->pos().x())?event->pos().x():mex;
        mey=(mey<event->pos().y())?event->pos().y():mey;
          //if(mex<msx){int xtmp=msx;msx=mex;mex=xtmp;}
       // if(mey<msy){int ytmp=msy;msy=mey;mey=ytmp;}
        int imsx=msx-myPenSize;
        int imsy=msy-myPenSize;
        int imex=mex+myPenSize;
        int imey=mey+myPenSize;
        //burası önemli. pdf ile taşıma yapınca kayma oluyor bunu düzeltmek için kontrol ediliyor.
        //GraphicsView kenar kalınlığıda sebep olabilir. araştırılacak...
        if(scene->pdfObjectAdded&&scene->pdfMoved)
         startPoint=QPointF(imsx,imsy);
            else
        startPoint=QPointF(imsx-1,imsy-1);

        VERectangle*  itemToRectDraw = new VERectangle(scene);
        itemToRectDraw->sekilTur(DiagramItem::DiagramType::NormalPen);
        QRect selection;
        selection.setRect(imsx,imsy,imex-imsx,imey-imsy);
       // selection.setRect(msx-2,msy-2,(mex-msx)+4,(mey-msy)+4);

        QPixmap temp=QPixmap::fromImage(penTuval.copy(selection));
       // QPixmap temp=QPixmap::fromImage(penTuval);

        /* QImage result = img.copy(selection).scaled(mex-msx, mey-msy,
                                     Qt::IgnoreAspectRatio,
                                     Qt::SmoothTransformation);
          QPixmap temp=QPixmap::fromImage(result);*/
        // QPixmap temp(":icons/pen.png");
        itemToRectDraw->setPos(startPoint);
       // itemToRectDraw->setPos(QPointF(-1,-1));

        itemToRectDraw->setImage(temp);
        //scene->sceneItemAddedSignal(
        emit scene->sceneItemAddedSignal(scene,itemToRectDraw,true,Scene::Mode::PenMode,itemToRectDraw->sekilTr);
        /*
        scene->addItem(itemToRectDraw);
        scene->graphicsList.append(itemToRectDraw);
        scene->graphicsListTemp.append(itemToRectDraw);
        scene->historyBack.append(itemToRectDraw);
        scene->historyBackAction.append("added");
        depo::historyBackCount=scene->historyBack.count();
        depo::historyNextCount=scene->historyNext.count();
        /*******************************************/
        itemToRectDraw->setRect(0,0,(imex - imsx),(imey - imsy));
        //itemToRectDraw->setRect(0,0,this->width(),this->height());
        itemToRectDraw->fareState(false);
        itemToRectDraw = 0;
        clearImage();
        QPalette palet1;
        palet1.setBrush(QPalette::Background,QColor(0,0,0,0));
        this->setPalette(palet1);


        QPixmap pixMap = gv->grab(gv->sceneRect().toRect());
        QPalette palet;
        //pixMap.save("deneme.png");
        palet.setBrush(QPalette::Background,pixMap);
        this->setPalette(palet);
        // pageList[sceneSayfaActiveNumber]->setIcon(QIcon(pixMap));////önemli
    }
}
void toolTahta::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, penTuval, dirtyRect);
}
void toolTahta::clearImage()
{
    penTuval.fill(qRgba(0,0, 0, 0));
}

void toolTahta::toolTahta_DesktopSignalSlot()
{
qDebug()<<"tahta desktop seç masajı geldi...";
hide();
}

void toolTahta::toolTahta_PenSignalSlot()
{
qDebug()<<"tahta pen seç masajı geldi...";
show();
}

QImage toolTahta::copyImage(const QImage & input, const QRect & path){
    if(!input.isNull() && !path.isEmpty()){
        QRect r = path.intersected(input.rect());
        QImage tmp(input.size(), QImage::Format_ARGB32);
        tmp.fill(Qt::transparent);
        QPainter painter(&tmp);
        painter.setClipRect(path);
        painter.drawImage(QPoint{}, input, input.rect());
        painter.end();
        return tmp.copy(r);
    }
    return QImage();
}
void toolTahta::drawLineTo(const QPoint &endPoint)
{
    //qDebug()<<"çizim";
//QColor myPenColor("0,0,0,255");
int myPenSize=scene->myPenSize;
//Qt::SolidLine myPenStyle;
    QPainter painter(&penTuval);
    QPen pen=QPen( scene->myPenColor, scene->myPenSize, Qt::SolidLine, Qt::RoundCap ,Qt::RoundJoin);
    pen.setCosmetic(true);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    /***************************************************************************/
    if(scene->sceneMode==Scene::Mode::DrawPenPattern)
    {
        qreal spacing=0.1;
        QPainterPath path;
        path.moveTo(lastPoint);
        path.lineTo(endPoint);
        qreal length = path.length();
        qreal pos = 0;
        ///https://stackoverflow.com/questions/18502611/line-interpolation-in-qt
        QPixmap myPixmapForNow;
        if(!myPixmapForNow.load(":/icons/k1.png")){
            qWarning("Failed to load");
        }

        myPixmapForNow= myPixmapForNow.scaled(myPenSize,myPenSize);
        while (pos < length) {
            qreal percent = path.percentAtLength(pos);
            ///drawYourPixmapAt(path.pointAtPercent(percent)); // pseudo method, use QPainter and your brush pixmap instead
            //painter.drawPoint(path.pointAtPercent(percent));
            painter.drawPixmap(path.pointAtPercent(percent),myPixmapForNow);
            //painter.drawEllipse(path.pointAtPercent(percent),myPenSize,myPenSize);

            //  qDebug()<<path.pointAtPercent(percent);
            pos += spacing;
        }
    }
    if(scene->sceneMode==Scene::Mode::DrawPen)
    {
        painter.drawLine(lastPoint, endPoint);
    }
    /*******************************************************************************/
    int rad = (myPenSize / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
           .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;

}
void toolTahta::resizeImage(QImage *image, const QSize &newSize, QRgb renk)
{
   if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_ARGB32);
    newImage.fill(renk);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;

  }
