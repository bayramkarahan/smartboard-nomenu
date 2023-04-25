#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include<QGridLayout>
#include<toolKalem.h>
#include<QApplication>
#include<QScreen>
#include<QDebug>
#include<tooltahta.h>
#include<toolkalemmenu.h>
#include<toolpagemenu.h>
#include<QDesktopWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     toolTahta *current_toolTahta;
     toolKalemMenu *current_toolKalemMenu;
    toolPageMenu *curent_pageMenu;
public slots:
     void kalemZeminModeSignalSlot(DiagramItem::DiagramType type);
    void kalemPenModeSignalSlot(DiagramItem::DiagramType type);
    void kalemModeSignalSlot(Scene::Mode mode,DiagramItem::DiagramType type);
    void kalemColorSignalSlot(QString colorType, QColor color);
    void kalemSekilModeSignalSlot(DiagramItem::DiagramType type);
   // void slotBos();
    void slotPenInit();
    void slotErase();
    void slotHand();
    void slotCopy();
    void selectCopySlot(QPoint pos);
    void selectZoomSlot(QPoint pos);

    //void slotJumpPage();
   // void slotSearch();
    void slotScaleSceneItem(double sizex, double sizey);
    void mainClipBoard(QPoint pos, bool copy, bool zoom);
    void sceneItemAddedSignalSlot();

private:

 toolKalem *kw;
 QSize screenSize;
 int en;
 int boy;
 bool durum=false;
 QTimer *timer;

private:
 void resizeEvent(QResizeEvent * event);

private slots:
 void slotTimer();
};

#endif // MAINWINDOW_H
