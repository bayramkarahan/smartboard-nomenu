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
    qDebug()<<"ekran boyutu:"<<screenSize;
    //current_toolTahta=new toolTahta(screenSize.width()*0.7,screenSize.height()*0.4);
    current_toolTahta=new toolTahta(screenSize.width(),screenSize.height());
    current_toolTahta->move(screenSize.width()/2-current_toolTahta->width()/2,screenSize.height()/2-current_toolTahta->height()/2);
    current_toolTahta->lower();
    current_toolTahta->lower();
    current_toolTahta->lower();

    current_toolTahta->show();

    /***************************Top Menu**********************************************/
    //current_toolKalemMenu=new toolKalemMenu(kw->penTopMenu(screenSize.height()*0.05),screenSize.width()*0.8,screenSize.height()*0.05);
    //current_toolKalemMenu->move(screenSize.width()/2-current_toolKalemMenu->width()/2,0);
   // current_toolKalemMenu->show();
    current_toolKalemMenu=new toolKalemMenu(new QWidget(),screenSize.width()*0.8,screenSize.height()*0.05);


 /******************************************************************************/
   kw=new toolKalem("Kalem",en*1/3*2-2,boy*0.8,current_toolTahta,current_toolKalemMenu,screenSize.width(),screenSize.height());
   kw->setFixedSize(en*1.15,boy*0.8*13);
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
   connect(kw, SIGNAL(desktopSignal()),current_toolTahta, SLOT(toolTahta_DesktopSignalSlot()));
   connect(kw, SIGNAL(penSignal()),current_toolTahta, SLOT(toolTahta_PenSignalSlot()));

   connect(kw, SIGNAL(desktopSignal()), current_toolKalemMenu, SLOT(toolKalemMenu_DesktopSignalSlot()));
   connect(kw, SIGNAL(penSignal()),current_toolKalemMenu, SLOT(toolKalemMenu_PenSignalSlot()));

  /**************************************************************************/
   connect(kw, SIGNAL(kalemModeSignal(Scene::Mode,DiagramItem::DiagramType)),
           kw, SLOT(kalemModeSignalSlot(Scene::Mode,DiagramItem::DiagramType)));

   connect(kw, SIGNAL(kalemZeminModeSignal(DiagramItem::DiagramType)),
           kw, SLOT(kalemZeminModeSignalSlot(DiagramItem::DiagramType)));

   connect(kw, SIGNAL(kalemSekilModeSignal(DiagramItem::DiagramType)),
           kw, SLOT(kalemSekilModeSignalSlot(DiagramItem::DiagramType)));
   /********************************************/
  // slotPenInit();
      /***************************Bottom Menu**********************************************/
   curent_pageMenu=new toolPageMenu(kw->pageBottomMenu(screenSize.height()*0.045),screenSize.width()*0.85,screenSize.height()*0.045);
   curent_pageMenu->move(screenSize.width()/2-curent_pageMenu->width()/2,screenSize.height()-curent_pageMenu->height()*2.5);
   curent_pageMenu->show();
   /**************************************************************************/
   connect(kw, SIGNAL(desktopSignal()),
           curent_pageMenu, SLOT(toolPageMenu_DesktopSignalSlot()));
   connect(kw, SIGNAL(penSignal()),
           curent_pageMenu, SLOT(toolPageMenu_PenSignalSlot()));

   /*******************ilk Açılış Hazırlığı****************************/
   kw->ekleSayfaButtonClick(-1,false,-1);
   //kalemModeSignalSlot(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
   //kw->penButtonSlot();
   //kw->desktopButtonSlot();
   kw->raise();kw->raise();
   curent_pageMenu->raise();curent_pageMenu->raise();
   current_toolKalemMenu->raise();current_toolKalemMenu->raise();


}

/*
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
      qDebug()<<"seffaf zemin"<<current_toolTahta->scene->sceneMode;
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
 /* }
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
        if(selection->sekilTr!=0&&selection->sekilTr==DiagramItem::DiagramType::PatternPage){
            current_toolTahta->scene->removeItem(selection);
        }
    }
}
    // qDebug()<<"zemin..0";
   VERectangle *zeminItem = new VERectangle(current_toolTahta->scene);
   zeminItem->setPen(QPen(current_toolTahta->scene->mySekilKalemColor, kw->penSize, current_toolTahta->scene->mySekilPenStyle));
   zeminItem->sekilTur(DiagramItem::DiagramType::PatternPage);
   zeminItem->setImage(current_toolTahta->scene->myImage);
   current_toolTahta->scene->addItem(zeminItem);
   current_toolTahta->scene->graphicsList.append(zeminItem);
   current_toolTahta->scene->graphicsListTemp.append(zeminItem);
   current_toolTahta->scene->historyBack.append(zeminItem);
   current_toolTahta->scene->historyBackAction.append("added");
   zeminItem->setRect(0,0,current_toolTahta->width(),current_toolTahta->height());
   zeminItem->setPos(0,0);
   zeminItem->setZValue(-200);
  // zeminItem->setSelected(false);
   zeminItem->fareState(false);
   //current_toolTahta->scene->makeItemsControllable(false);
//}
kw->secSayfaButtonClick(current_toolTahta->current_sceneIndex);

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
///}
/*
void MainWindow::kalemSekilModeSignalSlot(DiagramItem::DiagramType type){
   // qDebug()<<"sekil butonclick"<<type;
    kw->sekilButtonIconSlot(type);//şekil buton iconu ayarlanıyor
    current_toolTahta->scene->setSekilPenSize(kw->penSize);
    current_toolTahta->scene->setSekilKalemColor(kw->penColor);
    current_toolTahta->scene->setSekilZeminColor(kw->sekilZeminColor);
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawRectangle;


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

}
*/
MainWindow::~MainWindow()
{

}


