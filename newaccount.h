#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include "login.h"

class NewAccount : public Login
{
    Q_OBJECT

public:
    NewAccount(QWidget *parent = nullptr);
    ~NewAccount();

    void createAccount();

private:
    QString username;
    QString password;
};

#endif // NEWACCOUNT_H
