#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <QWidget>
#include <QFile>
#include <QTextStream>

class QLineEdit;
class QLabel;
class QPushButton;
class QVBoxLayout;
class QMainWindow;

/**
 * @brief The Login class extends QWidget and provides a means of authentication to the programm. The user needs to either
 * validate an existing combination of a password and a username, or create a new username and associated
 * password. Without this verification step, a user cannot and shall not be able to log in.
 * This class is based on a loose text file because implementation of a hashed database was not in the
 * release window. That said, more about the login procedure can be read in the developper documentation
 * here : https://gitlab-etu.ing.he-arc.ch/isc/2021-22/niveau-2/2282-1-projet-p2-il-sp/g3/-/wikis/Documentation-D%C3%A9veloppeurs
 */

class Login : public QWidget
{
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);
    void createUI();

private:
    QString username;
    QString password;

    // UI
    QLineEdit *lineUsername;
    QLineEdit *linePassword;
    QPushButton *btnLogin;
    QPushButton *btnNewAcc;

    QVBoxLayout *vbox;

public slots:
    void slotNewAcc();
    void slotReturnHandler();

signals:
    void signalNewAcc();
    void signalLoggedIn();

};

#endif // LOGIN_H
