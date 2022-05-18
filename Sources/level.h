#ifndef LEVEL_H
#define LEVEL_H
#include <QString>
#include <QList>
#include "target.h"
#include "qte.h"
#include "graphicsscene.h"

class Level
{
public:
    Level(QString filePath);
    Level();
    void exportLevel();
    void importLevel();
    void addTarget(int timeSeconds);
    void addQTE(int timeSeconds);
    void removeTarget(int timeSeconds);
    void removeQte(int timeSeconds);
    void updateTarget(int oldTimeSeconds, int newTimeSeconds);
    void updateQte(int oldTimeSeconds, int newTimeSeconds);
    void setName(QString levelName);


    QList<int> targetsSeconds;
    QList<int> qtesSeconds;

    int totalSeconds;

private:
    QString filePath;
    QString difficulty;
    QString levelName;
};

#endif // LEVEL_H
