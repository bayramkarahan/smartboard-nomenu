#include "toolKalem.h"
#include<QDebug>
#include<QMouseEvent>
#include<QToolButton>
#include<QAction>
#include<QMenu>
#include<QGridLayout>

bool toolKalem::eventFilter(QObject * obj, QEvent *event)
{
   /* if (event->type() == QEvent::Show && obj == sekilButton->menu())
    {
         int button_x = mapToParent(sekilButton->pos()).x();
        int button_y = mapToParent(sekilButton->pos()).y();

        int menu_width = sekilButton->menu()->size().width();
        int menu_height = sekilButton->menu()->size().height();

        QPoint pos = QPoint(button_x - menu_width-1 ,
                            button_y-menu_height/2);
        sekilButton->menu()->move(pos);
        return true;
    }
    if (event->type() == QEvent::Show && obj == penButton->menu())
    {
         int button_x = mapToParent(penButton->pos()).x();
        int button_y = mapToParent(penButton->pos()).y();

        int menu_width = penButton->menu()->size().width();
        int menu_height = penButton->menu()->size().height();

        QPoint pos = QPoint(button_x - menu_width-1 ,
                            button_y);
        penButton->menu()->move(pos);
        return true;
    }
    if (event->type() == QEvent::Show && obj == zeminButton->menu())
    {
         int button_x = mapToParent(zeminButton->pos()).x();
        int button_y = mapToParent(zeminButton->pos()).y();

        int menu_width = zeminButton->menu()->size().width();
        int menu_height = zeminButton->menu()->size().height();

        QPoint pos = QPoint(button_x - menu_width-1 ,
                            button_y-menu_height/2);
        zeminButton->menu()->move(pos);
        return true;
    }
  /*  if (event->type() == QEvent::Show && obj == colorButton->menu())
    {
         int button_x = mapToParent(colorButton->pos()).x();
        int button_y = mapToParent(colorButton->pos()).y();

        int menu_width = colorButton->menu()->size().width();
        int menu_height = colorButton->menu()->size().height();

        QPoint pos = QPoint(button_x - menu_width-1 ,
                            button_y-menu_height/2);
        colorButton->menu()->move(pos);
        return true;
    }*/
    return false;
}
void toolKalem::sagSolHizala()
{
    if (!sagSolHizaStatus)
    {
        move(parentw-this->width()-10,parenth/2- this->height()/2);
        sagSolHizaStatus=true;
    }else
    {
        move(10,parenth/2- this->height()/2);
        sagSolHizaStatus=false;
    }

}
void toolKalem::buttonStateClear()
{
    desktopButton->setChecked(false);
    handButton->setChecked(false);
    copyButton->setChecked(false);
    penButton->setChecked(false);
    eraseButton->setChecked(false);
    sekilButton->setChecked(false);

}

void toolKalem::handButtonSlot()
{
    buttonStateClear();handButton->setChecked(true);
    emit kalemModeSignal(Scene::Mode::SelectObject,DiagramItem::NoType);

}

void toolKalem::penButtonSlot()
{
    buttonStateClear();
    penButton->setChecked(true);
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
    current_toolTahta->scene->setSekilTanimlamaStatus(false);
    emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::NormalPen);
}

void toolKalem::clearButtonSlot()
{
     current_toolTahta->scene->removeAllItem();
     secSayfaButtonClick(current_toolTahta->current_sceneIndex);
    //emit kalemModeSignal(Scene::Mode::ClearMode,DiagramItem::DiagramType::NoType);
}

void toolKalem::modeKontrolSlot()
{

//qDebug()<<"oldMode:"<<oldMode<<"currentMode"<<currentMode;

    if(oldMode==Scene::Mode::DrawPen||
            oldMode==Scene::Mode::SelectObject||
            oldMode==Scene::Mode::EraseMode||
            oldMode==Scene::Mode::SekilMode)
    {

    if(currentMode==Scene::Mode::ClearMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::NextPageMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::BackPageMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::ZoomPozitifMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::ZoomNegatifMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::ZoomSelectionMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::FitWindowMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::FitPageMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::ZeminMode)
        emit kalemModeSignal(oldMode,oldType);

    //if(currentMode==Scene::Mode::SekilMode)
     //   emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::IleriAlMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::GeriAlMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::JumpPageMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::SaveMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::PrintMode)
        emit kalemModeSignal(oldMode,oldType);


    if(currentMode==Scene::Mode::ListMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::SearchMode)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::PanelSideLeftRight)
        emit kalemModeSignal(oldMode,oldType);

    if(currentMode==Scene::Mode::PanelSideBottom)
        emit kalemModeSignal(oldMode,oldType);


}
}

void toolKalem::penToScene()
{   current_toolTahta->scene->setPenSize(penSize);
    current_toolTahta->scene->setPenAlpha(penAlpha);
    current_toolTahta->scene->setPenColor(penColor);
    current_toolTahta->scene->setPenStyle(penStyle);

    current_toolTahta->scene->mySekilType=sekilType;
    current_toolTahta->scene->setSekilKalemColor(penColor);
    current_toolTahta->scene->mySekilPenStyle=penStyle;
    current_toolTahta->scene->setSekilZeminColor(sekilZeminColor);
    current_toolTahta->scene->setSekilPenSize(penSize);

    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    current_toolTahta->scene->setSekilTanimlamaStatus(false);
   // current_toolTahta->scene->pageOfNumberScene=0;
       /*******************önemli ayarlar**************************************/
  ///    setContinuousMode(false);     //sayfalar birleşik gözükmeyecek
   ///   setLayoutMode(SinglePageMode);//Tek sayfa gösterme ayarlandı

       //currentTab()->setScaleMode(FitToPageWidthMode);//sayfayı orijinal boyutta göster
  ///   setScaleMode(FitToPageSizeMode);//sayfayı sığdır fit to window
     ///  kw->pageOfNumber->setText(QString::number(currentTab()->currentPage())+" / "+
     ///                           QString::number(currentTab()->numberOfPages()));
      /* currentTab()->scene->pageOfNumberScene=currentTab()->currentPage()-1;
       PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
       const QRectF pageItemRect = page->boundingRect().translated(page->pos());
       currentTab()->scene->pageItemRect=pageItemRect;
     **/
    /// kalemZeminModeSignalSlot(DiagramItem::DiagramType::TransparanPage);
  // current_toolTahta->scene->makeItemsControllable(false);

    // connect(current_toolTahta->scene, SIGNAL(sceneItemAddedSignal()),
    //this,SLOT(sceneItemAddedSignalSlot()));
    //  sceneItemAddedSignalSlot();
   // handButtonSlot();
    //kalemPenModeSignalSlot(DiagramItem::DiagramType::NormalPen);

    emit kalemModeSignal(currentMode,currentType);

}

void toolKalem::sceneToPen()
{
    penSize=current_toolTahta->scene->myPenSize;
    penAlpha=current_toolTahta->scene->myPenAlpha;
    penColor=current_toolTahta->scene->myPenColor;
    penStyle=current_toolTahta->scene->myPenStyle;
    sekilType=current_toolTahta->scene->mySekilType;
    sekilZeminColor=current_toolTahta->scene->mySekilKalemColor;
    //emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
    //   current_toolTahta->scene->makeItemsControllable(false);
    // connect(current_toolTahta->scene, SIGNAL(sceneItemAddedSignal()),
    //this,SLOT(sceneItemAddedSignalSlot()));
    //  sceneItemAddedSignalSlot();
    // handButtonSlot();
    //kalemPenModeSignalSlot(DiagramItem::DiagramType::NormalPen);



}
void toolKalem::desktopButtonSlot()
{
    buttonStateClear();
    if(!penDesktopStatus)
    {
        desktopButton->setChecked(true);
        current_toolTahta->hide();
        penDesktopStatus=!penDesktopStatus;
        emit kalemModeSignal(Scene::Mode::DesktopMode,DiagramItem::DiagramType::NoType);
        desktopButton->setIcon(QIcon(":/icons/app.svg"));
    }else
    {
        desktopButton->setChecked(false);
        current_toolTahta->show();
        penDesktopStatus=!penDesktopStatus;
        emit kalemModeSignal(Scene::Mode::PenMode,DiagramItem::DiagramType::NoType);
        penButtonSlot();
        desktopButton->setIcon(QIcon(":/icons/desktop.svg"));
    }
}
toolKalem::toolKalem(QString _title, int _en, int _boy, toolTahta *_toolTahta, int parentw, int parenth, QWidget *parent)
        {
    penDesktopStatus=false;
    this->parentw=parentw;
    this->parenth=parenth;
    title=_title;
    en=_en;
    boy=_boy;
    mouseClick=false;
    currentMode=Scene::Mode::SelectObject;
    current_toolTahta=_toolTahta;

/*******************************************************************/

    desktopButton = new QToolButton(this);
    desktopButton=butonToolSlot(desktopButton,"",":icons/desktop.svg",QColor(255,0,0,0),en*1.5,boy);
    desktopButton->setCheckable(true);
    desktopButton->setChecked(true);
    connect(desktopButton, &QToolButton::clicked, [=]() {
        desktopButtonSlot();

         });

handButton = new QToolButton(this);
handButton=butonToolSlot(handButton,"",":icons/hand.png",QColor(255,0,0,0),en*1.5,boy);
handButton->setCheckable(true);
handButton->setChecked(true);
connect(handButton, &QToolButton::clicked, [=]() {
    handButtonSlot();
     });

copyButton = new QToolButton(this);
copyButton=butonToolSlot(copyButton,"",":icons/copy.png",QColor(255,0,0,0),en*1.5,boy);
copyButton->setCheckable(true);
connect(copyButton, &QToolButton::clicked, [=]() {
    buttonStateClear();copyButton->setChecked(true);
   // current_toolTahta->gv->show();
   // current_toolTahta->gv->setEnabled(true);

    emit kalemModeSignal(Scene::Mode::CopyMode,DiagramItem::DiagramType::NoType);
   });

penButton = new QToolButton(this);
penButton=butonToolSlot(penButton,"Kalem",":icons/pen.svg",QColor(255,0,0,0),en*1.5,boy);
penButton->setIconSize(QSize(en*0.8,boy*1.3));
penButton->setMenu(penMenu());
penButton->setPopupMode(QToolButton::MenuButtonPopup);
penButton->setCheckable(true);
connect(penButton, &QToolButton::clicked, [=]() {
penButtonSlot();
});

eraseButton = new QToolButton(this);
eraseButton=butonToolSlot(eraseButton,"Silgi",":icons/erase.png",QColor(255,0,0,0),en*1.5,boy);
eraseButton->setCheckable(true);
eraseButton->setIconSize(QSize(en*0.8,boy*0.8));
connect(eraseButton, &QToolButton::clicked, [=]() {
       buttonStateClear();eraseButton->setChecked(true);
       emit kalemModeSignal(Scene::Mode::EraseMode,DiagramItem::DiagramType::NoType);
   });

QToolButton *clearButton = new QToolButton(this);
clearButton=butonToolSlot(clearButton,"Hepsini Sil",":icons/clear.png",QColor(255,0,0,0),en*1.5,boy);
clearButton->setIconSize(QSize(en*1,boy*1));
connect(clearButton, &QToolButton::clicked, [=]() {
  clearButtonSlot();
});

penColorButton = new QToolButton(this);
penColorButton=butonToolSlot(penColorButton,"",":icons/pencolor.png",QColor(0,0,0,255),en*1.5,boy*0.8);
connect(penColorButton, &QToolButton::clicked, [=]() {
 QMenu *menu= colorMenu("penColor","yatay",en,boy,true);
 menu->show();menu->hide();
 colorMenu("penColor","yatay",en,boy,true)->exec(mapToGlobal(penColorButton->pos())-QPoint(menu->width(),0));

});

QWidget *urw=new QWidget(this);
urw->setFixedSize(en*1.5,boy);
undoButton = new QToolButton(urw);
undoButton=butonToolSlot(undoButton,"",":icons/undo.png",QColor(255,0,0,0),en*0.75,boy);
undoButton->setIconSize(QSize(en*0.8,boy*0.8));
connect(undoButton, &QToolButton::clicked, [=]() {
    //emit kalemModeSignal(Scene::Mode::GeriAlMode,DiagramItem::DiagramType::NoType);
    current_toolTahta->scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
    secSayfaButtonClick(current_toolTahta->current_sceneIndex);

});

redoButton = new QToolButton(urw);
redoButton=butonToolSlot(redoButton,"",":icons/redo.png",QColor(255,0,0,0),en*0.75,boy);
redoButton->setIconSize(QSize(en*0.8,boy*0.8));
connect(redoButton, &QToolButton::clicked, [=]() {
   // emit kalemModeSignal(Scene::Mode::IleriAlMode,DiagramItem::DiagramType::NoType);
    current_toolTahta->scene->setMode(Scene::Mode::IleriAlMode, DiagramItem::DiagramType::NoType);
    secSayfaButtonClick(current_toolTahta->current_sceneIndex);

});

QHBoxLayout *line00 = new QHBoxLayout;
line00->addWidget(undoButton,Qt::AlignHCenter);
line00->addWidget(redoButton,Qt::AlignHCenter);

line00->setContentsMargins(0,0, 0,0);
line00->setSpacing(1);
urw->setLayout(line00);

sekilButton = new QToolButton(this);
DiagramItem *ditem=new DiagramItem();int ken=300;
QPixmap pixmap(image(ditem->sekilStore(DiagramItem::DiagramType::Cizgi,QRectF(QPointF(20,50),QPointF(ken-70,ken-70))),ken,ken));
sekilButton=butonToolSlot(sekilButton,"Şekiller",":icons/transparanboard.png",QColor(255,0,0,0),en*1.5,boy);
sekilButton->setIcon(pixmap);
sekilButton->setMenu(sekilMenu());
sekilButton->setPopupMode(QToolButton::MenuButtonPopup);
sekilButton->setCheckable(true);
connect(sekilButton, &QToolButton::clicked, [=]() {
   buttonStateClear(); sekilButton->setChecked(true);
   emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Cizgi);
   });

zeminButton = new QToolButton(this);
zeminButton=butonToolSlot(zeminButton,"Arkaplan",":icons/transparanboard.png",QColor(255,0,0,0),en*1.5,boy);
zeminButton->setMenu(zeminMenu());
zeminButton->setPopupMode(QToolButton::MenuButtonPopup);

connect(zeminButton, &QToolButton::clicked, [=]() {
    emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
   });

QToolButton *pdfButton = new QToolButton(this);
pdfButton=butonToolSlot(pdfButton,"",":icons/pdf.svg",QColor(255,0,0,0),en*1.5,boy);
connect(pdfButton, &QToolButton::clicked, [=]() {
emit kalemModeSignal(Scene::Mode::PdfMode,DiagramItem::DiagramType::NoType);
   });

QToolButton *printButton = new QToolButton(this);
printButton=butonToolSlot(printButton,"",":icons/print.png",QColor(255,0,0,0),en*1.5,boy);
connect(printButton, &QToolButton::clicked, [=]() {
    //emit kalemModeSignal(Scene::Mode::PrintMode,DiagramItem::DiagramType::NoType);
    //QString fileName = QFileDialog::getSaveFileName(this, "Export PDF",QString(), "*.pdf");
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    //printer.setOrientation(Qt::Horizontal);
    printer.setOrientation(QPrinter::Landscape);
    //printer.setOutputFormat(QPrinter::PdfFormat);
    //printer.setOutputFileName(fileName);
    int filenumber=20;
    // QSize screenSize = qApp->screens()[0]->size();
    QPixmap pixMap =current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
    QPainter p;
    p.begin(&printer);
    p.setWindow(QRect(0, 0, parentw,parenth));
    p.drawPixmap (0, 0, pixMap);
    p.end();
});



QToolButton *exitButton = new QToolButton(this);
exitButton=butonToolSlot(exitButton,"Kapat",":icons/close.png",QColor(255,0,0,0),en*1.5,boy);
connect(exitButton, &QToolButton::clicked, [=]() {
emit kalemModeSignal(Scene::Mode::ExitMode,DiagramItem::DiagramType::NoType);
   });

auto layout = new QGridLayout();
layout->setContentsMargins(2,5, 2,5);
layout->setSpacing(1);

layout->addWidget(desktopButton, 0, 0,1,2);
layout->addWidget(handButton, 1, 0,1,2);
layout->addWidget(copyButton, 2, 0,1,2);

layout->addWidget(penButton, 10, 0,1,2);
//layout->addWidget(penPopupButton, 10, 1,1,1);

layout->addWidget(eraseButton, 20, 0,1,2);
layout->addWidget(clearButton, 30, 0,1,2);

/*layout->addWidget(blackButton, 40, 0,1,2);
layout->addWidget(redButton, 41, 0,1,2);
layout->addWidget(blueButton, 42, 0,1,2);
*/
layout->addWidget(penColorButton, 43, 0,1,2);

//layout->addWidget(undoButton, 45, 0,1,1);
//layout->addWidget(redoButton, 45, 1,1,1);
layout->addWidget(urw, 45, 1,1,1);
layout->addWidget(sekilButton, 50, 0,1,2);
layout->addWidget(zeminButton, 60, 0,1,2);

layout->addWidget(pdfButton, 70, 0,1,2);


layout->addWidget(printButton, 91, 0,1,2);

layout->addWidget(exitButton, 95, 0,1,2);

this->setLayout(layout);

penToScene();
}

QPushButton *toolKalem::butonSlot(QPushButton *btn, QString text, QString icon, QColor color, int w, int h, int iw, int ih)
{
    int e=w;
    int b=h;
    btn->setFixedSize(e, b);
    btn->setIconSize(QSize(iw,ih));
    if(icon!="") btn->setIcon(QIcon(icon));
    btn->setText(text);
    btn->setFlat(true);
    //btn->setStyleSheet(QString("QPushButton{ background-color: rgba(%1, %2, %3, %4); }").arg(QString::number(color.red()),
    // btn->setPalette(*plt);
    QPalette *palet=new QPalette();
    palet->setColor(QPalette::Button, color);
    btn->setPalette(*palet);
    btn->setAutoFillBackground(true);
    QFont ff( "Arial", 8, QFont::Normal);
    btn->setFont(ff);

    btn->update();
    return btn;
}

QToolButton *toolKalem::butonToolSlot(QToolButton *btn,QString text,QString icon,QColor color,int w, int h)
{
    int e=w;
    int b=h;
    btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    btn->setFixedSize(e, b);
    btn->setIconSize(QSize(e*0.7,b*0.7));
    if(icon!="") btn->setIcon(QIcon(icon));
    //if(text!="") btn->setText(text);
     btn->setAutoRaise(true);
    btn->setAutoFillBackground(true);
    btn->setStyleSheet(QString("QToolButton{ background-color: rgba(%1, %2, %3, %4); }").arg(QString::number(color.red()),
                                                                                             QString::number(color.green()),
                                                                                             QString::number(color.blue()),
                                                                                      QString::number(color.alpha())));
    //QFont ff( "Arial", 7, QFont::Normal);
    //btn->setFont(ff);

    return btn;
}

