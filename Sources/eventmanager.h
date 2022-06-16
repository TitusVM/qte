#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QListView>
#include <QStandardItemModel>
#include "level.h"

/**
 * @brief The EventManager class extends QWidget and handles all the event interface by keeping the Level object and two seperate
 * QListView objects. These are seperate to make a more friendly UX:
 *
 *      - QListView *listViewTargets to keep a dynamic list of the Level object's targets
 *      - QListView *listViewQtes to keep a dynamic list of the Level object's QTEs
 *
 * The EventManager UI also has a signal that updates the two Lists dynamically. This is done via the slotLevelChanged() slot.
 */

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
