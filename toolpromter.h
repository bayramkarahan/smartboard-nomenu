#ifndef TOOLPROMTER_H
#define TOOLPROMTER_H
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
#include<QTextEdit>
#include<QEventLoop>
#include<shiftlabel.h>
class toolPromter : public QWidget
{
    Q_OBJECT
public:
    explicit toolPromter(int w, int h, QWidget *parent = nullptr);
    QSlider *sure;
protected slots:
    void timerTextslot();
    void saatslot();
    void setSure(int value);
    void paintEvent(QPaintEvent *pe) override;
protected:

signals:
    void promterCloseSignal();

private:
    QLabel *suresayacLabel;
    int suresayac=200;
    QProgressBar *bar;
    QLabel  *sayac;
     QLabel  *timerTextLabel;
    qint64 saniye;
    QEventLoop loop;
    QTimer timer;
 //   QTimer timerText;
    QTextEdit *text;

    QString actual_text_;
    int pos_;
};


#endif // TOOLPROMTER_H
