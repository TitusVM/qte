#include "login.h"
#include "newaccount.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    this->lineUsername = new QLineEdit();
    this->lineUsername->setPlaceholderText(tr("Username"));

    this->linePassword = new QLineEdit();
    this->linePassword->setPlaceholderText(tr("Password"));
    this->linePassword->setEchoMode(QLineEdit::Password);

    this->btnLogin = new QPushButton(tr("Login"));
    this->btnLogin->setDefault(false);
    this->btnLogin->setAutoDefault(true);
    this->btnNewAcc = new QPushButton(tr("New Account"));
    this->btnNewAcc->setDefault(false);
    this->btnNewAcc->setAutoDefault(true);

    connect(this->lineUsername, &QLineEdit::returnPressed, this, &Login::slotReturnHandler);
    connect(this->linePassword, &QLineEdit::returnPressed, this, &Login::slotReturnHandler);
    connect(this->btnLogin, &QPushButton::clicked, this, &Login::slotReturnHandler);
    connect(this->btnNewAcc, &QPushButton::clicked, this, &Login::slotNewAcc);

    createUI();
}

void Login::createUI()
{
    vbox = new QVBoxLayout();
    vbox->addWidget(this->lineUsername);
    vbox->addWidget(this->linePassword);
    vbox->addWidget(this->btnLogin);
    vbox->addWidget(this->btnNewAcc);
    setLayout(vbox);
}

void Login::checkCred()
{
    qDebug() << "checkCred() " + this->lineUsername->text() + " " + this->linePassword->text();
}

// SLOTS
void Login::slotNewAcc()
{
    emit Login::signalNewAcc();
}

void Login::slotReturnHandler()
{
    if (this->linePassword->text().isEmpty() && !this->lineUsername->text().isEmpty())
    {
        this->linePassword->setFocus();
    }
    else if (!this->lineUsername->text().isEmpty())
    {
        qDebug() << "here;";
        checkCred();
    }
}