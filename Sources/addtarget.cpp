#include "addtarget.h"

#include <QDebug>

/**
 * @brief AddTarget::AddTarget Constructor
 * @param timeSeconds The time at which the Target should take place in the sequential event structure
 * (Level in this case)
 * @param level The Level in which the Target needs to be placed
 */
AddTarget::AddTarget(int timeSeconds, Level *level)
{
    this->timeSeconds = timeSeconds;
    this->level = level;
}

/**
 * @brief AddTarget::execute
 */
void AddTarget::execute()
{
    this->level->addTarget(this->timeSeconds);
    this->level->sortTargets();
}

/**
 * @brief AddTarget::undo
 */
void AddTarget::undo()
{
    this->level->removeTarget(this->timeSeconds);
    this->level->sortTargets();
}

/**
 * @brief AddTarget::redo
 */
void AddTarget::redo()
{
    this->execute();
}
