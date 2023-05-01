#ifndef TOOLKALEMSIGNALSLOTS_H
#define TOOLKALEMSIGNALSLOTS_H
#include<toolKalem.h>

void toolKalem::sceneItemAddedSignalSlot(Scene *scenetemp, QGraphicsItem *item, bool additemstate, Scene::Mode mode, DiagramItem::DiagramType type)
{
    scenetemp->addItem(item);
    current_toolTahta->update();
    if (additemstate) secSayfaButtonClick(current_toolTahta->current_sceneIndex);
    scenetemp->graphicsList.append(item);
    scenetemp->graphicsListTemp.append(item);
    scenetemp->historyBack.append(item);
    scenetemp->historyBackAction.append("added");
    depo::historyBackCount=scenetemp->historyBack.count();
    depo::historyNextCount=scenetemp->historyNext.count();
    qDebug()<<"scene nesne eklendi.....";

}

void toolKalem::sceneItemRemovedSignalSlot(Scene *scenetemp, QGraphicsItem *item,Scene::Mode mode)
{
    /*scenetemp->addItem(item);
    scenetemp->graphicsList.append(item);
    scenetemp->graphicsListTemp.append(item);
    scenetemp->historyBack.append(item);
    scenetemp->historyBackAction.append("added");
    depo::historyBackCount=scenetemp->historyBack.count();
    depo::historyNextCount=scenetemp->historyNext.count();*/

    qDebug()<<"scene nesne Silindi......";
    secSayfaButtonClick(current_toolTahta->current_sceneIndex);
}

void toolKalem::kalemColorSignalSlot(QString colorType, QColor color)
{

  if (colorType=="penColor"){
     // qDebug()<<"penColor";
    penColor=color;
    current_toolTahta->scene->setSekilKalemColor( penColor);
    current_toolTahta->scene->setPenColor( penColor);
    penColorButton->setStyleSheet(QString("QToolButton{ background: %1; }").arg(penColor.name()));
  }
  if (colorType=="sekilZeminColor"){
     //qDebug()<<"sekilZeminColor"<<color;
     sekilZeminColor=color;
    current_toolTahta->scene->setSekilZeminColor(sekilZeminColor);
   }
  if (colorType=="zeminGridColor"){
     //qDebug()<<"sekilZeminColor"<<color;
     zeminGridColor=color;
    // kalemModeSignalSlot(Scene::Mode::ZeminMode,pagePattern);
     emit kalemModeSignal(Scene::Mode::ZeminMode,pagePattern);

    }
  if (colorType=="zeminColor"){
     //qDebug()<<"zeminColor"<<color;
     zeminColor=color;
     emit kalemZeminModeSignal(DiagramItem::DiagramType::CustomColorPage);
     //emit kalemModeSignal(Scene::Mode::ZeminMode,pagePattern);
   }
  if (colorType=="zeminDolguColor"){
     //qDebug()<<"zeminDolguColor"<<color;
     zeminDolguColor=color;
     current_toolTahta->scene->myzeminDolguColor=color;
   }
}

void toolKalem::sayacCloseSignalSlot()
{
//qDebug()<<"sayac Kapandı..";
current_toolTahta->setWindowFlags(current_toolTahta_old_flags);
current_toolTahta->show();
}

#endif // TOOLKALEMSIGNALSLOTS_H
