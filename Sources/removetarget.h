#ifndef REMOVETARGET_H
#define REMOVETARGET_H

#include "action_i.h"
#include "level.h"

class RemoveTarget : public Action_I
{
public:
    RemoveTarget(int timeSeconds, Level *level);
    void execute();
    void undo();
    void redo();

private:
    int timeSeconds;
    Level *level;
};

#endif // REMOVETARGET_H
