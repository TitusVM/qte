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

class LevelEditor : public QWidget
{
    Q_OBJECT
public:
    LevelEditor(QWidget *parent = nullptr);

private:
    QPushButton *btnAddTarget;
    QPushButton *btnAddMovTarget;
    //QPushButton *btnAddGrowTarget;
    QPushButton *btnDeleteEvent;
    QLineEdit *linTimeEvent;
    QPushButton *btnAddQte;
    QPushButton *btnManage;
    QPushButton *btnCreate;
    //QPushButton *btnBack;
    //QPushButton *btnQuit;

    //QString filePath;
    QLabel *lblTime;
    QLabel *linTime;

    QComboBox *comboChar;

    QLineEdit *linName;

    QGridLayout *mainLayout;

    Level *level;
    EventManager *eventManager;


// UI
private:
    void createUI();

};

#endif // EDITOR_H