void toolKalem::mouseMoveEvent(QMouseEvent *event)
{ //qDebug()<<"main mouse  move"<<event->pos();
       if ((event->buttons() & Qt::LeftButton) && mouseClick==true) {

          //this->move(mapToParent(event->pos()));
         /*  QPoint newpos_min = mapToParent(event->pos()-offset);
                 QPoint newpos_max = QPoint(newpos_min.x() + this->width(), newpos_min.y() + this->height());

                 if(newpos_min.x() > 0 &&
                    newpos_min.y() > 0 &&
                    newpos_max.x() < this->parentWidget()->width() &&
                    newpos_max.y() < this->parentWidget()->height()){

                     this->move(mapToParent(event->pos() - offset));
                 }
                 */
           //Excute movement follow mouse position
                /*  move(mapToParent(event->pos() - offset));
                  //Make sure control do not move out parent size
                  if (x() < 0)
                      move(1, y());
                  if (y() < 0)
                      move(x(), 1);
                  if (x() + width() > parentWidget()->width())
                      move(parentWidget()->width() - 1 - width(), y());
                  if (y() + height() > parentWidget()->height())
                      move(x(), parentWidget()->height() - 1 - height());
*/

   }

}

void toolKalem::mousePressEvent(QMouseEvent *event)
{
   // qDebug()<<"main press";

            if ((event->buttons() & Qt::LeftButton)) {
 offset = event->pos();

            mouseClick = true;


            }

}

void toolKalem::mouseReleaseEvent(QMouseEvent *event)
{
    // qDebug()<<"main mouse release";
    if (event->button() == Qt::LeftButton && mouseClick) {

          mouseClick = false;

      }
}

QMenu* toolKalem::colorMenu(QString colorType,QString yon,int w,int h,bool close)
{   QMenu *menu = new QMenu(this);
   // qDebug()<<"renk invoke"<<colorType;
    int e=w;
      int b=h;

   palette=new QPalette();
   palette->setColor(QPalette::Button,QColor(255,0,0,255));

     QPushButton *color1Button= new QPushButton;
     color1Button=butonSlot(color1Button,"","",QColor(255,0,0,255),e,b,e,b);
   connect(color1Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(255,0,0,255);
       emit kalemColorSignal(colorType,QColor(255,0,0,255));
      if(close) menu->close();
   });


   QPushButton *color2Button= new QPushButton;
   color2Button=butonSlot(color2Button,"","",QColor(0,255,0,255),e,b,e,b);

   connect(color2Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,255,0,255);
       emit kalemColorSignal(colorType,QColor(0,255,0,255));
      if(close)  menu->close();
});

   QPushButton *color3Button= new QPushButton;
   color3Button=butonSlot(color3Button,"","",QColor(0,0,255,255),e,b,e,b);

   connect(color3Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,0,255,255);
       emit kalemColorSignal(colorType,QColor(0,0,255,255));
       if(close) menu->close();
});

   QPushButton *color4Button= new QPushButton;
   color4Button=butonSlot(color4Button,"","",QColor(255,255,0,255),e,b,e,b);

   connect(color4Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(255,255,0,255);
       emit kalemColorSignal(colorType,QColor(255,255,0,255));
       if(close) menu->close();
});

   QPushButton *color5Button= new QPushButton;
   color5Button=butonSlot(color5Button,"","",QColor(0,255,255,255),e,b,e,b);

   connect(color5Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,255,255,255);
       emit kalemColorSignal(colorType,QColor(0,255,255,255));
       if(close) menu->close();
});

   QPushButton *color6Button= new QPushButton;
   color6Button=butonSlot(color6Button,"","",QColor(255,0,255,255),e,b,e,b);
   connect(color6Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(255,0,255,255);
       emit kalemColorSignal(colorType,QColor(255,0,255,255));
        if(close)   menu->close();
});

   QPushButton *color7Button= new QPushButton;
   color7Button=butonSlot(color7Button,"","",QColor(255,255,255,255),e,b,e,b);

   connect(color7Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(255,255,255,255);
       emit kalemColorSignal(colorType,QColor(255,255,255,255));
       if(close) menu->close();
});

   QPushButton *color8Button= new QPushButton;
   color8Button=butonSlot(color8Button,"","",QColor(0,0,0,255),e,b,e,b);

   connect(color8Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,0,0,255);
       emit kalemColorSignal(colorType,QColor(0,0,0,255));
       if(close) menu->close();
});

   QPushButton *color9Button= new QPushButton;
   color9Button=butonSlot(color9Button,"","",QColor(127,127,127,255),e,b,e,b);

   connect(color9Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(127,127,127,255);
       emit kalemColorSignal(colorType,QColor(127,127,127,255));
       if(close) menu->close();
});

   QPushButton *color11Button= new QPushButton;
   color11Button=butonSlot(color11Button,"RY","",QColor(0,0,0,0),e,b,e,b);

   connect(color11Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,0,0,0);
       emit kalemColorSignal(colorType,QColor(0,0,0,0));
         if(close) menu->close();
});
    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(0, 5, 0,5);
    layout->setVerticalSpacing(2);
  //  layout->setColumnMinimumWidth(0, 37);
    if(yon=="dikey"){
    layout->addWidget(color1Button, 1,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color2Button, 2,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color3Button, 3,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color4Button, 4,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color5Button, 5,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color6Button, 6,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color7Button, 7,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color8Button, 8,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color9Button, 9,1,1,1,Qt::AlignHCenter);
  // layout->addWidget(color10Button, 10,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color11Button, 11,1,1,1,Qt::AlignHCenter);
    }
    if(yon=="yatay"){
    layout->addWidget(color1Button, 1,0,1,1,Qt::AlignHCenter);
    layout->addWidget(color2Button, 1,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color3Button, 1,2,1,1,Qt::AlignHCenter);
    layout->addWidget(color4Button, 1,3,1,1,Qt::AlignHCenter);
    layout->addWidget(color5Button, 1,4,1,1,Qt::AlignHCenter);
    layout->addWidget(color6Button, 1,5,1,1,Qt::AlignHCenter);
    layout->addWidget(color7Button, 1,6,1,1,Qt::AlignHCenter);
    layout->addWidget(color8Button, 1,7,1,1,Qt::AlignHCenter);
    layout->addWidget(color9Button, 1,8,1,1,Qt::AlignHCenter);
  // layout->addWidget(color10Button, 9,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color11Button, 1,10,1,1,Qt::AlignHCenter);
    }

    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

     menu->setStyleSheet("QMenu {background-color:#acacac; }");
   return menu;
}

QWidget* toolKalem::colorWidget(QString colorType,QString yon,int w,int h,bool close)
{   QWidget *colorwidget = new QWidget(this);
   // qDebug()<<"renk invoke"<<colorType;
    int e=w;
      int b=h;

   palette=new QPalette();
   palette->setColor(QPalette::Button,QColor(255,0,0,255));

     QPushButton *color1Button= new QPushButton;
     color1Button=butonSlot(color1Button,"","",QColor(255,0,0,255),e,b,e,b);
   connect(color1Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(255,0,0,255);
       emit kalemColorSignal(colorType,QColor(255,0,0,255));
     // if(close) menu->close();
   });


   QPushButton *color2Button= new QPushButton;
   color2Button=butonSlot(color2Button,"","",QColor(0,255,0,255),e,b,e,b);

   connect(color2Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,255,0,255);
       emit kalemColorSignal(colorType,QColor(0,255,0,255));
     // if(close)  menu->close();
});

   QPushButton *color3Button= new QPushButton;
   color3Button=butonSlot(color3Button,"","",QColor(0,0,255,255),e,b,e,b);

   connect(color3Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,0,255,255);
       emit kalemColorSignal(colorType,QColor(0,0,255,255));
      // if(close) menu->close();
});

   QPushButton *color4Button= new QPushButton;
   color4Button=butonSlot(color4Button,"","",QColor(255,255,0,255),e,b,e,b);

   connect(color4Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(255,255,0,255);
       emit kalemColorSignal(colorType,QColor(255,255,0,255));
      // if(close) menu->close();
});

   QPushButton *color5Button= new QPushButton;
   color5Button=butonSlot(color5Button,"","",QColor(0,255,255,255),e,b,e,b);

   connect(color5Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,255,255,255);
       emit kalemColorSignal(colorType,QColor(0,255,255,255));
      // if(close) menu->close();
});

   QPushButton *color6Button= new QPushButton;
   color6Button=butonSlot(color6Button,"","",QColor(255,0,255,255),e,b,e,b);
   connect(color6Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(255,0,255,255);
       emit kalemColorSignal(colorType,QColor(255,0,255,255));
       // if(close)   menu->close();
});

   QPushButton *color7Button= new QPushButton;
   color7Button=butonSlot(color7Button,"","",QColor(255,255,255,255),e,b,e,b);

   connect(color7Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(255,255,255,255);
       emit kalemColorSignal(colorType,QColor(255,255,255,255));
       //if(close) menu->close();
});

   QPushButton *color8Button= new QPushButton;
   color8Button=butonSlot(color8Button,"","",QColor(0,0,0,255),e,b,e,b);

   connect(color8Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,0,0,255);
       emit kalemColorSignal(colorType,QColor(0,0,0,255));
      // if(close) menu->close();
});

   QPushButton *color9Button= new QPushButton;
   color9Button=butonSlot(color9Button,"","",QColor(127,127,127,255),e,b,e,b);

   connect(color9Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(127,127,127,255);
       emit kalemColorSignal(colorType,QColor(127,127,127,255));
       //if(close) menu->close();
});

   QPushButton *color11Button= new QPushButton;
   color11Button=butonSlot(color11Button,"RY","",QColor(0,0,0,0),e,b,e,b);

   connect(color11Button, &QPushButton::clicked, [=]() {
       QColor renk=QColor(0,0,0,0);
       emit kalemColorSignal(colorType,QColor(0,0,0,0));
       //  if(close) menu->close();
});
   // auto widget = new QWidget;
    auto layout = new QGridLayout(colorwidget);
    layout->setContentsMargins(0, 0, 0,0);
    layout->setVerticalSpacing(2);
  //  layout->setColumnMinimumWidth(0, 37);
    if(yon=="dikey"){
    layout->addWidget(color8Button, 0,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color1Button, 1,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color2Button, 2,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color3Button, 3,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color4Button, 4,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color5Button, 5,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color6Button, 6,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color7Button, 7,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color9Button, 9,1,1,1,Qt::AlignHCenter);
  // layout->addWidget(color10Button, 10,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color11Button, 11,1,1,1,Qt::AlignHCenter);
    }
    if(yon=="yatay"){
     layout->addWidget(color8Button, 1,0,1,1,Qt::AlignHCenter);
    layout->addWidget(color1Button, 1,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color2Button, 1,2,1,1,Qt::AlignHCenter);
    layout->addWidget(color3Button, 1,3,1,1,Qt::AlignHCenter);
    layout->addWidget(color4Button, 1,4,1,1,Qt::AlignHCenter);
    layout->addWidget(color5Button, 1,5,1,1,Qt::AlignHCenter);
    layout->addWidget(color6Button, 1,6,1,1,Qt::AlignHCenter);
    layout->addWidget(color7Button, 1,7,1,1,Qt::AlignHCenter);

    layout->addWidget(color9Button, 1,8,1,1,Qt::AlignHCenter);
  // layout->addWidget(color10Button, 9,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color11Button, 1,10,1,1,Qt::AlignHCenter);
    }

    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(colorwidget);
    colorwidget->addAction(wa);

   //  colorwidget->setStyleSheet("background-color:#ffffff; ");
   return colorwidget;
}

void toolKalem::setGridSize(int s)
{
    gridSize=s;
    gridSizePopLabel->setText("Satır ve Sütun Genişliği: "+QString::number(gridSize));
    emit kalemModeSignal(Scene::Mode::ZeminMode,pagePattern);
    //emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    //buttonStateClear();
    //penButton->setChecked(true);
}

QWidget *toolKalem::cizgiBoyutMenu()
{     int e=(en*0.8)/4*5.5;
      int b=(boy*0.6)/4*5;
      QWidget *menu = new QWidget(this);
      gridSizePopLabel= new QLabel();
      gridSizePopLabel->setText("Satır ve Sütun Genişliği: "+QString::number(gridSize));
      QFont ff( "Arial", 7, QFont::Normal);
      gridSizePopLabel->setFont(ff);

      QSlider *gSize= new QSlider(Qt::Horizontal,menu);
       gSize->setRange(5,60);
      gSize->setSliderPosition(15);
      //gSize->setSingleStep(10);
      gSize->setTickInterval(10);
      connect(gSize,SIGNAL(valueChanged(int)),this,SLOT(setGridSize(int)));

     // auto widget = new QWidget;
      auto layout = new QGridLayout(menu);
        layout->setContentsMargins(0, 0, 0,0);
          // layout->setColumnMinimumWidth(0, 37);

          layout->addWidget(gSize,0,1,1,2);

            layout->addWidget(gridSizePopLabel, 1, 1,1,2);
              //  layout->setColumnStretch(6, 255);
              // add a widget action to the context menu
              auto wa = new QWidgetAction(this);
    //  wa->setIcon(QIcon(":/icon1"));
      wa->setDefaultWidget(menu);
      menu->addAction(wa);
      gSize->setStyleSheet(".QSlider::groove:Horizontal {"
                                     "background: rgba(0, 0, 50, 200);"
                                     "width:"+QString::number(e*5)+"px;"
                                      "height:"+QString::number(b/2)+"px;"
                                     "}"

                                     ".QSlider::handle:Horizontal {"
                                     "background: rgba(242, 242, 242, 95);"
                                     "border: 2px solid rgb(0,0,0);"
                                     "background: rgba(0, 0, 50, 255);"
                                     "width: "+QString::number(e/2)+"px;"
                                     "height: "+QString::number(b)+"px;"
                                      "margin:-"+QString::number(e/8*3)+"px   0   -"+QString::number(b/8*3)+"px   0;"
                                     "}");

      gSize->setFixedSize(QSize(e*5,b));
     // menu->setStyleSheet("QMenu { width: 290 px; height: 180 px; }");
     return menu;
}

