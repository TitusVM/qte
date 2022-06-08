#ifndef LEVEL_H
#define LEVEL_H
#include <QString>
#include <QList>
#include <QFile>
#include <algorithm>

#include "target.h"
#include "qte.h"
#include "graphicsscene.h"

class Level : public QObject
{
    Q_OBJECT
public:
    Level();
    Level(QString filePath);
    void exportLevel();
    void importLevel();
    void addTarget(int timeSeconds);
    void addQTE(int timeSeconds);
    void removeTarget(int timeSeconds);
    void removeQte(int timeSeconds);
    void updateTarget(int oldTimeSeconds, int newTimeSeconds);
    void updateQte(int oldTimeSeconds, int newTimeSeconds);
    void setName(QString levelName);
    void sortQtes();
    void sortTargets();

public:
    QList<int> targetsSeconds;
    QList<int> qtesSeconds;

    int totalSeconds;

private:
    QString fileName;
    QString difficulty;
    QString levelName;

signals:
    void signalLevelChanged();
};

#endif // LEVEL_H
