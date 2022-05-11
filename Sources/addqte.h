#ifndef ADDQTE_H
#define ADDQTE_H

#include "action_i.h"
#include "level.h"

#include <QChar>

class AddQte : public Action_I
{
public:
    AddQte(int timeSeconds, Level *level);
    void execute();
    void undo();
    void redo();

private:
    int timeSeconds;
    Level* level;
};

#endif // ADDQTE_H
