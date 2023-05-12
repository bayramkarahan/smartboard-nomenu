#include "toolpromter.h"

toolPromter::toolPromter(int w, int h, QWidget *parent)
    : QWidget{parent}
{
    timer.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));


    setFixedSize(w,h);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    // setWindowFlags(Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_StaticContents);
    // setAttribute(Qt::WA_TranslucentBackground, true);
    // this->setAttribute(Qt::WA_NoSystemBackground, false);
    QGridLayout *mainlayout = new QGridLayout(this);
    mainlayout->setAlignment(Qt::AlignCenter);
    mainlayout->setMargin(0);
    setObjectName("promter");
    setStyleSheet("QWidget#promter{"
                  "border: 2px solid rgb(53, 132, 228);"
                  "border-radius: 5px;"
                  "background-color:rgba(250,250,250,255);"
                  "}");


    int en=w/20;
    int boy=h/20;
    //qDebug()<<en<<boy;
    QTimer  *saat = new QTimer(this);
    connect(saat, SIGNAL(timeout()), this, SLOT(saatslot()));

    timerText = new QTimer(this);
    connect(timerText, SIGNAL(timeout()), this, SLOT(timerTextslot()));

    timerTextLabel=new QLabel(this);
    timerTextLabel->setFixedSize(w-20, boy*5);
    timerTextLabel->move(10,boy*1.5);
    QFont f( "Arial", 90, QFont::Normal);
    timerTextLabel->setFont(f);
    timerTextLabel->setObjectName("timertext");
    timerTextLabel->setStyleSheet("QLabel#timertext{"
                  "border: 0.5px solid rgb(53, 132, 228);"
                  "border-radius: 5px;"
                  "background-color:rgba(0,0,0,70);"
                  "}");


    text=new QTextEdit(this);
    text->setText(" Bir millet irfan ordusuna sahip olmadıkça, muharebe meydanlarında ne kadar parlak zaferler elde ederse etsin, o zaferlerin kalıcı sonuçlar vermesi ancak irfan ordusuna bağlıdır. -Mustafa Kemal Atatürk ");
    text->setFixedSize(this->width()-20, boy*5);
    text->move(10,h-text->height()*2.5);
   // text->show();
    pos_=0;
    QString pad(50, ' ');
    actual_text_ = pad+text->toPlainText() ;

    //sure=new QSlider(this);
    sure= new QSlider(Qt::Horizontal,this);
    sure->setRange(1,500);
    sure->setSliderPosition(180);
    sure->setFixedSize(QSize(this->width()*0.5,boy*5));
    sure->move(this->width()/2-sure->width()/2,text->pos().y()+text->height());
    sure->setValue(180);
    connect(sure,SIGNAL(valueChanged(int)),this,SLOT(setSure(int)));
    sure->setStyleSheet(".QSlider::groove:Horizontal {"
                        "background: rgba(0, 0, 50, 200);"
                        "width:"+QString::number(en*14)+"px;"
                        "height:"+QString::number(boy/2)+"px;"
                        "}"
                        ".QSlider::handle:Horizontal {"
                        "background: rgba(242, 242, 242, 95);"
                        "border: 2px solid rgb(0,0,0);"
                        "background: rgba(0, 0, 50, 255);"
                        "width: "+QString::number(en/2)+"px;"
                        "height: "+QString::number(boy)+"px;"
                        "margin:-"+QString::number(boy/8*3)+"px   0   -"+QString::number(boy/8*3)+"px   0;"
                        "}");
    sure->hide();
    sure->show();

    suresayacLabel=new QLabel(this);
    suresayacLabel->setFixedSize(this->width()*0.1, boy*2);
    suresayacLabel->move(this->width()/2-suresayacLabel->width()/2,sure->pos().y()-10);
    suresayacLabel->setText("Süre: "+QString::number(suresayac));
    suresayacLabel->show();
    QWidget *butongrub=new QWidget(this);
    butongrub->setFixedSize(en*4, boy*2.5);
    butongrub->move(this->width()/2-butongrub->width()/2,this->height()-butongrub->height()*1);

    QPushButton *sayacStartButton= new QPushButton(butongrub);
    sayacStartButton->hide();
    sayacStartButton->setFixedSize(en*2, boy*2);
    sayacStartButton->setIconSize(QSize(en*2,boy*2));
    sayacStartButton->setFlat(true);
    sayacStartButton->setIcon(QIcon(":icons/startsayac.svg"));
    // sayacStartButton->move(this->width()*0.5,this->height()-sayacStartButton->height()*2);
    sayacStartButton->move(0,5);

    sayacStartButton->show();

    connect(sayacStartButton, &QPushButton::clicked, [=]() {
        /*saniye=0;
        saat->start(1000);
        //delete sure;
        sure->hide();
        sayacStartButton->hide();

       // sayacCloseButton->hide();


       /* QStringList liste=text->toPlainText().split(" ");
        qDebug()<<"Kelime Sayısı:"<<liste.length();
        for(int i=0;i<liste.length();i++)
        {
            qDebug()<<i<<":"<<liste[i];
            timer.start(2000);
            loop.exec();
        }*/

        sure->hide();
        suresayacLabel->hide();
        text->hide();
        sayacStartButton->hide();
        //sayacCloseButton->hide();


        timerText->start(sure->value());

    });


    QPushButton *sayacCloseButton= new QPushButton(butongrub);
    sayacCloseButton->hide();
    sayacCloseButton->setFixedSize(en*2, boy*2);
    sayacCloseButton->setIconSize(QSize(en*2,boy*2));
    sayacCloseButton->setFlat(true);
    sayacCloseButton->setIcon(QIcon(":icons/stopsayac.svg"));
    sayacCloseButton->move(butongrub->width()-sayacCloseButton->width()-boy/2,5);
    sayacCloseButton->show();
    connect(sayacCloseButton, &QPushButton::clicked, [=]() {

        timerText->stop();
        sure->show();
        suresayacLabel->show();
        text->show();
        sayacStartButton->show();
        sayacCloseButton->show();
        ///zeminSeffafButtonClick();///burada zemin beyaz yapılıyor
        //emit promterCloseSignal();
        //this->close();

    });


    QPushButton *sayacExitButton= new QPushButton(this);
    //sayacExitButton->hide();
    sayacExitButton->setFixedSize(en*0.5, boy*1);
    sayacExitButton->setIconSize(QSize(en*1,boy*1));
    sayacExitButton->setFlat(true);
    sayacExitButton->setIcon(QIcon(":icons/exit.svg"));
    sayacExitButton->move(width()-sayacExitButton->width(),0);
    //sayacExitButton->show();
    connect(sayacExitButton, &QPushButton::clicked, [=]() {
        /// sayacShow=false;//Sayac Kapatılıyor..
        saat->stop();
        sure->hide();

        sayacStartButton->hide();
        sayacCloseButton->hide();
        ///zeminSeffafButtonClick();///burada zemin beyaz yapılıyor
        emit promterCloseSignal();
        this->close();

    });


}

void toolPromter::timerTextslot(){
    pos_ = ++pos_ % actual_text_.length();
    timerTextLabel->setText(actual_text_.mid(pos_).append(actual_text_.left(pos_)));
    //setText(actual_text_.mid(pos_).append(actual_text_.left(pos_)));
}
void toolPromter::saatslot(){
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    //sayac->display(text);
    saniye+=1;
   //qDebug()<<saniye;
    int hour=saniye/3600;
     int minute=saniye/60;
     int second=saniye%60;
     int sr=suresayac*60;



}

void toolPromter::setSure(int value)
{
    suresayac=value;
    suresayacLabel->setText("Süre: "+QString::number(suresayac));
    //timerText->stop();
    //timerText->start(sure->value());
}

void toolPromter::paintEvent(QPaintEvent *pe)
{
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

