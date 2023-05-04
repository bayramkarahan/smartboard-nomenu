#ifndef TOOLKALEMSIGNALSLOTS_H
#define TOOLKALEMSIGNALSLOTS_H
#include<toolKalem.h>

void toolKalem::kalemModeSignalSlot(Scene::Mode mode,DiagramItem::DiagramType type)
{
    qDebug()<<"kw->currentMode:"<<currentMode<<oldMode;
   // oldMode=currentMode;    currentMode=mode;
   // oldType=currentType;    currentType=type;


   /* if(Scene::Mode::DrawPen==mode&&(DiagramItem::DiagramType::NormalPen==type||DiagramItem::DiagramType::PatternPen==type))
    {
       /*
        current_toolTahta->penDrawingMain=true;
        current_toolTahta->gv->hide();
        current_toolTahta->gv->setEnabled(false);
        current_toolTahta->scene->makeItemsControllable(false);
        QPixmap pixMap = current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
        QPalette palet;
        palet.setBrush(QPalette::Background,pixMap);
        current_toolTahta->setPalette(palet);
        */

    /*}else
    {
        qDebug()<<"Kalem Dışında Faklı Bir Araç Seçildi";
        current_toolTahta->penDrawingMain=false;
        current_toolTahta->gv->show();
        current_toolTahta->gv->setEnabled(true);
        /***************************form ekran fotosu resetleniyor**************/
     /*   QPalette palet;
        palet.setBrush(QPalette::Background,QColor(0,0,0,0));
        current_toolTahta->setPalette(palet);
        /***************************form ekran fotosu resetleniyor**************/
   /* }

    if(Scene::Mode::SekilMode==mode) kalemSekilModeSignalSlot(type);
    if(Scene::Mode::ZeminMode==mode) kalemZeminModeSignalSlot(type);
*/
   /* current_toolTahta->raise();
    raise();
    current_toolPageMenu->lower();
    current_toolKalemMenu->raise();*/
    //current_toolTahta->lower();
}


void toolKalem::sceneItemAddedSignalSlot(Scene *scenetemp, QGraphicsItem *item, bool additemstate, Scene::Mode mode, DiagramItem::DiagramType type)
{
    scenetemp->addItem(item);
    current_toolTahta->update();
   /// if (additemstate) secSayfaButtonClick(current_toolTahta->current_sceneIndex);
    scenetemp->graphicsList.append(item);
    scenetemp->graphicsListTemp.append(item);
    scenetemp->historyBack.append(item);
    scenetemp->historyBackAction.append("added");
    depo::historyBackCount=scenetemp->historyBack.count();
    depo::historyNextCount=scenetemp->historyNext.count();
    qDebug()<<"scene nesne eklendi.....";
    if(mode==Scene::CopyMode) handButtonSlot(true);
    if(mode==Scene::FenMode)
    {
        //qDebug()<<"Fen Seçtiniz...";
       //currentMode=oldMode;currentType=oldType;

    //current_toolKalemMenu->show();
    }
    /*    qDebug()<<"Kimya Seçtiniz...";
        /***************************form ekran fotosu resetleniyor**************/
      /*  QPalette palet;
        palet.setBrush(QPalette::Background,QColor(0,0,0,0));
        current_toolTahta->setPalette(palet);

       //handButtonSlot();
       //current_toolKalemMenu->show();
    }*/
  /*  if(mode==Scene::ZeminMode&&(type==DiagramItem::DiagramType::NoktaliKagit||
                                type==DiagramItem::DiagramType::IzometrikKagit||
                                type==DiagramItem::DiagramType::CizgiliKagit||
                                type==DiagramItem::DiagramType::KareliKagit))
    {
        qDebug()<<"noktalı kağıt seçtiniz...";
        //handButtonSlot();
        //current_toolKalemMenu->show();
    }
    if(mode==Scene::ZeminMode&&type==DiagramItem::DiagramType::PatternPage)
    {
        qDebug()<<"Zemin Eklendi.....";



        /***************************form ekran fotosu resetleniyor**************/
      /*  QPalette palet;
        palet.setBrush(QPalette::Background,QColor(0,0,0,0));
        current_toolTahta->setPalette(palet);

       //
       //current_toolKalemMenu->show();
       */
   // }
  modeKontrolSlot();

}

