#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>

class MainScreen : public QWidget
{
    Q_OBJECT
public:
    MainScreen(QWidget *parent = nullptr, QString username = "");
    void createUI();
    void createNewGame();
    void createLevelEditor();
    void showCredits();

private:
    QString username;

    // UI
    // QtELogo *qtELogo;
    QPushButton *btnNewGame;
    QPushButton *btnNewLevel;
    QPushButton *btnCredits;
    QPushButton *btnQuit;

    QVBoxLayout *vbox;

public slots:
    void slotNewGame();
    void slotNewLevel();
    void slotCredits();
    void slotQuit();

signals:
    void signalQuit();
};

#endif // MAINSCREEN_H
