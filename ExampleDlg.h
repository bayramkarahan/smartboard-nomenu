#ifndef _EXMAPLEDLG_H_
#define _EXMAPLEDLG_H_

#include <QDialog>
#include "ui_ExampleDlg.h"
#include "WidgetMarqueeLabel.h"

class ExampleDlg : public QDialog, public Ui::ExampleDlg
{
	Q_OBJECT
	public:
		ExampleDlg(QWidget *parent = 0);
		~ExampleDlg();

	private:
		WidgetMarqueeLabel *ml;
		int currentSpeed;

	private slots:
		void on_lineEdit_textChanged(QString text);
		void on_btnColor_clicked();
		void on_btnFont_clicked();	
		void on_btnPause_clicked();
		void on_radioButtonLTR_toggled();
};

#endif /*_EXMAPLEDLG_H_*/