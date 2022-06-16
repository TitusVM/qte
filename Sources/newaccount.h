#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QWidget>

class QLineEdit;
class QPushButton;

/**
 * @brief The NewAccount class extends QWidget and provides a User Interface and logic to create a new account. It is
 * generally called from either a Login object or in this case the MainWindow class upon hitting
 * the Login object's New Account button.
 * It communicates with the text file mentionned in the Login class documentation and developper
 * documentation (which can be found here : https://gitlab-etu.ing.he-arc.ch/isc/2021-22/niveau-2/2282-1-projet-p2-il-sp/g3/-/wikis/Documentation-D%C3%A9veloppeurs)
 * to check for available usernames. It also logs the new user in straight after account creation.
 */

class NewAccount : public QWidget
{
    Q_OBJECT

public:
    NewAccount(QWidget *parent = nullptr);
    void createUI();

private:
    QString username;
    QString password;

    QLineEdit *lineUsername;
    QLineEdit *linePassword;
    QLineEdit *lineVerifPassword;

    QPushButton *btnBack;
    QPushButton *btnSubmit;

public slots:
    void slotSubmit();
    void slotBack();

signals:
    void signalBack();
    void signalLoggedIn();

};

#endif // NEWACCOUNT_H
