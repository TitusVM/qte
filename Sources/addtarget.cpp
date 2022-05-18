#include "addtarget.h"

#include <QDebug>

AddTarget::AddTarget(int timeSeconds, Level *level)
{
    this->timeSeconds = timeSeconds;
    this->level = level;
}

void AddTarget::execute()
{
    this->level->addTarget(this->timeSeconds);
    this->level->sortTargets();
}

void AddTarget::undo()
{
    this->level->removeTarget(this->timeSeconds);
    this->level->sortTargets();
}

void AddTarget::redo()
{
    this->execute();
}
