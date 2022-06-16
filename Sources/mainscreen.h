#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPixmap>

/**
 * @brief The MainScreen class extends QWidget and provides a User Interface for the main controls of the program. It sends
 * signals back to the MainWindow, which does all the window changing. The User Interface contains 4
 * options:
 *      - New Game, starts the NewGame screen
 *      - New Level, starts the LevelEditor with a new Level
 *      - Edit Level, starts the LevelEditor which will ask to chose an existing Level
 *      - Quit, which quits the programm
 */

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
