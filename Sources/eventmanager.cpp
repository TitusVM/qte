#include "eventmanager.h"
#include <QAbstractItemView>

/**
 * @brief EventManager::EventManager Constructor creates the User Interface with given Level.
 * @param level
 */
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

/**
 * @brief EventManager::createUI delegate function to create Level
 */
void EventManager::createUI()
{
    this->listViewTargets->setModel(this->fetchModelTarget());
    this->listViewQtes->setModel(this->fetchModelQte());
    this->hbox->addWidget(this->listViewTargets);
    this->hbox->addWidget(this->listViewQtes);
    setLayout(this->hbox);
}

/**
 * @brief EventManager::fetchModelTarget gets all the Target events as QStandardItemModel pointer
 * @return QStandardItemModel*
 */
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

/**
 * @brief EventManager::fetchModelQte gets all the Qte events as QStandardItemModel pointer
 * @return QStandardItemModel*
 */
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
/**
 * @brief EventManager::slotLevelChanged updates the lists in the user interface with the updated models
 */
void EventManager::slotLevelChanged()
{
    this->listViewTargets->setModel(this->fetchModelTarget());
    this->listViewQtes->setModel(this->fetchModelQte());
}
