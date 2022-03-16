#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QFile>
#include <iostream>
#include <QTextStream>

<<<<<<< HEAD
#include "newaccount.h"

=======
>>>>>>> 270c0c9 (Login's logic development)
class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void checkConnexion();
<<<<<<< HEAD
    void newAccount();
=======
>>>>>>> 270c0c9 (Login's logic development)

private:
    QString username;
    QString password;
};

#endif // LOGIN_H
