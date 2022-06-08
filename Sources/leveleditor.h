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
 * @brief The LevelEditor class
 *
 * Interface for editing existing or non-existing levels.
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
    //QPushButton *btnAddMovTarget;
    //QPushButton *btnAddGrowTarget;

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

    //QString filePath;

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
