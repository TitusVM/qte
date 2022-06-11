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
    this->newGameWindow = new NewGame();
    this->gameplayWindow = new Gameplay();
    this->mainScreenWindow = new MainScreen();
    this->newAccountWindow = new NewAccount();

    connect(this->loginWindow, &Login::signalNewAcc, this, &MainWindow::slotNewAcc);
    connect(this->loginWindow, &Login::signalLoggedIn, this, &MainWindow::slotLoggedIn);
    connect(this->newAccountWindow, &NewAccount::signalBack, this, &MainWindow::slotBackToLogin);
    connect(this->newAccountWindow, &NewAccount::signalLoggedIn, this, &MainWindow::slotLoggedIn);
    connect(this->mainScreenWindow, &MainScreen::signalQuit, this, &MainWindow::slotQuit);
    connect(this->mainScreenWindow, &MainScreen::signalNewGame, this, &MainWindow::slotNewGame);
    connect(this->loginWindow, &Login::signalLoggedIn, this, &MainWindow::slotLoggedIn);
    connect(this->newGameWindow, &NewGame::signalLevelPlay, this, &MainWindow::slotPlay);
    connect(this->gameplayWindow, &Gameplay::signalGameOver, this, &MainWindow::slotGameOver);
    connect(this->mainScreenWindow, &MainScreen::signalNewLevel, this, &MainWindow::slotNewLevel);
    connect(this->mainScreenWindow, &MainScreen::signalLevelEditor, this, &MainWindow::slotLevelEditor);

    setCentralWidget(this->loginWindow);
}

MainWindow::~MainWindow()
{
}


// SLOTS
void MainWindow::slotNewAcc()
{
    //this->loginWindow->setParent(NULL); TODO ADD TO DOC
    takeCentralWidget();
    setCentralWidget(this->newAccountWindow);
}

void MainWindow::slotBackToLogin()
{
    //this->newAccountWindow->setParent(NULL); TODO ADD TO DOC
    takeCentralWidget();
    setCentralWidget(this->loginWindow);
}

void MainWindow::slotLoggedIn()
{
    takeCentralWidget();
    setCentralWidget(this->mainScreenWindow);
}

void MainWindow::slotNewLevel()
{
    this->levelEditorWindow = new LevelEditor(true);
    connect(this->levelEditorWindow, &LevelEditor::signalBackClicked, this, &MainWindow::slotBackToMainscreen);

    takeCentralWidget();
    setCentralWidget(this->levelEditorWindow);
}

void MainWindow::slotLevelEditor()
{
    this->levelEditorWindow = new LevelEditor(false);
    connect(this->levelEditorWindow, &LevelEditor::signalBackClicked, this, &MainWindow::slotBackToMainscreen);

    takeCentralWidget();
    setCentralWidget(this->levelEditorWindow);
 }

void MainWindow::slotQuit()
{
    close();
}

void MainWindow::slotNewGame()
{
    takeCentralWidget();
    setCentralWidget(this->newGameWindow);
}

void MainWindow::slotPlay(QString levelName, bool isCustom)
{
    takeCentralWidget();
    setCentralWidget(this->gameplayWindow);
    this->gameplayWindow->Play(levelName, isCustom);
}

void MainWindow::slotGameOver()
{
    takeCentralWidget();
    setCentralWidget(this->mainScreenWindow);
}

void MainWindow::slotBackToMainscreen()
{
    takeCentralWidget();
    setCentralWidget(this->mainScreenWindow);
}
