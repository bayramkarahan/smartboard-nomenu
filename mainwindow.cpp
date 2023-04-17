#include "mainwindow.h"
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
  this->setFixedSize(300,600);

    setWindowFlags(Qt::WindowStaysOnTopHint);
   // setWindowFlags(Qt::X11BypassWindowManagerHint);
   // setAttribute(Qt::WA_StaticContents);
   //setAttribute(Qt::WA_TranslucentBackground, true);

    screenSize = qApp->screens()[0]->size();
    boy=(screenSize.height()/100)*5.70;
    en=boy;
    //qDebug()<<"ekran boyutu:"<<screenSize;
    current_toolTahta=new toolTahta(screenSize.width()*0.6,screenSize.height()*0.6);
    current_toolTahta->move(screenSize.width()/2-current_toolTahta->width()/2,0);
    current_toolTahta->show();

    QGridLayout *mainlayout = new QGridLayout();
   mainlayout->setAlignment(Qt::AlignCenter);
   mainlayout->setRowStretch(2,1);
   mainlayout->setColumnStretch(2,1);

 /******************************************************************************/
   kw=new toolKalem("Kalem",en*1/3*2-2,boy*0.8);
   kw->setFixedSize(en*2-1,boy*0.8*19.7);
   kw->move(screenSize.width()-en*1-10-en,screenSize.height()/2- kw->height()/2);
   kw->setStyleSheet("background-color:rgb(220, 220, 220);");
   kw->setWindowFlags(Qt::X11BypassWindowManagerHint);
   kw->show();
   connect(kw, SIGNAL(kalemModeSignal(Scene::Mode,DiagramItem::DiagramType)),
           this, SLOT(kalemModeSignalSlot(Scene::Mode,DiagramItem::DiagramType)));

   connect(kw, SIGNAL(kalemColorSignal(QString,QColor)),
           this, SLOT(kalemColorSignalSlot(QString,QColor)));

   connect(kw, SIGNAL(kalemPenModeSignal(DiagramItem::DiagramType)),
           this, SLOT(kalemPenModeSignalSlot(DiagramItem::DiagramType)));

   connect(kw, SIGNAL(kalemZeminModeSignal(DiagramItem::DiagramType)),
           this, SLOT(kalemZeminModeSignalSlot(DiagramItem::DiagramType)));

   connect(kw, SIGNAL(kalemSekilModeSignal(DiagramItem::DiagramType)),
           this, SLOT(kalemSekilModeSignalSlot(DiagramItem::DiagramType)));
   /********************************************/
   slotPenInit();
   /***********************************************/

}
void MainWindow::kalemModeSignalSlot(Scene::Mode mode,DiagramItem::DiagramType type)
{
    // qDebug()<<"kalem mode:"<<mode<<type;
    kw->oldMode=kw->currentMode;
    kw->currentMode=mode;

    kw->oldType=kw->currentType;
    kw->currentType=type;
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
    if(Scene::Mode::DrawPen==mode)
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
        current_toolTahta->penDrawingMain=false;
        current_toolTahta->gv->show();
        current_toolTahta->gv->setEnabled(true);

        QPalette palet;
        palet.setBrush(QPalette::Background,QColor(0,0,0,0));
        current_toolTahta->setPalette(palet);

    }

    if(Scene::Mode::DrawPen==mode) kalemPenModeSignalSlot(type);
    if(Scene::Mode::SekilMode==mode) kalemSekilModeSignalSlot(type);
    if(Scene::Mode::ZeminMode==mode) kalemZeminModeSignalSlot(type);
    if(Scene::Mode::SelectObject==mode) slotHand();
    if(Scene::Mode::EraseMode==mode) slotErase();
    if(Scene::Mode::ClearMode==mode) slotClear();
    if(Scene::Mode::CopyMode==mode) slotCopy();
     /* if(Scene::Mode::NextPageMode==mode) {
        on_nextPage_triggered();
        }
    if(Scene::Mode::BackPageMode==mode){
        on_previousPage_triggered();
     }
    if(Scene::Mode::ZoomPozitifMode==mode){
        PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
            const QRectF pageRect = page->boundingRect().translated(page->pos());
        //qDebug()<<"1. ölçek:"<<pageRect.height();

        on_zoomIn_triggered();
        const QRectF pageRect1 = page->boundingRect().translated(page->pos());
        //qDebug()<<"2. ölçek:"<<pageRect1.height();
        // qDebug()<<"ölçek:"<<pageRect1.height()/pageRect.height();
        slotScaleSceneItem(pageRect1.width()/pageRect.width(),pageRect1.height()/pageRect.height());
      // kw->handButtonSlot();
    }
    if(Scene::Mode::ZoomNegatifMode==mode) {


        PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
            const QRectF pageRect = page->boundingRect().translated(page->pos());
        //qDebug()<<"1. ölçek:"<<pageRect.height();

         on_zoomOut_triggered();
        const QRectF pageRect1 = page->boundingRect().translated(page->pos());
        //qDebug()<<"2. ölçek:"<<pageRect1.height();
         //qDebug()<<"ölçek:"<<pageRect1.height()/pageRect.height();
        slotScaleSceneItem(pageRect1.width()/pageRect.width(),pageRect1.height()/pageRect.height());


    }
    if(Scene::Mode::ZoomSelectionMode==mode) {
        currentTab()->scene->sceneMode=Scene::Mode::ZoomSelectionMode;
        PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
        const QRectF pageRect = page->boundingRect().translated(page->pos());

        //currentTab()->setContinuousMode(false);     //sayfalar birleşik gözükmeyecek
       // currentTab()->setLayoutMode(SinglePageMode);//Tek sayfa gösterme ayarlandı
         on_fitToPageSizeMode_triggered(true);

        const QRectF pageRect1 = page->boundingRect().translated(page->pos());
        slotScaleSceneItem(pageRect1.width()/pageRect.width(),pageRect1.height()/pageRect.height());

      //  PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
        page->zoomSelectMode=true;
        on_copyToClipboardMode_triggered(true);
        foreach(QGraphicsItem* item, currentTab()->scene->items()){
            VERectangle * selection = dynamic_cast<VERectangle *>(item);
            if(selection)
            {
                if(selection->sekilTr==DiagramItem::DiagramType::PatternPage){
                    // qDebug()<<"arka plan";
                    if(currentTab()->currentPage()-1==selection->pageOfNumber)
                        selection->setVisible(false);
                    update();
                }
            }
        }
    }
    if(Scene::Mode::FitWindowMode==mode){


         PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
         const QRectF pageRect = page->boundingRect().translated(page->pos());

         //currentTab()->setContinuousMode(false);     //sayfalar birleşik gözükmeyecek
        // currentTab()->setLayoutMode(SinglePageMode);//Tek sayfa gösterme ayarlandı
          on_fitToPageSizeMode_triggered(true);

         const QRectF pageRect1 = page->boundingRect().translated(page->pos());
         slotScaleSceneItem(pageRect1.width()/pageRect.width(),pageRect1.height()/pageRect.height());
//currentTab()->scene->update();

    }
    if(Scene::Mode::FitPageMode==mode){

       PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
       const QRectF pageRect = page->boundingRect().translated(page->pos());

      // currentTab()->setContinuousMode(false);     //sayfalar birleşik gözükmeyecek
      // currentTab()->setLayoutMode(SinglePageMode);//Tek sayfa gösterme ayarlandı
      on_fitToPageWidthMode_triggered(true);

       const QRectF pageRect1 = page->boundingRect().translated(page->pos());
       slotScaleSceneItem(pageRect1.width()/pageRect.width(),pageRect1.height()/pageRect.height());
        ///currentTab()->scene->update();
       // qDebug()<<"aaaaa";
      // kalemModeSignalSlot(Scene::Mode::NoMode,DiagramItem::DiagramType::NoType);
      // kw->buttonStateClear();
      // kw->handButton->setChecked(true);
       currentTab()->scene->update();
       page->update();

     }
    if(Scene::Mode::IleriAlMode==mode){
      // qDebug()<<"ileri al";
      Scene::Mode tempmode=currentTab()->scene->sceneMode;
      currentTab()->scene->setMode(Scene::Mode::IleriAlMode, DiagramItem::DiagramType::NoType);
      sceneItemAddedSignalSlot();
     currentTab()->scene->sceneMode=tempmode;

     }
    if(Scene::Mode::GeriAlMode==mode){
         // qDebug()<<"geri al";
        Scene::Mode tempmode=currentTab()->scene->sceneMode;
        currentTab()->scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
        sceneItemAddedSignalSlot();
        currentTab()->scene->sceneMode=tempmode;
      }
    if(Scene::Mode::JumpPageMode==mode) slotJumpPage();
    if(Scene::Mode::SaveMode==mode) on_saveAs_triggered();
    if(Scene::Mode::PrintMode==mode) on_print_triggered();
    if(Scene::Mode::ListMode==mode) {
        if(m_thumbnailsDock->isVisible())
             m_thumbnailsDock->hide();
        else
                m_thumbnailsDock->show();

    }
    if(Scene::Mode::SearchMode==mode) {
   /* if(m_searchDock->isVisible())
         m_searchDock->hide();
    else
            m_searchDock->show();

       slotSearch();
    }
*/
    if(Scene::Mode::PanelSideLeftRight==mode) {
        if (kw->panelSide=="Right"){
       //    addToolBar(Qt::LeftToolBarArea, kw);
            kw->panelSide="Left";
            return;
        }
        if (kw->panelSide=="Left"){
   //        addToolBar(Qt::RightToolBarArea, kw);
            kw->panelSide="Right";
            return;
        }

        if (kw->panelSide=="Bottom"||kw->panelSide=="Top"){
        //    addToolBar(Qt::RightToolBarArea, kw);
            kw->panelSide="Right";
            return;
        }
       // qDebug()<<"sağsol hizala";
       // kw->setOrientation(Qt::Vertical);//Qt::Vertical Horizontal
       // addToolBar(Qt::RightToolBarArea, kw);
        //kw->setAllowedAreas(Qt::RightToolBarArea);

    }
    if(Scene::Mode::PanelSideBottom==mode) {
        if (kw->panelSide=="Left"||kw->panelSide=="Right"){
         //  addToolBar(Qt::BottomToolBarArea, kw);
           kw->panelSide="Bottom";
           return;
        }
        if (kw->panelSide=="Bottom"){
          //  addToolBar(Qt::TopToolBarArea, kw);
            kw->panelSide="Top";
            return;
        }
        if (kw->panelSide=="Top"){
          //  addToolBar(Qt::BottomToolBarArea, kw);
            kw->panelSide="Bottom";
            return;
        }
          // qDebug()<<"aşağı hizala";
          // addToolBar(Qt::LeftToolBarArea, kw);
         //kw->setAllowedAreas(Qt::LeftToolBarArea);
    }
    if(Scene::Mode::ExitMode==mode){
     //   QMainWindow::close();
        exit(0);
       }
    slotScaleSceneItem(1,1);
  //  kw->pageOfNumber->setText(QString::number(currentTab()->currentPage())+"/"+
    //                         QString::number(currentTab()->numberOfPages()));

 if(Scene::Mode::ZoomSelectionMode!=mode||
         Scene::Mode::SekilMode!=mode)
     kw->modeKontrolSlot();
}
void MainWindow::slotErase()
{

   current_toolTahta->scene->setEraseSize(kw->penSize*2);
   current_toolTahta->scene->sceneMode=Scene::Mode::EraseMode;
   current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::NoType;

}
void MainWindow::slotClear()
{
   /*scene->pageOfNumberScene=currentTab()->currentPage()-1;
    PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
    const QRectF pageItemRect = page->boundingRect().translated(page->pos());
    currentTab()->scene->pageItemRect=pageItemRect;
*/
  current_toolTahta->scene->sceneMode=Scene::Mode::ClearMode;
  current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::NoType;
  current_toolTahta->scene->removeAllItem();
///qDebug()<<"sil*****";

}
void MainWindow::slotCopy()
{
    /*
    currentTab()->scene->sceneMode=Scene::Mode::CopyMode;
    PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
    page->copyMode=true;
    on_copyToClipboardMode_triggered(true);
    foreach(QGraphicsItem* item, currentTab()->scene->items()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);
        if(selection)
        {
            if(selection->sekilTr==DiagramItem::DiagramType::PatternPage){
                // qDebug()<<"arka plan";
                if(currentTab()->currentPage()-1==selection->pageOfNumber)
                    selection->setVisible(false);
                update();
            }
        }
    }
    */
    qDebug()<<"copy çalıştı";
}
void MainWindow::slotScaleSceneItem(double sizex,double sizey)
{/*
    foreach(QGraphicsItem* item, currentTab()->scene->items()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);
        if(selection)
        {
            if(selection->sekilTr!=0){
              //  PageItem* page =currentTab()->m_pageItems.at((selection->pageOfNumber));
                //const QRectF pageRect = page->boundingRect().translated(page->pos());

                //qDebug()<<"currentpage:"<<currentTab()->currentPage()-1<<selection->pageOfNumber;
                ///if(currentTab()->currentPage()-1==selection->pageOfNumber)
              ///      selection->setVisible(true);
               /// else selection->setVisible(false);
                // qDebug()<<"render param:"<<page->m_renderParam.resolutionX() * page->m_renderParam.scaleFactor() / 72.0;
                selection->setRect(0,0,selection->rect().width()*sizex,selection->rect().height()*sizey);
                selection->setPos(selection->pos().x()*sizex,selection->pos().y()*sizey);
            }

            if(selection->sekilTr!=0&&

             selection->pageOfNumber==currentTab()->scene->pageOfNumberScene&&
             selection->sekilTr==DiagramItem::DiagramType::PatternPage){
             PageItem* page =currentTab()->m_pageItems.at((selection->pageOfNumber));
             const QRectF pageItemRect = page->boundingRect().translated(page->pos());

            /// selection->setImage(currentTab()->scene->myImage);
             selection->setRect(0,0,pageItemRect.width(),pageItemRect.height());
             selection->setPos(pageItemRect.left(),pageItemRect.top());

             selection->update();
             }
        }
     }

currentTab()->update();
*/
}
void MainWindow::slotHand()
{
   // qDebug()<<"hand";

  current_toolTahta->scene->sceneMode=Scene::Mode::SelectObject;
  current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::NoType;
  /*  setDragMode(QGraphicsView::ScrollHandDrag);
  scene->pageOfNumberScene=currentTab()->currentPage()-1;
  PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
   const QRectF pageItemRect = page->boundingRect().translated(page->pos());
   currentTab()->scene->pageItemRect=pageItemRect;
*/
   foreach(QGraphicsItem* item, current_toolTahta->scene->items()){
       VERectangle * selection = dynamic_cast<VERectangle *>(item);
       if(selection)
       {
           if(selection->sekilTr==DiagramItem::DiagramType::PatternPage){
              // qDebug()<<"arka plan";
              /* if(currentTab()->currentPage()-1==selection->pageOfNumber)
                selection->setVisible(false);
                */update();
              }
       }
    }
//    tvl->hide();

}
void MainWindow::slotPenInit()
{     current_toolTahta->scene->setPenSize(kw->penSize);
      current_toolTahta->scene->setPenAlpha(kw->penAlpha);
     current_toolTahta->scene->setPenColor(kw->penColor);
      current_toolTahta->scene->setPenStyle(kw->penStyle);

      current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::NoType;
      current_toolTahta->scene->setSekilKalemColor(kw->penColor);
      current_toolTahta->scene->mySekilPenStyle=kw->penStyle;
       kw->sekilZeminColor=QColor(255,255,255,0);
     current_toolTahta->scene->setSekilZeminColor(kw->sekilZeminColor);
       current_toolTahta->scene->setSekilPenSize(kw->penSize);

       current_toolTahta->scene->sceneGridYatay=false;
      current_toolTahta->scene->sceneGridDikey=false;
      current_toolTahta->scene->sceneGuzelYazi=false;
       current_toolTahta->scene->setSekilTanimlamaStatus(false);
     current_toolTahta->scene->pageOfNumberScene=0;
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
       kalemZeminModeSignalSlot(DiagramItem::DiagramType::TransparanPage);
     current_toolTahta->scene->makeItemsControllable(false);

       connect(current_toolTahta->scene, SIGNAL(sceneItemAddedSignal()),
       this,SLOT(sceneItemAddedSignalSlot()));
       sceneItemAddedSignalSlot();
       kw->handButtonSlot();
       //kalemPenModeSignalSlot(DiagramItem::DiagramType::NormalPen);



}
void  MainWindow::kalemPenModeSignalSlot(DiagramItem::DiagramType type)
{

    //current_toolTahta->penTuval.
   // qDebug()<<"pen mode:"<<type;
   /* currentTab()->scene->pageOfNumberScene=currentTab()->currentPage()-1;
    */
   /// PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
   /// const QRectF pageItemRect = page->boundingRect().translated(page->pos());
   // currentTab()->scene->pageItemRect=pageItemRect;
    //if(DiagramItem::DiagramType::SolidLine==type)  currentTab()->scene->setSekilPenStyle(Qt::SolidLine);
    //else if(DiagramItem::DiagramType::DashLine==type)  currentTab()->scene->setSekilPenStyle(Qt::DashLine);
   // else if(DiagramItem::DiagramType::DotLine==type)  currentTab()->scene->setSekilPenStyle(Qt::DotLine);

    if(DiagramItem::DiagramType::SolidLine==type){
        current_toolTahta->scene->setSekilPenStyle(Qt::SolidLine);
        current_toolTahta->scene->setPenStyle(Qt::SolidLine);
    }
    if(DiagramItem::DiagramType::DashLine==type){
       current_toolTahta->scene->setPenStyle(Qt::DashLine);
        current_toolTahta->scene->setSekilPenStyle(Qt::DashLine);
    }
    if(DiagramItem::DiagramType::DotLine==type){
        current_toolTahta->scene->setPenStyle(Qt::DotLine);
       current_toolTahta-> scene->setSekilPenStyle(Qt::DotLine);
    }

    if(DiagramItem::DiagramType::PenSize2==type){kw->penSize=2; current_toolTahta->scene->setPenSize(kw->penSize);}
    if(DiagramItem::DiagramType::PenSize4==type){kw->penSize=4; current_toolTahta->scene->setPenSize(kw->penSize);}
    if(DiagramItem::DiagramType::PenSize6==type){kw->penSize=6; current_toolTahta->scene->setPenSize(kw->penSize);}
    if(DiagramItem::DiagramType::PenSize8==type){kw->penSize=8; current_toolTahta->scene->setPenSize(kw->penSize);}
    if(DiagramItem::DiagramType::PenSize10==type){kw->penSize=10; current_toolTahta->scene->setPenSize(kw->penSize);}
    if(DiagramItem::DiagramType::PenSize12==type){kw->penSize=12; current_toolTahta->scene->setPenSize(kw->penSize);}
    if(DiagramItem::DiagramType::PenSize14==type){kw->penSize=14; current_toolTahta->scene->setPenSize(kw->penSize);}


    if(DiagramItem::DiagramType::NormalPen==type){
       current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
        current_toolTahta->scene->setSekilTanimlamaStatus(false);
    }
    if(DiagramItem::DiagramType::SmartPen==type){
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
       current_toolTahta->scene->setSekilTanimlamaStatus(true);
    }
    if(DiagramItem::DiagramType::FosforluPen==type){
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawPenFosfor;
      current_toolTahta->scene->setSekilTanimlamaStatus(false);
         current_toolTahta->scene->setPenAlpha(50);

    }

}
void MainWindow::kalemZeminModeSignalSlot(DiagramItem::DiagramType type)
{

//qDebug()<<"zemin mode:"<<type<<kw->penSize;
  /* current_toolTahta->scene->pageOfNumberScene=currentTab()->currentPage()-1;
    PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
    const QRectF pageItemRect = page->boundingRect().translated(page->pos());
    current_toolTahta->scene->pageItemRect=pageItemRect;
   */
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
    kw->pagePattern=type;
    kw->sekilZeminColor=QColor(0,0,0,0);
    current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
    current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*10,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi,kw->sekilZeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
   current_toolTahta->scene->myImage= bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);

  }
