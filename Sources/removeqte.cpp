#include "removeqte.h"

#include <QDebug>

RemoveQte::RemoveQte(int timeSeconds, Level *level)
{
    this->timeSeconds = timeSeconds;
    this->level = level;
}

void RemoveQte::execute()
{
    this->level->removeQte(this->timeSeconds);
    this->level->sortQtes();
}

void RemoveQte::undo()
{
    this->level->addQTE(this->timeSeconds);
    this->level->sortQtes();
}

void RemoveQte::redo()
{
    this->execute();
}
