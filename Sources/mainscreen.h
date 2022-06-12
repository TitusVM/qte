#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
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
    //QtELogo *qtELogo;
    QPushButton *btnNewGame;
    QPushButton *btnNewLevel;
    QPushButton *btnEditCreate;
    QPushButton *btnQuit;

    QGridLayout *grid;

public slots:
    void slotNewGame();
    void slotNewLevel();
    void slotEditCreate();
    void slotQuit();

signals:
    void signalNewLevel();
    void signalQuit();
    void signalLevelEditor();
    void signalNewGame();
	
	
	
};

#endif // MAINSCREEN_H
