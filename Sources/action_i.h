#ifndef ACTION_I_H
#define ACTION_I_H

class Action_I
{
public:
    virtual ~Action_I() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;

private:
    int timeSeconds;
};

#endif // ACTION_I_H
