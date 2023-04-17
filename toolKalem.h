#ifndef TOOLKALEM_H
#define TOOLKALEM_H
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<scene.h>
#include<diagramitem.h>
#include<QMenu>
#include<QPushButton>
#include<QPalette>
#include<QWidgetAction>
#include<QFileDialog>
#include<QToolButton>
///#include<popupmenu.h>
#include<QToolBar>
#include<QFrame>

class QMouseEvent;
class toolKalem : public QFrame
{
     using super = QFrame;
    Q_OBJECT
public:
    Scene::Mode oldMode;
    Scene::Mode currentMode;
    DiagramItem::DiagramType oldType;
    DiagramItem::DiagramType currentType;
    QString panelSide="Right";

    QPoint offset;
    bool mouseClick;
    explicit toolKalem(QString _title, int _en, int _boy, QWidget *parent = nullptr);
    int en;
    int boy;
    int penSize=4;
    int gridSize=15;
    int penAlpha=50;
    QColor penColor=QColor(0,0,0,255);
    Qt::PenStyle penStyle=Qt::SolidLine;
    QLabel *moveLabel;
    QColor sekilZeminColor=QColor(0,0,0,0);
    QColor zeminColor=QColor(0,0,0,0);
    QColor zeminGridColor=QColor(0,0,0,255);
    DiagramItem::DiagramType pagePattern=DiagramItem::DiagramType::TransparanPage;
    QToolButton *penColorButton;
    QLineEdit *pageOfNumber;
    QPixmap zeminImage(const QPolygonF &myPolygon, int w, int h, QColor color, int pensize) const;
    QToolButton *handButton;
    QToolButton *copyButton;
    QToolButton *penButton;
    QToolButton *eraseButton;
    QToolButton *sekilButton;
    QToolButton *zeminButton;
    QToolButton *undoButton;
    QToolButton *redoButton;
    QMenu *penMenu();

signals:
    void kalemColorSignal(QString colorType,QColor color);
    void kalemModeSignal(Scene::Mode mode,DiagramItem::DiagramType type);

    void kalemZeminModeSignal(DiagramItem::DiagramType type);
    void kalemPenModeSignal(DiagramItem::DiagramType type);
    void kalemSekilModeSignal(DiagramItem::DiagramType type);

public slots:
    void handButtonSlot();
    void penButtonSlot();
    void clearButtonSlot();
    void modeKontrolSlot();

   void buttonStateClear();
   void setGridSize(int s);
    QMenu *eraseMenu();
    QWidget *cizgiBoyutMenu();
    void sekilButtonIconSlot(DiagramItem::DiagramType mySekilType);
    QPixmap lineImage(const QPolygonF &myPolygon,const Qt::PenStyle &stl,int w,int h) const;
    QPixmap imageEllipse(const QPolygonF &myPolygon, int w, int h) const;
    QPixmap image(const QPolygonF &myPolygon, int w, int h) const;
    QMenu *sekilMenu();
    QMenu *colorMenu(QString colorType, QString yon, int w, int h, bool close);
    QWidget *colorWidget(QString colorType, QString yon, int w, int h, bool close);

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject * obj, QEvent *event);
    QPushButton *butonSlot(QPushButton *btn, QString text, QString icon, QColor color, int w, int h, int iw, int ih);

    QToolButton *butonToolSlot(QToolButton *btn, QString text, QString icon, QColor color, int w, int h);

private:
    QString title;

    QMenu *zeminMenu();
    QMenu *pageMenu();
    QPalette *palette;
    QLabel *eraseSizePopLabel;
    QLabel *sekilKalemSizePopLabel;
    QLabel *kalemSizePopLabel;
    QLabel *gridSizePopLabel;

protected:
    virtual void paintEvent (QPaintEvent *event) override
        {

            /*
             * Draw the title centred in the top margin.
             */
            QPainter painter(this);
            QRect title_rect(QPoint(0, 0), QSize(width(), contentsMargins().top()));
            painter.fillRect(title_rect, Qt::blue);
            painter.setPen(Qt::black);
            painter.drawText(title_rect, Qt::AlignCenter, title);

            /*
             * Defer to the base class implementation to update everything else.
             */
            super::paintEvent(event);
        }

};

#endif // TOOLKALEM_H
