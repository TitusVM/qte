#ifndef QTE_H
#define QTE_H
#include <QKeyEvent>

class QTE
{
public:
    QTE();
    void generate();
    QChar randomKey();

    QChar qteKey;
};

#endif // QTE_H
