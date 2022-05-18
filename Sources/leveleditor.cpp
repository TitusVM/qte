#include "leveleditor.h"

/**
 * @brief LevelEditor::LevelEditor
 * @param parent
 *
 * Public Constructor, initializing attributes and connecting signals to slots
 */
LevelEditor::LevelEditor(QWidget *parent) : QWidget(parent)
{
    //this->btnAddMovTarget = new QPushButton(tr("Add Moving Target"));
   // this->btnAddGrowTarget = new QPushButton(tr("Add Growing Target"));

    this->level = new Level(":/Levels/Easy.csv");
    this->level->importLevel();
    this->eventManager = new EventManager(this->level);

    this->commandManager = new CommandManager();
    this->btnUndo = new QPushButton(tr("Undo"));
    this->btnUndo->setShortcut(tr("Ctrl+Z"));
    this->btnRedo = new QPushButton(tr("Redo"));
    this->btnRedo->setShortcut(tr("Ctrl+Y"));
    this->btnSave = new QPushButton(tr("Save"));
    this->btnSave->setShortcut(tr("Ctrl+S"));

    connect(this->btnUndo, &QPushButton::clicked, this, &LevelEditor::slotUndo);
    connect(this->btnRedo, &QPushButton::clicked, this, &LevelEditor::slotRedo);
    connect(this->btnSave, &QPushButton::clicked, this, &LevelEditor::slotSave);

    this->btnAddTarget = new QPushButton(tr("Add Target"));
    this->linTimeTarget = new QLineEdit(this->secondsToString(300));
    this->linTimeTarget->setInputMask("00:00");

    this->btnDeleteEvent = new QPushButton(tr("Delete"));
    this->btnDeleteEvent->setDisabled(true);
    this->linSelectedEvent = new QLineEdit(this->secondsToString(0));
    this->linSelectedEvent->setInputMask("00:00");
    this->linSelectedEvent->setDisabled(true);

    this->btnAddQte = new QPushButton(tr("Add QTE"));
    this->linTimeQte = new QLineEdit(this->secondsToString(197));
    this->linTimeQte->setInputMask("00:00");

    this->btnManage = new QPushButton(tr("Manage Events"));
    this->btnCreate = new QPushButton(tr("Save Level"));

    // TODO
    // this->level = new Level();

    this->mainLayout = new QGridLayout();

    connect(this->btnAddTarget, &QPushButton::clicked, this, &LevelEditor::slotAddTarget);
    connect(this->btnAddQte, &QPushButton::clicked, this, &LevelEditor::slotAddQte);

    createUI();
}

/**
 * @brief LevelEditor::createUI
 *
 * Function to add elements to layout and set layout. Creating interface.
 */
void LevelEditor::createUI()
{
    this->mainLayout->addWidget(this->eventManager, 0,0,3,3);
    this->mainLayout->addWidget(this->linTimeTarget, 0,3,1,1);
    this->mainLayout->addWidget(this->btnAddTarget, 0,4,1,2);
    this->mainLayout->addWidget(this->linSelectedEvent, 1,3,1,1);
    this->mainLayout->addWidget(this->btnDeleteEvent, 1,4,1,2);
    this->mainLayout->addWidget(this->linTimeQte, 2,4,1,1);
    this->mainLayout->addWidget(this->btnAddQte, 2,5,1,1);
    this->mainLayout->addWidget(this->btnUndo, 3,0,1,1);
    this->mainLayout->addWidget(this->btnRedo, 3,1,1,1);
    this->mainLayout->addWidget(this->btnSave, 3,2,1,1);

    setLayout(this->mainLayout);
}

// TOOLS
QString LevelEditor::secondsToString(int nbSeconds)
{
    int seconds = nbSeconds % 60;
    int minutes = (nbSeconds / 60) % 60;

    QString timeString = QString("%1:%2")
      .arg(minutes, 2, 10, QChar('0'))
      .arg(seconds, 2, 10, QChar('0'));
    return timeString;
}

int LevelEditor::stringToSeconds(QString timeString)
{
    auto split = timeString.split(":");
    int seconds = split[0].toInt() * 60 + split[1].toInt();
    return seconds;
}

// SLOTS

/**
 * @brief LevelEditor::slotAddTarget
 *
 * Slot to add a Target at selected time to Level
 */
void LevelEditor::slotAddTarget()
{
    int addAt = this->stringToSeconds(this->linTimeTarget->text());
    AddTarget *addTarget = new AddTarget(addAt, this->level);
    commandManager->execute(addTarget);
}

/**
 * @brief LevelEditor::slotAddTarget
 *
 * Slot to add a QTE at selected time to Level
 */
void LevelEditor::slotAddQte()
{
    int addAt = this->stringToSeconds(this->linTimeQte->text());
    AddQte *addQte = new AddQte(addAt, this->level);
    commandManager->execute(addQte);
}

void LevelEditor::slotUndo()
{
    this->commandManager->undo();
}

void LevelEditor::slotRedo()
{
    this->commandManager->redo();
}

void LevelEditor::slotSave()
{
    this->level->exportLevel();
}
