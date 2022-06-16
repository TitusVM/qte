#ifndef Gameplay_H
#define Gameplay_H

#include <QWidget>

class QLabel;
class QGridLayout;
class QGraphicsScene;
class QGraphicsView;
class GraphicsScene;
class Level;


/**
 * @brief The Gameplay class extends QWidget and is where the game actually takes place. Here the Level container is sequentially
 * read and the events are drawn out in two seperate displays. There is one display for the target and another
 * display for the Qtes. It also launches a timer to be able to keep the events of the Level structure
 * synchronised.
 */
class Gameplay : public QWidget
{
    Q_OBJECT
public:
    Gameplay(QWidget *parent = nullptr);
    void createUI();
    int randomCoord(int max);
    void Play(QString levelName, bool isCustom);
    void clearTargets();
    void clearQtes();

    int targetHit;
    int qteHit;
    int score;

private:
    QLabel *lblLevelName;
    QLabel *lblSecondsLeft;
    QLabel *lblNumberQTEs;
    QLabel *lblAccuracyQTEs;
    QLabel *lblAccuracyQTEsPourcentage;
    QLabel *lblNumberTargets;
    QLabel *lblAccuracyTargets;
    QLabel *lblAccuracyTargetsPourcentage;

    QGraphicsScene *sceneQTEs;
    GraphicsScene *sceneTargets;

    QGraphicsView *viewQTEs;
    QGraphicsView *viewTargets;

    QGridLayout *grid;

    QTimer *timer;
    Level *level;

    int seconds;
    int widthWindow;
    int heightWindow;
    int qteTotal;
    int targetTotal;

private slots:
    void slotSelectDifficulty();
    void slotPlayCustom();
    void slotUpdate();
    void slotRepaintTarget();
    void slotRepaintQTE();

signals:
    void signalGameOver();
};

#endif // Gameplay_H
