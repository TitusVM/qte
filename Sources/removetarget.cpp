#include "removetarget.h"

#include <QDebug>

RemoveTarget::RemoveTarget(int timeSeconds, Level *level)
{
    this->timeSeconds = timeSeconds;
    this->level = level;
}

void RemoveTarget::execute()
{
    this->level->removeTarget(this->timeSeconds);
    this->level->sortTargets();
}

void RemoveTarget::undo()
{
    this->level->addTarget(this->timeSeconds);
    this->level->sortTargets();
}

void RemoveTarget::redo()
{
    this->execute();
}
