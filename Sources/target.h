#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

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
