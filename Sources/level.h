#ifndef LEVEL_H
#define LEVEL_H
#include <QString>
#include <QList>
#include "target.h"
#include "qte.h"

class Level
{
public:
    Level();
    void exportLevel();
    void importLevel();
    void addTarget(int timeSeconds, bool isMoving, bool isGrowing);
    void addQTE(int timeSeconds);
    void removeTarget(int timeSeconds);
    void removeQte(int timeSeconds);
    void updateTarget(int timeSeconds);
    void updateQte(int timeSeconds);

private:
    QString filePath;
    QList<Target> targets;
    QList<QTE> qtes;
    QString difficulty;
    int totalSeconds;
};

#endif // LEVEL_H
