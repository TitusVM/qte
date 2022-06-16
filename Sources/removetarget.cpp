#include "removetarget.h"

#include <QDebug>

/**
 * @brief RemoveTarget::RemoveTarget Constructor
 * @param timeSeconds The time at which the Target takes place in the sequential event structure
 * (Level in this case)
 * @param level The Level which the Target needs to be removed from
 */
RemoveTarget::RemoveTarget(int timeSeconds, Level *level)
{
    this->timeSeconds = timeSeconds;
    this->level = level;
}

/**
 * @brief RemoveTarget::execute
 */
void RemoveTarget::execute()
{
    this->level->removeTarget(this->timeSeconds);
    this->level->sortTargets();
}

/**
 * @brief RemoveTarget::undo
 */
void RemoveTarget::undo()
{
    this->level->addTarget(this->timeSeconds);
    this->level->sortTargets();
}

/**
 * @brief RemoveTarget::redo
 */
void RemoveTarget::redo()
{
    this->execute();
}
