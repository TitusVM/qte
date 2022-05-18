#include "eventmanager.h"
#include <QAbstractItemView>

EventManager::EventManager(Level *level) : QWidget(nullptr)
{
    this->level = level;
    this->listViewTargets = new QListView();
    this->listViewTargets->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->listViewQtes = new QListView();
    this->listViewQtes->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(this->level, &Level::signalLevelChanged, this, &EventManager::slotLevelChanged);
    this->hbox = new QHBoxLayout();

    createUI();
}

void EventManager::createUI()
{
    this->listViewTargets->setModel(this->fetchModelTarget());
    this->listViewQtes->setModel(this->fetchModelQte());
    this->hbox->addWidget(this->listViewTargets);
    this->hbox->addWidget(this->listViewQtes);
    setLayout(this->hbox);
}

QStandardItemModel* EventManager::fetchModelTarget()
{
    QStandardItem *item;
    QStandardItemModel *model = new QStandardItemModel();
    QString itemString = "";
    size_t counter;

    for (size_t i = 0; i < this->level->targetsSeconds.length(); i++)
    {
        itemString = "Target : " + QString::number(this->level->targetsSeconds[i]);
        item = new QStandardItem(itemString);
        model->appendRow(item);
    }
    return model;
}

QStandardItemModel* EventManager::fetchModelQte()
{
    QStandardItem *item;
    QStandardItemModel *model = new QStandardItemModel();
    QString itemString = "";
    size_t counter;

    for (size_t i = 0; i < this->level->qtesSeconds.length(); i++)
    {
        itemString = "Qte : " + QString::number(this->level->qtesSeconds[i]);
        item = new QStandardItem(itemString);
        model->appendRow(item);
    }
    return model;
}

// SLOTS

void EventManager::slotLevelChanged()
{
    this->listViewTargets->setModel(this->fetchModelTarget());
    this->listViewQtes->setModel(this->fetchModelQte());
}
