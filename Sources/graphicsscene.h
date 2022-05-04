#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include "gameplay.h"

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(Gameplay *parent = 0);
    void setX(int value);
    void setY(int value);
    void setKey(QChar key);
    bool target;
    bool qte;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    int x;
    int y;
    Gameplay *parent;
    QChar key;
};

#endif // GRAPHICSSCENE_H
