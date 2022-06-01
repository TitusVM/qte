#include "mainscreen.h"
#include "level.h"
#include <QDebug>
#include <QGraphicsView>

MainScreen::MainScreen(QWidget *parent, QString username)
    : QWidget(parent)
{
    this->username = username;
    this->btnNewGame = new QPushButton(tr("New Game"));
    this->btnNewLevel = new QPushButton(tr("New Level"));
    this->btnEditCreate = new QPushButton(tr("Edit Level"));
    this->btnCredits = new QPushButton(tr("Credits"));
    this->btnQuit = new QPushButton(tr("Quit"));

    connect(this->btnNewGame, &QPushButton::clicked, this, &MainScreen::slotNewGame);
    connect(this->btnNewLevel, &QPushButton::clicked, this, &MainScreen::slotNewLevel);
    connect(this->btnEditCreate, &QPushButton::clicked, this, &MainScreen::slotEditCreate);
    connect(this->btnCredits, &QPushButton::clicked, this, &MainScreen::slotCredits);
    connect(this->btnQuit, &QPushButton::clicked, this, &MainScreen::slotQuit);

    this->vbox = new QVBoxLayout();

    createUI();
    setMinimumSize(QSize(500,250));
    qDebug() << "size : " << this->size();
    qDebug() << "here as : " << this->username;
}

void MainScreen::createUI()
{
    this->vbox->addWidget(this->btnNewGame);
    this->vbox->addWidget(this->btnNewLevel);
    this->vbox->addWidget(this->btnEditCreate);
    this->vbox->addWidget(this->btnCredits);
    this->vbox->addWidget(this->btnQuit);

    setLayout(this->vbox);
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

void MainScreen::slotCredits()
{
    qDebug() << "slotCredits called";
}

void MainScreen::slotQuit()
{
    emit signalQuit();
}

