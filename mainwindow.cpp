#include "mainwindow.h"
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
  this->setFixedSize(300,600);
   // QGuiApplication::instance()->setW->setWindowIcon(QIcon(":icons/pencolor.png"));
    setWindowFlags(Qt::WindowStaysOnTopHint);
   // setWindowFlags(Qt::X11BypassWindowManagerHint);
   // setAttribute(Qt::WA_StaticContents);
   //setAttribute(Qt::WA_TranslucentBackground, true);

    screenSize = qApp->screens()[0]->size();
    boy=(screenSize.height()/100)*5.70;
    en=boy;
    //qDebug()<<"ekran boyutu:"<<screenSize;
    current_toolTahta=new toolTahta(screenSize.width()*0.7,screenSize.height()*0.6);
    //current_toolTahta=new toolTahta(screenSize.width(),screenSize.height());
    current_toolTahta->move(screenSize.width()/2-current_toolTahta->width()/2,screenSize.height()/2-current_toolTahta->height()/2);
    current_toolTahta->lower();
    current_toolTahta->lower();
    current_toolTahta->lower();

    current_toolTahta->show();


 /******************************************************************************/
   kw=new toolKalem("Kalem",en*1/3*2-2,boy*0.8,current_toolTahta,screenSize.width(),screenSize.height());
   kw->setFixedSize(en*1.15,boy*0.8*12);
   kw->sagSolHizala();
  // kw->move(screenSize.width()-kw->width()-10,screenSize.height()/2- kw->height()/2);
  // kw->setStyleSheet("background-color:rgb(220, 220, 220);");
   kw->setWindowFlags(Qt::X11BypassWindowManagerHint);
   kw->setObjectName("kalem");
   kw->setStyleSheet("QWidget#kalem{"
                         "border: 2px solid rgb(62, 140, 183);"
                         "border-radius: 3px;"
                         "background-color:rgba(240,240,240,250);"
                         "}");

   kw->show();
   connect(kw, SIGNAL(kalemModeSignal(Scene::Mode,DiagramItem::DiagramType)),
           this, SLOT(kalemModeSignalSlot(Scene::Mode,DiagramItem::DiagramType)));

   connect(kw, SIGNAL(kalemColorSignal(QString,QColor)),
           this, SLOT(kalemColorSignalSlot(QString,QColor)));

   connect(kw, SIGNAL(kalemZeminModeSignal(DiagramItem::DiagramType)),
           this, SLOT(kalemZeminModeSignalSlot(DiagramItem::DiagramType)));

   connect(kw, SIGNAL(kalemSekilModeSignal(DiagramItem::DiagramType)),
           this, SLOT(kalemSekilModeSignalSlot(DiagramItem::DiagramType)));
   /********************************************/
  // slotPenInit();
   /***************************Top Menu**********************************************/
   current_toolKalemMenu=new toolKalemMenu(kw->penTopMenu(screenSize.height()*0.05),screenSize.width()*0.8,screenSize.height()*0.05);
   current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,0);
  // current_toolKalemMenu->show();

   /***************************Bottom Menu**********************************************/
   curent_pageMenu=new toolPageMenu(kw->pageBottomMenu(screenSize.height()*0.045),screenSize.width()*0.85,screenSize.height()*0.045);
   curent_pageMenu->move(screenSize.width()/2-curent_pageMenu->width()/2,screenSize.height()-curent_pageMenu->height()*2.5);
   curent_pageMenu->show();
   /*******************ilk Açılış Hazırlığı****************************/
   kw->ekleSayfaButtonClick(-1,false,-1);
   //kalemModeSignalSlot(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
   //kw->penButtonSlot();
   //kw->desktopButtonSlot();
   kw->raise();kw->raise();
   curent_pageMenu->raise();curent_pageMenu->raise();
   current_toolKalemMenu->raise();current_toolKalemMenu->raise();


}
void MainWindow::kalemModeSignalSlot(Scene::Mode mode,DiagramItem::DiagramType type)
{
    // qDebug()<<"kalem mode:"<<mode<<type;
    kw->oldMode=kw->currentMode;
    kw->currentMode=mode;

    kw->oldType=kw->currentType;
    kw->currentType=type;
   // qDebug()<<"penDesktopStatus"<<kw->penDesktopStatus;
   /* if(!kw->penDesktopStatus)
    {
        current_toolKalemMenu->hide();
        curent_pageMenu->hide();
        current_toolTahta->hide();
        qDebug()<<"desktop";
    }*/
   if((Scene::Mode::DrawPen==mode||
            Scene::Mode::SekilMode==mode||
            Scene::Mode::ZeminMode==mode||
            Scene::Mode::EraseMode==mode||
            Scene::Mode::PdfMode==mode||
            Scene::Mode::PenMode)&&kw->penDesktopStatus)
    {
        //current_toolKalemMenu->show();
        //curent_pageMenu->show();
        current_toolTahta->show();
        qDebug()<<"pen";
    }

/*
    currentTab()->scene->pageOfNumberScene=currentTab()->currentPage()-1;
    PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
    const QRectF pageItemRect = page->boundingRect().translated(page->pos());
    currentTab()->scene->pageItemRect=pageItemRect;
     currentTab()->setDragMode(QGraphicsView::NoDrag);
     foreach(QGraphicsItem* item, currentTab()->scene->items()){
         VERectangle * selection = dynamic_cast<VERectangle *>(item);
         if(selection)
         {
             if(selection->sekilTr==DiagramItem::DiagramType::PatternPage){

                 if(currentTab()->currentPage()-1==selection->pageOfNumber)
                 {
                     // qDebug()<<"arka plan";
                     selection->setVisible(true);
                     currentTab()->scene->update();
                 }
             }
         }
     }
     /****************************************************************/
   /*  page->copyMode=false;
     on_copyToClipboardMode_triggered(false);
*/
        qDebug()<<"kw->currentMode:"<<kw->currentMode<<kw->oldMode;

   if(kw->currentMode!=kw->oldMode)
    {
    //qDebug()<<"toolKalemMenu seçenekleri kontrol ediliyor";
    if(current_toolKalemMenu->isVisible()) current_toolKalemMenu->close();
   if(mode==Scene::Mode::DrawPen)
   {
       current_toolKalemMenu=new toolKalemMenu(kw->penTopMenu(screenSize.height()*0.045),screenSize.width()*0.9,screenSize.height()*0.045);
       current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,2);
       current_toolKalemMenu->show();
   }
   if(mode==Scene::Mode::EraseMode)
   {
       current_toolKalemMenu=new toolKalemMenu(kw->eraseTopMenu(screenSize.height()*0.045),screenSize.width()*0.2,screenSize.height()*0.045);
       current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,2);
       current_toolKalemMenu->show();
   }
   if(mode==Scene::Mode::SekilMode)
      {
       current_toolKalemMenu=new toolKalemMenu(kw->sekilTopMenu(screenSize.height()*0.045),screenSize.width()*0.9,screenSize.height()*0.045);
       current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,2);
       current_toolKalemMenu->show();
   }
   if(mode==Scene::Mode::ZeminMode)
   {
       current_toolKalemMenu=new toolKalemMenu(kw->zeminTopMenu(screenSize.height()*0.045),screenSize.width()*0.9,screenSize.height()*0.045);
       current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,2);
       current_toolKalemMenu->show();
   }
   if(mode==Scene::Mode::PdfMode)
   {
       current_toolKalemMenu=new toolKalemMenu(kw->pdfTopMenu(screenSize.height()*0.045),screenSize.width()*0.2,screenSize.height()*0.045);
       current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,2);
       current_toolKalemMenu->show();
   }

   if(mode==Scene::Mode::ToolMode)
   {
       current_toolKalemMenu=new toolKalemMenu(kw->toolTopMenu(screenSize.height()*0.045),screenSize.width()*0.2,screenSize.height()*0.045);
       current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,2);
       current_toolKalemMenu->show();
   }
       if(mode==Scene::Mode::SelectObject||
//           mode==Scene::Mode::ClearMode||
           mode==Scene::Mode::CopyMode)
       {
       current_toolKalemMenu=new toolKalemMenu(new QWidget(),screenSize.width()*0.6,screenSize.height()*0.045);
       current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,2);
       current_toolKalemMenu->hide();
       }
    }

    if(Scene::Mode::DrawPen==mode&&(DiagramItem::DiagramType::NormalPen==type||DiagramItem::DiagramType::PatternPen==type))
    {
        current_toolTahta->penDrawingMain=true;
        current_toolTahta->gv->hide();
        current_toolTahta->gv->setEnabled(false);
        //current_toolTahta->setAutoFillBackground(true);
        QPixmap pixMap = current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
        QPalette palet;
        palet.setBrush(QPalette::Background,pixMap);
        current_toolTahta->setPalette(palet);


    }else
    {
        qDebug()<<"Kalem Dışında Faklı Bir Araç Seçildi";
        current_toolTahta->penDrawingMain=false;
        current_toolTahta->gv->show();
        current_toolTahta->gv->setEnabled(true);

    }

    if(Scene::Mode::SekilMode==mode) kalemSekilModeSignalSlot(type);
    if(Scene::Mode::ZeminMode==mode) kalemZeminModeSignalSlot(type);
    if(Scene::Mode::ExitMode==mode)exit(0);


}


