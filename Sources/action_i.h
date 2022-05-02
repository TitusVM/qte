#ifndef ACTION_I_H
#define ACTION_I_H

class Action_I
{
public:
    virtual void undo();
    virtual void redo();

private:
    int timeSeconds;
};

#endif // ACTION_I_H
