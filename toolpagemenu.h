#ifndef TOOLPAGEMENU_H
#define TOOLPAGEMENU_H

#include <QWidget>
#include<QGridLayout>
class toolPageMenu:public QWidget
{
    Q_OBJECT
public:
    explicit toolPageMenu(QWidget *_menu, int w, int h, QWidget *parent = nullptr);
    QWidget *menu;
};

#endif // TOOLPAGEMENU_H
