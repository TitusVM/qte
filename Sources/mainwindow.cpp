#include "mainwindow.h"
#include <QDebug>

/**
 * @brief MainWindow::MainWindow Constructor Initialize UI
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
}

/**
 * @brief MainWindow::createUI Create UI elements and connect required signals to slots for window changes
 */
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
    connect(this->newGameWindow, &NewGame::signalBackClicked, this, &MainWindow::slotBackToMainscreen);
    connect(this->gameplayWindow, &Gameplay::signalGameOver, this, &MainWindow::slotGameOver);
    connect(this->mainScreenWindow, &MainScreen::signalNewLevel, this, &MainWindow::slotNewLevel);
    connect(this->mainScreenWindow, &MainScreen::signalLevelEditor, this, &MainWindow::slotLevelEditor);

    setCentralWidget(this->loginWindow);
}

MainWindow::~MainWindow()
{
}


// SLOTS
/**
 * @brief MainWindow::slotNewAcc
 */
void MainWindow::slotNewAcc()
{
    takeCentralWidget();
    setCentralWidget(this->newAccountWindow);
}

/**
 * @brief MainWindow::slotBackToLogin
 */
void MainWindow::slotBackToLogin()
{
    takeCentralWidget();
    setCentralWidget(this->loginWindow);
}

/**
 * @brief MainWindow::slotLoggedIn
 */
void MainWindow::slotLoggedIn()
{
    takeCentralWidget();
    setCentralWidget(this->mainScreenWindow);
}

/**
 * @brief MainWindow::slotNewLevel
 */
void MainWindow::slotNewLevel()
{
    this->levelEditorWindow = new LevelEditor(true);
    connect(this->levelEditorWindow, &LevelEditor::signalBackClicked, this, &MainWindow::slotBackToMainscreen);

    takeCentralWidget();
    setCentralWidget(this->levelEditorWindow);
}

/**
 * @brief MainWindow::slotLevelEditor
 */
void MainWindow::slotLevelEditor()
{
    this->levelEditorWindow = new LevelEditor(false);
    connect(this->levelEditorWindow, &LevelEditor::signalBackClicked, this, &MainWindow::slotBackToMainscreen);

    takeCentralWidget();
    setCentralWidget(this->levelEditorWindow);
}

/**
 * @brief MainWindow::slotQuit
 */
void MainWindow::slotQuit()
{
    close();
}

/**
 * @brief MainWindow::slotNewGame
 */
void MainWindow::slotNewGame()
{
    takeCentralWidget();
    setCentralWidget(this->newGameWindow);
}

/**
 * @brief MainWindow::slotPlay
 * @param levelName
 * @param isCustom
 */
void MainWindow::slotPlay(QString levelName, bool isCustom)
{
    takeCentralWidget();
    setCentralWidget(this->gameplayWindow);
    this->gameplayWindow->Play(levelName, isCustom);
}

/**
 * @brief MainWindow::slotGameOver
 */
void MainWindow::slotGameOver()
{
    takeCentralWidget();
    setCentralWidget(this->mainScreenWindow);
}

/**
 * @brief MainWindow::slotBackToMainscreen
 */
void MainWindow::slotBackToMainscreen()
{
    takeCentralWidget();
    setCentralWidget(this->mainScreenWindow);
}
