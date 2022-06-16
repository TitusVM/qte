#include "qte.h"
#include <QRandomGenerator>

/**
 * @brief QTE::QTE Constructor, initializes Qte object
 */
QTE::QTE()
{
    generate();
}

/**
 * @brief QTE::generate generates random key event
 */
void QTE::generate()
{
    QChar key = randomKey();
    this->qteKey = key;
}

/**
 * @brief QTE::randomKey returns a random key from the uppercase alphabet
 * @return QChar randomKey
 */
QChar QTE::randomKey()
{
    return QChar(65 + QRandomGenerator::global()->bounded(0, 26));
}
