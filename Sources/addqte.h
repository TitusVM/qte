#ifndef ADDQTE_H
#define ADDQTE_H

#include "action_i.h"

#include <QChar>

class AddQte : public Action_I
{
public:
    AddQte(int timeSeconds, QChar* letter);
    void execute();
    void undo();
    void redo();

private:
    int timeSeconds;
    QChar* letter;
};

#endif // ADDQTE_H