void MainWindow::kalemZeminModeSignalSlot(DiagramItem::DiagramType type)
{

qDebug()<<"Zemin Türü Seçiliyor:"<<type;

    current_toolTahta->scene->setSekilZeminColor(kw->sekilZeminColor);
    current_toolTahta->scene->setSekilPenSize(kw->penSize);
    current_toolTahta->scene->setSekilKalemColor(kw->penColor);
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
      qDebug()<<"seffaf zemin";
    kw->pagePattern=type;
    kw->zeminColor=QColor(0,0,0,0);
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*10,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,kw->zeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
   current_toolTahta->scene->myImage= bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);

  }
if(DiagramItem::DiagramType::BlackPage==type){
   // qDebug()<<"siyah zemin";
    kw->pagePattern=type;
    kw->zeminColor=QColor(0,0,0,255);

    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (current_toolTahta->width(),current_toolTahta->height(),kw->gridSize*10,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi, kw->zeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,current_toolTahta->width(),current_toolTahta->height());

    current_toolTahta->scene->myImage=bkgnd;
    //current_toolTahta->scene->donSlot(DiagramItem::DiagramType::PatternPage);
  //  kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
   // kw->buttonStateClear();
   // kw->penButton->setChecked(true);
  }
if(DiagramItem::DiagramType::WhitePage==type){
    kw->pagePattern=type;
    kw->zeminColor=QColor(255,255,255,255);
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,kw->zeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
    /*kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);
*/
 }
