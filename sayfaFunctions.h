#ifndef SAYFAFUNCTIONS_H
#define SAYFAFUNCTIONS_H
#include<toolKalem.h>
void toolKalem::ekleSayfaButtonClick(int insertIndex,bool pdfObjectAdded,int pdfPageIndex){
     qDebug()<<"Sayfa Ekleniyor: "<<insertIndex<<pdfObjectAdded<<pdfPageIndex;
   // bool initprg=false;
    if(current_toolTahta->sceneIndex==0&&current_toolTahta->current_sceneIndex==0)
    {

        current_toolTahta->sceneIndex++;
        current_toolTahta->current_sceneIndex=0;
       // current_toolTahta->sceneList.removeAt(0);
        //if(pdfobjectnumber==1&&pdfObjectAdded==false) pdfObjectAdded=true;
    }else
    {

        current_toolTahta->sceneIndex++;
      if(insertIndex==-1)current_toolTahta->current_sceneIndex=current_toolTahta->sceneIndex-1;
      else current_toolTahta->current_sceneIndex++;
    }

  ///  qDebug()<<"ekle sayfa2"<<sceneSayfaNumber<<sceneSayfaActiveNumber<<pdfObjectAdded;
     current_toolTahta->_scene = new Scene(current_toolTahta->gv);
     connect(current_toolTahta->_scene, SIGNAL(sceneItemAddedSignal(Scene*,QGraphicsItem*,bool,Scene::Mode,DiagramItem::DiagramType) ), this, SLOT(sceneItemAddedSignalSlot(Scene*,QGraphicsItem*,bool,Scene::Mode,DiagramItem::DiagramType) ) );
     connect(current_toolTahta->_scene, SIGNAL(sceneItemRemovedSignal(Scene*,Scene::Mode,QGraphicsItem *,bool) ), this, SLOT(sceneItemRemovedSignalSlot(Scene*,Scene::Mode,QGraphicsItem *,bool) ) );

     current_toolTahta->_scene->pdfObjectAdded=pdfObjectAdded;
     current_toolTahta->_scene->pdfPageNumber=pdfPageIndex;
     current_toolTahta->scene=current_toolTahta->_scene;
     current_toolTahta->sceneList.insert(current_toolTahta->current_sceneIndex,current_toolTahta->scene);
     current_toolTahta->gv->setScene(current_toolTahta->scene);
     current_toolTahta->scene->setSceneRect(current_toolTahta->gv->pos().x(),current_toolTahta->gv->pos().y(), current_toolTahta->gv->width(),current_toolTahta->gv->height());
     penToScene();
    // pageNumberPopLabel->setText("Sayfa( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");

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

      if(pdfObjectAdded)
          emit kalemZeminModeSignal(DiagramItem::DiagramType::WhitePage);

      secSayfaButtonClick(_screenbtn->toolTip().toInt());
      penButtonSlot(true);
}

