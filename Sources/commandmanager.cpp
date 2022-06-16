#include "commandmanager.h"
#include <QDebug>

/**
 * @brief CommandManager::CommandManager Constructor creates two new Action Stacks
 */
CommandManager::CommandManager()
{
    this->undoActionStack = new QStack<Action_I*>();
    this->redoActionStack = new QStack<Action_I*>();
}

CommandManager::~CommandManager()
{
}

/**
 * @brief CommandManager::execute executes given action
 * @param action to execute
 */
void CommandManager::execute(Action_I *action)
{
    action->execute();
    this->undoActionStack->push(action);
}

/**
 * @brief CommandManager::undo undoes last action
 */
void CommandManager::undo()
{
    if (!this->undoActionStack->isEmpty())
    {
        this->undoActionStack->top()->undo();
        this->redoActionStack->push(this->undoActionStack->pop());
    }
}

/**
 * @brief CommandManager::redo redoes last undone action
 */
void CommandManager::redo()
{
    if (!this->redoActionStack->isEmpty())
    {
        this->redoActionStack->top()->redo();
        this->undoActionStack->push(this->redoActionStack->pop());
    }
}

/**
 * @brief CommandManager::getUndoActionStackLength
 * @return int undoActionStackLength
 */
int CommandManager::getUndoActionStackLength()
{
    return this->undoActionStack->length();
}

int CommandManager::getRedoActionStackLength()
{
    return this->redoActionStack->length();
}
