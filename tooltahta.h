#ifndef TOOLTAHTA_H
#define TOOLTAHTA_H
#include <QWidget>
#include<QDebug>
#include<QPainter>
#include<QPaintEvent>
#include<scene.h>
#include<QGraphicsView>
#include<QGridLayout>
#include<QPixmap>
#include<QPalette>
#include<depo.h>
#include<QLabel>
#include<QToolButton>

class toolTahta : public QWidget
{
    Q_OBJECT
public:
    explicit toolTahta(int w, int h, QWidget *parent = nullptr);
    bool penDrawingMain=false;
    QImage penTuval;
    QLabel *tahtaTuval;
    QLabel *penTuvalZemin;

    Scene *scene;
    Scene *_scene;
    QGraphicsView *gv;
    QPointF startPoint;
    float msx,msy,mex,mey;
    GridLines * gridLines; ///< this is my custom QGraphicsItem
    int sceneIndex=0;
    int current_sceneIndex=0;
    QList<QToolButton*> sceneListButton;
    QList<Scene*> sceneList;
      void clearImage();
public slots:


signals:
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void resizeImage(QImage *image, const QSize &newSize,QRgb renk);
    void drawLineTo(const QPoint &endPoint);
    QImage copyImage(const QImage & input, const QRect & path);

private:
    bool drawStatus;
    QPoint lastPoint;

};

#endif // TOOLTAHTA_H
