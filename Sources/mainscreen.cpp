#include "mainscreen.h"
#include "level.h"
#include <QDebug>
#include <QGraphicsView>
#include <QLabel>

MainScreen::MainScreen(QWidget *parent, QString username)
    : QWidget(parent)
{
    this->username = username;
    this->btnNewGame = new QPushButton(tr("New Game"));
    this->btnNewLevel = new QPushButton(tr("New Level"));
    this->btnEditCreate = new QPushButton(tr("Edit Level"));
    this->btnQuit = new QPushButton(tr("Quit"));

    connect(this->btnNewGame, &QPushButton::clicked, this, &MainScreen::slotNewGame);
    connect(this->btnNewLevel, &QPushButton::clicked, this, &MainScreen::slotNewLevel);
    connect(this->btnEditCreate, &QPushButton::clicked, this, &MainScreen::slotEditCreate);
    connect(this->btnQuit, &QPushButton::clicked, this, &MainScreen::slotQuit);

    this->grid = new QGridLayout();

    createUI();
    setMinimumSize(QSize(1200, 600));
}

void MainScreen::createUI()
{
    this->grid->addWidget(this->btnNewGame, 1, 1);
    this->grid->addWidget(this->btnNewLevel, 2, 1);
    this->grid->addWidget(this->btnEditCreate, 3, 1);
    this->grid->addWidget(this->btnQuit, 5, 1);
    this->grid->addWidget(new QLabel(), 0, 0);
    this->grid->addWidget(new QLabel(), 4, 2);
    this->grid->addWidget(new QLabel(), 5, 0);

    setLayout(this->grid);
}

void MainScreen::createNewGame()
{

}

void MainScreen::createLevelEditor()
{
    emit signalLevelEditor();
}

void MainScreen::showCredits()
{

}

// Slots

void MainScreen::slotNewGame()
{
    emit signalNewGame();
}

void MainScreen::slotNewLevel()
{
    emit signalNewLevel();
}


void MainScreen::slotEditCreate()
{
    createLevelEditor();
}

void MainScreen::slotQuit()
{
    emit signalQuit();
}

