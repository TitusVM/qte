#include "addtarget.h"

#include <QDebug>

AddTarget::AddTarget(int timeSeconds)
{
     this->timeSeconds = timeSeconds;
}

void AddTarget::execute()
{
    qDebug() << "addtarget execute";
}

void AddTarget::undo()
{
    qDebug() << "addtarget undo";
}

void AddTarget::redo()
{
    qDebug() << "addtarget redo";
}
