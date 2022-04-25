#include "qte.h"
#include <QRandomGenerator>

QTE::QTE()
{
    generate();
}

void QTE::generate()
{
    QChar key = randomKey();
    this->qteKey = key;
}

QChar QTE::randomKey()
{
    return QChar(65 + QRandomGenerator::global()->bounded(0, 26));
}
