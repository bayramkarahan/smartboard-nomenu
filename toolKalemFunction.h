#ifndef TOOLKALEMFUNCTION_H
#define TOOLKALEMFUNCTION_H
#include<toolKalem.h>
void toolKalem::setGridSize(int s)
{
    gridSize=s;
    gridSizePopLabel->setText("Satır ve Sütun Genişliği: "+QString::number(gridSize));
    emit kalemModeSignal(Scene::Mode::ZeminMode,pagePattern);
    //emit kalemModeSignal(Scene::Mode::DrawPen,DiagramItem::DiagramType::NoType);
    //buttonStateClear();
    //penButton->setChecked(true);
}

void toolKalem::setEraseSize(int size)
{
    eraseSizePopLabel->setText("Silgi Boyutu: "+QString::number(size));
}
QPixmap toolKalem::lineImage(const QPolygonF &myPolygon,const Qt::PenStyle &stl,int w,int h) const
{
    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8,stl));
  // painter.translate(en, boy);
    painter.drawPolyline(myPolygon);
    return pixmap;
}

QPixmap toolKalem::imageEllipse(const QPolygonF &myPolygon,int w,int h) const
{
    QRectF rectangle(myPolygon[0],myPolygon[1]);
   // QPainter painter(this);
   // painter.drawEllipse(rectangle);
    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
  // painter.translate(en, boy);
    painter.drawEllipse(rectangle);
    return pixmap;
}

QPixmap toolKalem::image(const QPolygonF &myPolygon,int w,int h) const
{
    QPixmap pixmap(w, h);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
  // painter.translate(en, boy);
    painter.drawPolyline(myPolygon);
    return pixmap;
}

QPixmap toolKalem::zeminImage(const QPolygonF &myPolygon, int w, int h,QColor zemincolor, QColor cizgicolor,int pensize) const
{
    QPixmap pixmap(w, h);
    //pixmap.fill(Qt::transparent);
    pixmap.fill(zemincolor);
    QPainter painter(&pixmap);
    painter.setPen(QPen(cizgicolor, pensize));
  // painter.translate(en, boy);
    painter.drawPolyline(myPolygon);
    return pixmap;
}

#endif // TOOLKALEMFUNCTION_H