void toolKalem::sceneItemRemovedSignalSlot(Scene *scenetemp, Scene::Mode mode, QGraphicsItem * item, bool deleteAction)
{
   /* scenetemp->addItem(item);
    scenetemp->graphicsList.append(item);
    scenetemp->graphicsListTemp.append(item);
    scenetemp->historyBack.append(item);
    scenetemp->historyBackAction.append("added");
    depo::historyBackCount=scenetemp->historyBack.count();
    depo::historyNextCount=scenetemp->historyNext.count();*/
    scenetemp->removeItem(item);

    qDebug()<<"scene nesne Silindi......";
    if(mode==Scene::EraseMode) eraseButtonSlot();
    if(mode==Scene::ClearMode) {currentMode= oldMode;currentType=oldType;}
      modeKontrolSlot();

}

void toolKalem::kalemColorSignalSlot(QString colorType, QColor color)
{

  if (colorType=="penColor"){
     // qDebug()<<"penColor";
    penColor=color;
    current_toolTahta->scene->setSekilKalemColor( penColor);
    current_toolTahta->scene->setPenColor( penColor);
    penColorButton->setStyleSheet(QString("QToolButton{ background: %1; }").arg(penColor.name()));
  }
  if (colorType=="sekilZeminColor"){
     //qDebug()<<"sekilZeminColor"<<color;
     sekilZeminColor=color;
    current_toolTahta->scene->setSekilZeminColor(sekilZeminColor);
   }
  if (colorType=="zeminGridColor"){
     //qDebug()<<"sekilZeminColor"<<color;
     zeminGridColor=color;
    // kalemModeSignalSlot(Scene::Mode::ZeminMode,pagePattern);
     emit kalemModeSignal(Scene::Mode::ZeminMode,pagePattern);

    }
  if (colorType=="zeminColor"){
     //qDebug()<<"zeminColor"<<color;
     zeminColor=color;
     emit kalemZeminModeSignal(DiagramItem::DiagramType::CustomColorPage);
     //emit kalemModeSignal(Scene::Mode::ZeminMode,pagePattern);
   }
  if (colorType=="zeminDolguColor"){
     //qDebug()<<"zeminDolguColor"<<color;
     zeminDolguColor=color;
     current_toolTahta->scene->myzeminDolguColor=color;
   }
}

void toolKalem::sayacCloseSignalSlot()
{
//qDebug()<<"sayac Kapandı..";
current_toolTahta->setWindowFlags(current_toolTahta_old_flags);
current_toolTahta->show();
}

void toolKalem::kalemZeminModeSignalSlot(DiagramItem::DiagramType type)
{

//qDebug()<<"Zemin Türü Seçiliyor:"<<type;

    current_toolTahta->scene->setSekilZeminColor(sekilZeminColor);
    current_toolTahta->scene->setSekilPenSize(penSize);
    current_toolTahta->scene->setSekilKalemColor(penColor);
    //current_toolTahta->scene->sceneMode=Scene::Mode::DrawRectangle;

if(DiagramItem::DiagramType::NDogru==type){ current_toolTahta->scene->donSlot(type);return;}
if(DiagramItem::DiagramType::NKoordinat==type){ current_toolTahta->scene->donSlot(type);return;}
if(DiagramItem::DiagramType::NNKoordinat==type){current_toolTahta->scene->donSlot(type);return;}
if(DiagramItem::DiagramType::HNKoordinat==type){ current_toolTahta->scene->donSlot(type);return;}
if(DiagramItem::DiagramType::NoktaliKagit==type) {current_toolTahta->scene->donSlot(type);return;}
if(DiagramItem::DiagramType::IzometrikKagit==type){ current_toolTahta->scene->donSlot(type);return;}
if(DiagramItem::DiagramType::KareliKagit==type) {current_toolTahta->scene->donSlot(type);return;}
if(DiagramItem::DiagramType::CizgiliKagit==type) {current_toolTahta->scene->donSlot(type);return;}

if(DiagramItem::DiagramType::TransparanPage==type){
      qDebug()<<"seffaf zemin"<<current_toolTahta->scene->sceneMode;
    pagePattern=type;
    zeminColor=QColor(0,0,0,0);
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),gridSize*10,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,zeminColor, penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
   current_toolTahta->scene->myImage= bkgnd;
  }
