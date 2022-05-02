#ifndef ADDTARGET_H
#define ADDTARGET_H

#include <QObject>
#include "action_i.h"

class AddTarget : public Action_I
{
public:
    void undo();
    void redo();

private:
    int timeSeconds;
};

#endif // ADDTARGET_H
