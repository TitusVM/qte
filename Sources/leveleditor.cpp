#include "leveleditor.h"

LevelEditor::LevelEditor(QWidget *parent) : QWidget(parent)
{
    this->btnAddTarget = new QPushButton(tr("Add Target"));
    this->btnAddMovTarget = new QPushButton(tr("Add Moving Target"));
   // this->btnAddGrowTarget = new QPushButton(tr("Add Growing Target"));
    this->btnDeleteEvent = new QPushButton(tr("Delete"));
    this->btnDeleteEvent->setDisabled(true);
    this->linTimeEvent = new QLineEdit(tr("1:23"));
    this->linTimeEvent->setDisabled(true);
    this->btnAddQte = new QPushButton(tr("Add QTE"));
    this->btnManage = new QPushButton(tr("Manage Events"));
    this->btnCreate = new QPushButton(tr("Save Level"));

    this->lblTime = new QLabel(tr("Time in seconds (0 to 300):"));
    this->linTime = new QLabel(tr("197"));

    // TODO
    this->level = new Level();

    this->comboChar = new QComboBox();
    this->eventManager = new EventManager(this->level);

    this->mainLayout = new QGridLayout();

    createUI();
}

void LevelEditor::createUI()
{
    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    foreach(QChar character, alphabet)
    {
        this->comboChar->addItem(character);
    }

    this->mainLayout->addWidget(this->lblTime, 0,0,1,1);
    this->mainLayout->addWidget(this->linTime, 0,1,1,1);
    this->mainLayout->addWidget(this->eventManager, 1,0,3,3);
    this->mainLayout->addWidget(this->btnAddTarget, 1,3,1,2);
    this->mainLayout->addWidget(this->linTimeEvent, 2,3,1,1);
    this->mainLayout->addWidget(this->btnDeleteEvent, 2,4,1,1);
    this->mainLayout->addWidget(this->comboChar, 3,3,1,1);
    this->mainLayout->addWidget(this->btnAddQte, 3,4,1,1);

    setLayout(this->mainLayout);

}
