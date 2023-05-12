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
    //mainlayout->addWidget(ml);
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
                        "width:"+QString::number(en*10)+"px;"
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
    butongrub->setFixedSize(en*10, boy*2.5);
    butongrub->move(this->width()/2-butongrub->width()/2,this->height()-butongrub->height()*1);

    QPushButton *sayacStartButton= new QPushButton(butongrub);
    sayacStartButton->hide();
    sayacStartButton->setFixedSize(en*2, boy*2);
    sayacStartButton->setIconSize(QSize(en*2,boy*2));
    sayacStartButton->setFlat(true);
    sayacStartButton->setIcon(QIcon(":icons/startsayac.svg"));
    sayacStartButton->move(en*4,0);

    sayacStartButton->show();

    connect(sayacStartButton, &QPushButton::clicked, [=]() {
        sure->hide();
        suresayacLabel->hide();
        text->hide();
        sayacStartButton->hide();
        timerText->start(sure->value());
    });


    QPushButton *sayacPauseButton= new QPushButton(butongrub);
    sayacPauseButton->hide();
    sayacPauseButton->setFixedSize(en*2, boy*2);
    sayacPauseButton->setIconSize(QSize(en*2,boy*2));
    sayacPauseButton->setFlat(true);
    sayacPauseButton->setIcon(QIcon(":icons/stopsayac.svg"));
    sayacPauseButton->move(en*6,0);
    sayacPauseButton->show();
    connect(sayacPauseButton, &QPushButton::clicked, [=]() {
        timerText->stop();
        sure->show();
        suresayacLabel->show();
        text->show();
        sayacStartButton->show();
    });


    QPushButton *sayacExitButton= new QPushButton(this);
    sayacExitButton->setFixedSize(en*0.5, boy*1);
    sayacExitButton->setIconSize(QSize(en*1,boy*1));
    sayacExitButton->setFlat(true);
    sayacExitButton->setIcon(QIcon(":icons/exit.svg"));
    sayacExitButton->move(width()-sayacExitButton->width(),0);
    connect(sayacExitButton, &QPushButton::clicked, [=]() {
        saat->stop();
        sure->hide();
        sayacStartButton->hide();
        emit promterCloseSignal();
        this->close();
    });

    QPushButton *fontButton= new QPushButton(butongrub);
    fontButton->setFixedSize(en*2, boy*2);
    fontButton->setIconSize(QSize(en*2,boy*2));
    fontButton->setFlat(true);
    //fontButton->setText("Font");
    fontButton->setIcon(QIcon(":icons/font.svg"));
    fontButton->move(0,0);
    fontButton->show();
    connect(fontButton, &QPushButton::clicked, [=]() {
      on_btnFont_clicked();
    });
    QPushButton *colorButton= new QPushButton(butongrub);
    colorButton->setFixedSize(en*2, boy*2);
    colorButton->setIconSize(QSize(en*2,boy*2));
    colorButton->setFlat(true);
    //colorButton->setText("Color");
    colorButton->setIcon(QIcon(":icons/color.svg"));
    colorButton->move(en*2,0);
    colorButton->show();
    connect(colorButton, &QPushButton::clicked, [=]() {
        on_btnColor_clicked();
    });
 /*   ml = new WidgetMarqueeLabel(this);
    ml->setFixedSize(width()-en*2,boy);
    ml->setTextFormat(Qt::RichText);
    ml->setAlignment(Qt::AlignVCenter);
    ml->setText(text->toPlainText());
    ml->setFont(QFont("Arial", 20,20));
    ml->move(10,0);
    */
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


void toolPromter::on_btnColor_clicked()
{
    QColor c = QColorDialog::getColor();
    QPalette p;
    p.setBrush(QPalette::WindowText, c);
    timerTextLabel->setPalette(p);
}

void toolPromter::on_btnFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, timerTextLabel->font(), this);
    if (ok)
    {
        timerTextLabel->setFont(font);
    }
}
void toolPromter::on_btnPause_clicked()
{
    /*
    if(btnPause->text() == QString("Pause"))
    {
        currentSpeed = sliderSpeed->value();
        ml->setSpeed(0);
        btnPause->setText("Resume");
    }
    else
    {
        ml->setSpeed(currentSpeed);
        btnPause->setText("Pause");
    }
    */
}