if(DiagramItem::DiagramType::BlackPage==type){
   // qDebug()<<"siyah zemin";
    pagePattern=type;
    zeminColor=QColor(0,0,0,255);
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (current_toolTahta->width(),current_toolTahta->height(),gridSize*10,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi, zeminColor, penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,current_toolTahta->width(),current_toolTahta->height());
    current_toolTahta->scene->myImage=bkgnd;
  }
if(DiagramItem::DiagramType::WhitePage==type){
    pagePattern=type;
    zeminColor=QColor(255,255,255,255);
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),gridSize*3.4,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,zeminColor, penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;
 }
if(DiagramItem::DiagramType::CustomColorPage==type){
    pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),gridSize*10,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,zeminColor, penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;

}
if(DiagramItem::DiagramType::CizgiliPage==type){
    pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=true;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),gridSize*3.4,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,zeminColor,zeminGridColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;

  }
if(DiagramItem::DiagramType::KareliPage==type){
    pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=true;
    current_toolTahta->scene->sceneGridDikey=true;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),gridSize*3.4,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,zeminColor, zeminGridColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;

  }
if(DiagramItem::DiagramType::MuzikPage==type){
    pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=true;
    current_toolTahta->scene->sceneGridDikey=false;
   current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    DiagramItem *ditem=new DiagramItem();
    QPixmap pim(zeminImage(ditem->sekilStore(DiagramItem::DiagramType::Muzik,QRectF(QPointF(0,0),QPointF(current_toolTahta->width(),current_toolTahta->height()))),current_toolTahta->width(),current_toolTahta->height(),zeminColor,zeminGridColor,2));
    current_toolTahta->scene->myImage=pim;
/*
    VERectangle*  itemToRectDraw = new VERectangle(current_toolTahta->scene);
    itemToRectDraw->sekilTur(DiagramItem::DiagramType::Copy);
    //itemToRectDraw->setPen(QPen(mySekilKalemColor, mySekilPenSize, mySekilPenStyle));
    //itemToRectDraw->setBrush(mySekilZeminColor);
    QPixmap temp(":icons/musicikon.png");
    itemToRectDraw->setPos(QPoint(50,this->height()/3*0));
    itemToRectDraw->setImage(temp);
    itemToRectDraw->setRect(0,0,75,250);
    current_toolTahta->scene->addItem(itemToRectDraw);
    itemToRectDraw->fareState(false);
    itemToRectDraw = 0;

   // VERectangle*
            itemToRectDraw = new VERectangle(current_toolTahta->scene);
    itemToRectDraw->sekilTur(DiagramItem::DiagramType::Copy);
    //itemToRectDraw->setPen(QPen(mySekilKalemColor, mySekilPenSize, mySekilPenStyle));
    //itemToRectDraw->setBrush(mySekilZeminColor);
    //QPixmap temp(":icons/musicikon.png");
    itemToRectDraw->setPos(QPoint(50,this->height()/3*1));
    itemToRectDraw->setImage(temp);
    itemToRectDraw->setRect(0,0,75,250);
    current_toolTahta->scene->addItem(itemToRectDraw);
    itemToRectDraw->fareState(false);
    itemToRectDraw = 0;

    //VERectangle*
            itemToRectDraw = new VERectangle(current_toolTahta->scene);
    itemToRectDraw->sekilTur(DiagramItem::DiagramType::Copy);
   // itemToRectDraw->setPen(QPen(mySekilKalemColor, mySekilPenSize, mySekilPenStyle));
   // itemToRectDraw->setBrush(mySekilZeminColor);
    //QPixmap temp(":icons/musicikon.png");
    itemToRectDraw->setPos(QPoint(50,this->height()/3*2));
    itemToRectDraw->setImage(temp);
    itemToRectDraw->setRect(0,0,75,250);
    current_toolTahta->scene->addItem(itemToRectDraw);
    itemToRectDraw->fareState(false);
    itemToRectDraw = 0;
*/
  }
