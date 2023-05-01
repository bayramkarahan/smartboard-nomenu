#ifndef TOOLSAYAC_H
#define TOOLSAYAC_H

#include <QWidget>
#include<QGridLayout>
#include<QPushButton>
#include<QLabel>
#include<QProgressBar>
#include<QTimer>
#include<QTime>
#include<QDebug>
#include<tooltahta.h>
#include<QSlider>
class toolSayac : public QWidget
{
    Q_OBJECT
public:
    explicit toolSayac(int w, int h, QWidget *parent = nullptr);
    QSlider *sure;
protected slots:
    void saatslot();
    void setSure(int value);
    void paintEvent(QPaintEvent *pe) override;
protected:

signals:
    void sayacCloseSignal();

private:
    QLabel *suresayacLabel;
    int suresayac=30;
    QProgressBar *bar;
    QLabel  *sayac;
    qint64 saniye;
};

#endif // TOOLSAYAC_H
