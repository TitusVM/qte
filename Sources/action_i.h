#ifndef ACTION_I_H
#define ACTION_I_H

/**
 * @brief The Action_I interface outlines the three major methods that need to be
 * implemented in the various Actions the programm uses to manipulate the sequential
 * event structure.
 * Those being:
 *      - execute() - executes the action
 *      - undo()    - undoes the action
 *      - redo()    - redoes the action
 *
 * An action has a single attribute, this being timeSeconds, an integer representing
 * it's position in the sequential event structure (Level in this case)
 */

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
