#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
}

void MainWindow::createUI()
{
    this->loginWindow = new Login();
    this->newAccountWindow = new NewAccount();
    this->newGameWindow = new NewGame();
    this->gameplayWindow = new Gameplay();
    this->mainScreenWindow = new MainScreen();
    //this->levelEditorWindow = new LevelEditor();
    this->widgetStack = new QStack<QWidget*>;

    connect(this->loginWindow, &Login::signalNewAcc, this, &MainWindow::slotNewAcc);
    connect(this->newAccountWindow, &NewAccount::signalBack, this, &MainWindow::slotBackToLogin);
    connect(this->loginWindow, &Login::signalLoggedIn, this, &MainWindow::slotLoggedIn);
    connect(this->newGameWindow, &NewGame::signalLevelPlay, this, &MainWindow::slotPlay);
    connect(this->gameplayWindow, &Gameplay::signalGameOver, this, &MainWindow::slotGameOver);
    connect(this->mainScreenWindow, &MainScreen::signalLevelEditor, this, &MainWindow::slotLevelEditor);

    //this->widgetStack->push(this->loginWindow);
    //this->widgetStack->push(this->newAccountWindow);

    //setCentralWidget(this->loginWindow);
    //setCentralWidget(this->newGameWindow);
    this->widgetStack->push(this->newGameWindow);
    this->widgetStack->push(this->gameplayWindow);
    setCentralWidget(this->mainScreenWindow);
    //setCentralWidget(this->newGameWindow);
    //this->widgetStack->push(this->newGameWindow);
    //this->widgetStack->push(this->gameplayWindow);
    //setCentralWidget(this->levelEditorWindow);
}

MainWindow::~MainWindow()
{
}


// SLOTS
void MainWindow::slotNewAcc()
{
    //this->loginWindow->setParent(NULL); TODO ADD TO DOC
    this->newAccountWindow = (NewAccount*)this->widgetStack->pop();
    this->widgetStack->push(this->loginWindow);
    takeCentralWidget();
    setCentralWidget(this->newAccountWindow);
}

void MainWindow::slotBackToLogin()
{
    //this->newAccountWindow->setParent(NULL); TODO ADD TO DOC
    this->loginWindow = (Login*)this->widgetStack->pop();
    this->widgetStack->push(this->newAccountWindow);
    takeCentralWidget();
    setCentralWidget(this->loginWindow);
}

void MainWindow::slotLoggedIn()
{
    this->mainScreenWindow = new MainScreen(this, "TODO_USERNAME");

    connect(this->mainScreenWindow, &MainScreen::signalQuit, this, &MainWindow::slotQuit);

    qDebug() << "slotLoggedIn called";
    this->widgetStack->push(this->loginWindow);
    takeCentralWidget();
    setCentralWidget(this->mainScreenWindow);
}

void MainWindow::slotLevelEditor()
{
    this->levelEditorWindow = new LevelEditor();
    setCentralWidget(this->levelEditorWindow);
}

void MainWindow::slotQuit()
{
    close();
}

void MainWindow::slotPlay(QString levelName)
{
    this->gameplayWindow->Play(levelName);

    this->widgetStack->push(this->newGameWindow);
    takeCentralWidget();
    setCentralWidget(this->gameplayWindow);
}

void MainWindow::slotGameOver()
{
    this->widgetStack->push(this->gameplayWindow);
    takeCentralWidget();
    setCentralWidget(this->newGameWindow);
}
