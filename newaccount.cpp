#include "newaccount.h"

NewAccount::NewAccount(QWidget *parent)
    : Login(parent)
{
    //createUI


    //connect(bouton, QButton::Clicked(), this, createAccount());
}

void NewAccount::createAccount()
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
            //attribut username = textbox
            //attribut password = textbox
            if (password == "") //remplacer "" par la deuxième textbox
            {
                out << username << " , " << password;
                //Connected
            }
        }
        else
        {
            std::cout << "user already exists" << std::endl;
        }

    }  catch (...) {
        std::cout << "Error occured while opening or writing file";
    }
}

NewAccount::~NewAccount()
{

}
