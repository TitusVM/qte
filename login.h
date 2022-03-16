#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QFile>
#include <iostream>
#include <QTextStream>

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void checkConnexion();

private:
    QString username;
    QString password;
};

#endif // LOGIN_H
