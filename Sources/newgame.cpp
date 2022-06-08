#include "newgame.h"
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>
#include <QFileDialog>
#include "level.h"

NewGame::NewGame(QWidget *parent) : QWidget(parent)
{
    this->grid = new QGridLayout();

    this->lblNewGame = new QLabel(tr("New Game"));
    this->lblNewGame->setStyleSheet("font-weight: bold;");

    this->lblDefaultLevels = new QLabel(tr("Default Levels"));
    this->lblCustomLevels = new QLabel(tr("Or select a level"));

    this->btnEasy = new QPushButton(tr("Easy"));
    this->btnNormal = new QPushButton(tr("Normal"));
    this->btnHard = new QPushButton(tr("Hard"));

    this->btnSelectCustom = new QPushButton("Browse");

    this->btnPlayCustom = new QPushButton(tr("Play Level"));

    connect(this->btnEasy, &QPushButton::clicked, this, &NewGame::slotSelectEasy);
    connect(this->btnNormal, &QPushButton::clicked, this, &NewGame::slotSelectNormal);
    connect(this->btnHard, &QPushButton::clicked, this, &NewGame::slotSelectHard);
    connect(this->btnSelectCustom, &QPushButton::clicked, this, &NewGame::slotPlayCustom);

    createUI();
}

void NewGame::createUI()
{
    this->grid->addWidget(this->lblNewGame, 0, 1);
    this->grid->addWidget(this->lblDefaultLevels, 1, 1);
    this->grid->addWidget(this->btnEasy, 2, 1);
    this->grid->addWidget(this->btnNormal, 3, 1);
    this->grid->addWidget(this->btnHard, 4, 1);
    this->grid->addWidget(this->lblCustomLevels, 6, 1);
    this->grid->addWidget(this->btnSelectCustom, 7, 1);
    this->grid->addWidget(this->btnPlayCustom, 8, 1);

    //Spaces
    this->grid->addWidget(new QLabel(), 5, 1);
    this->grid->addWidget(new QLabel(), 8, 2);
    this->grid->addWidget(new QLabel(), 8, 0);

    setLayout(this->grid);
}

void NewGame::slotSelectEasy()
{
    QString levelName ="Easy.csv";
    emit signalLevelPlay(levelName, false);
}

void NewGame::slotSelectNormal()
{
    QString levelName ="Normal.csv";
    emit signalLevelPlay(levelName, false);
}

void NewGame::slotSelectHard()
{
    QString levelName ="Hard.csv";
    emit signalLevelPlay(levelName, false);
}

void NewGame::slotPlayCustom()
{
    qDebug() << "oho";
    QString levelName = QFileDialog::getOpenFileName(this, tr("Open Level"), ".", tr("Level Files (*.csv)"));
    emit signalLevelPlay(levelName, true);
}
