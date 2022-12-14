#include "target.h"
#include <QPen>
#include <QGraphicsScene>
#include <math.h>

/**
 * @brief Target::Target Constructor, initializes the QGraphicsScene and the coordinates
 * @param x
 * @param y
 * @param parent
 */
Target::Target(int x, int y, QGraphicsScene *parent)
{
    this->scene = parent;
    this->x = &x;
    this->y = &y;
}

/**
 * @brief Target::draw implements the draw method to draw on the object's QGraphicsScene
 */
void Target::draw()
{
    QPen pen = QPen();
    pen.setColor(Qt::black);
    pen.setWidth(11);
    this->scene->addEllipse(*(this->x), *(this->y), 70, 70, pen);
    pen.setColor(QColor(0, 114, 206));
    pen.setWidth(11);
    this->scene->addEllipse(*(this->x)+10, *(this->y)+10, 50, 50, pen);
    pen.setColor(Qt::red);
    pen.setWidth(11);
    this->scene->addEllipse(*(this->x)+20, *(this->y)+20, 30, 30, pen);
    pen.setColor(Qt::yellow);
    pen.setWidth(11);
    this->scene->addEllipse(*(this->x)+30, *(this->y)+30, 10, 10, pen);
}

/**
 * @brief Target::mousePressEvent handles the mouse event
 * @param event
 */
void Target::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        qDebug() << "WTF WORKS !!!";
    }
}

/**
 * @brief Target::clicked Handles the scoring based on the coordinates of the event
 * @param centerX
 * @param centerY
 * @param clickedX
 * @param clickedY
 * @return
 */
int Target::clicked(int centerX, int centerY, int clickedX, int clickedY)
{
    int vectorX = clickedX - (centerX+35);
    int vectorY = clickedY - (centerY+35);

    int length = sqrt(pow(vectorX, 2) + pow(vectorY, 2));

    if (length > 30)
    {
        return 25;
    }
    else if (length > 20)
    {
        return 50;
    }
    else if (length > 10)
    {
        return 75;
    }
    else
    {
        return 100;
    }
}
