#ifndef TOOLPAGEMENU_H
#define TOOLPAGEMENU_H

#include <QWidget>
#include<QGridLayout>
#include<QDebug>
class toolPageMenu:public QWidget
{
    Q_OBJECT
public:
    explicit toolPageMenu(QWidget *_menu, int w, int h, QWidget *parent = nullptr);
    QWidget *menu;
public slots:
      void toolPageMenu_DesktopSignalSlot();
      void toolPageMenu_PenSignalSlot();
      void toolPageMenuOlustur(QWidget *_menu, int w, int h, int parentw, int parenth);
private:
       QGridLayout *mainlayout;
};

#endif // TOOLPAGEMENU_H
