#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include<QLabel>
class MyLabel:public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget* parent=0);
};

#endif // MYLABEL_H
