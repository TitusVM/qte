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

    QMainWindow *parent;

    QVBoxLayout *vbox;

public slots:
    void slotNewAcc();
    void slotReturnHandler();

signals:
    void signalNewAcc();
    void signalLoggedIn();

};

#endif // LOGIN_H
