#ifndef Gameplay_H
#define Gameplay_H

#include <QWidget>

class QLabel;
class QGridLayout;
class QGraphicsScene;
class QGraphicsView;

class Gameplay : public QWidget
{
    Q_OBJECT
public:
    Gameplay(QWidget *parent = nullptr);
    void createUI();

private:
    QLabel *lblDifficulty;
    QLabel *lblNumberQTEs;
    QLabel *lblAccuracyQTEs;
    QLabel *lblAccuracyQTEsPourcentage;
    QLabel *lblNumberTargets;
    QLabel *lblAccuracyTargets;
    QLabel *lblAccuracyTargetsPourcentage;

    QGraphicsScene *sceneQTEs;
    QGraphicsScene *sceneTargets;

    QGraphicsView *viewQTEs;
    QGraphicsView *viewTargets;

    QGridLayout *grid;

private slots:
    void slotSelectDifficulty();
    void slotPlayCustom();
};

#endif // Gameplay_H