if(DiagramItem::DiagramType::CustomColorPage==type){
    kw->pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*10,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,kw->zeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
   /* kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);
*/
}
if(DiagramItem::DiagramType::CizgiliPage==type){
    kw->pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=true;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,kw->zeminColor, kw->zeminGridColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
   /* kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);
*/
  }
if(DiagramItem::DiagramType::KareliPage==type){
    kw->pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=true;
    current_toolTahta->scene->sceneGridDikey=true;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,kw->zeminColor, kw->zeminGridColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
   /* kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);
*/
  }
if(DiagramItem::DiagramType::MuzikPage==type){
    kw->pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=true;
    current_toolTahta->scene->sceneGridDikey=false;
   current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    DiagramItem *ditem=new DiagramItem();
    QPixmap pim(kw->zeminImage(ditem->sekilStore(DiagramItem::DiagramType::Muzik,QRectF(QPointF(0,0),QPointF(current_toolTahta->width(),current_toolTahta->height()))),current_toolTahta->width(),current_toolTahta->height(),kw->zeminColor,kw->zeminGridColor,2));
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
    kw->pagePattern=type;
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=true;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,kw->zeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    current_toolTahta->scene->myImage=bkgnd;
    //currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
  /*  kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);
*/
  }
if(DiagramItem::DiagramType::CustomImagePage==type)
{
    kw->pagePattern=type;
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
    kw->setWindowFlags(flags);
    kw->show();
}

bool pageadd=false;
foreach(QGraphicsItem* item,current_toolTahta->scene->items()){
         VERectangle * selection = dynamic_cast<VERectangle *>(item);
          if(selection)
         {
            if(selection->sekilTr!=0&&
            // selection->pageOfNumber==current_toolTahta->scene->pageOfNumberScene&&
             selection->sekilTr==DiagramItem::DiagramType::PatternPage){

           //  pageadd=true;
             ///selection->setImage(current_toolTahta->scene->myImage);
            // qDebug()<<"zemin..x";
            // selection->setRect(0,0,current_toolTahta->width(),current_toolTahta->height());
           //  selection->setPos(current_toolTahta->left(),current_toolTahta->top());
            // selection->setPos(current_toolTahta->pos());
            current_toolTahta->scene->removeItem(selection);
            // selection->update();
             }
         }
     }
 //qDebug()<<"zemin..0"<<pageadd;
//if(pageadd)

