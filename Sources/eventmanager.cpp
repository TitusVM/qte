#include "eventmanager.h"

EventManager::EventManager(Level *level) : QWidget(nullptr)
{
    this->level = level;
    this->listView = new QListView();
    connect(this->level, &Level::signalLevelChanged, this, &EventManager::slotLevelChanged);
    this->hbox = new QHBoxLayout();

    createUI();
}

void EventManager::createUI()
{
    this->listView->setModel(this->fetchModel());
    this->hbox->addWidget(this->listView);
    setLayout(this->hbox);
}

QStandardItemModel* EventManager::fetchModel()
{
    QStandardItem *item;
    QStandardItemModel *model = new QStandardItemModel();
    QString itemString = "";

    int maxElements = this->level->targetsSeconds.length();
    int minElements = 0;
    bool qteMax;
    if(this->level->qtesSeconds.length() > this->level->targetsSeconds.length())
    {
        qteMax = true;
        maxElements = this->level->qtesSeconds.length();
        minElements = this->level->targetsSeconds.length();
    }
    else
    {
        qteMax = false;
        minElements = this->level->qtesSeconds.length();
    }

    size_t counter;

    for (counter = 0; counter < minElements ; counter++)
    {
        itemString = "Target : " + QString::number(this->level->targetsSeconds[counter]);
        item = new QStandardItem(itemString);
        model->appendRow(item);
        itemString = "Qte : " + QString::number(this->level->qtesSeconds[counter]);
        item = new QStandardItem(itemString);
        model->appendRow(item);
    }

    while (counter < maxElements)
    {
        if(qteMax)
        {
            itemString = "Qte : " + QString::number(this->level->qtesSeconds[counter++]);
            item = new QStandardItem(itemString);
            model->appendRow(item);
        }
        else
        {
            itemString = "Target : " + QString::number(this->level->targetsSeconds[counter++]);
            item = new QStandardItem(itemString);
            model->appendRow(item);
        }
    }
    return model;
}

// SLOTS

void EventManager::slotLevelChanged()
{
    this->listView->setModel(this->fetchModel());
}
