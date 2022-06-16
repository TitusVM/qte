#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

/**
 * @brief The Target class is the implementation of an event in the sequential event structure. It holds the
 * necessary information to display a Target at a particular time in the Level.
 */
class Target
{
public:
    Target(int x, int y, QGraphicsScene *parent);
    void draw();
    int clicked(int centerX, int centerY, int clickedX, int clickedY);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsScene *scene;
    int *x;
    int *y;
};

#endif // TARGET_H
