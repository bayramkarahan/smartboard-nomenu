#include "mainwindow.h"
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(300,600);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    screenSize = qApp->screens()[0]->size();
    boy=(screenSize.height()/100)*5.70;
    en=boy;
    //qDebug()<<"ekran boyutu:"<<screenSize;
    current_toolTahta=new toolTahta(screenSize.width()*0.7,screenSize.height()*0.4);
    current_toolTahta->move(screenSize.width()/2-current_toolTahta->width()/2,screenSize.height()/2-current_toolTahta->height()*0.85);

    current_toolTahta=new toolTahta(screenSize.width(),screenSize.height());
    current_toolTahta->move(screenSize.width()/2-current_toolTahta->width()/2,screenSize.height()/2-current_toolTahta->height()/2);
    current_toolTahta->show();
    /***************************Top Menu**********************************************/
    current_toolKalemMenu=new toolKalemMenu(new QWidget(),screenSize.width()*0.8,screenSize.height()*0.05);
    /***************************Bottom Menu**********************************************/
    curent_pageMenu=new toolPageMenu(new QWidget(),screenSize.width()*0.85,screenSize.height()*0.045);
    //curent_pageMenu=new toolPageMenu(kw->pageBottomMenu(screenSize.height()*0.045),screenSize.width()*0.85,screenSize.height()*0.045);
    /******************************************************************************/
    kw=new toolKalem("Kalem",en*0.55,boy*0.7,current_toolTahta,current_toolKalemMenu,curent_pageMenu,screenSize.width(),screenSize.height());
    kw->setFixedSize(en*1.0,boy*0.75*11);
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
  /* connect(kw, SIGNAL(kalemModeSignal(Scene::Mode,DiagramItem::DiagramType)),
           kw, SLOT(kalemModeSignalSlot(Scene::Mode,DiagramItem::DiagramType)));
*/
   connect(kw, SIGNAL(kalemZeminModeSignal(DiagramItem::DiagramType)),
           kw, SLOT(kalemZeminModeSignalSlot(DiagramItem::DiagramType)));

   connect(kw, SIGNAL(kalemSekilModeSignal(DiagramItem::DiagramType)),
           kw, SLOT(kalemSekilModeSignalSlot(DiagramItem::DiagramType)));
    /**************************************************************************/
   connect(kw, SIGNAL(desktopSignal()),curent_pageMenu, SLOT(toolPageMenu_DesktopSignalSlot()));
   connect(kw, SIGNAL(penSignal()),curent_pageMenu, SLOT(toolPageMenu_PenSignalSlot()));
   curent_pageMenu->toolPageMenuOlustur(kw->pageBottomMenu(screenSize.height()*0.045),screenSize.width()*0.85,screenSize.height()*0.045,screenSize.width(),screenSize.height());
   curent_pageMenu->move(screenSize.width()/2-curent_pageMenu->width()/2,screenSize.height()-curent_pageMenu->height()*2.5);
   curent_pageMenu->show();

   /*******************ilk Açılış Hazırlığı****************************/
   //kw->penToScene();
   kw->ekleSayfaButtonClick(-1,false,-1);
   //kalemModeSignalSlot(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
   //kw->penButtonSlot();
   //kw->desktopButtonSlot();
   kw->raise();
   curent_pageMenu->raise();
   current_toolKalemMenu->raise();
   current_toolTahta->lower();


}


MainWindow::~MainWindow()
{

}