if(DiagramItem::DiagramType::BlackPage==type){
    kw->pagePattern=type;
    kw->sekilZeminColor=QColor(0,0,0,255);

  current_toolTahta->scene->sceneGridYatay=false;
    current_toolTahta->scene->sceneGridDikey=false;
   current_toolTahta->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*10,current_toolTahta->scene->sceneGridYatay,current_toolTahta->scene->sceneGridDikey,current_toolTahta->scene->sceneGuzelYazi, kw->sekilZeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
   current_toolTahta->scene->myImage=bkgnd;
  //  currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
    kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);
  }
/*
if(DiagramItem::DiagramType::WhitePage==type){
    kw->pagePattern=type;
    kw->sekilZeminColor=QColor(255,255,255,255);
    currentTab()->scene->sceneGridYatay=false;
    currentTab()->scene->sceneGridDikey=false;
    currentTab()->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,currentTab()->scene->sceneGridYatay,currentTab()->scene->sceneGridDikey,currentTab()->scene->sceneGuzelYazi,kw->sekilZeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    currentTab()->scene->myImage=bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
    kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);

 }
if(DiagramItem::DiagramType::CustomColorPage==type){
    kw->pagePattern=type;
    currentTab()->scene->sceneGridYatay=false;
    currentTab()->scene->sceneGridDikey=false;
    currentTab()->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*10,currentTab()->scene->sceneGridYatay,currentTab()->scene->sceneGridDikey,currentTab()->scene->sceneGuzelYazi,kw->sekilZeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    currentTab()->scene->myImage=bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
    kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);

}
if(DiagramItem::DiagramType::CizgiliPage==type){
    kw->pagePattern=type;
    currentTab()->scene->sceneGridYatay=true;
    currentTab()->scene->sceneGridDikey=false;
    currentTab()->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,currentTab()->scene->sceneGridYatay,currentTab()->scene->sceneGridDikey,currentTab()->scene->sceneGuzelYazi,kw->sekilZeminColor, kw->zeminGridColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    currentTab()->scene->myImage=bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
    kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);

  }
if(DiagramItem::DiagramType::KareliPage==type){
    kw->pagePattern=type;
    currentTab()->scene->sceneGridYatay=true;
    currentTab()->scene->sceneGridDikey=true;
    currentTab()->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,currentTab()->scene->sceneGridYatay,currentTab()->scene->sceneGridDikey,currentTab()->scene->sceneGuzelYazi,kw->sekilZeminColor, kw->zeminGridColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    currentTab()->scene->myImage=bkgnd;
   // currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
    kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);

  }
if(DiagramItem::DiagramType::MuzikPage==type){
    kw->pagePattern=type;
    currentTab()->scene->sceneGridYatay=true;
    currentTab()->scene->sceneGridDikey=false;
    currentTab()->scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    DiagramItem *ditem=new DiagramItem();
    QPixmap pim(kw->zeminImage(ditem->sekilStore(DiagramItem::DiagramType::Muzik,QRectF(QPointF(0,0),QPointF(screenSize.width(),screenSize.height()))),screenSize.width(),screenSize.height(),kw->zeminGridColor,2));
    currentTab()->scene->myImage=pim;
    //currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
    kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);

  }
if(DiagramItem::DiagramType::GuzelYaziPage==type){
    kw->pagePattern=type;
    currentTab()->scene->sceneGridYatay=false;
    currentTab()->scene->sceneGridDikey=false;
    currentTab()->scene->sceneGuzelYazi=true;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    QSize screenSize = qApp->screens()[0]->size();
    GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,currentTab()->scene->sceneGridYatay,currentTab()->scene->sceneGridDikey,currentTab()->scene->sceneGuzelYazi,kw->sekilZeminColor, kw->penColor);
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    currentTab()->scene->myImage=bkgnd;
    //currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);
    kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);

  }

if(DiagramItem::DiagramType::CustomImagePage==type)
{ kw->pagePattern=type;

   /* Qt::WindowFlags flags = 0;
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
    // */
