#include "login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    //createUI


    //connect(bouton, QButton::Clicked(), this, createNewAccount());
}

void Login::checkConnexion()
{
    QFile file("users.txt");

    try {
        file.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream in(&file);

        while (!in.atEnd())
        {
             QString line = in.readLine();
             QStringList newLine = line.split(" , ");
             if(username == newLine.at(0))
             {
                 //Connected
             }
         }
    }
    catch (...) {
        std::cout << "Error occured while opening or writing file";
    }
}

<<<<<<< HEAD
void Login::newAccount()
{
    new NewAccount(this);
}

=======
>>>>>>> 270c0c9 (Login's logic development)
Login::~Login()
{

}
