#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QWidget>

class QLineEdit;
class QPushButton;

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

};

#endif // NEWACCOUNT_H
