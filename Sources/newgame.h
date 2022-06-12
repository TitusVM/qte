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