QWidget *toolKalem::pageBottomMenu(int _boy)
{   int e=(_boy*0.8)/4*7;
    int b=(_boy*0.6)/4*5;
    QWidget *menu = new QWidget(this);


    QFont ff( "Arial", 8, QFont::Normal);

    delPageButton=new QPushButton();
    delPageButton=butonSlot(delPageButton,"",":icons/delpage.svg",QColor(255,0,0,0),e,b,e,b);

    connect(delPageButton, &QPushButton::clicked, [=]() {
        if (current_toolTahta->sceneIndex>0)
        {

           // current_toolTahta->sceneIndex--;
            silSayfaButtonClick();
            qDebug()<<"current_toolTahta->sceneIndex:"<<current_toolTahta->sceneIndex;
        }
        //emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);

    });

    addPageButton=new QPushButton();
    addPageButton=butonSlot(addPageButton,"",":icons/addpage.svg",QColor(255,0,0,0),e,b,e,b);

    connect(addPageButton, &QPushButton::clicked, [=]() {
        //current_toolTahta->sceneIndex++;
       // current_toolTahta->current_sceneIndex=current_toolTahta->sceneIndex;
        //qDebug()<<"current_toolTahta->sceneIndex:"<<current_toolTahta->sceneIndex;

       ekleSayfaButtonClick(-1,false,-1);///İlk Sayfa ekleniyor Açıldığında göünen sayfa
      //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });
    nextPageButton=new QPushButton();
    nextPageButton=butonSlot(nextPageButton,"",":icons/nextpage.svg",QColor(255,0,0,0),e,b,e,b);

    connect(nextPageButton, &QPushButton::clicked, [=]() {
        if(current_toolTahta->sceneIndex>current_toolTahta->current_sceneIndex)
        {
            current_toolTahta->current_sceneIndex++;
            qDebug()<<"current_toolTahta->current_sceneIndex:"<<current_toolTahta->current_sceneIndex;
        }
        //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);

    });

   backPageButton=new QPushButton();
    backPageButton=butonSlot(backPageButton,"",":icons/backpage.svg",QColor(255,0,0,0),e,b,e,b);

    connect(backPageButton, &QPushButton::clicked, [=]() {
        if (current_toolTahta->sceneIndex>0&&current_toolTahta->current_sceneIndex>0)
        {
            current_toolTahta->current_sceneIndex--;
            qDebug()<<"current_toolTahta->current_sceneIndex:"<<current_toolTahta->current_sceneIndex;
         }

      //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });

    zoomnegatifPageButton=new QPushButton();
    zoomnegatifPageButton=butonSlot(zoomnegatifPageButton,"",":icons/zoompagenegatif.svg",QColor(255,0,0,0),e,b,e,b);

    connect(zoomnegatifPageButton, &QPushButton::clicked, [=]() {
        zoomnegatifSayfaButtonClick();
      //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });


    zoompozitifPageButton=new QPushButton();
    zoompozitifPageButton=butonSlot(zoompozitifPageButton,"",":icons/zoompagepozitif.svg",QColor(255,0,0,0),e,b,e,b);

    connect(zoompozitifPageButton, &QPushButton::clicked, [=]() {
        zoompozitifSayfaButtonClick();
      //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });


    zoomfitPageButton=new QPushButton();
    zoomfitPageButton=butonSlot(zoomfitPageButton,"",":icons/zoompagefit.svg",QColor(255,0,0,0),e,b,e,b);

    connect(zoomfitPageButton, &QPushButton::clicked, [=]() {
        zoomfitSayfaButtonClick();
      //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });

    leftsidePageButton=new QPushButton();
    leftsidePageButton=butonSlot(leftsidePageButton,"",":icons/leftside.svg",QColor(255,0,0,0),e,b,e,b);

    connect(leftsidePageButton, &QPushButton::clicked, [=]() {
        sagSolHizala();
      //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });

    rightsidePageButton=new QPushButton();
    rightsidePageButton=butonSlot(rightsidePageButton,"",":icons/rightside.svg",QColor(255,0,0,0),e,b,e,b);

    connect(rightsidePageButton, &QPushButton::clicked, [=]() {
        sagSolHizala();
      //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });

    pageListwg=new QWidget(menu);
    pageListwg->setFixedSize(e*12,b);
   /// pageListwg->setPalette(*palette);
   // pageListwg->move(this->width()/4,this->height()-boy-boy);
    //pageListwg->setAutoFillBackground(true);
    pageListwg->setObjectName("pageListwg");

    pageListwg->setStyleSheet("QWidget#pageListwg{"
                          "border: 0.5px solid rgba(62, 140, 220,20);"
                          "border-radius: 5px;"
                          "background-color:rgba(255,255,255,0);"
                          "}");

    sceneListButtonLayout = new QHBoxLayout(pageListwg);
    sceneListButtonLayout->setContentsMargins(0, 0, 0, 0);

    auto layout = new QGridLayout(menu);
    layout->setContentsMargins(0, 0, 0, 1);
    //layout->setMargin(0);
   // layout->setColumnMinimumWidth(0, 37);


    layout->addWidget(leftsidePageButton, 0, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(backPageButton, 0, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(addPageButton, 0, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(pageListwg, 0, 4,1,1,Qt::AlignHCenter);

    layout->addWidget(delPageButton, 0, 6,1,1,Qt::AlignHCenter);
    layout->addWidget(nextPageButton, 0, 7,1,1,Qt::AlignHCenter);
    layout->addWidget(zoomnegatifPageButton, 0, 8,1,1,Qt::AlignHCenter);
    layout->addWidget(zoompozitifPageButton, 0, 9,1,1,Qt::AlignHCenter);
    layout->addWidget(zoomfitPageButton, 0, 10,1,1,Qt::AlignHCenter);
    layout->addWidget(rightsidePageButton, 0, 11,1,1,Qt::AlignHCenter);

       //menu->setFixedSize(QSize(e*20,b));
   // menu->setStyleSheet("QMenu { width: 290 px; height: 180 px; }");

   return menu;
}
QWidget *toolKalem::pdfTopMenu(int _boy)
{   int e=(en*0.8)/4*5;
    int b=(boy*0.6)/4*4.3;
    QWidget *menu = new QWidget(this);
    QFont ff( "Arial", 7, QFont::Normal);

    QPushButton *pdfOpenButton=new QPushButton();
    pdfOpenButton=butonSlot(pdfOpenButton,"",":icons/pdfopen.svg",QColor(255,0,0,0),e,b,e,b);
    connect(pdfOpenButton, &QPushButton::clicked, [=]() {
        //emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);

        bool fileSelected=false;
        Qt::WindowFlags flags = 0;
       //if(screenDesktop==true) ekranButtonClick();

        flags |= Qt::Window;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::CustomizeWindowHint;
        this->setWindowFlags(flags);

        QFileDialog abc;
       /// abc.setSidebarUrls(urls);
        abc.setFileMode(QFileDialog::AnyFile);

        flags |= Qt::SplashScreen;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::WindowStaysOnTopHint;
        // QFileDialog abc;
        abc.setWindowFlags(flags);

        QString os="";
    #ifdef WIN32
        // Windows code here
        os="windows";
    #else
        // UNIX code here
        os="linux";
    #endif

        if(os=="linux"){
            //qDebug()<<"linux fileopen";
            abc.setWindowTitle("Pdf Dosyası Aç");
            abc.setDirectory(QDir::homePath()+"/Masaüstü");
            abc.setNameFilter(tr("PDF file (*.pdf)"));
            abc.setWindowModality( Qt::WindowModal );
            abc.setFileMode( QFileDialog::AnyFile );
            abc.setModal(true);
               abc.setWindowModality(Qt::ApplicationModal);

            if(abc.exec()) {
                if(abc.selectedFiles()[0].contains(".pdf", Qt::CaseInsensitive)) fileSelected=true;

               //..

            }
           // int i =
                 //   abc.show();
             //   qDebug() << "Dialog result: " << i;

    //if(screenDesktop==false) ekranButtonClick();
        }
        else
        {
            //qDebug()<<"windows fileopen";
            abc.setWindowTitle("Pdf Dosya Aç");
            abc.setDirectory(QDir::homePath()+"/desktop");
            abc.setNameFilter(tr("PDF file (*.pdf)"));
            abc.setWindowModality( Qt::WindowModal );
            abc.setFileMode( QFileDialog::AnyFile );
            int i = abc.exec();
                qDebug() << "Dialog result: " << i;

            if(abc.exec()) {
                if(abc.selectedFiles()[0].contains(".pdf", Qt::CaseInsensitive)) fileSelected=true;

            ///    if(screenDesktop==false) ekranButtonClick();

            }
            //qDebug()<<"selam";


        }

        flags |= Qt::Window;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::WindowStaysOnTopHint;
        this->setWindowFlags(flags);
        show();


        if(fileSelected==false) return;
        fileSelected=false;
       // Poppler::Document *doc
         current_toolTahta->doc = Poppler::Document::load(abc.selectedFiles()[0]);
       current_toolTahta->doc->setRenderHint(Poppler::Document::TextAntialiasing,true);
        current_toolTahta->doc->setRenderHint(Poppler::Document::Antialiasing,true);
        current_toolTahta->doc->setRenderHint(Poppler::Document::TextHinting,true);
        current_toolTahta->doc->setRenderHint(Poppler::Document::TextSlightHinting,true);
        current_toolTahta->doc->setRenderHint(Poppler::Document::ThinLineSolid,true);
        current_toolTahta->doc->setRenderBackend(Poppler::Document::ArthurBackend);

        current_toolTahta->pdfPageCount=current_toolTahta->doc->numPages();
        current_toolTahta->pdfFirstPageNumber=0;
        current_toolTahta->pdfLastPageNumber=0;
        //******************Load Pdf File************************************
        if(current_toolTahta->pdfPageCount>0)
        {


            //pdfobjectnumber=1;
           // pdfPageList=1;
            ileriSayfaButtonClick();

            //sceneSayfaActiveNumber=0;
           // scene=sceneSayfa[sceneSayfaActiveNumber];
           // view->setScene(scene);
           // if(scene->pdfObjectAdded&&scene->pdfObjectShow==false) pdfLoaderPage(sceneSayfaActiveNumber);///pdf page loader
            //currentScreenModeSlot();
        }
    });

    QPushButton *pdfSaveButton=new QPushButton();
    pdfSaveButton=butonSlot(pdfSaveButton,"",":icons/pdfsave.svg",QColor(255,0,0,0),e,b,e,b);
    connect(pdfSaveButton, &QPushButton::clicked, [=]() {
        //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
        Qt::WindowFlags flags = 0;
        flags |= Qt::Dialog;
        flags |= Qt::X11BypassWindowManagerHint;

        QMessageBox messageBox(this);
        messageBox.setWindowFlags(flags);
        messageBox.setText("Bilgi\t\t\t\t\t\t");
        messageBox.setInformativeText("Pdf Dosyası Masaüstünüze Kaydedilecek\n"
                                      "Bu İşlem Kaydedeceğiniz Sayfa Sayısına Göre Zaman Alacaktır\n"
                                      "İşlemler Tamamlanana Kadar Lütfen Bekleyiniz... ");
        QAbstractButton *evetButton =messageBox.addButton(tr("Tamam"), QMessageBox::ActionRole);
        messageBox.setIcon(QMessageBox::Information);
        messageBox.exec();
        /**********************************************************************************************************/
        QString fileName;
        QString os="";
        #ifdef WIN32
        // Windows code here
        os="windows";
        #else
        // UNIX code here
            os="linux";
        #endif

            if(os=="linux"){
            fileName=QDir::homePath()+"/Masaüstü/E-Tahta.pdf";
            }
        else{//windows
            fileName=QDir::homePath()+"/desktop/E-Tahta.pdf";
           }


            QFile f(fileName);
               f.open(QIODevice::WriteOnly);
               QPdfWriter* pdfWriter = new QPdfWriter(&f);

            //QPdfWriter *pdfWriter(&f);
    //pdfWriter.setPageSize(QPageSize(100,100));
    pdfWriter->setPageSizeMM(QSizeF(current_toolTahta->gv->sceneRect().toRect().width(), current_toolTahta->gv->sceneRect().toRect().height()));
    QPainter painter(pdfWriter);
    //qDebug()<<"Sayfacreate Start"<<QDateTime::currentDateTime();
    for(int i=0;i<current_toolTahta->sceneListButton.length();i++) {
          secSayfaButtonClick(i);///sayfalar sırayla pdf yapılıyor
                 current_toolTahta->scene->makeItemsControllable(false);
                 painter.setWindow(QRect(0, 0, current_toolTahta->gv->sceneRect().toRect().width(), current_toolTahta->gv->sceneRect().toRect().height()));
                 QPixmap pixMap = current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
                 painter.drawPixmap(0,0,pixMap);

        if(i!=current_toolTahta->sceneListButton.length()-1)pdfWriter->newPage();
    }
    //qDebug()<<"Sayfacreate End"<<QDateTime::currentDateTime();
    painter.end();
    delete pdfWriter;
    f.close();

    QString st;
    st.append(QDir::homePath()+"/Masaüstü/E-Tahta.pdf");
    st.append("\n\nDosyası Masaüstünüze Kaydedildi. ");


     Qt::WindowFlags flagss = 0;
     flagss |= Qt::Dialog;
     flagss |= Qt::X11BypassWindowManagerHint;

     QMessageBox messageBox1(this);
     messageBox1.setWindowFlags(flagss);
     messageBox1.setText("Bilgi\t\t\t");
     messageBox1.setInformativeText(st);
     QAbstractButton *evetButton1 =messageBox1.addButton(tr("Tamam"), QMessageBox::ActionRole);
    // QAbstractButton *hayirButton =messageBox.addButton(tr("Hayır"), QMessageBox::ActionRole);
     messageBox1.setIcon(QMessageBox::Information);
             messageBox1.exec();

    });
    QLabel *openLabel=new QLabel("Pdf Aç");      openLabel->setFont(ff);
    QLabel *saveLabel=new QLabel("Pdf Kaydet");  saveLabel->setFont(ff);

    auto layout = new QGridLayout(menu);
    layout->setContentsMargins(5, 3, 5, 1);
    layout->addWidget(pdfOpenButton, 0, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(pdfSaveButton, 0, 2,1,1,Qt::AlignHCenter);
     layout->addWidget(openLabel,1,1,1,1,Qt::AlignHCenter);
     layout->addWidget(saveLabel,1,2,1,1,Qt::AlignHCenter);
    //  layout->setColumnStretch(6, 255);
    //menu->setFixedSize(QSize(e*10,b*2));
    return menu;
}

QWidget *toolKalem::eraseTopMenu(int _boy)
{   int e=(_boy*0.8)/4*5;
    int b=(_boy*0.6)/4*4.3;
    QWidget *menu = new QWidget(this);
    eraseSizePopLabel= new QLabel();

    eraseSizePopLabel->setText("Silgi Boyutu: "+QString::number(penSize));
  //  eraseSizePopLabel->resize(e,b);
    QFont ff( "Arial", 7, QFont::Normal);
    eraseSizePopLabel->setFont(ff);

    QSlider *eraseSize= new QSlider(Qt::Horizontal,menu);
    //eraseSize->setMinimum(2);
    //eraseSize->setMaximum(1);
    eraseSize->setRange(1,15);
    eraseSize->setSliderPosition(4);
    connect(eraseSize,SIGNAL(valueChanged(int)),this,SLOT(setEraseSize(int)));

    QPushButton *silMenuButton=new QPushButton();
  //  silMenuButton->setFixedSize(e, b);
    //silMenuButton->setIconSize(QSize(e,b));
   // silMenuButton=butonToolSlot(silMenuButton,"Silgi",":icons/erase.png",QColor(255,0,0,0),en*1.5,boy);
    silMenuButton=butonSlot(silMenuButton,"",":icons/erase.png",QColor(255,0,0,0),e,b,e,b);

    connect(silMenuButton, &QPushButton::clicked, [=]() {
        //qDebug()<<b;
        //emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });

    QPushButton *temizleMenuButton=new QPushButton();
   // temizleMenuButton->setFixedSize(e, b);
    //temizleMenuButton->setIconSize(QSize(e,b));
     temizleMenuButton=butonSlot(temizleMenuButton,"",":icons/clear.png",QColor(255,0,0,0),e,b,e,b);

    connect(temizleMenuButton, &QPushButton::clicked, [=]() {
      //  emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
       });

    auto layout = new QGridLayout(menu);
    layout->setContentsMargins(5, 3, 5, 1);
    //layout->setMargin(0);
   // layout->setColumnMinimumWidth(0, 37);

    QLabel *silLabel=new QLabel("Sil");
    QLabel *temizleLabel=new QLabel("Temizle");
    QLabel *boyutLabel=new QLabel("Silgi Boyutu");
    silLabel->setFont(ff);temizleLabel->setFont(ff);boyutLabel->setFont(ff);
    layout->addWidget(eraseSizePopLabel, 0,0,2,1);
    layout->addWidget(silMenuButton, 0, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(temizleMenuButton, 0, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(eraseSize,0,3,1,1);

    layout->addWidget(silLabel,1,1,1,1,Qt::AlignHCenter);
    layout->addWidget(temizleLabel,1,2,1,1,Qt::AlignHCenter);
    layout->addWidget(boyutLabel,1,3,1,1,Qt::AlignHCenter);


  //  layout->setColumnStretch(6, 255);
    connect(silMenuButton, &QPushButton::clicked, [=]() {
        //scene->setPopMenuStatus(false);
      //  menu->close();
        //kalemButtonClick();
    });
    connect(temizleMenuButton, &QPushButton::clicked, [=]() {
       // scene->setPopMenuStatus(false);
        //menu->close();
        //kalemButtonClick();
    });
    // add a widget action to the context menu

    eraseSize->setStyleSheet(".QSlider::groove:Horizontal {"
                                   "background: rgba(0, 0, 50, 200);"
                                   "width:"+QString::number(e*3)+"px;"
                                    "height:"+QString::number(b/2)+"px;"
                                   "}"

                                   ".QSlider::handle:Horizontal {"
                                   "background: rgba(242, 242, 242, 95);"
                                   "border: 2px solid rgb(0,0,0);"
                                   "background: rgba(0, 0, 50, 255);"
                                   "width: "+QString::number(e/2)+"px;"
                                   "height: "+QString::number(b)+"px;"
                                    "margin:-"+QString::number(e/8*3)+"px   0   -"+QString::number(b/8*3)+"px   0;"
                                   "}");

    eraseSize->setFixedSize(QSize(e*3,b));
   menu->setFixedSize(QSize(e*10,b*2));
   // menu->setStyleSheet("QMenu { width: 290 px; height: 180 px; }");
   return menu;
}

QMenu *toolKalem::eraseMenu()
{   int e=(en*0.8)/4*9;
    int b=(boy*0.6)/4*5;
    QMenu *menu = new QMenu(this);
    eraseSizePopLabel= new QLabel();

    eraseSizePopLabel->setText("Silgi Boyutu: "+QString::number(penSize));
  //  eraseSizePopLabel->resize(e,b);
    QFont ff( "Arial", 8, QFont::Normal);
    eraseSizePopLabel->setFont(ff);

    QSlider *eraseSize= new QSlider(Qt::Horizontal,menu);
    //eraseSize->setMinimum(2);
    //eraseSize->setMaximum(1);
    eraseSize->setRange(1,15);
    eraseSize->setSliderPosition(4);
    ///connect(eraseSize,SIGNAL(valueChanged(int)),this,SLOT(setEraseSize(int)));
    QToolButton *silMenuButton=new QToolButton();
    silMenuButton->setFixedSize(e, b);
    silMenuButton->setIconSize(QSize(e,b));

    QToolButton *temizleMenuButton=new QToolButton();
    temizleMenuButton->setFixedSize(e, b);
    temizleMenuButton->setIconSize(QSize(e,b));

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
   // layout->setContentsMargins(0, 0, 0, 3);
   // layout->setColumnMinimumWidth(0, 37);


    layout->addWidget(eraseSizePopLabel, 1, 1,1,2);
    layout->addWidget(silMenuButton, 2, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(temizleMenuButton, 2, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Sil</font>"),3,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Tahta Temizle</font>"),3,2,1,1,Qt::AlignHCenter);

    layout->addWidget(eraseSize,4,1,1,2);
  //  layout->setColumnStretch(6, 255);
    connect(silMenuButton, &QPushButton::clicked, [=]() {
        //scene->setPopMenuStatus(false);
        menu->close();
        //kalemButtonClick();
    });
    connect(temizleMenuButton, &QPushButton::clicked, [=]() {
       // scene->setPopMenuStatus(false);
        menu->close();
        //kalemButtonClick();
    });
    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);
    eraseSize->setStyleSheet(".QSlider::groove:Horizontal {"
                                   "background: rgba(0, 0, 50, 200);"
                                   "width:"+QString::number(e*3)+"px;"
                                    "height:"+QString::number(b/2)+"px;"
                                   "}"

                                   ".QSlider::handle:Horizontal {"
                                   "background: rgba(242, 242, 242, 95);"
                                   "border: 2px solid rgb(0,0,0);"
                                   "background: rgba(0, 0, 50, 255);"
                                   "width: "+QString::number(e/2)+"px;"
                                   "height: "+QString::number(b)+"px;"
                                    "margin:-"+QString::number(e/8*3)+"px   0   -"+QString::number(b/8*3)+"px   0;"
                                   "}");

    eraseSize->setFixedSize(QSize(e*2.5,b));
   // menu->setStyleSheet("QMenu { width: 290 px; height: 180 px; }");
   return menu;
}

QMenu* toolKalem::sekilMenu()
{
    int ken=300;
    //ken=300;
    int e=(en*0.8)/4*9;
    int b=(boy*0.6)/4*5;
    e=e/2;
    QMenu *menu= new QMenu();
      menu->installEventFilter(this);
      /*************************************************************************/
    DiagramItem *ditem=new DiagramItem();

    QPushButton *penStyleSolidLine = new QPushButton;
    penStyleSolidLine->setFixedSize(e, b);
    penStyleSolidLine->setIconSize(QSize(e,b));
   // penStyleSolidLine->setFlat(true);
    penStyleSolidLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::SolidLine,ken,ken));
    connect(penStyleSolidLine, &QPushButton::clicked, [=]() {
     emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::SolidLine);

    });

    QPushButton *penStyleDashLine = new QPushButton;
    penStyleDashLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DashLine,ken,ken));
    penStyleDashLine->setFixedSize(e, b);
    penStyleDashLine->setIconSize(QSize(e,b));
   // penStyleDashLine->setFlat(true);
    connect(penStyleDashLine, &QPushButton::clicked, [=]() {
  emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::DashLine);

    });

    QPushButton *penStyleDotLine = new QPushButton;
    penStyleDotLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DotLine,ken,ken));
    penStyleDotLine->setFixedSize(e, b);
    penStyleDotLine->setIconSize(QSize(e,b));
   // penStyleDotLine->setFlat(true);
    connect(penStyleDotLine, &QPushButton::clicked, [=]() {
         emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::DotLine);

    });
/********************************************************************/


    /***********************pergel cetvel gönye iletki***************/


    QPushButton *pergel = new QPushButton;
    pergel->setFixedSize(e, b);
    pergel->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);
    pergel->setIcon(QIcon(":icons/pergel.png"));
    connect(pergel, &QPushButton::clicked, [=]() {
          emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Pergel);

        menu->close();
    });

    QPushButton *cetvel = new QPushButton;
    cetvel->setIcon(QIcon(":icons/cetvel.png"));
    cetvel->setFixedSize(e, b);
    cetvel->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    connect(cetvel, &QPushButton::clicked, [=]() {
         emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Cetvel);

        menu->close();

    });

    QPushButton *gonye = new QPushButton;
    gonye->setIcon(QIcon(":icons/gonye.png"));
    gonye->setFixedSize(e, b);
    gonye->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(gonye, &QPushButton::clicked, [=]() {
         emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Gonye);

        menu->close();

    });

    QPushButton *iletki = new QPushButton;
    iletki->setIcon(QIcon(":icons/iletki.png"));
    iletki->setFixedSize(e, b);
    iletki->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(iletki, &QPushButton::clicked, [=]() {
          emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Iletki);

        menu->close();

    });
    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->setSpacing(en/3*2);
    layout1->addWidget(pergel);
    layout1->addWidget(cetvel);
    layout1->addWidget(gonye);
    layout1->addWidget(iletki);

     /***********************küp silindir küre pramid***************/


    QPushButton *kup = new QPushButton;
    kup->setFixedSize(e, b);
    kup->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);
    kup->setIcon(QIcon(":/icons/kup.png"));
    connect(kup, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Kup);
         menu->close();
    });

    QPushButton *silindir = new QPushButton;
    silindir->setIcon(QIcon(":icons/silindir.png"));
    silindir->setFixedSize(e, b);
    silindir->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    connect(silindir, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Silindir);
        menu->close();

    });

    QPushButton *pramit = new QPushButton;
    pramit->setIcon(QIcon(":icons/pramit.png"));
    pramit->setFixedSize(e, b);
    pramit->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(pramit, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Pramit);
        menu->close();

    });

    QPushButton *kure = new QPushButton;
    kure->setIcon(QIcon(":/icons/kure.png"));
    kure->setFixedSize(e, b);
    kure->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(kure, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Kure);
     menu->close();

    });
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(kup);
    layout2->addWidget(silindir);
    layout2->addWidget(pramit);
    layout2->addWidget(kure);
    layout2->setSpacing(en/3*2);
    /***********************************************************/

    QPushButton *cizgi= new QPushButton;
    cizgi->setFixedSize(e, b);
    cizgi->setIconSize(QSize(e,b));
   // cizgi->setFlat(true);
    cizgi->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Cizgi,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cizgi, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Cizgi);
        menu->close();
    });

    QPushButton *ok= new QPushButton;
    ok->setFixedSize(e, b);
    ok->setIconSize(QSize(e,b));
    //ok->setFlat(true);
    ok->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Ok,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ok, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Ok);

    menu->close();
    });

    QPushButton *ciftok= new QPushButton;
    ciftok->setFixedSize(e, b);
    ciftok->setIconSize(QSize(e,b));
    //ciftok->setFlat(true);
    ciftok->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::CiftOk,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ciftok, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::CiftOk);
        menu->close();
    });

    QPushButton *ucgen= new QPushButton;
    ucgen->setFixedSize(e, b);
    ucgen->setIconSize(QSize(e,b));
   // ucgen->setFlat(true);
    ucgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Ucgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ucgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Ucgen);
         menu->close();
    });

    QPushButton *dortgen= new QPushButton;
    dortgen->setFixedSize(e, b);
    dortgen->setIconSize(QSize(e,b));
    //dortgen->setFlat(true);
    dortgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Dortgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(dortgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Dortgen);
        menu->close();
    });

    QPushButton *cember= new QPushButton;
    cember->setFixedSize(e, b);
    cember->setIconSize(QSize(e,b));
   // cember->setFlat(true);
    cember->setIcon(imageEllipse(ditem->sekilStore(DiagramItem::DiagramType::Cember,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cember, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Cember);
       menu->close();
    });

    QPushButton *baklava= new QPushButton;
    baklava->setFixedSize(e, b);
    baklava->setIconSize(QSize(e,b));
    //baklava->setFlat(true);
    baklava->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Baklava,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(baklava, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Baklava);
         menu->close();
    });

    QPushButton *yamuk= new QPushButton;
    yamuk->setFixedSize(e, b);
    yamuk->setIconSize(QSize(e,b));
    //yamuk->setFlat(true);
    yamuk->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Yamuk,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(yamuk, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Yamuk);
          menu->close();
    });

    QPushButton *besgen= new QPushButton;
    besgen->setFixedSize(e, b);
    besgen->setIconSize(QSize(e,b));
    //esgen->setFlat(true);
    besgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Besgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(besgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Besgen);
        menu->close();
     });

    QPushButton *altigen= new QPushButton;
    altigen->setFixedSize(e, b);
    altigen->setIconSize(QSize(e,b));
    //altigen->setFlat(true);
    altigen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Altigen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(altigen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Altigen);

      menu->close();
    });

    QPushButton *sekizgen= new QPushButton;
    sekizgen->setFixedSize(e, b);
    sekizgen->setIconSize(QSize(e,b));
    //sekizgen->setFlat(true);
    sekizgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Sekizgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(sekizgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Sekizgen);
          menu->close();
    });

    QPushButton *dikucgen= new QPushButton;
    dikucgen->setFixedSize(e, b);
    dikucgen->setIconSize(QSize(e,b));
    //dikucgen->setFlat(true);
    dikucgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::DikUcgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(dikucgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::DikUcgen);
     menu->close();
    });

    QPushButton *guzelyazi= new QPushButton;
    guzelyazi->setFixedSize(e, b);
    guzelyazi->setIconSize(QSize(e,b));
    //guzelyazi->setFlat(true);
    guzelyazi->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::GuzelYazi,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(guzelyazi, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::GuzelYazi);
     menu->close();
    });

    QPushButton *muzik= new QPushButton;
    muzik->setFixedSize(e, b);
    muzik->setIconSize(QSize(e,b));
    //muzik->setFlat(true);
    muzik->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Muzik,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(muzik, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Muzik);
    menu->close();
    });

    QPushButton *cizgilisayfa= new QPushButton;
    cizgilisayfa->setFixedSize(e, b);
    cizgilisayfa->setIconSize(QSize(e,b));
   // cizgilisayfa->setFlat(true);
    cizgilisayfa->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::CizgiliSayfa,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cizgilisayfa, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::CizgiliSayfa);
         menu->close();
    });
    QPushButton *resimEkle= new QPushButton;
    resimEkle->setFixedSize(e, b);
    resimEkle->setIconSize(QSize(e,b));
    resimEkle->setFlat(true);
    resimEkle->setIcon(QIcon(":icons/addimage.png"));
    connect(resimEkle, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Resim);

         menu->close();
    });

    QPushButton *sekilKalemRenkButton=new QPushButton();
    sekilKalemRenkButton->setFixedSize(e,b);
    sekilKalemRenkButton->setIconSize(QSize(e,b));
    QPushButton *sekilZeminRenkButton=new QPushButton();

    sekilZeminRenkButton->setFixedSize(e,b);
    sekilZeminRenkButton->setIconSize(QSize(e,b));
    connect(sekilZeminRenkButton, &QPushButton::clicked, [=]() {
        colorMenu("sekilZeminColor","dikey",en,boy,true)->exec(mapToGlobal(mapToParent(menu->pos())));

         //menu->close();
    });
    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
   // layout->setContentsMargins(20, 0, 0, 0);
    //layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(sekilLabel, 0, 1,1,3);
   // layout->addWidget(sekilKalemSizePopLabel, 1, 1,1,3);
  //  layout->addWidget(sekilPenSize, 2, 1,1,3);

  /*  layout->addWidget(penStyleSolidLine, 3, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDashLine, 3, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDotLine, 3, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Çizgi</font>"),4,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Kesik Çizgi</font>"),4,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Noktalı Çizgi</font>"),4,3,1,1,Qt::AlignHCenter);
*/
    layout->addLayout(layout1, 5, 1,1,3,Qt::AlignHCenter);
    QFont ff( "Arial", 5, QFont::Normal);

    QHBoxLayout *arac = new QHBoxLayout;
    QLabel *pergell= new QLabel("Pergel");      pergell->setFont(ff);
    QLabel *gonyel=  new QLabel("Gönye");        gonyel->setFont(ff);
    QLabel *cetvell= new QLabel("Cetvel");    cetvell->setFont(ff);;
    QLabel *iletkil= new QLabel("İletki");      iletkil->setFont(ff);
    arac->addWidget(pergell,Qt::AlignHCenter);
    arac->addWidget(gonyel,Qt::AlignHCenter);
    arac->addWidget(cetvell,Qt::AlignHCenter);
    arac->addWidget(iletkil,Qt::AlignHCenter);
    arac->setSpacing(en/3*2);
    layout->addLayout(arac, 6, 1,1,3,Qt::AlignHCenter);


    layout->addLayout(layout2, 7, 1,1,3,Qt::AlignHCenter);
   //layout->addLayout(layout0, 8, 1,1,3,Qt::AlignHCenter);
  // layout->addLayout(layout00, 9, 1,1,3,Qt::AlignHCenter);

