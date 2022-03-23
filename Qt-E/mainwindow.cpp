#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
}

void MainWindow::createUI()
{
    this->loginWindow = new Login(this);
    this->newAccountWindow = new NewAccount(this);
    this->widgetStack = new QStack<QWidget*>;

    connect(this->loginWindow, &Login::signalNewAcc, this, &MainWindow::slotNewAcc);
    connect(this->newAccountWindow, &NewAccount::signalBack, this, &MainWindow::slotBackToLogin);

    this->widgetStack->push(this->newAccountWindow);
    setCentralWidget(this->loginWindow);
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

