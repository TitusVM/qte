#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

#include "newaccount.h"
#include "login.h"



NewAccount::NewAccount(QWidget *parent)
    : QWidget(parent)
{
    this->lineUsername = new QLineEdit();
    this->lineUsername->setPlaceholderText(tr("Username"));

    this->linePassword = new QLineEdit();
    this->linePassword->setPlaceholderText(tr("Password"));

    this->lineVerifPassword = new QLineEdit();
    this->lineVerifPassword->setPlaceholderText(tr("Password"));

    this->btnSubmit = new QPushButton(tr("Submit"));
    this->btnBack = new QPushButton(tr("Back"));

    connect(this->btnSubmit, &QPushButton::clicked, this, &NewAccount::slotSubmit);
    connect(this->btnBack, &QPushButton::clicked, this, &NewAccount::slotBack);

    createUI();
}

void NewAccount::createUI()
{
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(this->lineUsername);
    vbox->addWidget(this->linePassword);
    vbox->addWidget(this->lineVerifPassword);
    vbox->addWidget(this->btnSubmit);
    vbox->addWidget(this->btnBack);
    setLayout(vbox);
}

// SLOTS
void NewAccount::slotSubmit()
{
    QFile file("users.txt");

    try {
        file.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream in(&file);
        QStringList userList;

        while (!in.atEnd()) {
                 QString line = in.readLine();
                 QStringList newLine = line.split(" , ");
                 userList.append(newLine.at(0));
             }

        if (!userList.contains(username)) {
            QTextStream out(&file);
            this->username = this->lineUsername->text();
            this->password = this->linePassword->text();
            if (password == this->lineVerifPassword->text())
            {
                out << "\n" << this->username << " , " << this->password;
                qDebug() << "yay worked";
                //Connected
            }
        }
        else
        {
            qDebug() << "user already exists";
        }

    }  catch (...) {
        qDebug() << "Error occured while opening or writing file";
    }
}

void NewAccount::slotBack()
{
    emit NewAccount::signalBack();
}
