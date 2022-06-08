#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <QStack>
#include "action_i.h"

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
    // void clear(); /* Not sure if this is useful */

private:
    QStack<Action_I*> *undoActionStack;
    QStack<Action_I*> *redoActionStack;


};

#endif // COMMANDMANAGER_H
