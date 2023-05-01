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
    void kalemModeSignalSlot(Scene::Mode mode,DiagramItem::DiagramType type);
    void kalemSekilModeSignalSlot(DiagramItem::DiagramType type);

private:

 toolKalem *kw;
 QSize screenSize;
 int en;
 int boy;
};

#endif // MAINWINDOW_H
