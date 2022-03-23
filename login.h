#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QFile>
#include <iostream>
#include <QTextStream>

<<<<<<< HEAD
<<<<<<< HEAD
#include "newaccount.h"

=======
>>>>>>> 270c0c9 (Login's logic development)
=======
#include "newaccount.h"

>>>>>>> d7ddc7e (bug fix in login)
class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void checkConnexion();
<<<<<<< HEAD
<<<<<<< HEAD
    void newAccount();
=======
>>>>>>> 270c0c9 (Login's logic development)
=======
    void newAccount();
>>>>>>> d7ddc7e (bug fix in login)

private:
    QString username;
    QString password;
};

#endif // LOGIN_H
