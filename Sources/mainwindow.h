#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include "newaccount.h"
#include "newgame.h"
#include "mainscreen.h"
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

    QStack<QWidget*> *widgetStack;


public slots:
    void slotNewAcc();
    void slotBackToLogin();
    void slotLoggedIn();
    void slotQuit();
};
#endif // MAINWINDOW_H
