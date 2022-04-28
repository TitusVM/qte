#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>

#include "level.h"
#include "eventmanager.h"


/**
 * @brief The LevelEditor class
 *
 * Interface for editing existing or non-existing levels.
 */

class LevelEditor : public QWidget
{
    Q_OBJECT
public:
    LevelEditor(QWidget *parent = nullptr);

private:
    QPushButton *btnAddTarget;
    QLineEdit *linTimeTarget;
    //QPushButton *btnAddMovTarget;
    //QPushButton *btnAddGrowTarget;
    QPushButton *btnDeleteEvent;
    QLineEdit *linSelectedEvent;

    QPushButton *btnAddQte;
    QLineEdit *linTimeQte;

    QPushButton *btnManage;
    QPushButton *btnCreate;
    //QPushButton *btnBack;
    //QPushButton *btnQuit;

    //QString filePath;

    QComboBox *comboChar;

    QLineEdit *linName;

    QGridLayout *mainLayout;

    Level *level;
    EventManager *eventManager;


// UI
private:
    void createUI();
    QString secondsToString(int nbSeconds);
    int stringToSeconds(QString timeString);

// Slots
private slots:
    void slotAddTarget();
    void slotAddQte();

};

#endif // EDITOR_H