if(DiagramItem::DiagramType::GuzelYaziPage==type){
    pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=true;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),gridSize*3.4,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,zeminColor, penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;
 }
if(DiagramItem::DiagramType::CustomImagePage==type)
{
    pagePattern=type;
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
        abc.setWindowTitle("Resim Aç jpg png bmp");
        abc.setDirectory(QDir::homePath()+"/Masaüstü");
        abc.setNameFilter(tr("Image Files (*.png *.jpg *.bmp)"));
        if(abc.exec()) {
            if(abc.selectedFiles()[0]!="")
            {
                QPixmap image = QPixmap(abc.selectedFiles()[0]);
               current_toolTahta->scene->myImage=image;
             }
        }

    }
    else
    {
        //qDebug()<<"windows fileopen";
        abc.setWindowTitle("Resim Aç jpg png bmp");
        abc.setDirectory(QDir::homePath()+"/desktop");
        abc.setNameFilter(tr("Image Files (*.png *.jpg *.bmp)"));
        if(abc.exec()) {
            if(abc.selectedFiles()[0]!="")
            {
                QPixmap image = QPixmap(abc.selectedFiles()[0]);
                current_toolTahta->scene->myImage=image;
                current_toolTahta->scene->donSlot(DiagramItem::DiagramType::PatternPage);
            }
        }

    }

    flags |= Qt::Window;
    flags |= Qt::X11BypassWindowManagerHint;
    flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);
    show();
}

bool pageadd=false;
foreach(QGraphicsItem* item,current_toolTahta->scene->items()){
    VERectangle * selection = dynamic_cast<VERectangle *>(item);
    if(selection)
    {
        if(selection->sekilTr!=0&&selection->sekilTr==DiagramItem::DiagramType::PatternPage){
            current_toolTahta->scene->removeItem(selection);
        }
    }
}
    // qDebug()<<"zemin..0";
   VERectangle *zeminItem = new VERectangle(current_toolTahta->scene);
   zeminItem->setPen(QPen(current_toolTahta->scene->mySekilKalemColor, penSize, current_toolTahta->scene->mySekilPenStyle));
   zeminItem->sekilTur(DiagramItem::DiagramType::PatternPage);
   zeminItem->setImage(current_toolTahta->scene->myImage);
   /*current_toolTahta->scene->addItem(zeminItem);
   current_toolTahta->scene->graphicsList.append(zeminItem);
   current_toolTahta->scene->graphicsListTemp.append(zeminItem);
   current_toolTahta->scene->historyBack.append(zeminItem);
   current_toolTahta->scene->historyBackAction.append("added");
   */
   emit current_toolTahta->scene->sceneItemAddedSignal(current_toolTahta->scene,zeminItem,false,Scene::ZeminMode,DiagramItem::DiagramType::PatternPage);
   zeminItem->setRect(0,0,current_toolTahta->width(),current_toolTahta->height());
   zeminItem->setPos(0,0);
   zeminItem->setZValue(-200);
  // zeminItem->setSelected(false);
   zeminItem->fareState(false);
   //current_toolTahta->scene->makeItemsControllable(false);
//}
///secSayfaButtonClick(current_toolTahta->current_sceneIndex);