/*QFileDialog abc;
   // abc.setWindowFlags(flags);
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

               /* currentTab()->scene->sceneGridYatay=false;
                currentTab()->scene->sceneGridDikey=false;
                currentTab()->scene->sceneGuzelYazi=true;
                ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
                //QSize screenSize = qApp->screens()[0]->size();
                //GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,currentTab()->scene->sceneGridYatay,currentTab()->scene->sceneGridDikey,currentTab()->scene->sceneGuzelYazi,kw->sekilZeminColor, kw->penColor);
               */// QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
              /*  currentTab()->scene->myImage=image;
                //currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);

               // currentTab()->scene->setImage(image);
                 //currentTab()->scene->donSlot(type);


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

                /*currentTab()->scene->sceneGridYatay=false;
                currentTab()->scene->sceneGridDikey=false;
                currentTab()->scene->sceneGuzelYazi=true;
                ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
                QSize screenSize = qApp->screens()[0]->size();
                //GridLines *gridLines = new GridLines (screenSize.width(), screenSize.height(),kw->gridSize*3.4,currentTab()->scene->sceneGridYatay,currentTab()->scene->sceneGridDikey,currentTab()->scene->sceneGuzelYazi,kw->sekilZeminColor, kw->penColor);
               */// QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
           ///     currentTab()->scene->myImage=image;
                //currentTab()->scene->donSlot(DiagramItem::DiagramType::PatternPage);

               // currentTab()->scene->setImage(image);
                // currentTab()->scene->donSlot(type);

         /*   }
        }

    }*/

   /* flags |= Qt::Window;
    flags |= Qt::X11BypassWindowManagerHint;
    flags |= Qt::WindowStaysOnTopHint;
    this->setWindowFlags(flags);
    show();*/
   // currentTab()->scene->mySekilType=type;

  /*  kalemModeSignalSlot(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    kw->buttonStateClear();
    kw->penButton->setChecked(true);

}

bool pageadd=false;
foreach(QGraphicsItem* item, currentTab()->scene->items()){
         VERectangle * selection = dynamic_cast<VERectangle *>(item);
          if(selection)
         {
            if(selection->sekilTr!=0&&
             selection->pageOfNumber==currentTab()->scene->pageOfNumberScene&&
             selection->sekilTr==DiagramItem::DiagramType::PatternPage){

             pageadd=true;
             selection->setImage(currentTab()->scene->myImage);
           //  qDebug()<<"zemin..x";
             selection->setRect(0,0,pageItemRect.width(),pageItemRect.height());
             selection->setPos(pageItemRect.left(),pageItemRect.top());

             selection->update();
             }
         }
     }

if(!pageadd)

{
    // qDebug()<<"zemin..0";
   VERectangle *zeminItem = new VERectangle(currentTab()->scene);
   zeminItem->setPen(QPen(currentTab()->scene->mySekilKalemColor, kw->penSize, currentTab()->scene->mySekilPenStyle));

   zeminItem->sekilTur(DiagramItem::DiagramType::PatternPage);
   zeminItem->setImage(currentTab()->scene->myImage);
   currentTab()->scene->addItem(zeminItem);
   zeminItem->pageOfNumber=currentTab()->scene->pageOfNumberScene;
   currentTab()->scene->graphicsList.append(zeminItem);
   currentTab()->scene->graphicsListTemp.append(zeminItem);
   currentTab()->scene->historyBack.append(zeminItem);
   currentTab()->scene->historyBackAction.append("added");
   zeminItem->setRect(0,0,pageItemRect.width(),pageItemRect.height());
   zeminItem->setPos(pageItemRect.left(),pageItemRect.top());
  // zeminItem->setSelected(false);
}

*/

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
        Qt::WindowFlags flags = 0;
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
        this->setWindowFlags(flags);
        show();
      current_toolTahta->scene->mySekilType=type;
    }

    else current_toolTahta->scene->mySekilType=type;