//colorWidget
   QWidget *cw=colorWidget("sekilZeminColor","yatay",en/2,boy/2,false);
   cw->setFixedSize(en*6,boy);
   cw->setVisible(true);
    layout->addWidget(cw, 10, 1,1,3,Qt::AlignHCenter);
   QHBoxLayout *line0 = new QHBoxLayout;
   line0->addWidget(cizgi,Qt::AlignHCenter);
   line0->addWidget(ok,Qt::AlignHCenter);
   line0->addWidget(ciftok,Qt::AlignHCenter);
   line0->addWidget(ucgen,Qt::AlignHCenter);
   line0->setSpacing(en/3*2);
   layout->addLayout(line0, 11, 1,1,3,Qt::AlignHCenter);
   QHBoxLayout *line00 = new QHBoxLayout;
   QLabel *lb00= new QLabel("Çizgi");
   QLabel *lb01=  new QLabel("Ok");
   QLabel *lb02= new QLabel("Çift Ok");
   QLabel *lb03= new QLabel("Üçgen");
  // QFont ff( "Arial", 5, QFont::Normal);
   lb00->setFont(ff);lb01->setFont(ff);lb02->setFont(ff);lb03->setFont(ff);
   lb00->setFixedSize(20,15);
   lb01->setFixedSize(20,15);
   lb02->setFixedSize(22,15);
   lb03->setFixedSize(20,15);

   line00->addWidget(lb00,Qt::AlignHCenter);
   line00->addWidget(lb01,Qt::AlignHCenter);
   line00->addWidget(lb02,Qt::AlignHCenter);
   line00->addWidget(lb03,Qt::AlignHCenter);
   line00->setSpacing(en/3*2);
   layout->addLayout(line00, 12, 1,1,3,Qt::AlignHCenter);

   /***************************************************************/
   QHBoxLayout *line01 = new QHBoxLayout;
   line01->addWidget(dortgen,Qt::AlignHCenter);
   line01->addWidget(cember,Qt::AlignHCenter);
   line01->addWidget(baklava,Qt::AlignHCenter);
   line01->addWidget(yamuk,Qt::AlignHCenter);
   line01->setSpacing(en/3*2);
   layout->addLayout(line01, 13, 1,1,3,Qt::AlignHCenter);
   QHBoxLayout *line10 = new QHBoxLayout;
   QLabel *lb10= new QLabel("Dörtgen");
   QLabel *lb11=  new QLabel("Çember");
   QLabel *lb12= new QLabel("Baklava");
   QLabel *lb13= new QLabel("Yamuk");
  // QFont ff( "Arial", 5, QFont::Normal);
   lb10->setFont(ff);lb11->setFont(ff);lb12->setFont(ff);lb13->setFont(ff);
   lb10->setFixedSize(25,15);
   lb11->setFixedSize(25,15);
   lb12->setFixedSize(24,15);
   lb13->setFixedSize(24,15);

   line10->addWidget(lb10,Qt::AlignHCenter);
   line10->addWidget(lb11,Qt::AlignHCenter);
   line10->addWidget(lb12,Qt::AlignHCenter);
   line10->addWidget(lb13,Qt::AlignHCenter);
   line10->setSpacing(en/3*2);
   layout->addLayout(line10, 14, 1,1,3,Qt::AlignHCenter);

   /**************************************************************/
   QHBoxLayout *line02 = new QHBoxLayout;
   line02->addWidget(besgen,Qt::AlignHCenter);
   line02->addWidget(altigen,Qt::AlignHCenter);
   line02->addWidget(sekizgen,Qt::AlignHCenter);
   line02->addWidget(dikucgen,Qt::AlignHCenter);
   line02->setSpacing(en/3*2);
   layout->addLayout(line02, 15, 1,1,3,Qt::AlignHCenter);
    QLabel *lb20= new QLabel("Beşgen");
   QLabel *lb21=  new QLabel("Altıgen");
   QLabel *lb22= new QLabel("Sekizgen");
   QLabel *lb23= new QLabel("D.Üçgen");
  // QFont ff( "Arial", 5, QFont::Normal);
   lb20->setFont(ff);lb21->setFont(ff);lb22->setFont(ff);lb23->setFont(ff);
   lb20->setFixedSize(25,15);
   lb21->setFixedSize(25,15);
   lb22->setFixedSize(24,15);
   lb23->setFixedSize(24,15);
   QHBoxLayout *line20 = new QHBoxLayout;
   line20->addWidget(lb20,Qt::AlignHCenter);
   line20->addWidget(lb21,Qt::AlignHCenter);
   line20->addWidget(lb22,Qt::AlignHCenter);
   line20->addWidget(lb23,Qt::AlignHCenter);
   line20->setSpacing(en/3*2);
   layout->addLayout(line20, 16, 1,1,3,Qt::AlignHCenter);
   layout->addWidget(resimEkle, 17, 1,1,3,Qt::AlignHCenter);


 //   layout->setColumnStretch(10, 255);
    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);
      return menu;
}

QWidget* toolKalem::sekilTopMenu(int _boy)
{
    int ken=300;
    //ken=300;
    int e=(_boy*0.8)/4*5;
    int b=(_boy*0.6)/4*4.3;
    e=e/2;
    QWidget *menu= new QWidget();
      menu->installEventFilter(this);
      /*************************************************************************/
    DiagramItem *ditem=new DiagramItem();

    QPushButton *penStyleSolidLine = new QPushButton;
    penStyleSolidLine->setFixedSize(e, b);
    penStyleSolidLine->setIconSize(QSize(e,b));
   // penStyleSolidLine->setFlat(true);
    penStyleSolidLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::SolidLine,ken,ken));
    connect(penStyleSolidLine, &QPushButton::clicked, [=]() {
     emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::SolidLine);

    });

    QPushButton *penStyleDashLine = new QPushButton;
    penStyleDashLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DashLine,ken,ken));
    penStyleDashLine->setFixedSize(e, b);
    penStyleDashLine->setIconSize(QSize(e,b));
   // penStyleDashLine->setFlat(true);
    connect(penStyleDashLine, &QPushButton::clicked, [=]() {
  emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::DashLine);

    });

    QPushButton *penStyleDotLine = new QPushButton;
    penStyleDotLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DotLine,ken,ken));
    penStyleDotLine->setFixedSize(e, b);
    penStyleDotLine->setIconSize(QSize(e,b));
   // penStyleDotLine->setFlat(true);
    connect(penStyleDotLine, &QPushButton::clicked, [=]() {
         emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::DotLine);

    });
