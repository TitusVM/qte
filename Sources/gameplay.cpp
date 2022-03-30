#include "gameplay.h"
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>

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
    this->sceneTargets = new QGraphicsScene(this);

    QPen pen = QPen(Qt::red, 20);
    this->sceneQTEs->addEllipse(this->sceneQTEs->width()/2, this->sceneQTEs->height()/2, 250, 250, pen);

    pen.setColor(Qt::black);
    pen.setWidth(11);
    this->sceneTargets->addEllipse(200, 200, 70, 70, pen);
    pen.setColor(QColor(0, 114, 206));
    pen.setWidth(11);
    this->sceneTargets->addEllipse(210, 210, 50, 50, pen);
    pen.setColor(Qt::red);
    pen.setWidth(11);
    this->sceneTargets->addEllipse(220, 220, 30, 30, pen);
    pen.setColor(Qt::yellow);
    pen.setWidth(11);
    this->sceneTargets->addEllipse(230, 230, 10, 10, pen);

    this->viewQTEs = new QGraphicsView(this->sceneQTEs, this);
    this->viewTargets = new QGraphicsView(this->sceneTargets, this);

    createUI();
    setMinimumSize(QSize(1200, 600));
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