//qDebug()<<"buraya geldinn..";
//kw->modeKontrolSlot();

}
void MainWindow::kalemColorSignalSlot(QString colorType, QColor color)
{
 // qDebug()<<"colorsignal slot"<<colorType<<color;
 //  current_toolTahta->scene->pageOfNumberScene=currentTab()->currentPage()-1;
   /* PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
    const QRectF pageItemRect = page->boundingRect().translated(page->pos());
    currentTab()->scene->pageItemRect=pageItemRect;
*/
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
     //currentTab()->scene->setSekilZeminColor(kw->sekilZeminColor);
   }

   /*if(colorType=="pencolor") setPenColor(renk);
   if(colorType=="mySekilKalemColor")  mySekilKalemColor=renk;
   if(colorType=="mySekilZeminColor")  mySekilZeminColor=renk;
   if(colorType=="myZeminColor")  myZeminColor=renk;
   if(colorType=="myGridColor")  myGridColor=renk;
   */

}
void MainWindow::mainClipBoard(QPoint pos,bool copy,bool zoom)
{
/*
    if(copy) selectCopySlot(pos);///Kopyalama
    if(zoom) selectZoomSlot(pos);

  //  qDebug()<<"mainClipBoard gerçekleşti";
   // copyWidget();

*/
}
void MainWindow::selectCopySlot(QPoint pos)
{
   /* const QClipboard *cb = QApplication::clipboard();
    const QMimeData *md = cb->mimeData();
    QImage img;
    if (md->hasImage())
    {
        img=QImage(cb->image());
       //  logo->setPixmap(QPixmap::fromImage(img).scaled(400,300,Qt::IgnoreAspectRatio));
    }
    else if(md->formats().contains(QStringLiteral("text/uri-list")))
    {
       img=QImage(QUrl(cb->text()).toLocalFile());

    }

    // logo->setPixmap(QPixmap::fromImage(img).scaled(400,300,Qt::IgnoreAspectRatio));
    currentTab()->scene->sceneMode=Scene::Mode::CopyMode;
    tempCopyModeItemToRectDraw=new VERectangle(currentTab()->scene);
    tempCopyModeItemToRectDraw->sekilTur(DiagramItem::DiagramType::Copy);
    QPixmap temp=QPixmap::fromImage(img).scaled(img.width(),img.height(),Qt::IgnoreAspectRatio);

    tempCopyModeItemToRectDraw->setImage(temp);
    currentTab()->scene->addItem(tempCopyModeItemToRectDraw);
    tempCopyModeItemToRectDraw->setRect(0,0,temp.width(),temp.height());

    tempCopyModeItemToRectDraw->pageOfNumber=currentTab()->currentPage()-1;
    PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
        const QRectF pageRect = page->boundingRect().translated(page->pos());
    //tempCopyModeItemToRectDraw->setPos(pageRect.left(),pageRect.top()+pageRect.height()/3);
    tempCopyModeItemToRectDraw->setPos(pageRect.left()+pageRect.width()/2-temp.width()/2,pageRect.top()+pageRect.height()/2-temp.height()/2);

    tempCopyModeItemToRectDraw->fareState(false);
    currentTab()->scene->makeItemsControllable(false);
    tempCopyModeItemToRectDraw->fareState(true);
    tempCopyModeItemToRectDraw->sekilTr=DiagramItem::DiagramType::Copy;

   // currentTab()->scene->sceneMode=Scene::Mode::SelectObject;
    currentTab()->scene->graphicsList.append(tempCopyModeItemToRectDraw);
    currentTab()->scene->graphicsListTemp.append(tempCopyModeItemToRectDraw);
    currentTab()->scene->historyBack.append(tempCopyModeItemToRectDraw);
    currentTab()->scene->historyBackAction.append("added");
    depo::historyBackCount=currentTab()->scene->historyBack.count();
    depo::historyNextCount=currentTab()->scene->historyNext.count();

    tempCopyModeItemToRectDraw=0;
   // kalemModeSignalSlot(Scene::Mode::NoMode,DiagramItem::DiagramType::NoType);
   // kw->buttonStateClear();
    //kw->handButton->setChecked(true);
    currentTab()->scene->update();
    page->update();
    kw->handButtonSlot();
    */
}
void MainWindow::selectZoomSlot(QPoint pos)
{
 /*   const QClipboard *cb = QApplication::clipboard();
    const QMimeData *md = cb->mimeData();
    QImage img;
    if (md->hasImage())
    {
        img=QImage(cb->image());
       //  logo->setPixmap(QPixmap::fromImage(img).scaled(400,300,Qt::IgnoreAspectRatio));
    }
    else if(md->formats().contains(QStringLiteral("text/uri-list")))
    {
       img=QImage(QUrl(cb->text()).toLocalFile());

    }

    // logo->setPixmap(QPixmap::fromImage(img).scaled(400,300,Qt::IgnoreAspectRatio));
    ///currentTab()->scene->sceneMode=Scene::Mode::CopyMode;
    ///tempCopyModeItemToRectDraw=new VERectangle(currentTab()->scene);
   /// tempCopyModeItemToRectDraw->sekilTur(DiagramItem::DiagramType::Copy);
    QPixmap temp=QPixmap::fromImage(img).scaled(img.width(),img.height(),Qt::IgnoreAspectRatio);
   // QLabel *logo=new QLabel();
   // logo->setPixmap(temp);
    //logo->show();


   /// tempCopyModeItemToRectDraw->setImage(temp);
   /// currentTab()->scene->addItem(tempCopyModeItemToRectDraw);
   /// tempCopyModeItemToRectDraw->setRect(0,0,temp.width(),temp.height());

   /// tempCopyModeItemToRectDraw->pageOfNumber=currentTab()->currentPage()-1;
  ////  PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
  ////  const QRectF pageRect = page->boundingRect().translated(page->pos());
 ////   qDebug()<<pageRect<<pageRect.left()<<pageRect.top();

    //tempCopyModeItemToRectDraw->setPos(pageRect.left(),pageRect.top()+pageRect.height()/3);
   /// tempCopyModeItemToRectDraw->setPos(pageRect.left()+pageRect.width()/2-temp.width()/2,pageRect.top()+pageRect.height()/2-temp.height()/2);
   // on_zoomIn_triggered();
   /// page->setPos(pageRect.left()-50,pageRect.top());
 /// on_fitToPageSizeMode_triggered(true);

     // currentTab()->on_pages_zoomToSelection(currentTab()->currentPage(),rt);
    PageItem* page =currentTab()->m_pageItems.at((currentTab()->currentPage()-1));
        const QRectF pageRect = page->boundingRect().translated(page->pos());
    //qDebug()<<"1. ölçek:"<<pageRect.height();
  // currentTab()->scene->sceneMode=Scene::Mode::DrawRectangle;
        VERectangle *gri= new VERectangle(currentTab()->scene);
        gri->sekilTur(DiagramItem::DiagramType::Dortgen);
        gri->setRect(0,0,temp.width(),temp.height());
        gri->setPos(pos.x()+pageRect.left(),pos.y());
       // gri->setPos(pos.x()+pageRect.left(),pos.y(),temp.width(),temp.height());
        currentTab()->scene->addItem(gri);
        gri->fareState(false);
        currentTab()->scene->makeItemsControllable(false);
        gri->fareState(true);
        currentTab()->scene->sceneMode=Scene::Mode::SelectObject;

        on_fitToPageWidthMode_triggered(true);
       // on_zoomIn_triggered();
        //on_zoomIn_triggered();
        if(m_tabWidget->hasCurrent())

        {

            bool ok = false;

            qreal scaleFactor =100 / 100.0;

            scaleFactor = qMax(scaleFactor, s_settings->documentView().minimumScaleFactor());
            scaleFactor = qMin(scaleFactor, s_settings->documentView().maximumScaleFactor());


                currentTab()->setScaleFactor(scaleFactor);
                currentTab()->setScaleMode(ScaleFactorMode);


            on_currentTab_scaleFactorChanged(currentTab()->scaleFactor());
            on_currentTab_scaleModeChanged(currentTab()->scaleMode());
        }*/
       // on_zoomIn_triggered();



  /*  const QRectF pageRect1 = page->boundingRect().translated(page->pos());
    //qDebug()<<"2. ölçek:"<<pageRect1.height();
    // qDebug()<<"ölçek:"<<pageRect1.height()/pageRect.height();
    qreal sx=pageRect1.width()/pageRect.width();
    qreal sy=pageRect1.height()/pageRect.height();
    slotScaleSceneItem(sx,sy);

    gri->fareState(true);

//
    QRectF rt=QRectF(gri->boundingRect());
  //  page->zoomToSelection(currentTab()->currentPage(),rt);
   qDebug()<<"point"<<gri->pos()<<gri->boundingRect().translated(gri->pos());
   qDebug()<<"page"<<page->pos()<<pageRect1<<pageRect1.height()/2;

   QPointF gripos=gri->boundingRect().translated(gri->pos()).center();
   QPointF pagepos=page->boundingRect().translated(page->pos()).center();
   qDebug()<<"fark"<<gripos.y()<<pagepos.y()<<pagepos.y()-gripos.y();

  // page->setPos(mapToGlobal(currentTab()->mapFromScene(gri->boundingRect().center())));
   if(gripos.y()>pageRect1.height()/4*3&&gripos.y()<pageRect1.height())
   {
       page->setPos(pageRect1.left(),pageRect1.top()-gripos.y());
       qDebug()<<"alt-alt";
   }

   if(gripos.y()>pageRect1.height()/2&&gripos.y()<pageRect1.height()/4*3)
   {
       page->setPos(pageRect1.left(),pageRect1.top()-gripos.y()/2);
       qDebug()<<"alt-ust";
   }


   if(gripos.y()>pageRect1.height()/4&&gripos.y()<pageRect1.height()/2)
   {
       page->setPos(pageRect1.left(),pageRect1.top()+gripos.y()/2);
       qDebug()<<"ust-alt";
   }
   if(gripos.y()<pageRect1.height()/4&&gripos.y()>pageRect1.top())
   {
       page->setPos(pageRect1.left(),page->boundingRect().top()+gripos.y()/2);
       qDebug()<<"ust-ust";
   }
    currentTab()->scene->removeItem(gri);

   // slotHand();
   // kalemModeSignalSlot(Scene::Mode::NoMode,DiagramItem::DiagramType::NoType);
   // kw->buttonStateClear();
   // kw->handButton->setChecked(true);
    currentTab()->scene->update();
    page->update();

    kw->modeKontrolSlot();
    */
}
void MainWindow::sceneItemAddedSignalSlot()
{
   //qDebug()<<"item eklendi";
  /* if(depo::historyBackCount>0)kw->undoButton->setEnabled(true);else kw->undoButton->setEnabled(false);
   if(depo::historyNextCount>0)kw->redoButton->setEnabled(true);else kw->redoButton->setEnabled(false);
*/
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

