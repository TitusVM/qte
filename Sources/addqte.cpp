#include "addqte.h"

#include <QDebug>

AddQte::AddQte(int timeSeconds, Level *level)
{
    this->timeSeconds = timeSeconds;
    this->level = level;
}

void AddQte::execute()
{
    this->level->addQTE(this->timeSeconds);
}

void AddQte::undo()
{
    this->level->removeQte(this->timeSeconds);
}

void AddQte::redo()
{
    this->execute();
}
