#include<QDebug>
#include<QMouseEvent>
#include<QToolButton>
#include<QAction>
#include<QMenu>
#include<QGridLayout>
#include "toolKalem.h"
#include<topMenus.h>
#include<sayfaFunctions.h>
#include<popMenus.h>
#include<toolKalemSlots.h>
#include<toolKalemFunction.h>
#include<toolKalemSignalSlots.h>


void toolKalem::modeKontrolSlot()
{

//qDebug()<<"oldMode:"<<oldMode<<"currentMode"<<currentMode;
   // qDebug()<<"Mode-Type(kalem:16-43;hand:1-0):"<<oldMode<<oldType;
    if(oldMode==Scene::DrawPen&&(oldType==DiagramItem::DiagramType::NormalPen||
                                 oldType==DiagramItem::DiagramType::PatternPen))
    {
        qDebug()<<"Kalem Seçili";
        /***************************form ekran fotosu resetleniyor**************/
        current_toolTahta->gvToTahta();
        /****************************Kalem Seçimi Ayarı Yapıldı**************************/

        current_toolTahta->penDrawingMain=true;
        current_toolTahta->gv->hide();
        current_toolTahta->gv->setEnabled(false);
        current_toolTahta->scene->makeItemsControllable(false);
    }else
        {
            qDebug()<<"Kalem Dışında Araç Seçildi:"<<oldMode;

            current_toolTahta->penDrawingMain=false;
            current_toolTahta->gv->show();
            current_toolTahta->gv->setEnabled(true);
            /***************************form ekran fotosu resetleniyor**************/
            QPalette palet;
            palet.setBrush(QPalette::Background,QColor(0,0,0,0));
            current_toolTahta->setPalette(palet);

        }
    /********************************undo redo buton işlemleri*********/
    if(depo::historyBackCount>0&&undoPageButton)undoPageButton->setEnabled(true);
    if(depo::historyBackCount==0||undoPageButton==nullptr) undoPageButton->setEnabled(false);
    if(depo::historyNextCount>0&&redoPageButton)  redoPageButton->setEnabled(true);
    if(depo::historyNextCount==0||redoPageButton==nullptr) redoPageButton->setEnabled(false);
    /**************************önemli bir Yer**************************/
    current_toolTahta->raise();
    current_toolPageMenu->raise();
    current_toolKalemMenu->raise();
    raise();
   /* QPixmap pixMap =current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
     QPalette palet;
     //pixMap.save("deneme.png");
     palet.setBrush(QPalette::Background,pixMap);
     this->setPalette(palet);
     current_toolPageMenu->
     pageList[sceneSayfaActiveNumber]->setIcon(QIcon(pixMap));////önemli
    */
 /*   if(oldMode==Scene::Mode::DrawPen||
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


}*/

}

void toolKalem::penToScene()
{   current_toolTahta->scene->setPenSize(penSize);
    current_toolTahta->scene->setPenAlpha(penAlpha);
    current_toolTahta->scene->setPenColor(penColor);
    current_toolTahta->scene->setPenStyle(penStyle);
    current_toolTahta->scene->myzeminDolguColor=zeminDolguColor;

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

    //emit kalemModeSignal(currentMode,currentType);

}

