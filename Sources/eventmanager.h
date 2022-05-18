#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QListView>
#include <QStandardItemModel>
#include "level.h"

class EventManager : public QWidget
{
    Q_OBJECT
public:
    EventManager(Level* level = nullptr);

private:
    Level *level;
    QListView *listViewTargets;
    QListView *listViewQtes;

private slots:
    void slotLevelChanged();

// UI
private:
    QHBoxLayout *hbox;
    void createUI();
    QStandardItemModel *fetchModelTarget();
    QStandardItemModel *fetchModelQte();
};

#endif // EVENTMANAGER_H
