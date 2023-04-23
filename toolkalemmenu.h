#ifndef TOOLKALEMMENU_H
#define TOOLKALEMMENU_H

#include <QWidget>
#include<QMenu>
#include<QGridLayout>
class toolKalemMenu : public QWidget
{
    Q_OBJECT
public:
    explicit toolKalemMenu(QWidget *_menu, int w, int h, QWidget *parent = nullptr);
    QWidget *menu;
signals:

};

#endif // TOOLKALEMMENU_H