/********************************************************************/


    /***********************pergel cetvel gönye iletki***************/


    QPushButton *pergel = new QPushButton;
    pergel->setFixedSize(e*2, b);
    pergel->setIconSize(QSize(e*2,b));
    pergel->setFlat(true);
    pergel->setIcon(QIcon(":icons/pergel.png"));
    connect(pergel, &QPushButton::clicked, [=]() {
          emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Pergel);

      //  menu->close();
    });

    QPushButton *cetvel = new QPushButton;
    cetvel->setIcon(QIcon(":icons/cetvel.png"));
    cetvel->setFixedSize(e*2, b);
    cetvel->setIconSize(QSize(e*2,b));
    cetvel->setFlat(true);
    connect(cetvel, &QPushButton::clicked, [=]() {
         emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Cetvel);

     //   menu->close();

    });

    QPushButton *gonye = new QPushButton;
    gonye->setIcon(QIcon(":icons/gonye.png"));
    gonye->setFixedSize(e*2, b);
    gonye->setIconSize(QSize(e*2,b));
    gonye->setFlat(true);
    connect(gonye, &QPushButton::clicked, [=]() {
         emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Gonye);

    //    menu->close();

    });

    QPushButton *iletki = new QPushButton;
    iletki->setIcon(QIcon(":icons/iletki.png"));
    iletki->setFixedSize(e*2, b);
    iletki->setIconSize(QSize(e*2,b));
    iletki->setFlat(true);
    connect(iletki, &QPushButton::clicked, [=]() {
          emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Iletki);

      //  menu->close();

    });


     /***********************küp silindir küre pramid***************/


    QPushButton *kup = new QPushButton;
    kup->setFixedSize(e*2, b);
    kup->setIconSize(QSize(e*2,b));
    kup->setFlat(true);
    kup->setIcon(QIcon(":/icons/kup.png"));
    connect(kup, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Kup);
    //     menu->close();
    });

    QPushButton *silindir = new QPushButton;
    silindir->setIcon(QIcon(":icons/silindir.png"));
    silindir->setFixedSize(e*2, b);
    silindir->setIconSize(QSize(e*2,b));
    silindir->setFlat(true);
    connect(silindir, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Silindir);
    //    menu->close();

    });

    QPushButton *pramit = new QPushButton;
    pramit->setIcon(QIcon(":icons/pramit.png"));
    pramit->setFixedSize(e*2, b);
    pramit->setIconSize(QSize(e*2,b));
    pramit->setFlat(true);
    connect(pramit, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Pramit);
     //   menu->close();

    });

    QPushButton *kure = new QPushButton;
    kure->setIcon(QIcon(":/icons/kure.png"));
    kure->setFixedSize(e*2, b);
    kure->setIconSize(QSize(e*2,b));
    kure->setFlat(true);
    connect(kure, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Kure);
    // menu->close();

    });

    /***********************************************************/

    QPushButton *cizgi= new QPushButton;
    cizgi->setFixedSize(e*2, b);
    cizgi->setIconSize(QSize(e*2,b));
    cizgi->setFlat(true);
    cizgi->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Cizgi,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cizgi, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Cizgi);
     //   menu->close();
    });

    QPushButton *ok= new QPushButton;
    ok->setFixedSize(e*2, b);
    ok->setIconSize(QSize(e*2,b));
    ok->setFlat(true);
    ok->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Ok,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ok, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Ok);

   // menu->close();
    });

    QPushButton *ciftok= new QPushButton;
    ciftok->setFixedSize(e*2, b);
    ciftok->setIconSize(QSize(e*2,b));
    ciftok->setFlat(true);
    ciftok->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::CiftOk,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ciftok, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::CiftOk);
     //   menu->close();
    });

    QPushButton *ucgen= new QPushButton;
    ucgen->setFixedSize(e*2, b);
    ucgen->setIconSize(QSize(e*2,b));
    ucgen->setFlat(true);
    ucgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Ucgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ucgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Ucgen);
     //    menu->close();
    });

    QPushButton *dortgen= new QPushButton;
    dortgen->setFixedSize(e*2, b);
    dortgen->setIconSize(QSize(e*2,b));
    dortgen->setFlat(true);
    dortgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Dortgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(dortgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Dortgen);
    //    menu->close();
    });

    QPushButton *cember= new QPushButton;
    cember->setFixedSize(e*2, b);
    cember->setIconSize(QSize(e*2,b));
    cember->setFlat(true);
    cember->setIcon(imageEllipse(ditem->sekilStore(DiagramItem::DiagramType::Cember,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cember, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Cember);
     //  menu->close();
    });

    QPushButton *baklava= new QPushButton;
    baklava->setFixedSize(e*2, b);
    baklava->setIconSize(QSize(e*2,b));
    baklava->setFlat(true);
    baklava->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Baklava,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(baklava, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Baklava);
    //     menu->close();
    });

    QPushButton *yamuk= new QPushButton;
    yamuk->setFixedSize(e*2, b);
    yamuk->setIconSize(QSize(e*2,b));
    yamuk->setFlat(true);
    yamuk->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Yamuk,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(yamuk, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Yamuk);
     //     menu->close();
    });

    QPushButton *besgen= new QPushButton;
    besgen->setFixedSize(e*2, b);
    besgen->setIconSize(QSize(e*2,b));
    besgen->setFlat(true);
    besgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Besgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(besgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Besgen);
    //    menu->close();
     });

    QPushButton *altigen= new QPushButton;
    altigen->setFixedSize(e*2, b);
    altigen->setIconSize(QSize(e*2,b));
    altigen->setFlat(true);
    altigen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Altigen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(altigen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Altigen);

    //  menu->close();
    });

    QPushButton *sekizgen= new QPushButton;
    sekizgen->setFixedSize(e*2, b);
    sekizgen->setIconSize(QSize(e*2,b));
    sekizgen->setFlat(true);
    sekizgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Sekizgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(sekizgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Sekizgen);
   //       menu->close();
    });

    QPushButton *dikucgen= new QPushButton;
    dikucgen->setFixedSize(e*2, b);
    dikucgen->setIconSize(QSize(e*2,b));
    dikucgen->setFlat(true);
    dikucgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::DikUcgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(dikucgen, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::DikUcgen);
   //  menu->close();
    });

    QPushButton *guzelyazi= new QPushButton;
    guzelyazi->setFixedSize(e, b);
    guzelyazi->setIconSize(QSize(e,b));
    //guzelyazi->setFlat(true);
    guzelyazi->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::GuzelYazi,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(guzelyazi, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::GuzelYazi);
    // menu->close();
    });

    QPushButton *muzik= new QPushButton;
    muzik->setFixedSize(e, b);
    muzik->setIconSize(QSize(e,b));
    //muzik->setFlat(true);
    muzik->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Muzik,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(muzik, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Muzik);
   // menu->close();
    });

    QPushButton *cizgilisayfa= new QPushButton;
    cizgilisayfa->setFixedSize(e, b);
    cizgilisayfa->setIconSize(QSize(e,b));
   // cizgilisayfa->setFlat(true);
    cizgilisayfa->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::CizgiliSayfa,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cizgilisayfa, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::CizgiliSayfa);
        // menu->close();
    });
    QPushButton *resimEkle= new QPushButton;
    resimEkle->setFixedSize(e*2, b*1.5);
    resimEkle->setIconSize(QSize(e*2,b*1.5));
    resimEkle->setFlat(true);
    resimEkle->setIcon(QIcon(":icons/addimage.png"));
    connect(resimEkle, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::SekilMode,DiagramItem::DiagramType::Resim);

       //  menu->close();
    });

    QPushButton *sekilKalemRenkButton=new QPushButton();
    sekilKalemRenkButton->setFixedSize(e,b);
    sekilKalemRenkButton->setIconSize(QSize(e,b));
    QPushButton *sekilZeminRenkButton=new QPushButton();

    sekilZeminRenkButton->setFixedSize(e,b);
    sekilZeminRenkButton->setIconSize(QSize(e,b));
    connect(sekilZeminRenkButton, &QPushButton::clicked, [=]() {
        colorMenu("sekilZeminColor","dikey",en,boy,true)->exec(mapToGlobal(mapToParent(menu->pos())));

         //menu->close();
    });

    auto layout = new QGridLayout(menu);
   layout->setContentsMargins(5,3,5,1);
    //layout->setColumnMinimumWidth(0, 37);

     QFont ff( "Arial", 7, QFont::Normal);
    QGridLayout *arac = new QGridLayout;
    QLabel *pergell= new QLabel("Pergel");      pergell->setFont(ff);
    QLabel *gonyel=  new QLabel("Gönye");        gonyel->setFont(ff);
    QLabel *cetvell= new QLabel("Cetvel");    cetvell->setFont(ff);;
    QLabel *iletkil= new QLabel("İletki");      iletkil->setFont(ff);
    arac->addWidget(pergel,0,0,1,1,Qt::AlignHCenter);
    arac->addWidget(cetvel,0,1,1,1,Qt::AlignHCenter);
    arac->addWidget(gonye,0,2,1,1,Qt::AlignHCenter);
    arac->addWidget(iletki,0,3,1,1,Qt::AlignHCenter);
    arac->addWidget(pergell,1,0,1,1,Qt::AlignHCenter);
    arac->addWidget(cetvell,1,1,1,1,Qt::AlignHCenter);
    arac->addWidget(gonyel,1,2,1,1,Qt::AlignHCenter);
    arac->addWidget(iletkil,1,3,1,1,Qt::AlignHCenter);
    layout->addLayout(arac,0, 0,1,1,Qt::AlignHCenter);

    QGridLayout *layout2 = new QGridLayout;
    QHBoxLayout *b3 = new QHBoxLayout;
    QLabel *kupl= new QLabel("Küp");      kupl->setFont(ff);
    QLabel *silindirl=  new QLabel("Silindir");        silindirl->setFont(ff);
    QLabel *pramitl= new QLabel("Pramit");    pramitl->setFont(ff);;
    QLabel *kurel= new QLabel("Küre");      kurel->setFont(ff);

    layout2->addWidget(kup,0,0,1,1,Qt::AlignHCenter);
    layout2->addWidget(silindir,0,1,1,1,Qt::AlignHCenter);
    layout2->addWidget(pramit,0,2,1,1,Qt::AlignHCenter);
    layout2->addWidget(kure,0,3,1,1,Qt::AlignHCenter);

    layout2->addWidget(kupl,1,0,1,1,Qt::AlignHCenter);
    layout2->addWidget(silindirl,1,1,1,1,Qt::AlignHCenter);
    layout2->addWidget(pramitl,1,2,1,1,Qt::AlignHCenter);
    layout2->addWidget(kurel,1,3,1,1,Qt::AlignHCenter);
    layout->addLayout(layout2,0, 1,1,1,Qt::AlignHCenter);


   QGridLayout *line0 = new QGridLayout;
   QLabel *lb00= new QLabel("Çizgi");
   QLabel *lb01=  new QLabel("Ok");
   QLabel *lb02= new QLabel("Çift Ok");
   QLabel *lb03= new QLabel("Üçgen");
   lb00->setFont(ff);lb01->setFont(ff);lb02->setFont(ff);lb03->setFont(ff);
   line0->addWidget(cizgi,0,0,1,1,Qt::AlignHCenter);
   line0->addWidget(ok,0,1,1,1,Qt::AlignHCenter);
   line0->addWidget(ciftok,0,2,1,1,Qt::AlignHCenter);
   line0->addWidget(ucgen,0,3,1,1,Qt::AlignHCenter);

   line0->addWidget(lb00,1,0,1,1,Qt::AlignHCenter);
   line0->addWidget(lb01,1,1,1,1,Qt::AlignHCenter);
   line0->addWidget(lb02,1,2,1,1,Qt::AlignHCenter);
   line0->addWidget(lb03,1,3,1,1,Qt::AlignHCenter);
   //line0->setSpacing(en/3*2);
   layout->addLayout(line0, 0, 2,1,1,Qt::AlignHCenter);


   /***************************************************************/
   QGridLayout *line01 = new QGridLayout;
   QLabel *lb10= new QLabel("Dörtgen");
   QLabel *lb11=  new QLabel("Çember");
   QLabel *lb12= new QLabel("Baklava");
   QLabel *lb13= new QLabel("Yamuk");
  // QFont ff( "Arial", 5, QFont::Normal);
   lb10->setFont(ff);lb11->setFont(ff);lb12->setFont(ff);lb13->setFont(ff);
   line01->addWidget(dortgen,0,0,1,1,Qt::AlignHCenter);
   line01->addWidget(cember,0,1,1,1,Qt::AlignHCenter);
   line01->addWidget(baklava,0,2,1,1,Qt::AlignHCenter);
   line01->addWidget(yamuk,0,3,1,1,Qt::AlignHCenter);
   line01->addWidget(lb10,1,0,1,1,Qt::AlignHCenter);
   line01->addWidget(lb11,1,1,1,1,Qt::AlignHCenter);
   line01->addWidget(lb12,1,2,1,1,Qt::AlignHCenter);
   line01->addWidget(lb13,1,3,1,1,Qt::AlignHCenter);
   layout->addLayout(line01, 0, 3,1,1,Qt::AlignHCenter);

   /**************************************************************/
   QGridLayout *line02 = new QGridLayout;
   QLabel *lb20= new QLabel("Beşgen");
   QLabel *lb21=  new QLabel("Altıgen");
   QLabel *lb22= new QLabel("Sekizgen");
   QLabel *lb23= new QLabel("D.Üçgen");
   // QFont ff( "Arial", 5, QFont::Normal);
   lb20->setFont(ff);lb21->setFont(ff);lb22->setFont(ff);lb23->setFont(ff);
   line02->addWidget(besgen,0,0,1,1,Qt::AlignHCenter);
   line02->addWidget(altigen,0,1,1,1,Qt::AlignHCenter);
   line02->addWidget(sekizgen,0,2,1,1,Qt::AlignHCenter);
   line02->addWidget(dikucgen,0,3,1,1,Qt::AlignHCenter);

   line02->addWidget(lb20,1,0,1,1,Qt::AlignHCenter);
   line02->addWidget(lb21,1,1,1,1,Qt::AlignHCenter);
   line02->addWidget(lb22,1,2,1,1,Qt::AlignHCenter);
   line02->addWidget(lb23,1,3,1,1,Qt::AlignHCenter);

  layout->addLayout(line02, 0, 4,1,1,Qt::AlignHCenter);

  layout->addWidget(resimEkle, 0, 5,1,1,Qt::AlignHCenter);
  //colorWidget
  QGridLayout *renkloyout = new QGridLayout;

  QWidget *cw=colorWidget("sekilZeminColor","yatay",en*0.8,boy,false);
  cw->setFixedSize(en*9,boy*0.7);
  cw->setVisible(true);
  renkloyout->addWidget(cw, 0,0,1,1,Qt::AlignHCenter);
  QLabel *renk= new QLabel("Şekil Dolgu Rengi");      renk->setFont(ff);
  renkloyout->addWidget(renk, 1,0,1,1,Qt::AlignHCenter);
  layout->addLayout(renkloyout, 0,6,1,1,Qt::AlignHCenter);

  return menu;
}

QWidget *toolKalem::penTopMenu(int _boy)
{
 //  QSize *screenSize = qApp->screens()[0]->size();
    int ken=300;
    //en=screenSize->width();
    //boy=screenSize->height();
    int e=(_boy*0.8)/4*5;
    int b=(_boy*0.6)/4*4.5;

    QWidget *menu = new QWidget(this);
    kalemSizePopLabel= new QLabel();
        kalemSizePopLabel->setFixedSize(e*3, b);
    kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
    QFont ff( "Arial", 7, QFont::Normal);
    kalemSizePopLabel->setFont(ff);

   /* QSlider *penSize= new QSlider(Qt::Horizontal,menu);
    penSize->setMinimum(2);
    penSize->setMaximum(8);
    penSize->setSliderPosition(4);
    connect(penSize,SIGNAL(valueChanged(int)),this,SLOT(setPenSize(int)));
*/
    DiagramItem *ditem=new DiagramItem();

    QPushButton *penStyleSolidLine = new QPushButton();
    penStyleSolidLine->setFixedSize(e, b);
    penStyleSolidLine->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);*/
    penStyleSolidLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::SolidLine,ken,ken));
    connect(penStyleSolidLine, &QPushButton::clicked, [=]() {
        // setPenStyle(Qt::SolidLine);
         emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::SolidLine);
        current_toolTahta->scene->setSekilPenStyle(Qt::SolidLine);
        current_toolTahta->scene->setPenStyle(Qt::SolidLine);
        //  menu->close();
    });

    QPushButton *penStyleDashLine = new QPushButton;
    penStyleDashLine->setFixedSize(e, b);
    penStyleDashLine->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    penStyleDashLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DashLine,ken,ken));
    connect(penStyleDashLine, &QPushButton::clicked, [=]() {
        // setPenStyle(Qt::DashLine);
         emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::DashLine);
        //menu->close();
        current_toolTahta->scene->setPenStyle(Qt::DashLine);
        current_toolTahta->scene->setSekilPenStyle(Qt::DashLine);
    });

    QPushButton *penStyleDotLine = new QPushButton;
    penStyleDotLine->setFixedSize(e, b);
    penStyleDotLine->setIconSize(QSize(e,b));
   // penStyleDotLine->setFlat(true);
    penStyleDotLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DotLine,ken,ken));
    connect(penStyleDotLine, &QPushButton::clicked, [=]() {
        //setPenStyle(Qt::DotLine);
        emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::DotLine);
        //menu->close();
        current_toolTahta->scene->setPenStyle(Qt::DotLine);
        current_toolTahta-> scene->setSekilPenStyle(Qt::DotLine);
    });

    QPushButton *kalemSekilTanimlama= new QPushButton;
     kalemSekilTanimlama=butonSlot(kalemSekilTanimlama,"",":icons/smartpen.png",QColor(255,0,0,0),e,b,e,b);
    connect(kalemSekilTanimlama, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::SmartPen);
        // menu->close();
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
        current_toolTahta->scene->setSekilTanimlamaStatus(true);
    });


    QPushButton *kalemMenuButton=new QPushButton();
    /*kalemMenuButton->setFixedSize(e, b);
    kalemMenuButton->setIconSize(QSize(e,b));*/
    kalemMenuButton=butonSlot(kalemMenuButton,"",":icons/pen.svg",QColor(255,0,0,0),e,b,e,b);
    connect(kalemMenuButton, &QPushButton::clicked, [=]() {
        // menu->close();  qDebug()<<b;
       // current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
        current_toolTahta->scene->setSekilTanimlamaStatus(false);
        emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::NormalPen);
       // qDebug()<<"pen normal";
       // current_toolTahta->gv->hide();
       });

    QPushButton *fosforluKalemButton=new QPushButton();
    fosforluKalemButton=butonSlot(fosforluKalemButton,"",":icons/fosforlupen.png",QColor(255,0,0,0),e,b,e,b);
    connect(fosforluKalemButton, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::FosforluPen);
       // menu->close();
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawPenFosfor;
        current_toolTahta->scene->setSekilTanimlamaStatus(false);
        current_toolTahta->scene->setPenAlpha(50);
       });




    QPushButton *nokta2 = new QPushButton;
      nokta2=butonSlot(nokta2,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*0.2,b*0.2);
    connect(nokta2, &QPushButton::clicked, [=]() {
        //setPenSize(1);
        //emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize2);
        penSize=2; current_toolTahta->scene->setPenSize(penSize);
        kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));

        //menu->close();
    });

    QPushButton *nokta4 = new QPushButton;
     nokta4=butonSlot(nokta4,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*0.4,b*0.4);
    connect(nokta4, &QPushButton::clicked, [=]() {
       // setPenSize(2);
        //emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize4);
        penSize=4; current_toolTahta->scene->setPenSize(penSize);
        kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
       // menu->close();
    });

    QPushButton *nokta6 = new QPushButton;
     nokta6=butonSlot(nokta6,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*0.6,b*0.6);
    connect(nokta6, &QPushButton::clicked, [=]() {
        //setPenSize(3);
        //emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize6);
        penSize=6; current_toolTahta->scene->setPenSize(penSize);
        kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
         });

    QPushButton *nokta8 = new QPushButton;
      nokta8=butonSlot(nokta8,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*0.8,b*0.8);
    connect(nokta8, &QPushButton::clicked, [=]() {
        //setPenSize(4);
        //emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize8);
        penSize=8; current_toolTahta->scene->setPenSize(penSize);
        kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
       // menu->close();
    });

    QPushButton *nokta10 = new QPushButton;
     nokta10=butonSlot(nokta10,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*1,b);
    connect(nokta10, &QPushButton::clicked, [=]() {
      //  setPenSize(5);
        //emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize10);
        penSize=10; current_toolTahta->scene->setPenSize(penSize);
        kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));

        //menu->close();
   });

    QPushButton *nokta12 = new QPushButton;
      nokta12=butonSlot(nokta12,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*1.2,b*1.2);
    connect(nokta12, &QPushButton::clicked, [=]() {
        //setPenSize(6);
       // emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize12);
        penSize=12; current_toolTahta->scene->setPenSize(penSize);
        kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));

       // menu->close();
    });

    QPushButton *nokta14 = new QPushButton;
     nokta14=butonSlot(nokta14,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*1.4,b*1.4);
    connect(nokta14, &QPushButton::clicked, [=]() {
       // setPenSize(7);
     //emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize14);
        penSize=14; current_toolTahta->scene->setPenSize(penSize);
        kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));

   // menu->close();
    });


    auto layout = new QGridLayout(menu);
  layout->setContentsMargins(5, 2, 5,1);
   // layout->setColumnMinimumWidth(0, 37);


    layout->addWidget(kalemSizePopLabel, 0,0,2,1);
 //   layout->addWidget(geriAlButton,1,2,1,1);
//    layout->addWidget(new QLabel("<font size=1>Geri Al</font>"),2,2,1,1,Qt::AlignHCenter);
    QLabel *kl=new QLabel("Kalem");
    QLabel *fkl=new QLabel("Fosforlu Kalem");
    QLabel *akl=new QLabel("Akıllı Kalem");
    kl->setFont(ff);    fkl->setFont(ff);    akl->setFont(ff);
    layout->addWidget(kalemMenuButton,0,1,1,1,Qt::AlignHCenter);
    layout->addWidget(fosforluKalemButton,0,2,1,1,Qt::AlignHCenter);
    layout->addWidget(kalemSekilTanimlama,0,3,1,1,Qt::AlignHCenter);
    layout->addWidget(kl,1,1,1,1,Qt::AlignHCenter);
    layout->addWidget(fkl,1,2,1,1,Qt::AlignHCenter);
    layout->addWidget(akl,1,3,1,1,Qt::AlignHCenter);

   // layout->addWidget(penSize,5,1,1,3,Qt::AlignHCenter);

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(nokta2);
    layout1->addWidget(nokta4);
    layout1->addWidget(nokta6);
    layout1->addWidget(nokta8);
    layout1->addWidget(nokta10);
    layout1->addWidget(nokta12);
    layout1->addWidget(nokta14);
    layout->addLayout(layout1, 0,4,2,1,Qt::AlignHCenter);

    //QGridLayout *renkloyout = new QGridLayout;
    //renkloyout->setContentsMargins(0,0,0,0);
    QWidget *cw=colorWidget("penColor","yatay",en*0.8,boy*0.8,false);
    cw->setFixedSize(en*9,boy);
    cw->setVisible(true);
   // renkloyout->addWidget(cw, 0,0,1,1,Qt::AlignHCenter);
   // QLabel *renk= new QLabel("Kalem Rengi");      renk->setFont(ff);
   // renkloyout->addWidget(renk, 1,0,1,1,Qt::AlignHCenter);
   // layout->addWidget(cw, 0,5,2,1,Qt::AlignCenter);
    layout->addWidget(cw, 0,5,2,1,Qt::AlignHCenter);
   // layout->addWidget(renk, 1,5,1,1,Qt::AlignHCenter);


    QLabel *fd=new QLabel("Düz");
    QLabel *fk=new QLabel("Kesik");
    QLabel *fn=new QLabel("Noktalı");
    fd->setFont(ff);    fk->setFont(ff);    fn->setFont(ff);
    layout->addWidget(penStyleSolidLine, 0, 8,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDashLine, 0, 9,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDotLine, 0, 10,1,1,Qt::AlignHCenter);
    layout->addWidget(fd,1,8,1,1,Qt::AlignHCenter);
    layout->addWidget(fk,1,9,1,1,Qt::AlignHCenter);
    layout->addWidget(fn,1,10,1,1,Qt::AlignHCenter);
