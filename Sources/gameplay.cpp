#include "gameplay.h"
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include "target.h"
#include "graphicsscene.h"
#include <QRandomGenerator>
#include <QKeyEvent>
#include "qte.h"

Gameplay::Gameplay(QWidget *parent) : QWidget(parent)
{
    this->grid = new QGridLayout();

    this->lblDifficulty = new QLabel(tr("Difficulty : "));
    this->lblNumberQTEs = new QLabel(tr("Number of QTEs : "));
    this->lblAccuracyQTEs= new QLabel(tr("Accuracy : "));
    this->lblAccuracyQTEsPourcentage = new QLabel(tr("%"));
    this->lblAccuracyQTEsPourcentage->setStyleSheet("font-weight: bold;");
    this->lblNumberTargets = new QLabel(tr("Number of targets : "));
    this->lblAccuracyTargets = new QLabel(tr("Accuracy : "));
    this->lblAccuracyTargetsPourcentage = new QLabel(tr("%"));
    this->lblAccuracyTargetsPourcentage->setStyleSheet("font-weight: bold;");

    this->sceneQTEs = new QGraphicsScene(this);
    this->sceneTargets = new GraphicsScene(this);

    QPen pen = QPen(Qt::red, 20);
    this->sceneQTEs->addEllipse(this->sceneQTEs->width()/2, this->sceneQTEs->height()/2, 250, 250, pen);

    QTE *qte = new QTE();
    this->sceneTargets->setKey(qte->qteKey);
    QGraphicsTextItem *text = sceneQTEs->addText(qte->qteKey);

    int width = 1200 * 5/7 - 10;
    int height = 600 * 4/5;

    text->setPos((1200-width)/2 - 120, (600 - height)/2 - 50);
    text->setFont(QFont("SansSerif", 150, 75));

    int x = randomCoord(width)-50;
    int y = randomCoord(height)-50;

    this->sceneTargets->setX(x);
    this->sceneTargets->setY(y);
    Target *target1 = new Target(x, y, this->sceneTargets);
    target1->draw();

    this->viewQTEs = new QGraphicsView(this->sceneQTEs, this);
    this->viewTargets = new QGraphicsView(this->sceneTargets, this);
    viewTargets->setFixedSize(width, height);
    viewTargets->setSceneRect(0, 0, width, height);
    viewTargets->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    viewTargets->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    createUI();
    //setMinimumSize(QSize(1200, 600));

    //viewTargets->setFocus();
}


int Gameplay::randomCoord(int max)
{
    return QRandomGenerator::global()->bounded(5, max);
}

void Gameplay::createUI()
{
    this->grid->addWidget(this->viewQTEs, 0, 0, 4, 2);
    this->grid->addWidget(this->viewTargets, 0, 2, 4, 5);
    this->grid->addWidget(this->lblDifficulty, 4, 0, 1, 2);
    this->grid->addWidget(this->lblNumberQTEs, 4, 2);
    this->grid->addWidget(this->lblAccuracyQTEs, 5, 2);
    this->grid->addWidget(this->lblAccuracyQTEsPourcentage, 5, 3);
    this->grid->addWidget(this->lblNumberTargets, 4, 5);
    this->grid->addWidget(this->lblAccuracyTargets, 5, 5);
    this->grid->addWidget(this->lblAccuracyTargetsPourcentage, 5, 6);

    setLayout(this->grid);
}

void Gameplay::slotSelectDifficulty()
{
    // truc
}

void Gameplay::slotPlayCustom()
{
    // un autre truc
}
