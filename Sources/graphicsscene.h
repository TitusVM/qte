#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include "gameplay.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

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

signals:
    void signalRepaintTarget();
    void signalRepaintQTE();

private:
    int x;
    int y;
    Gameplay *parent;
    QChar key;
};

#endif // GRAPHICSSCENE_H
