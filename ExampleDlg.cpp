#include "ExampleDlg.h"
#include <QColorDialog>
#include <QFontDialog>
#include<QLayout>
ExampleDlg::ExampleDlg(QWidget *parent)
{

	ml = new WidgetMarqueeLabel(this);
	ml->setTextFormat(Qt::RichText);
    //layout()->addWidget(ml);
	ml->setAlignment(Qt::AlignVCenter);
	
    ml->setText("bu bir deneme");
	ml->setFont(QFont("Arial", 20,20));
    //sliderSpeed->setRange(1,10);
    //connect(sliderSpeed, SIGNAL(valueChanged(int)), ml, SLOT(setSpeed(int)));
}

ExampleDlg::~ExampleDlg()
{}

void ExampleDlg::on_lineEdit_textChanged(QString text)
{
	ml->setText(text);
}

void ExampleDlg::on_btnColor_clicked()
{
	QColor c = QColorDialog::getColor();
	QPalette p;
	p.setBrush(QPalette::WindowText, c);
	ml->setPalette(p);
}

void ExampleDlg::on_btnFont_clicked()
{
	bool ok;
	QFont font = QFontDialog::getFont(&ok, ml->font(), this);
	if (ok)
	{
		ml->setFont(font);
	}
}

void ExampleDlg::on_btnPause_clicked()
{
    /*if(btnPause->text() == QString("Pause"))
	{
		currentSpeed = sliderSpeed->value();
		ml->setSpeed(0);
		btnPause->setText("Resume");
	}
	else
	{
		ml->setSpeed(currentSpeed);
		btnPause->setText("Pause");
    }*/
}

void ExampleDlg::on_radioButtonLTR_toggled()
{
    /*if(radioButtonLTR->isChecked())
		ml->setDirection(WidgetMarqueeLabel::LeftToRight);
	else
        ml->setDirection(WidgetMarqueeLabel::RightToLeft);*/
}

