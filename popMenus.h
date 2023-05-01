#ifndef POPMENUS_H
#define POPMENUS_H
#include<toolKalem.h>

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
   // penStyleSolidLine->setFlat(true;
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

    QWidget *cm=cizgiGridBoyutMenu();
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

#endif // POPMENUS_H