return menu;
}

QMenu *toolKalem::penMenu()
{
    int ken=300;
       int e=(en*0.8)/4*9;
       int b=(boy*0.6)/4*5;

       QMenu *menu = new QMenu(this);
         menu->installEventFilter(this);
       kalemSizePopLabel= new QLabel();
       kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
       QFont ff( "Arial", 8, QFont::Normal);
       kalemSizePopLabel->setFont(ff);

      /* QSlider *penSize= new QSlider(Qt::Horizontal,menu);
       penSize->setMinimum(2);
       penSize->setMaximum(8);
       penSize->setSliderPosition(4);
       connect(penSize,SIGNAL(valueChanged(int)),this,SLOT(setPenSize(int)));
   */
       DiagramItem *ditem=new DiagramItem();

       QPushButton *penStyleSolidLine = new QPushButton;
       penStyleSolidLine->setFixedSize(e, b);
       penStyleSolidLine->setIconSize(QSize(e,b));
       //penStyleSolidLine->setFlat(true);*/
       penStyleSolidLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::SolidLine,ken,ken));
       connect(penStyleSolidLine, &QPushButton::clicked, [=]() {
          // setPenStyle(Qt::SolidLine);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::SolidLine);
           menu->close();
       });

       QPushButton *penStyleDashLine = new QPushButton;
       penStyleDashLine->setFixedSize(e, b);
       penStyleDashLine->setIconSize(QSize(e,b));
       //penStyleDashLine->setFlat(true);
       penStyleDashLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DashLine,ken,ken));
       connect(penStyleDashLine, &QPushButton::clicked, [=]() {
          // setPenStyle(Qt::DashLine);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::DashLine);
           menu->close();
       });

       QPushButton *penStyleDotLine = new QPushButton;
       penStyleDotLine->setFixedSize(e, b);
       penStyleDotLine->setIconSize(QSize(e,b));
      // penStyleDotLine->setFlat(true);
       penStyleDotLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DotLine,ken,ken));
       connect(penStyleDotLine, &QPushButton::clicked, [=]() {
           //setPenStyle(Qt::DotLine);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::DotLine);
           menu->close();
       });

       QPushButton *kalemSekilTanimlama= new QPushButton;
        kalemSekilTanimlama=butonSlot(kalemSekilTanimlama,"",":icons/smartpen.png",QColor(255,0,0,0),e,b,e,b);
       connect(kalemSekilTanimlama, &QPushButton::clicked, [=]()
       {
             emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::SmartPen);
               menu->close();
          /* scene->setPopMenuStatus(false);
           menu->close();
           kalemButtonClick();
           scene->setSekilTanimlamaStatus(true);
           buttonColorClear();
           palette->setColor(QPalette::Button, QColor(212,0,0,255));
          // kalemSekilTanimlama->setPalette(*palette);
           //kalemSekilTanimlama->setAutoFillBackground(true);
           kalemButton->setPalette(*palette);
           kalemButton->setAutoFillBackground(true);
           kalemButton->setIcon(QIcon(":icons/smartpen.png"));
   //kalemButton->setIconSize(QSize(20,20));
            currentScreenModeSlot();
            */
       });


       QPushButton *kalemMenuButton=new QPushButton();
       /*kalemMenuButton->setFixedSize(e, b);
       kalemMenuButton->setIconSize(QSize(e,b));*/
       kalemMenuButton=butonSlot(kalemMenuButton,"",":icons/pen.png",QColor(255,0,0,0),e,b,e,b);
       connect(kalemMenuButton, &QPushButton::clicked, [=]() {

           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::NormalPen);
           menu->close();

           /*scene->setPopMenuStatus(false);
           menu->close();
           scene->setSekilTanimlamaStatus(false);
   */
       });

       QPushButton *fosforluKalemButton=new QPushButton();
       fosforluKalemButton=butonSlot(fosforluKalemButton,"",":icons/fosforlupen.png",QColor(255,0,0,0),e,b,e,b);
       connect(fosforluKalemButton, &QPushButton::clicked, [=]() {
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::FosforluPen);
           menu->close();

           /*   scene->setPopMenuStatus(false);
              menu->close();
              //kalemButtonClick();
              scene->setSekilTanimlamaStatus(false);
      */
          });




       QPushButton *nokta2 = new QPushButton;
         nokta2=butonSlot(nokta2,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*0.2,b*0.2);
       connect(nokta2, &QPushButton::clicked, [=]() {
           //setPenSize(1);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize2);
           kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
           menu->close();
       });

       QPushButton *nokta4 = new QPushButton;
        nokta4=butonSlot(nokta4,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*0.4,b*0.4);
       connect(nokta4, &QPushButton::clicked, [=]() {
          // setPenSize(2);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize4);
           kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
           menu->close();
       });

       QPushButton *nokta6 = new QPushButton;
        nokta6=butonSlot(nokta6,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*0.6,b*0.6);
       connect(nokta6, &QPushButton::clicked, [=]() {
           //setPenSize(3);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize6);
           kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
           menu->close();
       });

       QPushButton *nokta8 = new QPushButton;
         nokta8=butonSlot(nokta8,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*0.8,b*0.8);
       connect(nokta8, &QPushButton::clicked, [=]() {
           //setPenSize(4);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize8);
           kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
           menu->close();
       });

       QPushButton *nokta10 = new QPushButton;
        nokta10=butonSlot(nokta10,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*1,b);
       connect(nokta10, &QPushButton::clicked, [=]() {
         //  setPenSize(5);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize10);
           kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
           menu->close();
      });

       QPushButton *nokta12 = new QPushButton;
         nokta12=butonSlot(nokta12,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*1.2,b*1.2);
       connect(nokta12, &QPushButton::clicked, [=]() {
           //setPenSize(6);
           emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize12);
           kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
           menu->close();
       });

       QPushButton *nokta14 = new QPushButton;
        nokta14=butonSlot(nokta14,"",":icons/nokta.png",QColor(0,0,0,0),e/2,b,e*1.4,b*1.4);
       connect(nokta14, &QPushButton::clicked, [=]() {
          // setPenSize(7);
        emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PenSize14);
        kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(penSize));
       menu->close();
       });

       auto widget = new QWidget;
       auto layout = new QGridLayout(widget);
      // layout->setContentsMargins(0, 0, 0, 3);
      // layout->setColumnMinimumWidth(0, 37);


       layout->addWidget(kalemSizePopLabel, 0, 1,1,3);
    //   layout->addWidget(geriAlButton,1,2,1,1);
   //    layout->addWidget(new QLabel("<font size=1>Geri Al</font>"),2,2,1,1,Qt::AlignHCenter);

       layout->addWidget(kalemMenuButton,3,1,1,1,Qt::AlignHCenter);
       layout->addWidget(fosforluKalemButton,3,2,1,1,Qt::AlignHCenter);
       layout->addWidget(kalemSekilTanimlama,3,3,1,2,Qt::AlignHCenter);
       layout->addWidget(new QLabel("<font size=1>Kalem</font>"),4,1,1,1,Qt::AlignHCenter);
       layout->addWidget(new QLabel("<font size=1>Fosforlu Kalem</font>"),4,2,1,1,Qt::AlignHCenter);
       layout->addWidget(new QLabel("<font size=1>Akıllı Kalem</font>"),4,3,1,1,Qt::AlignHCenter);

      // layout->addWidget(penSize,5,1,1,3,Qt::AlignHCenter);

       QHBoxLayout *layout1 = new QHBoxLayout;
            layout1->addWidget(nokta2);
            layout1->addWidget(nokta4);
            layout1->addWidget(nokta6);
            layout1->addWidget(nokta8);
            layout1->addWidget(nokta10);
            layout1->addWidget(nokta12);
            layout1->addWidget(nokta14);


       layout->addLayout(layout1, 6, 1,1,3,Qt::AlignHCenter);

       layout->addWidget(penStyleSolidLine, 7, 1,1,1,Qt::AlignHCenter);
       layout->addWidget(penStyleDashLine, 7, 2,1,1,Qt::AlignHCenter);
       layout->addWidget(penStyleDotLine, 7, 3,1,1,Qt::AlignHCenter);
       layout->addWidget(new QLabel("<font size=1>Düz</font>"),8,1,1,1,Qt::AlignHCenter);
       layout->addWidget(new QLabel("<font size=1>Kesik</font>"),8,2,1,1,Qt::AlignHCenter);
       layout->addWidget(new QLabel("<font size=1>Noktalı</font>"),8,3,1,1,Qt::AlignHCenter);


     //  layout->setColumnStretch(6, 255);

       // add a widget action to the context menu
       auto wa = new QWidgetAction(this);
     //  wa->setIcon(QIcon(":/icon1"));
       wa->setDefaultWidget(widget);
       menu->addAction(wa);
      /* penSize->setStyleSheet(".QSlider::groove:Horizontal {"
                                      "background: rgba(0, 0, 0, 200);"
                                      "width:"+QString::number(e*4)+"px;"
                                       "height: "+QString::number(b/2)+"px;"
                                      "}"
                                      ".QSlider::handle:Horizontal {"
                                      "background: rgba(242, 242, 242, 95);"
                                      "border: 2px solid rgb(0,0,0);"
                                      "background: rgba(0, 0, 0, 255);"
                                      "width: "+QString::number(e/2)+"px;"
                                      "height: "+QString::number(b)+"px;"
                                       "margin:-"+QString::number(e/8*3)+"px   0   -"+QString::number(b/8*3)+"px   0;"
                                      "}");
   */
      // penSize->setFixedSize(QSize(e*4,b));
       //menu->setStyleSheet("QMenu { width: 290 px; height: 250 px; }");
   return menu;
}

QWidget *toolKalem::zeminTopMenu(int _boy)
{
    int e=(_boy*0.8)/4*5;
    int b=(_boy*0.6)/4*4.3;

    QWidget *menu = new QWidget(this);
      menu->installEventFilter(this);
    QLabel  *zeminLabel= new QLabel();
    zeminLabel->setText("Arkaplan\nSeçenekleri");
    QFont ffl( "Arial", 7, QFont::Normal);
    zeminLabel->setFont(ffl);

    auto layout = new QGridLayout(menu);
    layout->setContentsMargins(5, 3,5,1);
    //layout->setColumnMinimumWidth(0, 37);


    /***********************noktalı izometrik kareli çizgili***************/


    QPushButton *noktaliKagit = new QPushButton;
    noktaliKagit->setFixedSize(e, b);
    noktaliKagit->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);
    noktaliKagit->setIcon(QIcon(":icons/dotpage.svg"));
    connect(noktaliKagit, &QPushButton::clicked, [=]() {
   emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::NoktaliKagit);

       // menu->close();
    });

    QPushButton *izometrikKagit = new QPushButton;
    izometrikKagit->setIcon(QIcon(":icons/izometrikpage.svg"));
    izometrikKagit->setFixedSize(e, b);
    izometrikKagit->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    connect(izometrikKagit, &QPushButton::clicked, [=]() {
    emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::IzometrikKagit);
     // menu->close();

    });

    QPushButton *kareliKagit = new QPushButton;
    kareliKagit->setIcon(QIcon(":icons/karepage.svg"));
    kareliKagit->setFixedSize(e, b);
    kareliKagit->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(kareliKagit, &QPushButton::clicked, [=]() {
    emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::KareliKagit);

       // menu->close();

    });

    QPushButton *cizgiliKagit = new QPushButton;
    cizgiliKagit->setIcon(QIcon(":icons/linepage.svg"));
    cizgiliKagit->setFixedSize(e, b);
    cizgiliKagit->setIconSize(QSize(e,b));
    //penStyleDotLine->setFlat(true);
    connect(cizgiliKagit, &QPushButton::clicked, [=]() {
      emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::CizgiliKagit);
        //   menu->close();

    });
    /***********************ndogru nnkoordinat  hnkoordinat nkoordinat***************/


    QPushButton *ndogru = new QPushButton;
    ndogru->setFixedSize(e, b);
    ndogru->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);
    ndogru->setIcon(QIcon(":icons/ndogru.png"));
    connect(ndogru, &QPushButton::clicked, [=]() {
      emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::NDogru);
     // menu->close();
    });

    QPushButton *nnkoordinat = new QPushButton;
    nnkoordinat->setIcon(QIcon(":icons/nnkoordinat.png"));
    nnkoordinat->setFixedSize(e, b);
    nnkoordinat->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    connect(nnkoordinat, &QPushButton::clicked, [=]() {
      emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::NNKoordinat);
    //  menu->close();

    });

    QPushButton *hnkoordinat = new QPushButton;
    hnkoordinat->setIcon(QIcon(":icons/hnkoordinat.png"));
    hnkoordinat->setFixedSize(e, b);
    hnkoordinat->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(hnkoordinat, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::HNKoordinat);
    //menu->close();

    });

    QPushButton *nkoordinat = new QPushButton;
    nkoordinat->setIcon(QIcon(":icons/nkoordinat.png"));
    nkoordinat->setFixedSize(e, b);
    nkoordinat->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(nkoordinat, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::NKoordinat);
     //menu->close();

    });

    /*****************************************************/
    QPushButton *zeminSeffafButton=new QPushButton();
    zeminSeffafButton=butonSlot(zeminSeffafButton,"",":icons/transparanboard.png",QColor(255,0,0,0),e,b,e,b);
    zeminSeffafButton->setFlat(true);
    connect(zeminSeffafButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
    });

    QPushButton *zeminSiyahButton=new QPushButton();
    zeminSiyahButton=butonSlot(zeminSiyahButton,"",":icons/blackboard.png",QColor(255,0,0,0),e,b,e,b);
    zeminSiyahButton->setFlat(true);
    connect(zeminSiyahButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::BlackPage);

    });
    QPushButton *zeminBeyazButton=new QPushButton();
    zeminBeyazButton=butonSlot(zeminBeyazButton,"",":icons/whiteboard.png",QColor(255,0,0,0),e,b,e,b);
    zeminBeyazButton->setFlat(true);
    connect(zeminBeyazButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::WhitePage);

    });
    QPushButton *zeminCustomColorButton=new QPushButton();
     zeminCustomColorButton=butonSlot(zeminCustomColorButton,"",":icons/zeminCustomColor.png",QColor(255,0,0,0),e,b,e,b);
     zeminCustomColorButton->setFlat(true);
     zeminCustomColorButton=butonSlot(zeminCustomColorButton,"",":icons/zeminrenk.png",QColor(255,0,0,0),e,b,e,b);
     zeminCustomColorButton->setFlat(true);
     QMenu *zcc=colorMenu("zeminColor","dikey",en,boy,true);
      zeminCustomColorButton->setMenu(zcc);

     connect(zeminCustomColorButton, &QPushButton::clicked, [=]()
    {
       // emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::CustomColorPage);

    });
    QPushButton *zeminCizgiliSayfaButton = new QPushButton;
    zeminCizgiliSayfaButton->setIcon(QIcon(":icons/icons/cizgilisayfa.png"));
    zeminCizgiliSayfaButton=butonSlot(zeminCizgiliSayfaButton,"",":icons/cizgilisayfa.png",QColor(255,0,0,0),e,b,e,b);
    zeminCizgiliSayfaButton->setFlat(true);
    connect(zeminCizgiliSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::CizgiliPage);
    });

    QPushButton *zeminKareliSayfaButton = new QPushButton;
    zeminKareliSayfaButton=butonSlot(zeminKareliSayfaButton,"",":icons/karelisayfa.png",QColor(255,0,0,0),e,b,e,b);
    zeminKareliSayfaButton->setFlat(true);
    connect(zeminKareliSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::KareliPage);
    });

    QPushButton *zeminMuzikSayfaButton=new QPushButton();
    zeminMuzikSayfaButton=butonSlot(zeminMuzikSayfaButton,"",":icons/muziksayfa.png",QColor(255,0,0,0),e,b,e,b);
    zeminMuzikSayfaButton->setFlat(true);
    connect(zeminMuzikSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::MuzikPage);
    });


    QPushButton *zeminGuzelYaziSayfaButton=new QPushButton();
    zeminGuzelYaziSayfaButton=butonSlot(zeminGuzelYaziSayfaButton,"",":icons/guzelyazisayfa.png",QColor(255,0,0,0),e,b,e,b);
    zeminGuzelYaziSayfaButton->setFlat(true);
    connect(zeminGuzelYaziSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::GuzelYaziPage);
    });


    QPushButton *zeminDesenEkleSayfaButton=new QPushButton();
    zeminDesenEkleSayfaButton=butonSlot(zeminDesenEkleSayfaButton,"",":icons/resimekle.png",QColor(255,0,0,0),e,b,e,b);
    zeminDesenEkleSayfaButton->setFlat(true);
    connect(zeminDesenEkleSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::CustomImagePage);

    });

   QPushButton *zeminTemizleSayfaButton = new QPushButton;
   zeminTemizleSayfaButton=butonSlot(zeminTemizleSayfaButton,"",":icons/zemintemizle.png",QColor(255,0,0,0),e,b,e,b);
   zeminTemizleSayfaButton->setFlat(true);
   connect(zeminTemizleSayfaButton, &QPushButton::clicked, [=]()
    {
       emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);

    });

    QPushButton *gridRenkButton = new QPushButton;
    gridRenkButton=butonSlot(gridRenkButton,"",":icons/gridrenk.png",QColor(255,0,0,0),e,b,e,b);
    gridRenkButton->setFlat(true);
    QMenu *gcm=colorMenu("zeminGridColor","dikey",en,boy,true);
    gridRenkButton->setMenu(gcm);
   connect(gridRenkButton, &QPushButton::clicked, [=]()
    {
    });

    QPushButton *zeminRenkButton = new QPushButton;

     zeminRenkButton=butonSlot(zeminRenkButton,"",":icons/zeminrenk.png",QColor(255,0,0,0),e,b,e,b);
     zeminRenkButton->setFlat(true);
     QMenu *zcm=colorMenu("sekilZeminColor","dikey",en,boy,true);
      zeminRenkButton->setMenu(zcm);
     connect(zeminRenkButton, &QPushButton::clicked, [=]()
     {
     });

   layout->addWidget(zeminLabel, 0, 0,2,1);


   layout->addWidget(noktaliKagit,0,5,1,1,Qt::AlignHCenter);
   layout->addWidget(izometrikKagit,0,6,1,1,Qt::AlignHCenter);
   layout->addWidget(kareliKagit,0,7,1,1,Qt::AlignHCenter);
   layout->addWidget(cizgiliKagit,0,8,1,1,Qt::AlignHCenter);

   QLabel *noktali=new QLabel("Noktalı");   noktali->setFont(ffl);
   QLabel *izometrik=new QLabel("İzometrik"); izometrik->setFont(ffl);
   QLabel *kareli=new QLabel("Kareli");    kareli->setFont(ffl);
   QLabel *cizgili=new QLabel("Çizgili");   cizgili->setFont(ffl);
   layout->addWidget(noktali,1,5,1,1,Qt::AlignHCenter);
   layout->addWidget(izometrik,1,6,1,1,Qt::AlignHCenter);
   layout->addWidget(kareli,1,7,1,1,Qt::AlignHCenter);
   layout->addWidget(cizgili,1,8,1,1,Qt::AlignHCenter);

   layout->addWidget(nkoordinat,0,9,1,1,Qt::AlignHCenter);
   layout->addWidget(hnkoordinat,0,10,1,1,Qt::AlignHCenter);
   layout->addWidget(ndogru,0,11,1,1,Qt::AlignHCenter);
   layout->addWidget(nnkoordinat,0,12,1,1,Qt::AlignHCenter);

   QLabel *skoordinatl=new QLabel("S.Koordinat");   skoordinatl->setFont(ffl);
   QLabel *hnkoordinatl=new QLabel("Y. Koordinat"); hnkoordinatl->setFont(ffl);
   QLabel *ndogrul=new QLabel("Sayı Doğrusu");      ndogrul->setFont(ffl);
   QLabel *nnkoordinatl=new QLabel("Koordinat");    nnkoordinatl->setFont(ffl);

   layout->addWidget(skoordinatl,1,9,1,1,Qt::AlignHCenter);
   layout->addWidget(hnkoordinatl,1,10,1,1,Qt::AlignHCenter);
   layout->addWidget(ndogrul,1,11,1,1,Qt::AlignHCenter);
   layout->addWidget(nnkoordinatl,1,12,1,1,Qt::AlignHCenter);

    layout->addWidget(zeminSeffafButton,0,15,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminSiyahButton,0,16,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminBeyazButton,0,17,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminCustomColorButton,0,18,1,1,Qt::AlignHCenter);

    QLabel *seffaftahta=new QLabel("Şeffaf Tahta");   seffaftahta->setFont(ffl);
    QLabel *siyahtahta=new QLabel("Siyah Tahta"); siyahtahta->setFont(ffl);
    QLabel *beyaztahta=new QLabel("Beyaz Tahta");      beyaztahta->setFont(ffl);
    QLabel *customtahta=new QLabel("S. Renk Tahta");    customtahta->setFont(ffl);

    layout->addWidget(seffaftahta,1,15,1,1,Qt::AlignHCenter);
    layout->addWidget(siyahtahta,1,16,1,1,Qt::AlignHCenter);
    layout->addWidget(beyaztahta,1,17,1,1,Qt::AlignHCenter);
    layout->addWidget(customtahta,1,18,1,1,Qt::AlignHCenter);


    layout->addWidget(zeminCizgiliSayfaButton,0,20,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminKareliSayfaButton,0,21,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminMuzikSayfaButton,0,22,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminGuzelYaziSayfaButton,0,23,1,1,Qt::AlignHCenter);

    QLabel *cizgilitahta=new QLabel("Çizgili Tahta");   cizgilitahta->setFont(ffl);
    QLabel *karelitahta=new QLabel("Kareli Tahta"); karelitahta->setFont(ffl);
    QLabel *muziktahta=new QLabel("Müzik Tahta");      muziktahta->setFont(ffl);
    QLabel *gyazitahta=new QLabel("G.Yazı Tahta");    gyazitahta->setFont(ffl);

    layout->addWidget(cizgilitahta,1,20,1,1,Qt::AlignHCenter);
    layout->addWidget(karelitahta,1,21,1,1,Qt::AlignHCenter);
    layout->addWidget(muziktahta,1,22,1,1,Qt::AlignHCenter);
    layout->addWidget(gyazitahta,1,23,1,1,Qt::AlignHCenter);


    layout->addWidget(zeminTemizleSayfaButton,0,25,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminDesenEkleSayfaButton,0,26,1,1,Qt::AlignHCenter);
    layout->addWidget(gridRenkButton,0,27,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminRenkButton,0,28,1,1,Qt::AlignHCenter);
    QLabel *temizletahta=new QLabel("Tahta Temizle");   temizletahta->setFont(ffl);
    QLabel *desenekletahta=new QLabel("Desen Ekle");    desenekletahta->setFont(ffl);
    QLabel *cizgirengitahta=new QLabel("Çizgi Rengi");  cizgirengitahta->setFont(ffl);
    QLabel *zeminrengitahta=new QLabel("Zemin Rengi");  zeminrengitahta->setFont(ffl);

    layout->addWidget(temizletahta,1,25,1,1,Qt::AlignHCenter);
    layout->addWidget(desenekletahta,1,26,1,1,Qt::AlignHCenter);
    layout->addWidget(cizgirengitahta,1,27,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminrengitahta,1,28,1,1,Qt::AlignHCenter);

    QWidget *cm=cizgiBoyutMenu();
    cm->setVisible(true);
    //cm->setFixedSize(220,cm->height());
    layout->addWidget(cm,0,30,2,1,Qt::AlignHCenter);
   return menu;
}

