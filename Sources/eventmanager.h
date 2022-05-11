#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QListView>
#include "level.h"

class EventManager : public QWidget
{
    Q_OBJECT
public:
    EventManager(Level* level = nullptr);

private:
    Level *level;
    QListView *listView;

// UI
private:
    QHBoxLayout *hbox;
    void createUI();
};

#endif // EVENTMANAGER_H
