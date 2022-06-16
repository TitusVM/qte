#ifndef LEVEL_H
#define LEVEL_H
#include <QString>
#include <QList>
#include <QFile>
#include <algorithm>

#include "target.h"
#include "qte.h"
#include "graphicsscene.h"

/**
 * @brief The Level class extends QObject and is the sequential event structure which holds information about every and all
 * events happening in a gameplay level. It serves as a container for two seperate event lists:
 *
 *      - QList<int> targetsSeconds holds the target events of the Level Object
 *      - QList<int> qtesSeconds holds the qte events of the Level Object
 *
 * The Level class also provides all the different methods of manipulation to alter the sequential event
 * structure. As well as the necessary signal (signalLevelChanged()) to trigger update functions on the UI.
 */
class Level : public QObject
{
    Q_OBJECT
public:
    Level(QString filePath, bool isCustom);
    Level();
    void exportLevel(bool isNewLevel, QWidget* parent);
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
