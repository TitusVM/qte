#include "newgame.h"
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>
#include <QFileDialog>
#include "level.h"

/**
 * @brief NewGame::NewGame Constructor, initializes UI elements
 * @param parent
 */
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
    this->btnBack = new QPushButton(tr("Back"));

    connect(this->btnEasy, &QPushButton::clicked, this, &NewGame::slotSelectEasy);
    connect(this->btnNormal, &QPushButton::clicked, this, &NewGame::slotSelectNormal);
    connect(this->btnHard, &QPushButton::clicked, this, &NewGame::slotSelectHard);
    connect(this->btnSelectCustom, &QPushButton::clicked, this, &NewGame::slotPlayCustom);
    connect(this->btnBack, &QPushButton::clicked, this, &NewGame::slotBack);

    createUI();
}

/**
 * @brief NewGame::createUI adds to layout
 */
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
    this->grid->addWidget(this->btnBack, 9, 1);

    //Spaces
    this->grid->addWidget(new QLabel(), 5, 1);
    this->grid->addWidget(new QLabel(), 8, 2);
    this->grid->addWidget(new QLabel(), 8, 0);

    setLayout(this->grid);
}

/**
 * @brief NewGame::slotSelectEasy
 */
void NewGame::slotSelectEasy()
{
    QString levelName ="Easy.csv";
    emit signalLevelPlay(levelName, false);
}

/**
 * @brief NewGame::slotSelectNormal
 */
void NewGame::slotSelectNormal()
{
    QString levelName ="Normal.csv";
    emit signalLevelPlay(levelName, false);
}

/**
 * @brief NewGame::slotSelectHard
 */
void NewGame::slotSelectHard()
{
    QString levelName ="Hard.csv";
    emit signalLevelPlay(levelName, false);
}

/**
 * @brief NewGame::slotPlayCustom
 */
void NewGame::slotPlayCustom()
{
    QString levelName = QFileDialog::getOpenFileName(this, tr("Open Level"), ".", tr("Level Files (*.csv)"));
    emit signalLevelPlay(levelName, true);
}

/**
 * @brief NewGame::slotBack
 */
void NewGame::slotBack()
{
    emit signalBackClicked();
}
