#include "addqte.h"

#include <QDebug>

AddQte::AddQte(int timeSeconds, QChar* letter)
{
    this->timeSeconds = timeSeconds;
    this->letter = letter;
}

void AddQte::execute()
{
    qDebug() << "addqte execute";
}

void AddQte::undo()
{
    qDebug() << "addqte undo";
}

void AddQte::redo()
{
    qDebug() << "addqte redo";
}

