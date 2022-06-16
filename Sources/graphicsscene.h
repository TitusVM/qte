#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include "gameplay.h"
/**
 * @brief The GraphicsScene class is a custom class extending the QGraphicsScene. It allows the capturing
 * of mouse click events and position of said events. It also captures hit keyboard keys and tests them
 * against the sequential event structure (in this case a Level object).
 */
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