toolKalem::toolKalem(QString _title, int _en, int _boy, toolTahta *_toolTahta, toolKalemMenu *_toolKalemMenu, toolPageMenu *_toolPageMenu, int parentw, int parenth, QWidget *parent)
        {
    penDesktopStatus=false;
    this->parentw=parentw;
    this->parenth=parenth;
    title=_title;
    en=_en;
    boy=_boy;
    mouseClick=false;
    current_toolTahta=_toolTahta;
    current_toolKalemMenu=_toolKalemMenu;
    current_toolPageMenu=_toolPageMenu;


/*******************************************************************/
/*
    desktopButton = new QToolButton(this);
    desktopButton=butonToolSlot(desktopButton,"",":icons/desktop.svg",QColor(255,0,0,0),en*1.5,boy);
    desktopButton->setCheckable(true);
    //desktopButton->setChecked(true);
    connect(desktopButton, &QToolButton::clicked, [=]() {
        desktopButtonSlot();

         });
*/
/*handButton = new QToolButton(this);
handButton=butonToolSlot(handButton,"",":icons/hand.svg",QColor(255,0,0,0),en*1.5,boy);
handButton->setCheckable(true);
//handButton->setChecked(true);
connect(handButton, &QToolButton::clicked, [=]() {
    handButtonSlot(true);
     });

copyButton = new QToolButton(this);
copyButton=butonToolSlot(copyButton,"",":icons/copy.svg",QColor(255,0,0,0),en*1.5,boy);
copyButton->setCheckable(true);
connect(copyButton, &QToolButton::clicked, [=]() {
    copyButtonSlot();
   });

penButton = new QToolButton(this);
penButton=butonToolSlot(penButton,"Kalem",":icons/pen.svg",QColor(255,0,0,0),en*1.5,boy);
penButton->setIconSize(QSize(en*0.8,boy*1.3));
penButton->setCheckable(true);
connect(penButton, &QToolButton::clicked, [=]() {
penButtonSlot(true);
});

eraseButton = new QToolButton(this);
eraseButton=butonToolSlot(eraseButton,"Silgi",":icons/erase.svg",QColor(255,0,0,0),en*1.5,boy);
eraseButton->setCheckable(true);
//eraseButton->setIconSize(QSize(en*0.8,boy*0.8));
connect(eraseButton, &QToolButton::clicked, [=]() {
       eraseButtonSlot();
});

QToolButton *clearButton = new QToolButton(this);
clearButton=butonToolSlot(clearButton,"Hepsini Sil",":icons/clear.svg",QColor(255,0,0,0),en*1.5,boy);
clearButton->setIconSize(QSize(en*1.5,boy*1.5));
connect(clearButton, &QToolButton::clicked, [=]() {
  clearButtonSlot();
});*/
/*
penColorButton = new QToolButton(this);
penColorButton=butonToolSlot(penColorButton,"",":icons/pencolor.png",QColor(0,0,0,255),en*1.5,boy*0.8);
connect(penColorButton, &QToolButton::clicked, [=]() {
 QMenu *menu= colorMenu("penColor","yatay",en,boy,true);
 menu->show();menu->hide();
 colorMenu("penColor","yatay",en,boy,true)->exec(mapToGlobal(penColorButton->pos())-QPoint(menu->width(),0));

});*/
/*
QWidget *urw=new QWidget(this);
urw->setFixedSize(en*1.5,boy);
undoButton = new QToolButton(urw);
undoButton=butonToolSlot(undoButton,"",":icons/undo.png",QColor(255,0,0,0),en*0.75,boy);
undoButton->setIconSize(QSize(en*0.8,boy*0.8));
connect(undoButton, &QToolButton::clicked, [=]() {
    //emit kalemModeSignal(Scene::Mode::GeriAlMode,DiagramItem::DiagramType::NoType);
    Scene::Mode tempmode=current_toolTahta->scene->sceneMode;
    current_toolTahta->scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
    current_toolTahta->scene->sceneMode=tempmode;
    secSayfaButtonClick(current_toolTahta->current_sceneIndex);
});

redoButton = new QToolButton(urw);
redoButton=butonToolSlot(redoButton,"",":icons/redo.png",QColor(255,0,0,0),en*0.75,boy);
redoButton->setIconSize(QSize(en*0.8,boy*0.8));
connect(redoButton, &QToolButton::clicked, [=]() {
   // emit kalemModeSignal(Scene::Mode::IleriAlMode,DiagramItem::DiagramType::NoType);
    Scene::Mode tempmode=current_toolTahta->scene->sceneMode;
    current_toolTahta->scene->setMode(Scene::Mode::IleriAlMode, DiagramItem::DiagramType::NoType);
    current_toolTahta->scene->sceneMode=tempmode;
    secSayfaButtonClick(current_toolTahta->current_sceneIndex);
});

QHBoxLayout *line00 = new QHBoxLayout;
line00->addWidget(undoButton,Qt::AlignHCenter);
line00->addWidget(redoButton,Qt::AlignHCenter);

line00->setContentsMargins(0,0, 0,0);
line00->setSpacing(1);
urw->setLayout(line00);
*/
    /*
sekilButton = new QToolButton(this);
DiagramItem *ditem=new DiagramItem();int ken=300;
QPixmap pixmap(image(ditem->sekilStore(DiagramItem::DiagramType::Cizgi,QRectF(QPointF(20,50),QPointF(ken-70,ken-70))),ken,ken));
sekilButton=butonToolSlot(sekilButton,"Şekiller",":icons/transparanboard.svg",QColor(255,0,0,0),en*1.5,boy);
sekilButton->setIcon(pixmap);
sekilButton->setCheckable(true);
connect(sekilButton, &QToolButton::clicked, [=]() {
   buttonStateClear(); sekilButton->setChecked(true);
   sekilButtonSlot();
   emit kalemSekilModeSignal(DiagramItem::DiagramType::Cizgi);
   });

zeminButton = new QToolButton(this);
zeminButton=butonToolSlot(zeminButton,"Arkaplan",":icons/whiteboard.svg",QColor(255,0,0,0),en*1.5,boy);
//zeminButton->setMenu(zeminMenu());
//zeminButton->setPopupMode(QToolButton::MenuButtonPopup);

connect(zeminButton, &QToolButton::clicked, [=]() {
    zeminButtonSlot();
    //emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::TransparanPage);
   });

/*
QToolButton *pdfButton = new QToolButton(this);
pdfButton=butonToolSlot(pdfButton,"",":icons/pdf.svg",QColor(255,0,0,0),en*1.5,boy);
connect(pdfButton, &QToolButton::clicked, [=]() {
    pdfButtonSlot();
    //emit kalemModeSignal(Scene::Mode::PdfMode,DiagramItem::DiagramType::NoType);
   });
*//*
QToolButton *toolButton = new QToolButton(this);
toolButton=butonToolSlot(toolButton,"Araç",":icons/tool.svg",QColor(255,0,0,0),en*1.5,boy);
connect(toolButton, &QToolButton::clicked, [=]() {
    toolButtonSlot();
    //emit kalemModeSignal(Scene::Mode::ToolMode,DiagramItem::DiagramType::NoType);
   });

QToolButton *fenButton = new QToolButton(this);
fenButton=butonToolSlot(fenButton,"Araç",":icons/fen.svg",QColor(255,0,0,0),en*1.5,boy);
connect(fenButton, &QToolButton::clicked, [=]() {
    current_toolKalemMenu->toolKalemMenuOlustur(fenTopMenu(parenth*0.045),parentw*0.3,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();
   });

QToolButton *sosyalButton = new QToolButton(this);
sosyalButton=butonToolSlot(sosyalButton,"Araç",":icons/sosyal.svg",QColor(255,0,0,0),en*1.5,boy);
connect(sosyalButton, &QToolButton::clicked, [=]() {
    current_toolKalemMenu->toolKalemMenuOlustur(sosyalTopMenu(parenth*0.045),parentw*0.5,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();
   });

QToolButton *exitButton = new QToolButton(this);
exitButton=butonToolSlot(exitButton,"Kapat",":icons/close.svg",QColor(255,0,0,0),en*1.5,boy);
connect(exitButton, &QToolButton::clicked, [=]() {
//emit kalemModeSignal(Scene::Mode::ExitMode,DiagramItem::DiagramType::NoType);
    exit(0);
   });
*/
auto layout = new QGridLayout();
layout->setContentsMargins(2,5, 2,5);
layout->setSpacing(1);

//layout->addWidget(desktopButton, 0, 0,1,2);
//layout->addWidget(handButton, 1, 0,1,2);
//layout->addWidget(copyButton, 2, 0,1,2);

//layout->addWidget(penButton, 10, 0,1,2);
//layout->addWidget(penPopupButton, 10, 1,1,1);

//layout->addWidget(eraseButton, 20, 0,1,2);
//layout->addWidget(clearButton, 30, 0,1,2);

/*layout->addWidget(blackButton, 40, 0,1,2);
layout->addWidget(redButton, 41, 0,1,2);
layout->addWidget(blueButton, 42, 0,1,2);
*/
///layout->addWidget(penColorButton, 43, 0,1,2);

//layout->addWidget(undoButton, 45, 0,1,1);
//layout->addWidget(redoButton, 45, 1,1,1);
///layout->addWidget(urw, 45, 1,1,1);
//layout->addWidget(sekilButton, 50, 0,1,2);
//layout->addWidget(zeminButton, 60, 0,1,2);
//layout->addWidget(saveButton, 65, 0,1,2);

///layout->addWidget(pdfButton, 70, 0,1,2);
/*
layout->addWidget(fenButton, 92, 0,1,2);
layout->addWidget(sosyalButton, 93, 0,1,2);
layout->addWidget(toolButton, 94, 0,1,2);

layout->addWidget(exitButton,100, 0,1,2);
*/
this->setLayout(layout);
connect(this, SIGNAL(kalemColorSignal(QString,QColor)),
           this, SLOT(kalemColorSignalSlot(QString,QColor)));
}

