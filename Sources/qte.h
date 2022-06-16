#ifndef QTE_H
#define QTE_H
#include <QKeyEvent>

/**
 * @brief The QTE class is the implementation of an event in the sequential event structure. It holds the
 * necessary information to display a QTE at a particular time in the Level.
 */
class QTE
{
public:
    QTE();
    void generate();
    QChar randomKey();

    QChar qteKey;
};

#endif // QTE_H