//{*/
    // qDebug()<<"zemin..0";
   VERectangle *zeminItem = new VERectangle(current_toolTahta->scene);
   zeminItem->setPen(QPen(current_toolTahta->scene->mySekilKalemColor, kw->penSize, current_toolTahta->scene->mySekilPenStyle));

   zeminItem->sekilTur(DiagramItem::DiagramType::PatternPage);
   zeminItem->setImage(current_toolTahta->scene->myImage);
   current_toolTahta->scene->addItem(zeminItem);
   // zeminItem->pageOfNumber=current_toolTahta->scene->pageOfNumberScene;
   current_toolTahta->scene->graphicsList.append(zeminItem);
   current_toolTahta->scene->graphicsListTemp.append(zeminItem);
   current_toolTahta->scene->historyBack.append(zeminItem);
   current_toolTahta->scene->historyBackAction.append("added");
   zeminItem->setRect(0,0,current_toolTahta->width(),current_toolTahta->height());
   // zeminItem->setPos(current_toolTahta->left(),current_toolTahta->top());
   zeminItem->setPos(0,0);
   zeminItem->setZValue(-200);

  // zeminItem->setSelected(false);

   zeminItem->fareState(false);
   //current_toolTahta->scene->makeItemsControllable(false);

//}
kw->secSayfaButtonClick(current_toolTahta->current_sceneIndex);
}
void MainWindow::kalemSekilModeSignalSlot(DiagramItem::DiagramType type){
   // qDebug()<<"sekil butonclick"<<type;
 /*   currentTab()->scene->pageOfNumberScene=currentTab()->currentPage()-1;
    PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
    const QRectF pageItemRect = page->boundingRect().translated(page->pos());
    currentTab()->scene->pageItemRect=pageItemRect;
*/
    kw->sekilButtonIconSlot(type);//şekil buton iconu ayarlanıyor
    current_toolTahta->scene->setSekilPenSize(kw->penSize);
    current_toolTahta->scene->setSekilKalemColor(kw->penColor);
    current_toolTahta->scene->setSekilZeminColor(kw->sekilZeminColor);
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawRectangle;


    //if(DiagramItem::DiagramType::SolidLine==type)  currentTab()->scene->setSekilPenStyle(Qt::SolidLine);
    //else if(DiagramItem::DiagramType::DashLine==type)  currentTab()->scene->setSekilPenStyle(Qt::DashLine);
   // else if(DiagramItem::DiagramType::DotLine==type)  currentTab()->scene->setSekilPenStyle(Qt::DotLine);
    if(DiagramItem::DiagramType::Pergel==type) current_toolTahta->scene->donSlot(type);
    else if(DiagramItem::DiagramType::Cetvel==type) current_toolTahta->scene->donSlot(type);
    else if(DiagramItem::DiagramType::Gonye==type) current_toolTahta->scene->donSlot(type);
    else if(DiagramItem::DiagramType::Iletki==type) current_toolTahta->scene->donSlot(type);
    else if(DiagramItem::DiagramType::Kure==type)
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
        kw->setWindowFlags(flags);

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
        kw->setWindowFlags(flags);
        kw->show();
      current_toolTahta->scene->mySekilType=type;
    }

    else current_toolTahta->scene->mySekilType=type;

//qDebug()<<"buraya geldinn..";
//kw->modeKontrolSlot();

}
void MainWindow::kalemColorSignalSlot(QString colorType, QColor color)
{

  if (colorType=="penColor"){
     // qDebug()<<"penColor";
    kw->penColor=color;
    current_toolTahta->scene->setSekilKalemColor( kw->penColor);
    current_toolTahta->scene->setPenColor( kw->penColor);
    kw->penColorButton->setStyleSheet(QString("QToolButton{ background: %1; }").arg(kw->penColor.name()));
  }
  if (colorType=="sekilZeminColor"){
     //qDebug()<<"sekilZeminColor"<<color;
     kw->sekilZeminColor=color;
    current_toolTahta->scene->setSekilZeminColor(kw->sekilZeminColor);
   }
  if (colorType=="zeminGridColor"){
     //qDebug()<<"sekilZeminColor"<<color;
     kw->zeminGridColor=color;
     kalemModeSignalSlot(Scene::Mode::ZeminMode,kw->pagePattern);
    // emit kalemModeSignal(Scene::Mode::ZeminMode,pagePattern);

    }
  if (colorType=="zeminColor"){
     //qDebug()<<"zeminColor"<<color;
     kw->zeminColor=color;
     kalemZeminModeSignalSlot(DiagramItem::DiagramType::CustomColorPage);
   }
  if (colorType=="zeminDolguColor"){
     //qDebug()<<"zeminDolguColor"<<color;
     kw->zeminDolguColor=color;
     current_toolTahta->scene->myzeminDolguColor=color;
   }
}


MainWindow::~MainWindow()
{

}

void MainWindow::slotTimer()
{
  // timer->stop();
 //  scene->setSceneRect(0,0, gv->width() - 20,gv->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
   // timer->start(100);
    QWidget::resizeEvent(event);
}

