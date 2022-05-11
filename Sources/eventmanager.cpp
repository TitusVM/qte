#include "eventmanager.h"
#include <QStandardItemModel>

EventManager::EventManager(Level *level) : QWidget(nullptr)
{
    this->level = level;
    this->listView = new QListView();
    this->hbox = new QHBoxLayout();

    createUI();
}

void EventManager::createUI()
{
    QString stringList[3] = {"one", "two", "three"};
    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *item;
    for (size_t i=0; i < stringList->size(); i++)
    {
        item = new QStandardItem(stringList[i]);
        qDebug() << model;
        model->appendRow(item);
    }
    this->listView->setModel(model);
    this->hbox->addWidget(this->listView);
    setLayout(this->hbox);
}