QMenu *toolKalem::zeminMenu()
{  //int e=en;
   // int b=boy;
    int e=(en*0.8)/4*6;
    int b=(boy*0.6)/4*5;

    QMenu *menu = new QMenu(this);
      menu->installEventFilter(this);
    QLabel  *zeminLabel= new QLabel();
    zeminLabel->setText("Arkaplan Seçenekleri");
    QFont ff( "Arial", 8, QFont::Normal);
    zeminLabel->setFont(ff);

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(0, 0, 0, 3);
    //layout->setColumnMinimumWidth(0, 37);
    /***********************noktalı izometrik kareli çizgili***************/
    QPushButton *noktaliKagit = new QPushButton;
    noktaliKagit->setFixedSize(e, b);
    noktaliKagit->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);
    noktaliKagit->setIcon(QIcon(":icons/noktalikagit.png"));
    connect(noktaliKagit, &QPushButton::clicked, [=]() {
   emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::NoktaliKagit);

        menu->close();
    });

    QPushButton *izometrikKagit = new QPushButton;
    izometrikKagit->setIcon(QIcon(":icons/izometrikkagit.png"));
    izometrikKagit->setFixedSize(e, b);
    izometrikKagit->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    connect(izometrikKagit, &QPushButton::clicked, [=]() {
    emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::IzometrikKagit);
      menu->close();

    });

    QPushButton *kareliKagit = new QPushButton;
    kareliKagit->setIcon(QIcon(":icons/karelikagit.png"));
    kareliKagit->setFixedSize(e, b);
    kareliKagit->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(kareliKagit, &QPushButton::clicked, [=]() {
    emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::KareliKagit);

        menu->close();

    });

    QPushButton *cizgiliKagit = new QPushButton;
    cizgiliKagit->setIcon(QIcon(":icons/gridyatay.png"));
    cizgiliKagit->setFixedSize(e, b);
    cizgiliKagit->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(cizgiliKagit, &QPushButton::clicked, [=]() {
      emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::CizgiliKagit);
           menu->close();

    });
   /* QHBoxLayout *layout0 = new QHBoxLayout;
    layout0->addWidget(noktaliKagit);
    layout0->addWidget(izometrikKagit);
    layout0->addWidget(kareliKagit);
    layout0->addWidget(cizgiliKagit);
    layout0->setSpacing(en/3*2);
    QHBoxLayout *layout00 = new QHBoxLayout;
    layout00->addWidget(new QLabel("<font size=1>Noktalı  </font>"));
    layout00->addWidget(new QLabel("<font size=1>İzometrik</font>"));
    layout00->addWidget(new QLabel("<font size=1>Kareli   </font>"));
    layout00->addWidget(new QLabel("<font size=1>Çizgili  </font>"));
    layout00->setSpacing(en*1.5);


    /***********************ndogru nnkoordinat  hnkoordinat nkoordinat***************/


    QPushButton *ndogru = new QPushButton;
    ndogru->setFixedSize(e, b);
    ndogru->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);
    ndogru->setIcon(QIcon(":icons/ndogru.png"));
    connect(ndogru, &QPushButton::clicked, [=]() {
      emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::NDogru);
      menu->close();
    });

    QPushButton *nnkoordinat = new QPushButton;
    nnkoordinat->setIcon(QIcon(":icons/nnkoordinat.png"));
    nnkoordinat->setFixedSize(e, b);
    nnkoordinat->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    connect(nnkoordinat, &QPushButton::clicked, [=]() {
      emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::NNKoordinat);
      menu->close();

    });

    QPushButton *hnkoordinat = new QPushButton;
    hnkoordinat->setIcon(QIcon(":icons/hnkoordinat.png"));
    hnkoordinat->setFixedSize(e, b);
    hnkoordinat->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(hnkoordinat, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::HNKoordinat);
    menu->close();

    });

    QPushButton *nkoordinat = new QPushButton;
    nkoordinat->setIcon(QIcon(":icons/nkoordinat.png"));
    nkoordinat->setFixedSize(e, b);
    nkoordinat->setIconSize(QSize(e,b));
    // penStyleDotLine->setFlat(true);
    connect(nkoordinat, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::NKoordinat);
     menu->close();

    });
   /* QHBoxLayout *layout3 = new QHBoxLayout;
    layout3->addWidget(nkoordinat);
    layout3->addWidget(hnkoordinat);
    layout3->addWidget(ndogru);
    layout3->addWidget(nnkoordinat);
    layout3->setSpacing(en/3*2);
    QHBoxLayout *layout33 = new QHBoxLayout;
    layout33->addWidget(new QLabel("<font size=1>S.Koordinat</font>"));
    layout33->addWidget(new QLabel("<font size=1>Y. Koordinat</font>"));
    layout33->addWidget(new QLabel("<font size=1>Sayı Doğrusu</font>"));
    layout33->addWidget(new QLabel("<font size=1>Koordinat</font>"));
    layout33->setSpacing(en*1);


    /*****************************************************/
    QPushButton *zeminSeffafButton=new QPushButton();
    zeminSeffafButton=butonSlot(zeminSeffafButton,"",":icons/transparanboard.png",QColor(255,0,0,0),e,b,e,b);
    zeminSeffafButton->setFlat(true);
    connect(zeminSeffafButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
    });
    QPushButton *zeminSiyahButton=new QPushButton();
    zeminSiyahButton=butonSlot(zeminSiyahButton,"",":icons/blackboard.png",QColor(255,0,0,0),e,b,e,b);
    zeminSiyahButton->setFlat(true);
    connect(zeminSiyahButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::BlackPage);

    });
    QPushButton *zeminBeyazButton=new QPushButton();
    zeminBeyazButton=butonSlot(zeminBeyazButton,"",":icons/whiteboard.png",QColor(255,0,0,0),e,b,e,b);
    zeminBeyazButton->setFlat(true);
    connect(zeminBeyazButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::WhitePage);

    });
    QPushButton *zeminCustomColorButton=new QPushButton();
     zeminCustomColorButton=butonSlot(zeminCustomColorButton,"",":icons/zeminCustomColor.png",QColor(255,0,0,0),e,b,e,b);
     zeminCustomColorButton->setFlat(true);
     connect(zeminCustomColorButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::CustomColorPage);

    });
    QPushButton *zeminCizgiliSayfaButton = new QPushButton;
    zeminCizgiliSayfaButton->setIcon(QIcon(":icons/icons/cizgilisayfa.png"));
    zeminCizgiliSayfaButton=butonSlot(zeminCizgiliSayfaButton,"",":icons/cizgilisayfa.png",QColor(255,0,0,0),e,b,e,b);
    zeminCizgiliSayfaButton->setFlat(true);
    connect(zeminCizgiliSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::CizgiliPage);
    });

    QPushButton *zeminKareliSayfaButton = new QPushButton;
    zeminKareliSayfaButton=butonSlot(zeminKareliSayfaButton,"",":icons/karelisayfa.png",QColor(255,0,0,0),e,b,e,b);
    zeminKareliSayfaButton->setFlat(true);
    connect(zeminKareliSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::KareliPage);
    });

    QPushButton *zeminMuzikSayfaButton=new QPushButton();
    zeminMuzikSayfaButton=butonSlot(zeminMuzikSayfaButton,"",":icons/muziksayfa.png",QColor(255,0,0,0),e,b,e,b);
    zeminMuzikSayfaButton->setFlat(true);
    connect(zeminMuzikSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::MuzikPage);
    });


    QPushButton *zeminGuzelYaziSayfaButton=new QPushButton();
    zeminGuzelYaziSayfaButton=butonSlot(zeminGuzelYaziSayfaButton,"",":icons/guzelyazisayfa.png",QColor(255,0,0,0),e,b,e,b);
    zeminGuzelYaziSayfaButton->setFlat(true);
    connect(zeminGuzelYaziSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::GuzelYaziPage);
    });


    QPushButton *zeminDesenEkleSayfaButton=new QPushButton();
    zeminDesenEkleSayfaButton=butonSlot(zeminDesenEkleSayfaButton,"",":icons/resimekle.png",QColor(255,0,0,0),e,b,e,b);
    zeminDesenEkleSayfaButton->setFlat(true);
    connect(zeminDesenEkleSayfaButton, &QPushButton::clicked, [=]()
    {
        emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::CustomImagePage);

    });

   QPushButton *zeminTemizleSayfaButton = new QPushButton;
   zeminTemizleSayfaButton=butonSlot(zeminTemizleSayfaButton,"",":icons/zemintemizle.png",QColor(255,0,0,0),e,b,e,b);
   zeminTemizleSayfaButton->setFlat(true);
   connect(zeminTemizleSayfaButton, &QPushButton::clicked, [=]()
    {
       emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);

    });

    QPushButton *gridRenkButton = new QPushButton;
    gridRenkButton=butonSlot(gridRenkButton,"",":icons/gridrenk.png",QColor(255,0,0,0),e,b,e,b);
    gridRenkButton->setFlat(true);
    QMenu *gcm=colorMenu("zeminGridColor","dikey",en,boy,true);
    gridRenkButton->setMenu(gcm);
   connect(gridRenkButton, &QPushButton::clicked, [=]()
    {
    });

    QPushButton *zeminRenkButton = new QPushButton;

     zeminRenkButton=butonSlot(zeminRenkButton,"",":icons/zeminrenk.png",QColor(255,0,0,0),e,b,e,b);
     zeminRenkButton->setFlat(true);
     QMenu *zcm=colorMenu("sekilZeminColor","dikey",en,boy,true);
      zeminRenkButton->setMenu(zcm);
     connect(zeminRenkButton, &QPushButton::clicked, [=]()
     {
     });

   layout->addWidget(zeminLabel, 0, 1,1,4);
 /*  QWidget *cw=colorWidget("sekilZeminColor","yatay",en/2,boy/2,false);
   cw->setFixedSize(en*8,boy);
   cw->setVisible(true);
    //layout->addWidget(cw, 5, 1,1,4,Qt::AlignHCenter);
*/
   QFont ffl( "Arial", 6, QFont::Normal);

   layout->addWidget(noktaliKagit,10,1,1,1,Qt::AlignHCenter);
   layout->addWidget(izometrikKagit,10,2,1,1,Qt::AlignHCenter);
   layout->addWidget(kareliKagit,10,3,1,1,Qt::AlignHCenter);
   layout->addWidget(cizgiliKagit,10,4,1,1,Qt::AlignHCenter);

   QLabel *noktali=new QLabel("Noktalı");   noktali->setFont(ffl);
   QLabel *izometrik=new QLabel("İzometrik"); izometrik->setFont(ffl);
   QLabel *kareli=new QLabel("Kareli");    kareli->setFont(ffl);
   QLabel *cizgili=new QLabel("Çizgili");   cizgili->setFont(ffl);
   layout->addWidget(noktali,11,1,1,1,Qt::AlignHCenter);
   layout->addWidget(izometrik,11,2,1,1,Qt::AlignHCenter);
   layout->addWidget(kareli,11,3,1,1,Qt::AlignHCenter);
   layout->addWidget(cizgili,11,4,1,1,Qt::AlignHCenter);

   layout->addWidget(nkoordinat,12,1,1,1,Qt::AlignHCenter);
   layout->addWidget(hnkoordinat,12,2,1,1,Qt::AlignHCenter);
   layout->addWidget(ndogru,12,3,1,1,Qt::AlignHCenter);
   layout->addWidget(nnkoordinat,12,4,1,1,Qt::AlignHCenter);

   QLabel *skoordinatl=new QLabel("S.Koordinat");   skoordinatl->setFont(ffl);
   QLabel *hnkoordinatl=new QLabel("Y. Koordinat"); hnkoordinatl->setFont(ffl);
   QLabel *ndogrul=new QLabel("Sayı Doğrusu");      ndogrul->setFont(ffl);
   QLabel *nnkoordinatl=new QLabel("Koordinat");    nnkoordinatl->setFont(ffl);

   layout->addWidget(skoordinatl,13,1,1,1,Qt::AlignHCenter);
   layout->addWidget(hnkoordinatl,13,2,1,1,Qt::AlignHCenter);
   layout->addWidget(ndogrul,13,3,1,1,Qt::AlignHCenter);
   layout->addWidget(nnkoordinatl,13,4,1,1,Qt::AlignHCenter);

    layout->addWidget(zeminSeffafButton,20,1,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminSiyahButton,20,2,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminBeyazButton,20,3,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminCustomColorButton,20,4,1,1,Qt::AlignHCenter);

    QLabel *seffaftahta=new QLabel("Şeffaf Tahta");   seffaftahta->setFont(ffl);
    QLabel *siyahtahta=new QLabel("Siyah Tahta"); siyahtahta->setFont(ffl);
    QLabel *beyaztahta=new QLabel("Beyaz Tahta");      beyaztahta->setFont(ffl);
    QLabel *customtahta=new QLabel("S. Renk Tahta");    customtahta->setFont(ffl);

    layout->addWidget(seffaftahta,30,1,1,1,Qt::AlignHCenter);
    layout->addWidget(siyahtahta,30,2,1,1,Qt::AlignHCenter);
    layout->addWidget(beyaztahta,30,3,1,1,Qt::AlignHCenter);
    layout->addWidget(customtahta,30,4,1,1,Qt::AlignHCenter);


    layout->addWidget(zeminCizgiliSayfaButton,50,1,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminKareliSayfaButton,50,2,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminMuzikSayfaButton,50,3,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminGuzelYaziSayfaButton,50,4,1,1,Qt::AlignHCenter);

    QLabel *cizgilitahta=new QLabel("Çizgili Tahta");   cizgilitahta->setFont(ffl);
    QLabel *karelitahta=new QLabel("Kareli Tahta"); karelitahta->setFont(ffl);
    QLabel *muziktahta=new QLabel("Müzik Tahta");      muziktahta->setFont(ffl);
    QLabel *gyazitahta=new QLabel("G.Yazı Tahta");    gyazitahta->setFont(ffl);

    layout->addWidget(cizgilitahta,60,1,1,1,Qt::AlignHCenter);
    layout->addWidget(karelitahta,60,2,1,1,Qt::AlignHCenter);
    layout->addWidget(muziktahta,60,3,1,1,Qt::AlignHCenter);
    layout->addWidget(gyazitahta,60,4,1,1,Qt::AlignHCenter);


    layout->addWidget(zeminTemizleSayfaButton,90,1,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminDesenEkleSayfaButton,90,2,1,1,Qt::AlignHCenter);
    layout->addWidget(gridRenkButton,90,3,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminRenkButton,90,4,1,1,Qt::AlignHCenter);
    QLabel *temizletahta=new QLabel("Tahta Temizle");   temizletahta->setFont(ffl);
    QLabel *desenekletahta=new QLabel("Desen Ekle");    desenekletahta->setFont(ffl);
    QLabel *cizgirengitahta=new QLabel("Çizgi Rengi");  cizgirengitahta->setFont(ffl);
    QLabel *zeminrengitahta=new QLabel("Zemin Rengi");  zeminrengitahta->setFont(ffl);

    layout->addWidget(temizletahta,91,1,1,1,Qt::AlignHCenter);
    layout->addWidget(desenekletahta,91,2,1,1,Qt::AlignHCenter);
    layout->addWidget(cizgirengitahta,91,3,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminrengitahta,91,4,1,1,Qt::AlignHCenter);

    QWidget *cm=cizgiBoyutMenu();
    cm->setVisible(true);
    //cm->setFixedSize(220,cm->height());
    layout->addWidget(cm,95,1,1,4,Qt::AlignHCenter);
   // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
    //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

   return menu;
}

