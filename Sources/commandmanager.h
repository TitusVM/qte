#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <QStack>
#include "action_i.h"

/**
 * @brief The CommandManager class is the orchestring leader of the ensemble. It tells actions what to do and
 * keeps done and undone actions in their respective stacks:
 *
 *      - QStack<Action_I*> *undoActionStack which holds all the actions that have been actively executed
 *      - QStack<Action_I*> *redoActionStack which holds all the actions that have been actively undone
 *
 * The purpose of these two stacks is to make the general usage of the editor more user-friendly and to offer
 * the possibility of doing and undoing various actions.
 */
class CommandManager
{
public:
    CommandManager();
    ~CommandManager();
    void execute(Action_I *action);
    void undo();
    int getUndoActionStackLength();
    void redo();
    int getRedoActionStackLength();

private:
    QStack<Action_I*> *undoActionStack;
    QStack<Action_I*> *redoActionStack;


};

#endif // COMMANDMANAGER_H
