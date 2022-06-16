#ifndef ADDTARGET_H
#define ADDTARGET_H

#include "action_i.h"
#include "level.h"

/**
 * @brief The AddTarget class implements the Action_I interface for the purpose of adding a Target event
 * to the sequential event structure (Level in this particular case)
 */

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
