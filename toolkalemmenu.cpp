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
    QGridLayout *mainlayout = new QGridLayout(this);
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
                              "border-radius: 10px;"
                              "background-color:rgba(240,240,240,255);"
                            "}");

}
