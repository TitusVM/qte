#include "graphicsscene.h"

#include <QGraphicsSceneMouseEvent>
#include "target.h"
#include <QPixmap>
#include <QKeyEvent>

GraphicsScene::GraphicsScene(Gameplay *parent) : QGraphicsScene(parent)
{
    target = false;
    qte = false;
    this->parent = parent;
}

void GraphicsScene::setX(int value)
{
    this->x = value;
}

void GraphicsScene::setY(int value)
{
    this->y = value;
}

void GraphicsScene::setKey(QChar key)
{
    this->key = key;
}


void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QGraphicsItem *item = itemAt(event->scenePos(), QTransform());// it is your clicked item, you can do everything what you want. for example send it somewhere

        if (item != nullptr)
        {
            Target *target = (Target *) item;

            int score = target->clicked(this->x, this->y, event->scenePos().x(), event->scenePos().y());
            this->target = false;
            this->parent->score += score;
            this->parent->targetHit++;
        }
    }
}

void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    try
    {
        if (this->key == (QChar)event->key())
        {
            this->qte = false;
            this->parent->score += 50;
            this->parent->qteHit++;
        }
    }
    catch (...)
    {

    }

}
