#include "removeqte.h"

#include <QDebug>

/**
 * @brief RemoveQte::RemoveQte Constructor
 * @param timeSeconds The time at which the QTE takes place in the sequential event structure
 * (Level in this case)
 * @param level The Level from which the QTE needs to be removed from
 */
RemoveQte::RemoveQte(int timeSeconds, Level *level)
{
    this->timeSeconds = timeSeconds;
    this->level = level;
}

/**
 * @brief RemoveQte::execute
 */
void RemoveQte::execute()
{
    this->level->removeQte(this->timeSeconds);
    this->level->sortQtes();
}

/**
 * @brief RemoveQte::undo
 */
void RemoveQte::undo()
{
    this->level->addQTE(this->timeSeconds);
    this->level->sortQtes();
}

/**
 * @brief RemoveQte::redo
 */
void RemoveQte::redo()
{
    this->execute();
}