void toolKalem::silSayfaButtonClick(){
   /// if(sceneSayfaNumber>0)sceneSayfaNumber--;
    if(current_toolTahta->sceneIndex>0&&!current_toolTahta->scene->pdfObjectAdded){
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
    //sceneToPen();
    // currentScreenMode=scene->sceneMode;         ///çok önemli
    /// current_toolTahta->scene->sceneMode=currentScreenMode;         ///çok önemli

    for(int i=0;i<current_toolTahta->sceneListButton.length();i++)
    {
         palet.setColor(QPalette::Button, QColor(225,225,225,100));
        current_toolTahta->sceneListButton[i]->setPalette(palet);
        current_toolTahta->sceneListButton[i]->setAutoFillBackground(true);
    }

    palet.setColor(QPalette::Button, QColor(255,0,0,100));
    current_toolTahta->sceneListButton[index]->setPalette(palet);
    current_toolTahta->sceneListButton[index]->setAutoFillBackground(true);

    if(current_toolTahta->scene->pdfObjectAdded&&current_toolTahta->scene->pdfObjectShow==false&&
            current_toolTahta->scene->pdfPageNumber<=current_toolTahta->pdfPageCount-1)
      pdfLoaderPage(current_toolTahta->scene->pdfPageNumber);///pdf page loader
/***************************form ekran fotosu ayarlanıyor**************/
    qDebug()<<"Sayfa Seçiliyor ve Yenileniyor"<<current_toolTahta->sceneIndex;
    QPixmap pixMap = current_toolTahta->gv->grab(current_toolTahta->gv->sceneRect().toRect());
    QPalette palet1;
    palet1.setBrush(QPalette::Background,pixMap);
    current_toolTahta->setPalette(palet1);

/********************************************************************/
    if(current_toolTahta->sceneIndex>14)
    {
        nextPageButton->setEnabled(true);
        backPageButton->setEnabled(true);
    }
    else
    {
        nextPageButton->setEnabled(false);
        backPageButton->setEnabled(false);
    }
    if(current_toolTahta->scene->pdfObjectAdded)
   {
     //  qDebug()<<"sayfa ekle8";

       zoompozitifPageButton->setEnabled(true);
       zoomnegatifPageButton->setEnabled(true);
       zoomfitPageButton->setEnabled(true);

   }else
   {

        zoompozitifPageButton->setEnabled(false);
        zoomnegatifPageButton->setEnabled(false);
        zoomfitPageButton->setEnabled(false);

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
   // emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::WhitePage);
   // Poppler::Page *page=current_toolTahta->doc->page(pageIndex);
    //emit kalemModeSignal(Scene::Mode::ZeminMode,DiagramItem::DiagramType::WhitePage);

    //QImage image = doc->page(pageIndex)->renderToImage(125.0,125.0,-1,-1,-1,-1);
   // float scale = 72.0f * (float(current_toolTahta->doc->page(pageIndex)->pageSize().width()) / current_toolTahta->doc->page(pageIndex)->pageSizeF().width());
    QSize size = current_toolTahta->doc->page(pageIndex)->pageSize();
    float scale = 3.0;
    QImage  image = current_toolTahta->doc->page(pageIndex)->renderToImage(scale*72.0, scale*72.0, 0, 0, scale*size.width(), scale*size.height());
   // QImage image = current_toolTahta->doc->page(pageIndex)->renderToImage(150.0,150.0,current_toolTahta->doc->page(pageIndex)->pageSize().width(),current_toolTahta->doc->page(pageIndex)->pageSize().height());

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

void toolKalem::saveSayfaButtonClick(){
    QSize sSize = qApp->screens()[0]->size();
    QGraphicsTextItem *text = new QGraphicsTextItem(".");
    current_toolTahta->scene->addItem(text);
    text->setPos(0, 0);
    QGraphicsTextItem *text1 = new QGraphicsTextItem(".");
    current_toolTahta->scene->addItem(text1);
    text1->setPos(sSize.width()-2, sSize.height()-2);

    QPixmap pixmap(sSize.width(),sSize.height());
    pixmap.fill(Qt::transparent);     // Start all pixels transparent
    ///pixmap.fill(Qt::white);     // Start all pixels white
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    current_toolTahta->scene->render(&painter); //scene.render
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.end();
    QString os="";
    #ifdef WIN32
    // Windows code here
        os="windows";
    #else
    // UNIX code here
        os="linux";
    #endif

        if(os=="linux"){
        QDir directory(QDir::homePath()+"/Masaüstü");
        QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
        int deger=0;
        foreach(QString filename, images) {
            filename.chop(4);
            QString dosya=filename.right(filename.size()-10);
           /// qDebug() <<filename<<dosya;
            if(deger<dosya.toInt()) deger=dosya.toInt();
        }
        deger++;
        pixmap.save(QDir::homePath()+"/Masaüstü/screenshot"+QString::number(deger)+".png");
    }
     else{//windows işletim sistemi için
        QDir directory(QDir::homePath()+"/desktop");
        QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
        int deger=0;
        foreach(QString filename, images) {
            filename.chop(4);
            QString dosya=filename.right(filename.size()-10);
          ///  qDebug() <<filename<<dosya;
            if(deger<dosya.toInt()) deger=dosya.toInt();
        }
        deger++;
        pixmap.save(QDir::homePath()+"/desktop/screenshot"+QString::number(deger)+".png");

        }

    Qt::WindowFlags flags = 0;
    flags |= Qt::Dialog;
    flags |= Qt::X11BypassWindowManagerHint;

    QMessageBox messageBox(current_toolTahta);
    messageBox.setWindowFlags(flags);
    messageBox.setText("Bilgi\t\t\t");
    messageBox.setInformativeText("Ekran Görüntüsü Masaüstünüze Kaydedildi!");
    QAbstractButton *evetButton =messageBox.addButton(tr("Tamam"), QMessageBox::ActionRole);
   // QAbstractButton *hayirButton =messageBox.addButton(tr("Hayır"), QMessageBox::ActionRole);
    messageBox.setIcon(QMessageBox::Information);
    //messageBox.move(parentw/2,parenth/2);
            messageBox.exec();


}

 void toolKalem::addObjectScene(QString dosya,Scene::Mode mode,DiagramItem::DiagramType type,float w,float h,int posx,int posy,bool select)
 {
     QPixmap image;

     if(DiagramItem::DiagramType::NoktaliKagit==type||
             DiagramItem::DiagramType::KareliKagit==type||
             DiagramItem::DiagramType::CizgiliKagit==type||
             DiagramItem::DiagramType::Resim==type||
             DiagramItem::DiagramType::IzometrikKagit==type)
     {
         QPixmap pg;
         if(DiagramItem::DiagramType::CizgiliKagit==type){
         GridLines *gridLines = new GridLines (width(), height(),60,true,false,false,zeminDolguColor, penColor);
         pg=gridLines->PixItem(gridLines,width(), height());
         }else
             pg = QPixmap(dosya);
         QPixmap tmp(pg.width(),pg.height());
         // tmp.fill(QColor(QColor(255,0,0,255)));
          tmp.fill(QColor(zeminDolguColor));

          QPainter painter(&tmp);
          painter.drawPixmap(QPoint{}, pg, pg.rect());
          painter.end();
          image = tmp;
     }
     else
     image = QPixmap(dosya);
     //current_toolTahta->scene->setImage(image);
     current_toolTahta->scene->mySekilType=type;
     VERectangle  *itemToRectDraw = new VERectangle(current_toolTahta->scene);
     itemToRectDraw->setZValue(-100);
     itemToRectDraw->sekilTur(type);
     itemToRectDraw->setImage(image);
     emit current_toolTahta->scene->sceneItemAddedSignal(current_toolTahta->scene,itemToRectDraw,true,mode,current_toolTahta->scene->mySekilType);
     itemToRectDraw->setPos(posx,posy);
     itemToRectDraw->setRect(0,0,w,h);
      current_toolTahta->scene->makeItemsControllable(false);
     itemToRectDraw->fareState(select);
     //current_toolTahta->scene->setMode(Scene::Mode::SelectObject, DiagramItem::DiagramType::NoType);
     itemToRectDraw=0;
 }
#endif // SAYFAFUNCTIONS_H
