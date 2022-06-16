#ifndef REMOVETARGET_H
#define REMOVETARGET_H

#include "action_i.h"
#include "level.h"
/**
 * @brief The RemoveTarget class implements the Action_I interface for the purpose of removing a Target event
 * from the sequential event structure (Level in this particular case)
 */
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
