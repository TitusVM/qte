#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include "newaccount.h"
#include "newgame.h"
#include <QMainWindow>
#include <QStack>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createUI();

public slots:
    void slotNewAcc();
    void slotBackToLogin();

private:
    Login *loginWindow;
    NewAccount *newAccountWindow;
    NewGame *newGameWindow;

    QStack<QWidget*> *widgetStack;
};
#endif // MAINWINDOW_H
