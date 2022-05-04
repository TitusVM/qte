#ifndef NEWGAME_H
#define NEWGAME_H

#include <QWidget>

class QLabel;
class QPushButton;
class QComboBox;
class QGridLayout;

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
    QLabel *lblNewGame;
    QLabel *lblDefaultLevels;
    QLabel *lblCustomLevels;
    QComboBox *cbxSelectCustomLevels;

    QGridLayout *grid;

private slots:
    void slotSelectDifficulty();
    void slotPlayCustom();

signals:
    void signalLevelPlay(QString levelName);
};

#endif // NEWGAME_H
