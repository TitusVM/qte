#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

/**
 * @brief main The main function of the programm
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