QPixmap toolKalem::lineImage(const QPolygonF &myPolygon,const Qt::PenStyle &stl,int w,int h) const
{
    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8,stl));
  // painter.translate(en, boy);
    painter.drawPolyline(myPolygon);
    return pixmap;
}

QPixmap toolKalem::imageEllipse(const QPolygonF &myPolygon,int w,int h) const
{
    QRectF rectangle(myPolygon[0],myPolygon[1]);
   // QPainter painter(this);
   // painter.drawEllipse(rectangle);
    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
  // painter.translate(en, boy);
    painter.drawEllipse(rectangle);
    return pixmap;
}

QPixmap toolKalem::image(const QPolygonF &myPolygon,int w,int h) const
{
    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
  // painter.translate(en, boy);
    painter.drawPolyline(myPolygon);
    return pixmap;
}

QPixmap toolKalem::zeminImage(const QPolygonF &myPolygon, int w, int h, QColor color,int pensize) const
{
    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(color, pensize));
  // painter.translate(en, boy);
    painter.drawPolyline(myPolygon);
    return pixmap;
}

void toolKalem::sekilButtonIconSlot(DiagramItem::DiagramType mySekilType){
    DiagramItem *ditem=new DiagramItem();
    int ken=300;
    if(DiagramItem::DiagramType::Cember==mySekilType)
    {
        QPixmap pixmap(imageEllipse(ditem->sekilStore(mySekilType,QRectF(QPointF(20,50),QPointF(ken-50,ken-50))),ken,ken));
        sekilButton->setIcon(pixmap);
    }
    else  if(DiagramItem::DiagramType::Pergel==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/pergel.png")); }
    else  if(DiagramItem::DiagramType::Cetvel==mySekilType)   {sekilButton->setIcon(QIcon(":icons/icons/cetvel.png")); }
    else  if(DiagramItem::DiagramType::Gonye==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/gonye.png")); }
    else  if(DiagramItem::DiagramType::Iletki==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/iletki.png")); }
    else  if(DiagramItem::DiagramType::Kup==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/kup.png")); }
    else  if(DiagramItem::DiagramType::Silindir==mySekilType)   {sekilButton->setIcon(QIcon(":icons/icons/silindir.png")); }
    else  if(DiagramItem::DiagramType::Pramit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/pramit.png")); }
    else  if(DiagramItem::DiagramType::Kure==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/kure.png")); }
    else  if(DiagramItem::DiagramType::NDogru==mySekilType)    {
        sekilButton->setIconSize(QSize(50,50));
        sekilButton->setIcon(QIcon(":icons/ndogru.png"));}
    else  if(DiagramItem::DiagramType::NKoordinat==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/nkoordinat.png")); }
    else  if(DiagramItem::DiagramType::NNKoordinat==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/nnkoordinat.png")); }
    else  if(DiagramItem::DiagramType::HNKoordinat==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/hnkoordinat.png")); }
    else  if(DiagramItem::DiagramType::NoktaliKagit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/noktalikagit.png")); }
    else  if(DiagramItem::DiagramType::IzometrikKagit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/izometrikkagit.png")); }
    else  if(DiagramItem::DiagramType::KareliKagit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/karelikagit.png")); }
    else  if(DiagramItem::DiagramType::CizgiliKagit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/cizgilikagit.png")); }
    else  if(DiagramItem::DiagramType::Resim==mySekilType)    {sekilButton->setIcon(QIcon(":icons/icons/addimage.png")); }

    else
    {
        QPixmap pixmap(image(ditem->sekilStore(mySekilType,QRectF(QPointF(20,50),QPointF(ken-50,ken-50))),ken,ken));
        sekilButton->setIcon(pixmap);
    }
}

void toolKalem::setEraseSize(int size)
{
    eraseSizePopLabel->setText("Silgi Boyutu: "+QString::number(size));
}

void toolKalem::ekleSayfaButtonClick(int insertIndex,bool pdfObjectAdded,int pdfPageIndex){
     qDebug()<<"Sayfa Ekleniyor: "<<insertIndex<<pdfObjectAdded<<pdfPageIndex;

   // bool initprg=false;
    if(current_toolTahta->sceneIndex==0&&current_toolTahta->current_sceneIndex==0)
    {
        //initprg=true;
        current_toolTahta->sceneIndex++;
        current_toolTahta->current_sceneIndex=0;
       // current_toolTahta->sceneList.removeAt(0);
        //if(pdfobjectnumber==1&&pdfObjectAdded==false) pdfObjectAdded=true;
    }else
    {
        //initprg=false;
        current_toolTahta->sceneIndex++;

      if(insertIndex==-1)current_toolTahta->current_sceneIndex=current_toolTahta->sceneIndex-1;
      else current_toolTahta->current_sceneIndex++;
    }
  ///  qDebug()<<"ekle sayfa2"<<sceneSayfaNumber<<sceneSayfaActiveNumber<<pdfObjectAdded;
     current_toolTahta->_scene = new Scene(current_toolTahta->gv);
     current_toolTahta->_scene->pdfObjectAdded=pdfObjectAdded;
     current_toolTahta->_scene->pdfPageNumber=pdfPageIndex;
     current_toolTahta->scene=current_toolTahta->_scene;
     current_toolTahta->sceneList.insert(current_toolTahta->current_sceneIndex,current_toolTahta->scene);
     current_toolTahta->gv->setScene(current_toolTahta->scene);
     current_toolTahta->scene->setSceneRect(current_toolTahta->gv->pos().x(),current_toolTahta->gv->pos().y(), current_toolTahta->gv->width(),current_toolTahta->gv->height());
     penToScene();
    // pageNumberPopLabel->setText("Sayfa( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");
    ///kalemButtonClick();
    auto _screenbtn = new QToolButton(pageListwg);
    _screenbtn->setFixedSize(QSize(boy,boy));
    _screenbtn->setIconSize(QSize(boy*0.7,boy*0.7));
    _screenbtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _screenbtn->setText(QString::number(current_toolTahta->current_sceneIndex+1));
    _screenbtn->setToolTip(QString::number(current_toolTahta->current_sceneIndex));


    // screenlayout->addWidget(_screenbtn);
    sceneListButtonLayout->insertWidget(current_toolTahta->current_sceneIndex,_screenbtn);
    // pageList.append(_screenbtn);
    current_toolTahta->sceneListButton.insert(current_toolTahta->sceneIndex-1,_screenbtn);
   // current_toolTahta->sceneListButton.append(_screenbtn);

   for(int i=0;i<current_toolTahta->sceneListButton.count();i++){

        current_toolTahta->sceneListButton[i]->setText(QString::number(i+1));
        current_toolTahta->sceneListButton[i]->setToolTip(QString::number(i));

    }
   //if(pdfPageList>1) pdfPageList--;
  // ileriSayfaButtonClick();

      connect(_screenbtn, &QPushButton::clicked, [=]() {
          secSayfaButtonClick(_screenbtn->toolTip().toInt());
    });
      secSayfaButtonClick(_screenbtn->toolTip().toInt());

}

void toolKalem::silSayfaButtonClick(){
   /// if(sceneSayfaNumber>0)sceneSayfaNumber--;
    if(current_toolTahta->sceneIndex>0){
      // qDebug()<<"sil sayfa-1";
        QPalette palet;
        palet.setBrush(QPalette::Background,QColor(0,0,0,0));
        current_toolTahta->setPalette(palet);

        delete current_toolTahta->sceneListButton[current_toolTahta->current_sceneIndex];
        current_toolTahta->sceneListButton.removeAt(current_toolTahta->current_sceneIndex);
        current_toolTahta->sceneList.removeAt(current_toolTahta->current_sceneIndex);
        current_toolTahta->sceneIndex--;
        current_toolTahta->current_sceneIndex--;
        secSayfaButtonClick(current_toolTahta->current_sceneIndex);

    }

}

void toolKalem::secSayfaButtonClick(int index)
{
  /***************************form ekran fotosu resetleniyor**************/
    QPalette palet;
    palet.setBrush(QPalette::Background,QColor(0,0,0,0));
    current_toolTahta->setPalette(palet);
/*********************************************************************/
    current_toolTahta->current_sceneIndex=index;;
    current_toolTahta->clearImage();
    current_toolTahta->scene=current_toolTahta->sceneList[current_toolTahta->current_sceneIndex];
    current_toolTahta->gv->setScene(current_toolTahta->scene);
  ///  qDebug()<<"ekle button click"<<sceneSayfaNumber<<sceneSayfaActiveNumber<<scene->pdfObjectAdded<<scene->pdfObjectShow<<scene->pdfPageNumber;
    sceneToPen();
    // currentScreenMode=scene->sceneMode;         ///çok önemli
    /// current_toolTahta->scene->sceneMode=currentScreenMode;         ///çok önemli

    for(int i=0;i<current_toolTahta->sceneListButton.length();i++)
    {
        palette->setColor(QPalette::Button, QColor(225,225,225,100));
        current_toolTahta->sceneListButton[i]->setPalette(*palette);
        current_toolTahta->sceneListButton[i]->setAutoFillBackground(true);

    }
    palette->setColor(QPalette::Button, QColor(255,0,0,100));
    current_toolTahta->sceneListButton[index]->setPalette(*palette);
    current_toolTahta->sceneListButton[index]->setAutoFillBackground(true);

    if(current_toolTahta->scene->pdfObjectAdded&&current_toolTahta->scene->pdfObjectShow==false&&
            current_toolTahta->scene->pdfPageNumber<=current_toolTahta->pdfPageCount-1)
      pdfLoaderPage(current_toolTahta->scene->pdfPageNumber);///pdf page loader
/***************************form ekran fotosu ayarlanıyor**************/
    qDebug()<<"Sayfa Seçiliyor ve Yenileniyor";
    QPixmap pixMap = current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
    QPalette palet1;
    palet1.setBrush(QPalette::Background,pixMap);
    current_toolTahta->setPalette(palet1);
/********************************************************************/
    if(current_toolTahta->scene->pdfObjectAdded)
   {
     //  qDebug()<<"sayfa ekle8";
       nextPageButton->show();
       backPageButton->show();
       zoompozitifPageButton->show();
       zoomnegatifPageButton->show();
       zoomfitPageButton->show();

   }else
   {
        nextPageButton->hide();
        backPageButton->hide();
        zoompozitifPageButton->hide();
        zoomnegatifPageButton->hide();
        zoomfitPageButton->hide();

   }

   //  qDebug()<<"sayfa ekle11";
   if(current_toolTahta->sceneIndex>1)
   {

       ///ileriGeriSayfaLabel->show();
       delPageButton->setEnabled(true);
       //addSayfaButton->show();
   }
   else
   {

       delPageButton->setEnabled(false);

   }
}


void toolKalem::ileriSayfaButtonClick(){
    pdfPageList++;int start,end;
    int pdfPageCount=current_toolTahta->pdfPageCount;
  ///  qDebug()<<"ileri: pdfPageList"<<pdfPageList<<"pdfPageCount"<<pdfPageCount<<"ekliSayfa"<<ekliSayfa;
    start=pdfPageList*15-15;
    end=pdfPageList*15;
    if(pdfPageList>=((pdfPageCount+ekliSayfa)/15)+1)
    {   start=pdfPageList*15-15;    end=pdfPageCount+ekliSayfa; pdfPageList=(pdfPageCount+ekliSayfa)/15; }

    for(int i=start;i<end;i++)
    {
        //// qDebug()<<"ileri:"<<start<<end<<i;
        if(i>=ekliSayfa){
            //qDebug()<<"ileri:"<<i;
            if(current_toolTahta->sceneListButton.count()>i)
            {
               current_toolTahta->sceneListButton[i]->show();
            }
            else
            {

                ekleSayfaButtonClick(-1,true,i-ekliSayfa);
            }
        }
    }

    for(int i=0;i<current_toolTahta->sceneListButton.length();i++)
    {
        current_toolTahta->sceneListButton[i]->hide();
    }

    for(int i=start;i<end;i++)
    {
        palette->setColor(QPalette::Button, QColor(225,225,225,100));
        current_toolTahta->sceneListButton[i]->setPalette(*palette);
        current_toolTahta->sceneListButton[i]->setAutoFillBackground(true);
        //pageList[i]->update();

        current_toolTahta->sceneListButton[i]->show();
    }

  secSayfaButtonClick(start); //ilk sayfa gösteriliyor

}
void toolKalem::geriSayfaButtonClick(){
    pdfPageList--;
  //  qDebug()<<"geri: pdfPageList"<<pdfPageList<<"pdfPageCount"<<pdfPageCount<<"ekliSayfa"<<ekliSayfa;
    int start=pdfPageList*15;
    int end=pdfPageList*15+15;
    if(pdfPageList<=1)
    { pdfPageList=1;  start=pdfPageList*15-15;    end=pdfPageList*15;  }


    for(int i=0;i<current_toolTahta->sceneListButton.length();i++)
    {
        current_toolTahta->sceneListButton[i]->hide();
    }

        for(int i=start;i<end;i++)
        {
            palette->setColor(QPalette::Button, QColor(225,225,225,100));
            current_toolTahta->sceneListButton[i]->setPalette(*palette);
            current_toolTahta->sceneListButton[i]->setAutoFillBackground(true);
            //pageList[i]->update();
            current_toolTahta->sceneListButton[i]->show();
        }
        secSayfaButtonClick(start); //ilk sayfa gösteriliyor
   }
void toolKalem::pdfLoaderPage(int pageIndex)
{
   qDebug()<<"pdf loader function"<<pageIndex;
  /// zeminBeyazButtonClick();///burada zemin beyaz yapılıyor
    emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::WhitePage);

     //  QImage image = doc->page(pageIndex)->renderToImage(125.0,125.0,-1,-1,-1,-1);
     QImage image = current_toolTahta->doc->page(pageIndex)->renderToImage(150.0,150.0,current_toolTahta->doc->page(pageIndex)->pageSize().width(),current_toolTahta->doc->page(pageIndex)->pageSize().height());

    ///  view->setSceneRect(0,0,image.width(),image.height());
     VERectangle*  itemToRectDraw = new VERectangle(current_toolTahta->scene);
    itemToRectDraw->sekilTur(DiagramItem::DiagramType::Pdf);
    //itemToRectDraw->setPen(QPen(sekilKalemColor, sekilPenSize, sekilPenStyle));
     itemToRectDraw->setPos(QPoint(current_toolTahta->width()/8,0));

     itemToRectDraw->setBrush(sekilZeminColor);
     QPixmap tmp(image.width(),image.height());
     tmp.fill(QColor(sekilZeminColor));
     QPainter painter(&tmp);
     painter.drawImage(QPoint{}, image, image.rect());
     painter.end();

     itemToRectDraw->setImage(tmp);

    current_toolTahta->scene->addItem(itemToRectDraw);

    current_toolTahta->scene->graphicsList.append(itemToRectDraw);
    current_toolTahta->scene->graphicsListTemp.append(itemToRectDraw);
    current_toolTahta->scene->historyBack.append(itemToRectDraw);
    current_toolTahta->scene->historyBackAction.append("added");

    depo::historyBackCount=current_toolTahta->scene->historyBack.count();
    depo::historyNextCount=current_toolTahta->scene->historyNext.count();

    itemToRectDraw->setRect(0,0,current_toolTahta->width()/4*3,current_toolTahta->height());

    itemToRectDraw->fareState(false);
    itemToRectDraw->setZValue(-200);
    current_toolTahta->scene->makeItemsControllable(false);
    current_toolTahta->scene->pdfObjectShow=true;
    //itemToRectDraw->fareState(true);
    itemToRectDraw = 0;
    //secButtonClick();
current_toolTahta->scene->update();


}

void toolKalem::zoomfitSayfaButtonClick()
{
    foreach(QGraphicsItem* item, current_toolTahta->scene->items()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);

        if(selection)
        {
            if(selection->sekilTr==DiagramItem::DiagramType::Pdf)
            {
                selection->setRect(0,0,current_toolTahta->width()/4*3,current_toolTahta->height());
                selection->setPos(QPoint(current_toolTahta->width()/8,0));

/*
                selection->setRect(0,0,selection->rect().width()/6*7,selection->rect().height()/4*6);

                if(selection->rect().width()+boy<this->width())
                    selection->setPos(QPoint(this->width()/2-selection->rect().width()/2,0));


                if(selection->pos().x()-selection->rect().width()/12<boy)
                    selection->setPos(QPoint(boy*1.1,0));
                */
                 selection->fareState(false);
                current_toolTahta->scene->update();

              QPixmap pixMap = current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
              QPalette palet;
              palet.setBrush(QPalette::Background,pixMap);
              current_toolTahta->setPalette(palet);

                //    else
               // selection->setPos(QPoint(selection->pos().x()-selection->rect().width()/12,0));

            }
        }


    }
}
void toolKalem::zoompozitifSayfaButtonClick()
{
    foreach(QGraphicsItem* item, current_toolTahta->scene->items()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);

        if(selection)
        {
            if(selection->sekilTr==DiagramItem::DiagramType::Pdf)
            {

                selection->setRect(0,0,selection->rect().width()/6*7,selection->rect().height()/4*6);

                if(selection->rect().width()+boy<current_toolTahta->width())
                    selection->setPos(QPoint(current_toolTahta->width()/2-selection->rect().width()/2,0));


                if(selection->pos().x()-selection->rect().width()/12<boy)
                    selection->setPos(QPoint(boy*1.1,0));
                 selection->fareState(false);
                current_toolTahta->scene->update();

              QPixmap pixMap = current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
              QPalette palet;
              palet.setBrush(QPalette::Background,pixMap);
              current_toolTahta->setPalette(palet);

                //    else
               // selection->setPos(QPoint(selection->pos().x()-selection->rect().width()/12,0));

            }
        }


    }
}
void toolKalem::zoomnegatifSayfaButtonClick()
{
    foreach(QGraphicsItem* item, current_toolTahta->scene->items()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);

        if(selection)
        {
            if(selection->sekilTr==DiagramItem::DiagramType::Pdf)
            {

                selection->setRect(0,0,selection->rect().width()/7*6,selection->rect().height()/6*4);
                if(selection->rect().width()/7*6<current_toolTahta->width()+boy)
                    selection->setPos(QPoint(current_toolTahta->width()/2-selection->rect().width()/2,0));
                    else
                    selection->setPos(QPoint(selection->pos().x()+selection->rect().width()/12,0));
                     selection->fareState(false);
                 current_toolTahta->scene->update();

                 QPixmap pixMap = current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
                 QPalette palet;
                 palet.setBrush(QPalette::Background,pixMap);
                 current_toolTahta->setPalette(palet);

            }
        }


    }
}
