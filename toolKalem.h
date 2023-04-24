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
#include<QToolBar>
#include<QFrame>
#include<tooltahta.h>
#include<QPrinter>
#include<QMessageBox>
#include<QPdfWriter>
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
    GridLines * gridLines; ///< this is my custom QGraphicsItem

    QPoint offset;
    bool mouseClick;
    explicit toolKalem(QString _title, int _en, int _boy, toolTahta *_toolTahta, int parentw, int parenth, QWidget *parent = nullptr);
    int en;
    int boy;

    int penSize=4;
    int gridSize=15;
    int penAlpha=50;
    QColor penColor=QColor(0,0,0,255);
    Qt::PenStyle penStyle=Qt::SolidLine;
    QLabel *moveLabel;
    QColor sekilZeminColor=QColor(255,255,255,0);
    QColor zeminColor=QColor(0,0,0,0);
    QColor zeminGridColor=QColor(0,0,0,255);
    DiagramItem::DiagramType sekilType=DiagramItem::DiagramType::NoType;
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
    toolTahta *current_toolTahta;
    QHBoxLayout *sceneListButtonLayout;
    void penToScene();
    void sceneToPen();
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
    QWidget *penTopMenu();
    QWidget* sekilTopMenu();
    QWidget *zeminTopMenu();
    QWidget *eraseTopMenu();
     QWidget *pageBottomMenu();
     QWidget *pdfTopMenu();
    void setEraseSize(int size);
    void ekleSayfaButtonClick(int insertIndex, bool pdfObjectAdded, int pdfPageIndex);
    void silSayfaButtonClick();
    void secSayfaButtonClick(int index);
     void geriSayfaButtonClick();
     void ileriSayfaButtonClick();
     void pdfLoaderPage(int pageIndex);
     void zoomfitSayfaButtonClick();
     void zoompozitifSayfaButtonClick();
     void zoomnegatifSayfaButtonClick();
private:
     int pdfPageList=0;
     int ekliSayfa=1;
    int parentw;
    int parenth;
    QString title;
    QMenu *zeminMenu();
    QMenu *pageMenu();
    QPalette *palette;
    QLabel *eraseSizePopLabel;
    QLabel *sekilKalemSizePopLabel;
    QLabel *kalemSizePopLabel;
    QLabel *gridSizePopLabel;
    QWidget *pageListwg;
    QPushButton *delPageButton;
    QPushButton *addPageButton;
    QPushButton *nextPageButton;
    QPushButton *zoomnegatifPageButton;
    QPushButton *backPageButton;
    QPushButton *rightsidePageButton;
    QPushButton *leftsidePageButton;
    QPushButton *zoomfitPageButton;
    QPushButton *zoompozitifPageButton;
    protected:
    virtual void paintEvent (QPaintEvent *event) override
        {

            /*
             * Draw the title centred in the top margin.
             */
           /* QPainter painter(this);
            QRect title_rect(QPoint(0, 0), QSize(width(), contentsMargins().top()));
            painter.fillRect(title_rect, Qt::blue);
            painter.setPen(Qt::black);
            painter.drawText(title_rect, Qt::AlignCenter, title);

            /*
             * Defer to the base class implementation to update everything else.
             */
           /* super::paintEvent(event);
       */ }

};

#endif // TOOLKALEM_H
