#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QFile>
#include <iostream>
#include <QTextStream>

#include "newaccount.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void checkConnexion();
    void newAccount();

private:
    QString username;
    QString password;
};

#endif // LOGIN_H
