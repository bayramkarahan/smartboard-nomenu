#include "toolkalemmenu.h"

toolKalemMenu::toolKalemMenu(QWidget *_menu,int w, int h, QWidget *parent)
    : QWidget{parent}
{
    menu=_menu;
   // menu->setVisible(true);
    setFixedSize(w,h);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_StaticContents);
    setAttribute(Qt::WA_TranslucentBackground, true);

   // this->setAttribute(Qt::WA_NoSystemBackground, false);
    mainlayout = new QGridLayout(this);
       mainlayout->setAlignment(Qt::AlignCenter);
      // mainlayout->setRowStretch(2,1);
      // mainlayout->setColumnStretch(2,1);
         // mainlayout->setContentsMargins(5,5,5,5);
        //  mainlayout->setHorizontalSpacing(5);
         // mainlayout->setVerticalSpacing(5);
            mainlayout->setMargin(0);
         //    mainlayout->setSpacing(5);
       mainlayout->addWidget(menu);
       menu->setFixedSize(QSize(w,h));
       menu->setObjectName("buyukKutu");
        menu->setStyleSheet("QWidget#buyukKutu{"
                            "border: 2px solid rgb(53, 132, 228);"
                              "border-radius: 5px;"
                              "background-color:rgba(240,240,240,255);"
                            "}");

menuStatus=true;
}
void toolKalemMenu::toolKalemMenuOlustur(QWidget *_menu, int w, int h, int parentw, int parenth)
{
    qDeleteAll(this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));

    /* if (menuStatus) {
         mainlayout->removeWidget(menu);
        delete menu;
    }*/
    /* QLayoutItem* child;
               while ((child = mainlayout->takeAt(0)) != 0)
               {
                   if (child->widget() != NULL)
                   {
                       delete (child->widget());
                   }
                   delete child;
               }
               */
    //menuStatus=true;
    menu=_menu;
    //repaint();
    // menu->setVisible(true);
    this->setFixedSize(w,h);
    this->move(parentw/2-w/2,2);///sayfada nerede konumlanacağını belirlediğimiz yer...
    /// QGridLayout *mainlayout = new QGridLayout(this);
    ///      mainlayout->setContentsMargins(0,0,0,0);
    mainlayout->addWidget(menu);
    menu->setFixedSize(QSize(w,h));
    menu->setObjectName("buyukKutu");
    menu->setStyleSheet("QWidget#buyukKutu{"
                        "border: 2px solid rgb(53, 132, 228);"
                        "border-radius: 5px;"
                        "background-color:rgba(240,240,240,255);"
                        "}");


}
void toolKalemMenu::toolKalemMenu_DesktopSignalSlot()
{
qDebug()<<"toolKalemMenu desktop seç masajı geldi...";
hide();
}

void toolKalemMenu::toolKalemMenu_PenSignalSlot()
{
qDebug()<<"toolKalemMenu pen seç masajı geldi...";
show();
}
