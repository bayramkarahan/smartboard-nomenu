#ifndef TOOLKALEMMENU_H
#define TOOLKALEMMENU_H

#include <QWidget>
#include<QMenu>
#include<QGridLayout>
#include<QDebug>
class toolKalemMenu : public QWidget
{
    Q_OBJECT
public:
    explicit toolKalemMenu(QWidget *_menu, int w, int h, QWidget *parent = nullptr);
    void toolKalemMenuOlustur(QWidget *_menu, int w, int h,int parentw, int parenth);

    QWidget *menu;
    bool menuStatus=false;
    QGridLayout *mainlayout;
signals:
public slots:
      void toolKalemMenu_DesktopSignalSlot();
      void toolKalemMenu_PenSignalSlot();
};

#endif // TOOLKALEMMENU_H
