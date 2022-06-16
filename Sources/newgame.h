#ifndef NEWGAME_H
#define NEWGAME_H

#include <QWidget>

class QLabel;
class QPushButton;
class QComboBox;
class QGridLayout;

/**
 * @brief The NewGame class extends QWidget and provides a User Interface to start a new Level. A detailed
 * description of this UI can be found in the User documentation which can be found here: https://gitlab-etu.ing.he-arc.ch/isc/2021-22/niveau-2/2282-1-projet-p2-il-sp/g3/-/wikis/Documentation-Utilisateur
 * It has several Level selection options and also a browse button which is there so the user can select a custom Level.
 */

class NewGame : public QWidget
{
    Q_OBJECT
public:
    NewGame(QWidget *parent = nullptr);
    void createUI();

private:
    QString *difficulty;

    QPushButton *btnEasy;
    QPushButton *btnNormal;
    QPushButton *btnHard;
    QPushButton *btnPlayCustom;
    QPushButton *btnBack;
    QLabel *lblNewGame;
    QLabel *lblDefaultLevels;
    QLabel *lblCustomLevels;
    QPushButton *btnSelectCustom;

    QGridLayout *grid;

private slots:
    void slotSelectEasy();
    void slotSelectNormal();
    void slotSelectHard();
    void slotPlayCustom();
    void slotBack();

signals:
    void signalLevelPlay(QString levelName, bool isCustom);
    void signalBackClicked();
};

#endif // NEWGAME_H
