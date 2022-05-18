#ifndef ADDTARGET_H
#define ADDTARGET_H

#include "action_i.h"
#include "level.h"

class AddTarget : public Action_I
{
public:
    AddTarget(int timeSeconds, Level *level);
    void execute();
    void undo();
    void redo();

private:
    int timeSeconds;
    Level *level;
};

#endif // ADDTARGET_H
