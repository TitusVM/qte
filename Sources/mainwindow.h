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
    void slotPlay(QString levelName);
    void slotNewGame();
    void slotGameOver();
    void slotLevelEditor();
    void slotNewLevel();
    void slotBackToMainscreen();
};
#endif // MAINWINDOW_H
