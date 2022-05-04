#include "commandmanager.h"

CommandManager::CommandManager()
{
    this->undoActionStack = new QStack<Action_I*>();
    this->redoActionStack = new QStack<Action_I*>();
}

CommandManager::~CommandManager()
{
    // this->clear(); /* Not sure if this is useful */
}

void CommandManager::execute(Action_I *action)
{
    action->execute();
    this->undoActionStack->push(action);
}

void CommandManager::undo()
{
    if (!this->undoActionStack->isEmpty())
    {
        this->undoActionStack->top()->undo();
        this->redoActionStack->push(this->undoActionStack->pop());
    }
}

void CommandManager::redo()
{
    if (!this->redoActionStack->isEmpty())
    {
        this->redoActionStack->top()->redo();
        this->undoActionStack->push(this->redoActionStack->pop());
    }
}
