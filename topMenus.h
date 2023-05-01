#ifndef TOPMENUS_H
#define TOPMENUS_H
#include<toolKalem.h>
QWidget *toolKalem::cizgiGridBoyutMenu()
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


    QFont ff( "Arial", 7, QFont::Normal);

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
        clearButtonSlot();
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

QWidget *toolKalem::toolTopMenu(int _boy)
{   int e=(_boy*0.8)/4*5;
    int b=(_boy*0.6)/4*4.3;
    QWidget *menu = new QWidget(this);
    QFont ff( "Arial", 7, QFont::Normal);

    QPushButton *sayacButton=new QPushButton();
    sayacButton=butonSlot(sayacButton,"",":icons/sayac.svg",QColor(255,0,0,0),e,b,e,b);
    connect(sayacButton, &QPushButton::clicked, [=]() {
    //emit kalemModeSignal(Scene::Mode::PdfMode,DiagramItem::DiagramType::NoType);

       toolSayac *sayac=new toolSayac(parentw*0.90,parenth*0.8);
       connect(sayac, SIGNAL(sayacCloseSignal()),
               this, SLOT(sayacCloseSignalSlot()));

       sayac->move(parentw/2-sayac->width()/2,parenth/2-sayac->height()/2);
       Qt::WindowFlags flags = 0;
       flags |= Qt::Window;
       flags |= Qt::X11BypassWindowManagerHint;
       flags |= Qt::CustomizeWindowHint;
       current_toolTahta_old_flags=current_toolTahta->windowFlags();
       current_toolTahta->setWindowFlags(flags);

       flags |= Qt::SplashScreen;
       flags |= Qt::X11BypassWindowManagerHint;
       flags |= Qt::WindowStaysOnTopHint;
       sayac->setWindowFlags(flags);

       sayac->show();
       });

    QPushButton *saveButton=new QPushButton();
    saveButton=butonSlot(saveButton,"",":icons/save.svg",QColor(255,0,0,0),e,b,e,b);
    connect(saveButton, &QPushButton::clicked, [=]() {
    //emit kalemModeSignal(Scene::Mode::PdfMode,DiagramItem::DiagramType::NoType);
        saveSayfaButtonClick();
       });


    QPushButton *printButton = new QPushButton(this);
    printButton=butonSlot(printButton,"",":icons/print.svg",QColor(255,0,0,0),e,b,e,b);
    connect(printButton, &QPushButton::clicked, [=]() {
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

    QPushButton *infoButton = new QPushButton(this);
    infoButton=butonSlot(infoButton,"",":icons/info.svg",QColor(255,0,0,0),e,b,e,b);
    connect(infoButton, &QPushButton::clicked, [=]() {
    //emit kalemModeSignal(Scene::Mode::PdfMode,DiagramItem::DiagramType::NoType);
        infoButtonClick();
       });
     auto layout = new QGridLayout(menu);

      layout->setContentsMargins(5, 3, 5, 1);
    //layout->setMargin(0);
   // layout->setColumnMinimumWidth(0, 37);

layout->addWidget(sayacButton, 0, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(saveButton, 0, 5,1,1,Qt::AlignHCenter);
    layout->addWidget(printButton, 0, 10,1,1,Qt::AlignHCenter);
    layout->addWidget(infoButton, 0, 15,1,1,Qt::AlignHCenter);

    QLabel *sayacLabel=new QLabel("Sınav Sayacı");
    QLabel *kaydetLabel=new QLabel("Ekranı Kaydet");
    QLabel *printLabel=new QLabel("Ekranı Yazdır");
    QLabel *infoLabel=new QLabel("Hakkında");

    kaydetLabel->setFont(ff);printLabel->setFont(ff);
    infoLabel->setFont(ff);sayacLabel->setFont(ff);
    layout->addWidget(sayacLabel,1,1,1,1,Qt::AlignHCenter);
    layout->addWidget(kaydetLabel,1,5,1,1,Qt::AlignHCenter);
    layout->addWidget(printLabel,1,10,1,1,Qt::AlignHCenter);
    layout->addWidget(infoLabel,1,15,1,1,Qt::AlignHCenter);
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
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
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

    QPushButton *patternKalemButton=new QPushButton();
    patternKalemButton=butonSlot(patternKalemButton,"",":icons/patternpen.svg",QColor(255,0,0,0),e,b,e,b);
    connect(patternKalemButton, &QPushButton::clicked, [=]() {
        emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::PatternPen);
       // menu->close();
        current_toolTahta->scene->sceneMode=Scene::Mode::DrawPenPattern;
        current_toolTahta->scene->setSekilTanimlamaStatus(false);
        //current_toolTahta->scene->setPenAlpha(50);
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
    QLabel *pkl=new QLabel("Desen Kalem");

    QLabel *fkl=new QLabel("Fosforlu Kalem");
    QLabel *akl=new QLabel("Akıllı Kalem");
    kl->setFont(ff);    fkl->setFont(ff);    akl->setFont(ff); pkl->setFont(ff);
    layout->addWidget(kalemMenuButton,0,5,1,1,Qt::AlignHCenter);
    layout->addWidget(patternKalemButton,0,10,1,1,Qt::AlignHCenter);
    layout->addWidget(fosforluKalemButton,0,15,1,1,Qt::AlignHCenter);
    layout->addWidget(kalemSekilTanimlama,0,20,1,1,Qt::AlignHCenter);

    layout->addWidget(kl,1,5,1,1,Qt::AlignHCenter);
    layout->addWidget(pkl,1,10,1,1,Qt::AlignHCenter);
    layout->addWidget(fkl,1,15,1,1,Qt::AlignHCenter);
    layout->addWidget(akl,1,20,1,1,Qt::AlignHCenter);


   // layout->addWidget(penSize,5,1,1,3,Qt::AlignHCenter);

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(nokta2);
    layout1->addWidget(nokta4);
    layout1->addWidget(nokta6);
    layout1->addWidget(nokta8);
    layout1->addWidget(nokta10);
    layout1->addWidget(nokta12);
    layout1->addWidget(nokta14);
    layout->addLayout(layout1, 0,30,2,1,Qt::AlignHCenter);

    //QGridLayout *renkloyout = new QGridLayout;
    //renkloyout->setContentsMargins(0,0,0,0);
    QWidget *cw=colorWidget("penColor","yatay",en*0.8,boy*0.8,false);
    cw->setFixedSize(en*9,boy);
    cw->setVisible(true);
   // renkloyout->addWidget(cw, 0,0,1,1,Qt::AlignHCenter);
   // QLabel *renk= new QLabel("Kalem Rengi");      renk->setFont(ff);
   // renkloyout->addWidget(renk, 1,0,1,1,Qt::AlignHCenter);
   // layout->addWidget(cw, 0,5,2,1,Qt::AlignCenter);
    layout->addWidget(cw, 0,40,2,1,Qt::AlignHCenter);
   // layout->addWidget(renk, 1,5,1,1,Qt::AlignHCenter);


    QLabel *fd=new QLabel("Düz");
    QLabel *fk=new QLabel("Kesik");
    QLabel *fn=new QLabel("Noktalı");
    fd->setFont(ff);    fk->setFont(ff);    fn->setFont(ff);
    layout->addWidget(penStyleSolidLine, 0, 45,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDashLine, 0, 46,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDotLine, 0, 47,1,1,Qt::AlignHCenter);
    layout->addWidget(fd,1,45,1,1,Qt::AlignHCenter);
    layout->addWidget(fk,1,46,1,1,Qt::AlignHCenter);
    layout->addWidget(fn,1,47,1,1,Qt::AlignHCenter);
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



    QPushButton *gridRenkButton = new QPushButton;
    gridRenkButton=butonSlot(gridRenkButton,"",":icons/gridrenk.png",QColor(255,0,0,0),e,b,e,b);
    gridRenkButton->setFlat(true);
    QMenu *gcm=colorMenu("zeminGridColor","dikey",en,boy,true);
    gridRenkButton->setMenu(gcm);
   connect(gridRenkButton, &QPushButton::clicked, [=]()
    {
    });

    QPushButton *zeminDolguRenkButton = new QPushButton;

     zeminDolguRenkButton=butonSlot(zeminDolguRenkButton,"",":icons/zeminrenk.png",QColor(255,0,0,0),e,b,e,b);
     zeminDolguRenkButton->setFlat(true);
     QMenu *zcm=colorMenu("zeminDolguColor","dikey",en,boy,true);
      zeminDolguRenkButton->setMenu(zcm);
     connect(zeminDolguRenkButton, &QPushButton::clicked, [=]()
     {
     });

   layout->addWidget(zeminLabel, 0, 0,2,1);


   layout->addWidget(noktaliKagit,0,5,1,1,Qt::AlignHCenter);
   layout->addWidget(izometrikKagit,0,6,1,1,Qt::AlignHCenter);
   layout->addWidget(kareliKagit,0,7,1,1,Qt::AlignHCenter);
   layout->addWidget(cizgiliKagit,0,8,1,1,Qt::AlignHCenter);
   layout->addWidget(zeminDolguRenkButton,0,9,1,1,Qt::AlignHCenter);
   QLabel *noktali=new QLabel("Noktalı");   noktali->setFont(ffl);
   QLabel *izometrik=new QLabel("İzometrik"); izometrik->setFont(ffl);
   QLabel *kareli=new QLabel("Kareli");    kareli->setFont(ffl);
   QLabel *cizgili=new QLabel("Çizgili");   cizgili->setFont(ffl);
   QLabel *zeminrengitahta=new QLabel("Dolgu Rengi");  zeminrengitahta->setFont(ffl);


   layout->addWidget(noktali,1,5,1,1,Qt::AlignHCenter);
   layout->addWidget(izometrik,1,6,1,1,Qt::AlignHCenter);
   layout->addWidget(kareli,1,7,1,1,Qt::AlignHCenter);
   layout->addWidget(cizgili,1,8,1,1,Qt::AlignHCenter);
   layout->addWidget(zeminrengitahta,1,9,1,1,Qt::AlignHCenter);

   layout->addWidget(nkoordinat,0,10,1,1,Qt::AlignHCenter);
   layout->addWidget(hnkoordinat,0,11,1,1,Qt::AlignHCenter);
   layout->addWidget(ndogru,0,12,1,1,Qt::AlignHCenter);
   layout->addWidget(nnkoordinat,0,13,1,1,Qt::AlignHCenter);

   QLabel *skoordinatl=new QLabel("S.Koordinat");   skoordinatl->setFont(ffl);
   QLabel *hnkoordinatl=new QLabel("Y. Koordinat"); hnkoordinatl->setFont(ffl);
   QLabel *ndogrul=new QLabel("Sayı Doğrusu");      ndogrul->setFont(ffl);
   QLabel *nnkoordinatl=new QLabel("Koordinat");    nnkoordinatl->setFont(ffl);

   layout->addWidget(skoordinatl,1,10,1,1,Qt::AlignHCenter);
   layout->addWidget(hnkoordinatl,1,11,1,1,Qt::AlignHCenter);
   layout->addWidget(ndogrul,1,12,1,1,Qt::AlignHCenter);
   layout->addWidget(nnkoordinatl,1,13,1,1,Qt::AlignHCenter);

    layout->addWidget(zeminSeffafButton,0,15,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminSiyahButton,0,16,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminBeyazButton,0,17,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminCustomColorButton,0,18,1,1,Qt::AlignHCenter);

    QLabel *seffaftahta=new QLabel("Şeffaf Tahta");   seffaftahta->setFont(ffl);
    QLabel *siyahtahta=new QLabel("Siyah Tahta"); siyahtahta->setFont(ffl);
    QLabel *beyaztahta=new QLabel("Beyaz Tahta");      beyaztahta->setFont(ffl);
    QLabel *customtahta=new QLabel("Tahta Rengi");    customtahta->setFont(ffl);

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


     layout->addWidget(zeminDesenEkleSayfaButton,0,26,1,1,Qt::AlignHCenter);
    layout->addWidget(gridRenkButton,0,27,1,1,Qt::AlignHCenter);

    QLabel *temizletahta=new QLabel("Tahta Temizle");   temizletahta->setFont(ffl);
    QLabel *desenekletahta=new QLabel("Desen Ekle");    desenekletahta->setFont(ffl);
    QLabel *cizgirengitahta=new QLabel("Çizgi Rengi");  cizgirengitahta->setFont(ffl);

     layout->addWidget(desenekletahta,1,26,1,1,Qt::AlignHCenter);
    layout->addWidget(cizgirengitahta,1,27,1,1,Qt::AlignHCenter);

    QWidget *cm=cizgiGridBoyutMenu();
    cm->setVisible(true);
    //cm->setFixedSize(220,cm->height());
    layout->addWidget(cm,0,30,2,1,Qt::AlignHCenter);
   return menu;
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
    layout->addWidget(color8Button, 0,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color1Button, 1,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color2Button, 2,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color3Button, 3,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color4Button, 4,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color5Button, 5,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color6Button, 6,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color7Button, 7,1,1,1,Qt::AlignHCenter);
    layout->addWidget(color9Button, 9,1,1,1,Qt::AlignHCenter);
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
    layout->addWidget(color11Button, 1,9,1,1,Qt::AlignHCenter);
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
    btn->setIconSize(QSize(e*0.85,b*0.85));
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

void toolKalem::sekilButtonIconSlot(DiagramItem::DiagramType mySekilType){
    DiagramItem *ditem=new DiagramItem();
    int ken=300;
    if(DiagramItem::DiagramType::Cember==mySekilType)
    {
        QPixmap pixmap(imageEllipse(ditem->sekilStore(mySekilType,QRectF(QPointF(20,50),QPointF(ken-50,ken-50))),ken,ken));
        sekilButton->setIcon(pixmap);
    }
    else  if(DiagramItem::DiagramType::Pergel==mySekilType)    {sekilButton->setIcon(QIcon(":icons/pergel.png")); }
    else  if(DiagramItem::DiagramType::Cetvel==mySekilType)   {sekilButton->setIcon(QIcon(":icons/cetvel.png")); }
    else  if(DiagramItem::DiagramType::Gonye==mySekilType)    {sekilButton->setIcon(QIcon(":icons/gonye.png")); }
    else  if(DiagramItem::DiagramType::Iletki==mySekilType)    {sekilButton->setIcon(QIcon(":icons/iletki.png")); }
    else  if(DiagramItem::DiagramType::Kup==mySekilType)    {sekilButton->setIcon(QIcon(":icons/kup.png")); }
    else  if(DiagramItem::DiagramType::Silindir==mySekilType)   {sekilButton->setIcon(QIcon(":icons/silindir.png")); }
    else  if(DiagramItem::DiagramType::Pramit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/pramit.png")); }
    else  if(DiagramItem::DiagramType::Kure==mySekilType)    {sekilButton->setIcon(QIcon(":icons/kure.png")); }
    else  if(DiagramItem::DiagramType::NDogru==mySekilType)    {
        sekilButton->setIconSize(QSize(50,50));
        sekilButton->setIcon(QIcon(":icons/ndogru.png"));}
    else  if(DiagramItem::DiagramType::NKoordinat==mySekilType)    {sekilButton->setIcon(QIcon(":icons/nkoordinat.png")); }
    else  if(DiagramItem::DiagramType::NNKoordinat==mySekilType)    {sekilButton->setIcon(QIcon(":icons/nnkoordinat.png")); }
    else  if(DiagramItem::DiagramType::HNKoordinat==mySekilType)    {sekilButton->setIcon(QIcon(":icons/hnkoordinat.png")); }
    else  if(DiagramItem::DiagramType::NoktaliKagit==mySekilType)    {sekilButton->setIcon(QIcon(":icons//noktalikagit.png")); }
    else  if(DiagramItem::DiagramType::IzometrikKagit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/izometrikkagit.png")); }
    else  if(DiagramItem::DiagramType::KareliKagit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/karelikagit.png")); }
    else  if(DiagramItem::DiagramType::CizgiliKagit==mySekilType)    {sekilButton->setIcon(QIcon(":icons/cizgilikagit.png")); }
    else  if(DiagramItem::DiagramType::Resim==mySekilType)    {sekilButton->setIcon(QIcon(":icons/addimage.png")); }

    else
    {
        QPixmap pixmap(image(ditem->sekilStore(mySekilType,QRectF(QPointF(20,50),QPointF(ken-50,ken-50))),ken,ken));
        sekilButton->setIcon(pixmap);
    }
}

#endif // TOPMENUS_H
