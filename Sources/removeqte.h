#ifndef REMOVEQTE_H
#define REMOVEQTE_H
#include "action_i.h"
#include "level.h"

#include <QChar>

class RemoveQte : public Action_I
{
public:
    RemoveQte(int timeSeconds, Level *level);
    void execute();
    void undo();
    void redo();

private:
    int timeSeconds;
    Level* level;
};

#endif // REMOVEQTE_H
