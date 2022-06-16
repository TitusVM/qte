#include "leveleditor.h"
#include <QFileDialog>

/**
 * @brief LevelEditor::LevelEditor Constructor, initializing attributes and connecting signals to slots
 * @param isNewLevel
 * @param parent
 */
LevelEditor::LevelEditor(bool isNewLevel, QWidget *parent) : QWidget(parent)
{
    this->isNewLevel = isNewLevel;
    this->isSaved = true;
    this->level = nullptr;

    if(!isNewLevel)
    {
        this->level = new Level(QFileDialog::getOpenFileName(this, tr("Open Level"), ".", tr("Level Files (*.csv)")), true);
        if(this->level != nullptr) this->level->importLevel();
        else
        {
            this->isNewLevel = true;
            this->level = new Level();
        }
    }
    else
    {
        this->level = new Level();
    }

    this->eventManager = new EventManager(this->level);

    this->commandManager = new CommandManager();
    this->btnUndo = new QPushButton(tr("Undo"));
    this->btnUndo->setShortcut(tr("Ctrl+Z"));
    this->btnRedo = new QPushButton(tr("Redo"));
    this->btnRedo->setShortcut(tr("Ctrl+Y"));
    this->btnSave = new QPushButton(tr("Save"));
    this->btnSave->setShortcut(tr("Ctrl+S"));
    this->btnBack = new QPushButton(tr("Back"));
    this->btnBack->setShortcut(tr("Backspace"));

    connect(this->btnUndo, &QPushButton::clicked, this, &LevelEditor::slotUndo);
    connect(this->btnRedo, &QPushButton::clicked, this, &LevelEditor::slotRedo);
    connect(this->btnSave, &QPushButton::clicked, this, &LevelEditor::slotSave);
    connect(this->btnBack, &QPushButton::clicked, this, &LevelEditor::slotBack);

    this->btnAddTarget = new QPushButton(tr("Add Target"));
    this->linTimeTarget = new QLineEdit(this->secondsToString(0));
    this->linTimeTarget->setInputMask("00:00");

    this->btnDeleteEvent = new QPushButton(tr("Delete"));
    this->radioTarget = new QRadioButton(tr("Target"));
    this->radioQte = new QRadioButton(tr("Qte"));
    this->radioTarget->setChecked(true);
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addWidget(this->radioTarget);
    hbox->addWidget(this->radioQte);
    this->radioGroup = new QGroupBox();
    this->radioGroup->setLayout(hbox);
    this->linSelectedEvent = new QLineEdit(this->secondsToString(0));
    this->linSelectedEvent->setInputMask("00:00");

    this->btnAddQte = new QPushButton(tr("Add QTE"));
    this->linTimeQte = new QLineEdit(this->secondsToString(0));
    this->linTimeQte->setInputMask("00:00");

    this->btnManage = new QPushButton(tr("Manage Events"));
    this->btnCreate = new QPushButton(tr("Save Level"));

    this->mainLayout = new QGridLayout();

    connect(this->btnAddTarget, &QPushButton::clicked, this, &LevelEditor::slotAddTarget);
    connect(this->btnAddQte, &QPushButton::clicked, this, &LevelEditor::slotAddQte);
    connect(this->btnDeleteEvent, &QPushButton::clicked, this, &LevelEditor::slotDeleteEvent);


    createUI();
}

/**
 * @brief LevelEditor::createUI
 *
 * Function to add elements to layout and set layout. Creating interface.
 */
void LevelEditor::createUI()
{
    this->mainLayout->addWidget(this->btnUndo, 0,0,1,1);
    this->mainLayout->addWidget(this->btnRedo, 0,1,1,1);
    this->mainLayout->addWidget(this->btnSave, 0,2,1,1);
    this->mainLayout->addWidget(this->btnBack, 0,3,1,1);
    this->mainLayout->addWidget(this->eventManager, 1,0,3,3);
    this->mainLayout->addWidget(this->linTimeTarget, 1,3,1,1);
    this->mainLayout->addWidget(this->btnAddTarget, 1,4,1,2);
    this->mainLayout->addWidget(this->linSelectedEvent, 2,3,1,1);
    this->mainLayout->addWidget(this->radioGroup, 2,4,1,1);
    this->mainLayout->addWidget(this->btnDeleteEvent, 2,5,1,1);
    this->mainLayout->addWidget(this->linTimeQte, 3,3,1,1);
    this->mainLayout->addWidget(this->btnAddQte, 3,4,1,2);

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
    this->isSaved = false;
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
    this->isSaved = false;
}

void LevelEditor::slotDeleteEvent()
{
    int deleteAt = this->stringToSeconds(this->linSelectedEvent->text());
    if(this->radioQte->isChecked())
    {
        RemoveQte *removeQte = new RemoveQte(deleteAt, this->level);
        commandManager->execute(removeQte);
    }
    else
    {
        RemoveTarget *removeTarget = new RemoveTarget(deleteAt, this->level);
        commandManager->execute(removeTarget);
    }
    this->isSaved = false;
}

/**
 * @brief LevelEditor::slotUndo
 */
void LevelEditor::slotUndo()
{
    this->commandManager->undo();
}

/**
 * @brief LevelEditor::slotRedo
 */
void LevelEditor::slotRedo()
{
    this->commandManager->redo();
}

/**
 * @brief LevelEditor::slotSave
 */
void LevelEditor::slotSave()
{
    this->level->exportLevel(this->isNewLevel, this);
}

/**
 * @brief LevelEditor::slotBack
 */
void LevelEditor::slotBack()
{
    if(!this->isSaved)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Unsaved changes", "Save the document?",
                                    QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes && !this->isNewLevel)
        {
            this->slotSave();
            this->isSaved = true;
            emit signalBackClicked();
            return;
        }
    }
    emit signalBackClicked();
}
