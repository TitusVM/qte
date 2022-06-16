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
#include "level.h"
#include <QTimer>
#include <QMessageBox>

/**
 * @brief Gameplay::Gameplay Constructor builds the User Interface for the Gameplay Screen
 * @param parent
 */
Gameplay::Gameplay(QWidget *parent) : QWidget(parent)
{
    this->grid = new QGridLayout();

    this->lblLevelName = new QLabel(tr("Difficulty : "));
    this->lblSecondsLeft = new QLabel(tr("Seconds left : "));
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

    this->widthWindow = 1200 * 5/7 - 10;
    this->heightWindow = 600 * 4/5;

    this->viewQTEs = new QGraphicsView(this->sceneQTEs, this);
    this->viewTargets = new QGraphicsView(this->sceneTargets, this);
    viewTargets->setFixedSize(widthWindow, heightWindow);
    viewTargets->setSceneRect(0, 0, widthWindow, heightWindow);
    viewTargets->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    viewTargets->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(this->sceneTargets, &GraphicsScene::signalRepaintTarget, this, &Gameplay::slotRepaintTarget);
    connect(this->sceneTargets, &GraphicsScene::signalRepaintQTE, this, &Gameplay::slotRepaintQTE);

    score = 0;
    qteTotal = 0;
    qteHit = 0;
    targetTotal = 0;
    targetHit = 0;

    createUI();
    setMinimumSize(QSize(1200, 600));

    viewTargets->setFocus();
}

/**
 * @brief Gameplay::randomCoord returns a random coordinate for the target location RNG
 * @param max screen limit
 * @return int radomCoord random coordinate
 */
int Gameplay::randomCoord(int max)
{
    return QRandomGenerator::global()->bounded(6, max-76);
}

void Gameplay::createUI()
{
    this->grid->addWidget(this->viewQTEs, 0, 0, 4, 2);
    this->grid->addWidget(this->viewTargets, 0, 2, 4, 5);
    this->grid->addWidget(this->lblLevelName, 4, 0, 1, 2);
    this->grid->addWidget(this->lblSecondsLeft, 5, 0, 1, 2);
    this->grid->addWidget(this->lblNumberQTEs, 4, 2);
    this->grid->addWidget(this->lblAccuracyQTEs, 5, 2);
    this->grid->addWidget(this->lblAccuracyQTEsPourcentage, 5, 3);
    this->grid->addWidget(this->lblNumberTargets, 4, 5);
    this->grid->addWidget(this->lblAccuracyTargets, 5, 5);
    this->grid->addWidget(this->lblAccuracyTargetsPourcentage, 5, 6);

    setLayout(this->grid);
}

/**
 * @brief Gameplay::slotSelectDifficulty slot that allows the selection of difficulties
 */
void Gameplay::slotSelectDifficulty()
{
    // FUTURE IMPLEMENTS
}

/**
 * @brief Gameplay::slotPlayCustom slot that allows custom Level objects to be played
 */
void Gameplay::slotPlayCustom()
{
    // FUTURE IMPLEMENTS
}

/**
 * @brief Gameplay::Play the play method triggers the gameplay to start
 * @param levelName QString Name of level to be played
 * @param isCustom bool to signify if it is a new Level or if it already exists
 */
void Gameplay::Play(QString levelName, bool isCustom)
{
    level = new Level(levelName, isCustom);
    level->importLevel();

    this->lblLevelName->setText("Level name : " + levelName.split(".").at(0));
    this->lblSecondsLeft->setText("Seconds left : " + QString::number(this->level->totalSeconds));

    this->seconds = 0;

    this->qteHit = 0;
    this->qteTotal = 0;
    this->targetHit = 0;
    this->targetTotal = 0;
    this->lblNumberQTEs->setText("0");
    this->lblAccuracyQTEs->setText("Accuracy : 0/0");
    this->lblAccuracyQTEsPourcentage->setText("0%");
    this->lblNumberTargets->setText("0");
    this->lblAccuracyTargets->setText("Accuracy : 0/0");
    this->lblAccuracyTargetsPourcentage->setText("0%");

    clearTargets();
    clearQtes();

    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotUpdate()));
    timer->start(1000);
}

/**
 * @brief Gameplay::slotUpdate update visuals
 */
void Gameplay::slotUpdate()
{
    if (!this->sceneTargets->target)
    {
        clearTargets();
    }
    if (!this->sceneTargets->qte)
    {
        clearQtes();
    }

    if(level->targetsSeconds.contains(this->seconds))
    {
        if (this->sceneTargets->target)
        {
            score -= 100;
        }
        clearTargets();

        int x = randomCoord(widthWindow);
        int y = randomCoord(heightWindow);

        targetTotal++;

        this->sceneTargets->setX(x);
        this->sceneTargets->setY(y);
        Target *target1 = new Target(x, y, this->sceneTargets);
        target1->draw();

        this->viewTargets->repaint();
        this->sceneTargets->target = true;
    }
    if(level->qtesSeconds.contains(this->seconds))
    {
        if (this->sceneTargets->qte)
        {
            score -= 50;
        }
        clearQtes();

        QTE *qte = new QTE();

        QPen pen = QPen(Qt::red, 20);
        this->sceneQTEs->addEllipse((1200 - widthWindow)/2 - 200, (600 - heightWindow)/2 - 40, 300, 300, pen);

        this->sceneTargets->setKey(qte->qteKey);
        QGraphicsTextItem *text = sceneQTEs->addText(qte->qteKey);

        text->setPos((1200 - widthWindow)/2 - 130, (600 - heightWindow)/2 - 10);
        text->setFont(QFont("SansSerif", 150, 75));

        qteTotal ++;

        this->viewQTEs->repaint();
        this->sceneTargets->qte = true;
    }
    this->seconds++;
    if (this->seconds > this->level->totalSeconds)
    {
        this->timer->stop();
        QMessageBox msgBox;
        msgBox.setText("GG ! Score : " + QString::number(score) + " (Max : " + QString::number(qteTotal*50 + targetTotal*100) + ")");
        msgBox.exec();
        emit signalGameOver();
    }

    if (qteTotal != 0)
    {
        double qteAccuracy = ((double)qteHit/(double)qteTotal)*100;
        this->lblNumberQTEs->setText("Number of QTEs : " + QString::number(qteTotal));
        this->lblAccuracyQTEs->setText("Accuracy : " + QString::number(qteHit) + "/" + QString::number(qteTotal));
        this->lblAccuracyQTEsPourcentage->setText(QString::number(qteAccuracy) + "%");
    }
    if(targetTotal != 0)
    {
        double targetAccuracy = ((double)targetHit/(double)targetTotal)*100;
        this->lblNumberTargets->setText("Number of targets : " + QString::number(targetTotal));
        this->lblAccuracyTargets->setText("Accuracy : " + QString::number(targetHit) + "/" + QString::number(targetTotal));
        this->lblAccuracyTargetsPourcentage->setText(QString::number(targetAccuracy) + "%");
    }


    this->lblSecondsLeft->setText("Seconds left : " + QString::number(this->level->totalSeconds - seconds));
}

/**
 * @brief Gameplay::slotRepaintTarget
 */
void Gameplay::slotRepaintTarget()
{
    clearTargets();
}

/**
 * @brief Gameplay::slotRepaintQTE
 */
void Gameplay::slotRepaintQTE()
{
    clearQtes();
}

/**
 * @brief Gameplay::clearTargets
 */
void Gameplay::clearTargets()
{
    this->sceneTargets->clear();
}

/**
 * @brief Gameplay::clearQtes
 */
void Gameplay::clearQtes()
{
    this->sceneQTEs->clear();
}
