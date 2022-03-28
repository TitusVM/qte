#include "newgame.h"
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>

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

    this->cbxSelectCustomLevels = new QComboBox();
    this->cbxSelectCustomLevels->addItem(tr("test"));

    this->btnPlayCustom = new QPushButton(tr("Play Level"));

    connect(this->btnEasy, &QPushButton::clicked, this, &NewGame::slotSelectDifficulty);
    connect(this->btnNormal, &QPushButton::clicked, this, &NewGame::slotSelectDifficulty);
    connect(this->btnHard, &QPushButton::clicked, this, &NewGame::slotSelectDifficulty);
    connect(this->btnPlayCustom, &QPushButton::clicked, this, &NewGame::slotPlayCustom);

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
    this->grid->addWidget(this->cbxSelectCustomLevels, 7, 1);
    this->grid->addWidget(this->btnPlayCustom, 8, 1);

    //Spaces
    this->grid->addWidget(new QLabel(), 5, 1);
    this->grid->addWidget(new QLabel(), 8, 2);
    this->grid->addWidget(new QLabel(), 8, 0);

    setLayout(this->grid);
}

void NewGame::slotSelectDifficulty()
{
    // truc
}

void NewGame::slotPlayCustom()
{
    // un autre truc
}
