#include "leveltrack.h"

LevelTrack::LevelTrack()
{
    qgraphicswidget = new QGraphicsWidget();
    this->timeLine = new QTimeLine();
    timeLine->setFrameRange(0, 300);
    qgraphicswidget->addItem(this->timeLine);

    this->hbox = new QHBoxLayout();
    createUI();
}

void LevelTrack::createUI()
{
    this->hbox->addWidget(this->timeLine);
    setLayout(this->hbox);
}
