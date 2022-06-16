#include "graphicsscene.h"

#include <QGraphicsSceneMouseEvent>
#include "target.h"
#include <QPixmap>
#include <QKeyEvent>

/**
 * @brief GraphicsScene::GraphicsScene Constructor
 * @param parent
 */
GraphicsScene::GraphicsScene(Gameplay *parent) : QGraphicsScene(parent)
{
    target = false;
    qte = false;
    this->parent = parent;
}

/**
 * @brief GraphicsScene::setX
 * @param value
 */
void GraphicsScene::setX(int value)
{
    this->x = value;
}

/**
 * @brief GraphicsScene::setY
 * @param value
 */
void GraphicsScene::setY(int value)
{
    this->y = value;
}

/**
 * @brief GraphicsScene::setKey
 * @param key
 */
void GraphicsScene::setKey(QChar key)
{
    this->key = key;
}

/**
 * @brief GraphicsScene::mousePressEvent checks whether the mouse event was on Target or not
 * @param event
 */
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QGraphicsItem *item = itemAt(event->scenePos(), QTransform());// it is your clicked item, you can do everything what you want. for example send it somewhere

        if (item != nullptr && this->target)
        {
            Target *target = (Target *) item;

            int score = target->clicked(this->x, this->y, event->scenePos().x(), event->scenePos().y());
            this->target = false;
            this->parent->score += score;
            this->parent->targetHit++;
            emit signalRepaintTarget();
        }
        else
        {
            this->parent->score -= 100;
        }
    }
}

/**
 * @brief GraphicsScene::keyPressEvent checks whether the key event was the same as what was asked for in the Qte
 * @param event
 */
void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    try
    {
        if(event->key() >= 0xffff)
        {
            return;
        }

        if (this->key == (QChar)event->key() && this->qte)
        {
            this->qte = false;
            this->parent->score += 50;
            this->parent->qteHit++;
            emit signalRepaintQTE();
        }
        else
        {
            this->parent->score -= 50;
        }
    }
    catch (...)
    {
    // Simply to avoid that the programm crashes if system keys are pressed for instance
    }
}
