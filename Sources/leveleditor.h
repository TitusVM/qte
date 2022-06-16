#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QMessageBox>

#include "level.h"
#include "eventmanager.h"
#include "commandmanager.h"
#include "addtarget.h"
#include "removetarget.h"
#include "addqte.h"
#include "removeqte.h"


/**
 * @brief The LevelEditor class extends QWidget and is a User Interface for editing existing or non-existing levels. It
 * contains necessary visual elements to manipulate a chosen Level. Or even create a new Level and
 * save it using the Level::exportLevel() method.
 *
 * More about the usage of the LevelEditor User Interface can be read in the User Documentation found
 * at https://gitlab-etu.ing.he-arc.ch/isc/2021-22/niveau-2/2282-1-projet-p2-il-sp/g3/-/wikis/Documentation-Utilisateur
 */

class LevelEditor : public QWidget
{
    Q_OBJECT
public:
    LevelEditor(bool isNewLevel, QWidget *parent = nullptr);

private:
    bool isNewLevel;
    bool isSaved;

    QPushButton *btnUndo;
    QPushButton *btnRedo;
    QPushButton *btnSave;

    QPushButton *btnAddTarget;
    QLineEdit *linTimeTarget;

    QPushButton *btnDeleteEvent;
    QLineEdit *linSelectedEvent;
    QGroupBox *radioGroup;
    QRadioButton *radioTarget;
    QRadioButton *radioQte;

    QPushButton *btnAddQte;
    QLineEdit *linTimeQte;

    QPushButton *btnManage;
    QPushButton *btnCreate;
    QPushButton *btnBack;

    QLineEdit *linName;

    QGridLayout *mainLayout;

    Level *level;
    EventManager *eventManager;


// UI
private:
    void createUI();
    QString secondsToString(int nbSeconds);
    int stringToSeconds(QString timeString);
    CommandManager *commandManager;

// Slots
private slots:
    void slotAddTarget();
    void slotAddQte();
    void slotDeleteEvent();
    void slotUndo();
    void slotRedo();
    void slotSave();
    void slotBack();

// Signals
signals:
    void signalBackClicked();

};

#endif // EDITOR_H
