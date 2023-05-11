#include "shiftlabel.h"

ShiftLabel::ShiftLabel(QWidget *parent)
{

}

void ShiftLabel::setShiftLabel(QString text)
{
    QString pad(25, ' ');
    actual_text_ = text + pad;
    startTimer(100);
}