/*if(kw->oldMode==Scene::Mode::DrawPen&&kw->oldType==DiagramItem::DiagramType::NormalPen)
{
 qDebug()<<"kalem aktifleştirildi";
 current_toolTahta->penDrawingMain=true;
 current_toolTahta->gv->hide();
 current_toolTahta->gv->setEnabled(false);
kw->currentMode=kw->oldMode;
kw->currentType=kw->oldType;
}
*/
}

void toolKalem::kalemSekilModeSignalSlot(DiagramItem::DiagramType type){
    qDebug()<<"sekil butonclick"<<type;
    sekilButtonIconSlot(type);//şekil buton iconu ayarlanıyor
    current_toolTahta->scene->setSekilPenSize(penSize);
    current_toolTahta->scene->setSekilKalemColor(penColor);
    current_toolTahta->scene->setSekilZeminColor(sekilZeminColor);
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawRectangle;

    if(DiagramItem::DiagramType::Pergel==type){ current_toolTahta->scene->donSlot(type);return;}
    if(DiagramItem::DiagramType::Gonye==type){ current_toolTahta->scene->donSlot(type);return;}
    if(DiagramItem::DiagramType::Cetvel==type){current_toolTahta->scene->donSlot(type);return;}
    if(DiagramItem::DiagramType::Iletki==type){ current_toolTahta->scene->donSlot(type);return;}

   if(DiagramItem::DiagramType::Kure==type)
    {

        current_toolTahta->scene->mySekilType=type;
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawRectangle;
        current_toolTahta->scene->myImage=QPixmap(":/icons/kure.png");
      }
    else if(DiagramItem::DiagramType::Silindir==type)
    {
        current_toolTahta->scene->mySekilType=type;
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawRectangle;
        current_toolTahta->scene->myImage=QPixmap(":/icons/silindir.png");
      }
    else if(DiagramItem::DiagramType::Kup==type)
    {
      current_toolTahta->scene->mySekilType=type;
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawRectangle;
       current_toolTahta->scene->myImage=QPixmap(":/icons/kup.png");
      }
    else if(DiagramItem::DiagramType::Pramit==type)
    {
        current_toolTahta->scene->mySekilType=type;
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawRectangle;
        current_toolTahta->scene->myImage=QPixmap(":/icons/pramit.png");
      }

    else if(DiagramItem::DiagramType::Resim==type)
    {
        qDebug()<<"resim";
       Qt::WindowFlags flags = 0;
        flags |= Qt::Window;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::CustomizeWindowHint;
        setWindowFlags(flags);

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
            abc.setWindowTitle("Resim Aç jpg png");
            abc.setDirectory(QDir::homePath()+"/Masaüstü");
            abc.setNameFilter(tr("Resim Dosyaları (*.png *.jpg *.bmp)"));
            if(abc.exec()) {
                if(abc.selectedFiles()[0]!="")
                {
                    QPixmap image = QPixmap(abc.selectedFiles()[0]);
                 current_toolTahta->scene->setImage(image);
                 current_toolTahta->scene->donSlot(type);


                }
            }

        }
        else
        {
            //qDebug()<<"windows fileopen";
            abc.setWindowTitle("Resim Aç jpg png bmp");
            abc.setDirectory(QDir::homePath()+"/desktop");
            abc.setNameFilter(tr("Image Files (*.png *.jpg *.bmp)"));
            if(abc.exec()) {
                if(abc.selectedFiles()[0]!="")
                {
                    QPixmap image = QPixmap(abc.selectedFiles()[0]);
                   current_toolTahta->scene->setImage(image);
                 current_toolTahta->scene->donSlot(type);

                }
            }

        }

        flags |= Qt::Window;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::WindowStaysOnTopHint;
        setWindowFlags(flags);
        show();
      current_toolTahta->scene->mySekilType=type;
    }
    else current_toolTahta->scene->mySekilType=type;

}


#endif // TOOLKALEMSIGNALSLOTS_H
