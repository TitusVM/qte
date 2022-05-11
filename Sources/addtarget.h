#ifndef ADDTARGET_H
#define ADDTARGET_H

#include "action_i.h"

class AddTarget : public Action_I
{
public:
    AddTarget(int timeSeconds);
    void execute();
    void undo();
    void redo();

private:
    int timeSeconds;
};

#endif // ADDTARGET_H
