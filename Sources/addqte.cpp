#include "addqte.h"

#include <QDebug>

/**
 * @brief AddQte::AddQte Constructor
 * @param timeSeconds The time at which the QTE should take place in the sequential event structure
 * (Level in this case)
 * @param level The Level in which the QTE needs to be placed
 */
AddQte::AddQte(int timeSeconds, Level *level)
{
    this->timeSeconds = timeSeconds;
    this->level = level;
}

/**
 * @brief AddQte::execute
 */
void AddQte::execute()
{
    this->level->addQTE(this->timeSeconds);
    this->level->sortQtes();
}

/**
 * @brief AddQte::undo
 */
void AddQte::undo()
{
    this->level->removeQte(this->timeSeconds);
    this->level->sortQtes();
}

/**
 * @brief AddQte::redo
 */
void AddQte::redo()
{
    this->execute();
}
