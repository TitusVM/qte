#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include "newaccount.h"
#include "newgame.h"
#include "mainscreen.h"
#include "gameplay.h"
#include "leveleditor.h"

#include <QMainWindow>
#include <QStack>

/**
 * @brief The MainWindow class extends QMainWindow and handles the general User Interface of the application.
 * It also handles all the signals coming from the various QWidgets it contains. All the various UIs of the
 * application are contained, instanciated and executed in this class. All the window changes are done in this
 * class as well. The two methods most useful to window changes are:
 *
 *      - QMainWindow::takeCentralWidget() allows you to remove the currently shown central widget
 *      - QMainWindow::setCentralWidget(QWidget) allows you to show given widget as central widget
 *
 * All the slots in this class are made to capture underlying signals coming from the various interfaces
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createUI();

private:
    Login *loginWindow;
    NewAccount *newAccountWindow;
    NewGame *newGameWindow;
    MainScreen *mainScreenWindow;
    Gameplay *gameplayWindow;
    LevelEditor *levelEditorWindow;

    QStack<QWidget*> *widgetStack;


public slots:
    void slotNewAcc();
    void slotBackToLogin();
    void slotLoggedIn();
    void slotQuit();
    void slotPlay(QString levelName, bool isCustom);
    void slotNewGame();
    void slotGameOver();
    void slotLevelEditor();
    void slotNewLevel();
    void slotBackToMainscreen();
};
#endif // MAINWINDOW_H
