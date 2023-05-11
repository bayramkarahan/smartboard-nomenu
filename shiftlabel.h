#ifndef SHIFTLABEL_H
#define SHIFTLABEL_H

#include <QLabel>
#include <QWidget>
#include<QString>
class ShiftLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ShiftLabel(QWidget *parent = nullptr);

protected:
    void setShiftLabel(QString text);
  void timerEvent(QTimerEvent *) {
    pos_ = ++pos_ % actual_text_.length();
    setText(actual_text_.mid(pos_).append(actual_text_.left(pos_)));
  }

private:
  QString actual_text_;
  int pos_;
};

#endif // SHIFTLABEL_H
