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
#include<QDesktopWidget>
#include<QApplication>
#include<QScreen>
#include<toolsayac.h>
#include<toolpromter.h>
#include<QSlider>
#include<toolkalemmenu.h>
#include<toolpagemenu.h>

class QMouseEvent;
class toolKalem : public QFrame
{
    Q_OBJECT
public:
    Scene::Mode oldMode;
    Scene::Mode currentMode;
    DiagramItem::DiagramType oldType;
    DiagramItem::DiagramType currentType;
    GridLines * gridLines; ///< this is my custom QGraphicsItem
    bool penDesktopStatus;

    QPoint offset;
    bool mouseClick;
    explicit toolKalem(QString _title, int _en, int _boy, toolTahta *_toolTahta, toolKalemMenu *_toolKalemMenu, toolPageMenu *_toolPageMenu, int parentw, int parenth, QWidget *parent = nullptr);
    int en;
    int boy;

    int penSize=4;
    int gridSize=15;
    int penAlpha=50;
    QColor penColor=QColor(0,0,0,255);
    Qt::PenStyle penStyle=Qt::SolidLine;

    QColor sekilZeminColor=QColor(255,255,255,0);
    QColor zeminColor=QColor(0,0,0,0);
    QColor zeminDolguColor=QColor(0,0,0,0);

    QColor zeminGridColor=QColor(0,0,0,255);
    DiagramItem::DiagramType sekilType=DiagramItem::DiagramType::NoType;
    DiagramItem::DiagramType pagePattern=DiagramItem::DiagramType::TransparanPage;
    QToolButton *penColorButton;
    QPixmap zeminImage(const QPolygonF &myPolygon, int w, int h, QColor zemincolor, QColor cizgicolor, int pensize) const;
    QPushButton *handButton;
    QPushButton *desktopButton;
    QPushButton *copyButton;
    QPushButton *penButton;
    QPushButton *eraseButton;
    QPushButton *sekilButton;
    QToolButton *zeminButton;
    QToolButton *undoButton;
    QToolButton *redoButton;
    QMenu *penMenu();
    toolTahta *current_toolTahta;
    toolKalemMenu *current_toolKalemMenu;
    toolPageMenu *current_toolPageMenu;
    QHBoxLayout *sceneListButtonLayout;
    void penToScene();
    void sceneToPen();
    void copyButtonSlot();
    void eraseButtonSlot();
    void zeminButtonSlot();
    void sekilButtonSlot();
    void pdfButtonSlot();
    void toolButtonSlot();

signals:
    void kalemColorSignal(QString colorType,QColor color);
    void kalemZeminModeSignal(DiagramItem::DiagramType type);
    void kalemPenModeSignal(DiagramItem::DiagramType type);
    void kalemSekilModeSignal(DiagramItem::DiagramType type);
    void desktopSignal();
    void penSignal();


public slots:
    void sayacCloseSignalSlot();
    void promterCloseSignalSlot();
    void handButtonSlot(bool menushow);
    void penButtonSlot(bool menushow);
    void smartpenButtonSlot(bool menushow);
    void fosforpenButtonSlot(bool menushow);
    void patternpenButtonSlot(bool menushow);

    void clearButtonSlot();
    void modeKontrolSlot();
    void desktopButtonSlot();
    void buttonStateClear();
    void setGridSize(int s);

    QWidget *cizgiGridBoyutMenu();
    void sekilButtonIconSlot(DiagramItem::DiagramType mySekilType);
    QPixmap lineImage(const QPolygonF &myPolygon,const Qt::PenStyle &stl,int w,int h) const;
    QPixmap imageEllipse(const QPolygonF &myPolygon, int w, int h) const;
    QPixmap image(const QPolygonF &myPolygon, int w, int h) const;

    QMenu *colorMenu(QString colorType, QString yon, int w, int h, bool close);
    QWidget *colorWidget(QString colorType, QString yon, int w, int h, bool close);

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject * obj, QEvent *event);
    QPushButton *butonSlot(QPushButton *btn, QString text, QString icon, QColor color, int w, int h, int iw, int ih);

    QToolButton *butonToolSlot(QToolButton *btn, QString text, QString icon, QColor color, int w, int h);
    QWidget *penTopMenu(int _boy);
    QWidget* sekilTopMenu(int _boy);
    QWidget *zeminTopMenu(int _boy);
    QWidget *eraseTopMenu(int _boy);
    QWidget *toolTopMenu(int _boy);
    QWidget *fenTopMenu(int _boy);
    QWidget *sosyalTopMenu(int _boy);

    QWidget *pageBottomMenu(int _boy);
    QWidget *pdfTopMenu(int _boy);
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
     void sagSolHizala();
     void saveSayfaButtonClick();
     void addObjectScene(QString dosya, Scene::Mode mode, DiagramItem::DiagramType type, float w, float h , int posx, int posy, bool select);
     void infoButtonClick();
     void sceneItemAddedSignalSlot(Scene *scenetemp, QGraphicsItem *item ,bool additemstate, Scene::Mode mode, DiagramItem::DiagramType type);
     void sceneItemRemovedSignalSlot(Scene *scenetemp, Scene::Mode mode, QGraphicsItem *item,bool deleteAction);
     void kalemColorSignalSlot(QString colorType, QColor color);
     void kalemSekilModeSignalSlot(DiagramItem::DiagramType type);
     void kalemZeminModeSignalSlot(DiagramItem::DiagramType type);

private:
     Qt::WindowFlags current_toolTahta_old_flags;
     bool sagSolHizaStatus;
     bool sagSolHizaStatusInit;
     int pdfPageList=0;
     int ekliSayfa=1;
     int parentw;
     int parenth;
     QString title;

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
    QPushButton *undoPageButton;
    QPushButton *redoPageButton;
    QPushButton *backPageButton;
    QPushButton *updownButton;
    QPushButton *leftrightButton;
    QPushButton *zoomfitPageButton;
    QPushButton *zoomnegatifPageButton;
    QPushButton *zoompozitifPageButton;
    protected:


};

#endif // TOOLKALEM_H
