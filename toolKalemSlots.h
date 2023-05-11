#ifndef TOOLKALEMSLOTS_H
#define TOOLKALEMSLOTS_H
#include<toolKalem.h>
void toolKalem::buttonStateClear()
{
    desktopButton->setChecked(false);
    handButton->setChecked(false);
    copyButton->setChecked(false);
    penButton->setChecked(false);
    eraseButton->setChecked(false);
    sekilButton->setChecked(false);

}

void toolKalem::handButtonSlot(bool menushow)
{
    buttonStateClear();handButton->setChecked(true);
    if(menushow) current_toolKalemMenu->hide();

    currentMode=Scene::Mode::SelectObject;oldMode=Scene::Mode::SelectObject;
    currentType=DiagramItem::DiagramType::NoType;;oldType=DiagramItem::DiagramType::NoType;;

    current_toolTahta->scene->sceneMode=Scene::Mode::SelectObject;
    current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::NoType;
    if(current_toolTahta->scene->pdfObjectAdded) current_toolTahta->scene->pdfMoved=true;
modeKontrolSlot();
}

void toolKalem::penButtonSlot(bool menushow)
{
    buttonStateClear();penButton->setChecked(true);
    if(menushow){
        current_toolKalemMenu->toolKalemMenuOlustur(penTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
        current_toolKalemMenu->show();
    }
    penButton->setIcon(QIcon(":icons/pen.svg"));
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
    currentMode=Scene::Mode::DrawPen;
    oldMode=Scene::Mode::DrawPen;
    currentType=DiagramItem::DiagramType::NormalPen;
    oldType=DiagramItem::DiagramType::NormalPen;
modeKontrolSlot();
}
void toolKalem::patternpenButtonSlot(bool menushow)
{

    buttonStateClear();penButton->setChecked(true);
    if(menushow){
        current_toolKalemMenu->toolKalemMenuOlustur(penTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
        current_toolKalemMenu->show();
    }
    penButton->setIcon(QIcon(":icons/patternpen.svg"));
    current_toolTahta->scene->setSekilTanimlamaStatus(false);
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
    currentMode=Scene::Mode::DrawPen;
    oldMode=Scene::Mode::DrawPen;
    currentType=DiagramItem::DiagramType::PatternPen;
    oldType=DiagramItem::DiagramType::PatternPen;
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPenPattern;


modeKontrolSlot();
}

void toolKalem::smartpenButtonSlot(bool menushow)
{
    buttonStateClear();penButton->setChecked(true);
    if(menushow){
        current_toolKalemMenu->toolKalemMenuOlustur(penTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
        current_toolKalemMenu->show();
    }
     penButton->setIcon(QIcon(":icons/smartpen.svg"));
    current_toolTahta->scene->setSekilTanimlamaStatus(true);
    current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::SmartPen;
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPen;
    currentMode=Scene::Mode::DrawPen;
    oldMode=Scene::Mode::DrawPen;
    currentType=DiagramItem::DiagramType::SmartPen;
    oldType=DiagramItem::DiagramType::SmartPen;;
modeKontrolSlot();

}
void toolKalem::fosforpenButtonSlot(bool menushow)
{
    buttonStateClear();penButton->setChecked(true);
    if(menushow){
        current_toolKalemMenu->toolKalemMenuOlustur(penTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
        current_toolKalemMenu->show();
    }
      penButton->setIcon(QIcon(":icons/fosforlupen.svg"));
    current_toolTahta->scene->setSekilTanimlamaStatus(false);
    current_toolTahta->scene->setPenAlpha(50);
    current_toolTahta->scene->sceneMode=Scene::Mode::DrawPenFosfor;
    currentMode=Scene::Mode::DrawPenFosfor;
    oldMode=Scene::Mode::DrawPenFosfor;
    currentType=DiagramItem::DiagramType::FosforluPen;
    oldType=DiagramItem::DiagramType::FosforluPen;;
modeKontrolSlot();
}

void toolKalem::clearButtonSlot()
{
    oldMode=currentMode;
    oldType=currentType;
    current_toolTahta->scene->removeAllItem();
}

void toolKalem::eraseButtonSlot()
{
    buttonStateClear();eraseButton->setChecked(true);
    current_toolKalemMenu->toolKalemMenuOlustur(eraseTopMenu(parenth*0.045),parentw*0.2,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();
    current_toolTahta->scene->setEraseSize(penSize);
    current_toolTahta->scene->sceneMode=Scene::Mode::EraseMode;
    current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::NoType;
    currentMode=Scene::Mode::EraseMode;oldMode=Scene::Mode::EraseMode;
    currentType=DiagramItem::DiagramType::NoType;oldType=DiagramItem::DiagramType::NoType;
    modeKontrolSlot();
}

void toolKalem::copyButtonSlot()
{
      buttonStateClear();copyButton->setChecked(true);
    current_toolKalemMenu->hide();
    current_toolTahta->scene->setMode(Scene::Mode::CopyMode, DiagramItem::DiagramType::Copy);
    current_toolTahta->scene->sceneMode=Scene::Mode::CopyMode;
    current_toolTahta->scene->mySekilType=DiagramItem::DiagramType::Copy;
    oldMode=Scene::Mode::CopyMode;oldType=DiagramItem::DiagramType::NoType;
    currentMode=Scene::Mode::CopyMode;currentType=DiagramItem::DiagramType::Copy;

    current_toolTahta->scene->setSekilTanimlamaStatus(false);
    QPixmap desk = qApp->screens().at(0)->grabWindow(QDesktopWidget().winId(),0,0,parentw,parenth);
    current_toolTahta->scene->setImage(desk);
    modeKontrolSlot();
}

void toolKalem::zeminButtonSlot()
{
    current_toolKalemMenu->toolKalemMenuOlustur(zeminTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();
    //emit kalemZeminModeSignal(DiagramItem::DiagramType::WhitePage);
    current_toolTahta->gvToTahta();

}
void toolKalem::sekilButtonSlot()
{
    current_toolKalemMenu->toolKalemMenuOlustur(sekilTopMenu(parenth*0.045),parentw*0.9,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();

}
void toolKalem::pdfButtonSlot()
{
    current_toolKalemMenu->toolKalemMenuOlustur(pdfTopMenu(parenth*0.045),parentw*0.2,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();

}
void toolKalem::toolButtonSlot()
{
    current_toolKalemMenu->toolKalemMenuOlustur(toolTopMenu(parenth*0.045),parentw*0.3,parenth*0.045,parentw,parenth);
    current_toolKalemMenu->show();

}
void toolKalem::sceneToPen()
{
    penSize=current_toolTahta->scene->myPenSize;
    penAlpha=current_toolTahta->scene->myPenAlpha;
    penColor=current_toolTahta->scene->myPenColor;
    penStyle=current_toolTahta->scene->myPenStyle;
    sekilType=current_toolTahta->scene->mySekilType;
    sekilZeminColor=current_toolTahta->scene->mySekilKalemColor;
    zeminDolguColor=current_toolTahta->scene->myzeminDolguColor;

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
   qDebug()<<"Desktop Pen Modu Ayarlanır.."<<penDesktopStatus;
    buttonStateClear();
    if(!penDesktopStatus)
    {
        desktopButton->setChecked(false);
        penDesktopStatus=true;
        //current_toolTahta->hide();
        emit desktopSignal();
        //emit kalemModeSignal(Scene::Mode::PenMode,DiagramItem::DiagramType::NoType);
        desktopButton->setIcon(QIcon(":/icons/smartboard.svg"));

    }else
    {
        desktopButton->setChecked(true);
        //current_toolTahta->show();
        emit penSignal();
        penDesktopStatus=false;
        penButtonSlot(true);
        //emit kalemModeSignal(Scene::Mode::DesktopMode,DiagramItem::DiagramType::NoType);
        desktopButton->setIcon(QIcon(":/icons/desktop.svg"));
    }

}

void toolKalem::sagSolHizala()
{
    if (!sagSolHizaStatus)
    {
        move(parentw-this->width()-10,parenth/2- this->height()/2);
       if(sagSolHizaStatusInit) sagSolHizaStatus=true;
       sagSolHizaStatusInit=true;
    }else
    {
        move(10,parenth/2- this->height()/2);
        sagSolHizaStatus=false;
    }

}

void toolKalem::infoButtonClick(){
    QMessageBox msgBox;
    msgBox.setText("Bu uygulama etkileşimli tahtalarda kullanılmak üzere yazılmıştır."
                   "\n"
                   "\nYapılabilecek Eylemler:"
                   "\n\t* Çeşitli Kalem(Normal, Fosforlu)"
                   "\n\t* Tahta Rengi (Şeffaf, Beyaz, Siyah,Özel Renk)"
                   "\n\t* Tahta Desenleri(Yatay/Dikey Çizgi, Müzik,GüzelYazi)"
                   "\n\t* Otomatik Silgi Seçimi(Kalem Kalınlığına Uygun)"
                   "\n\t* Ekranda Taşıma Özelliği"
                   "\n\t* Tam Ekran Modunda Çalışmalarda Üstte Konumlanma"
                   "\n\t* Dışarıdan Arkaplan Resim Yükleme Özelliği"
                   "\n\t* Ekran Görüntüsünü Kaydetme Özelliği"
                   "\n\t* Geometrik Şekil Seçme,Taşıma,Boyutlandırma Özelliği"
                   "\n\t* Farklı Sanal Masaüstünde Çalışma Özelliği"
                   "\n\t* Geri ileri Alma Özelliği"
                   "\n\t* Ekranın Her Alanına Yazma Özelliği"
                   "\n\t* Pdf Dosyaları Yükleme ve Çalışma Kaydetme Özelliği"
                   "\n\t* Nesne Olarak Resim Ekleme Özelliği"
                   "\n\t* Yazdırma Özelliği"
                   "\n\t* Ekranın Bölgesini (Kesme,Taşıma,Büyültme) Özelliği"
                   "\n\t* Kullanıcı Ayarlarını Kaydetme ve Açma Özelliği"
                   "\n\t* Sınavlar için Sayaç Özelliği"
                   "\n*****************************************************************************"
                   "\n   Copyright (C) 2023 by Bayram KARAHAN                                    "
                   "\n\tgithub.com/bayramkarahan/E-Tahta"
                   "\n\tbayramkarahan.blogspot.com"
                   "\n\tbayramk@gmail.com  "
                    "\n\n   This program is free software; you can redistribute it and/or modify    "
                    "\n   it under the terms of the GNU General Public License as published by    "
                    "\n   the Free Software Foundation; either version 3 of the License, or       "
                    "\n   (at your option) any later version.                                     "
                    "\n                                                                           "
                    "\n   This program is distributed in the hope that it will be useful,         "
                    "\n   but WITHOUT ANY WARRANTY; without even the implied warranty of          "
                    "\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           "
                    "\n   GNU General Public License for more details.                            "
                    "\n                                                                           "
                    "\n   You should have received a copy of the GNU General Public License       "
                    "\n   along with this program; if not, write to the                          "
                    "\n   Free Software Foundation, Inc.,                                         "
                    "\n   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .          "

                   );
    msgBox.setWindowTitle("smartboard 1.0");
    QFont ff( "Arial", 10, QFont::Normal);
    msgBox.setFont(ff);


    msgBox.setStandardButtons(QMessageBox::Ok);
    Qt::WindowFlags flags = 0;
    flags |= Qt::Window;
    flags |= Qt::X11BypassWindowManagerHint;
    flags |= Qt::CustomizeWindowHint;
     current_toolTahta->setWindowFlags(flags);

    flags = 0;
    flags |= Qt::Window;

    //  QColorDialog abc;
    msgBox.setWindowFlags(flags);



    //msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.exec();
    //   kalemEgitim();
    flags |= Qt::Window;
    flags |= Qt::X11BypassWindowManagerHint;
    flags |= Qt::WindowStaysOnTopHint;
    current_toolTahta->setWindowFlags(flags);
     current_toolTahta->show();


}

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

#endif // TOOLKALEMSLOTS_H
