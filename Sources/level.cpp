#include "level.h"
#include <QFile>

Level::Level(QString filePath)
{
    this->filePath = filePath;
    this->totalSeconds = 0;
}

void Level::importLevel()
{
    QString levelPath = "../Sources/Levels/" + this->filePath;
    QFile file(levelPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }


    QString line;
    QStringList events;
    QTextStream in(&file);
    if (!file.atEnd())
    {

       line = file.readLine();
    }
    if (line.split(";").at(0) == "Qt-eMitus")
    {
        line = file.readLine();
        this->totalSeconds = line.split(";").at(0).toInt();
        qDebug() << line.toInt();
        while (!file.atEnd())
        {
            line = file.readLine();
            events = line.split(';');

            if (events.at(0) == "target")
            {
                this->addTarget(events.at(1).toInt());
            }
            else if (events.at(0) == "qte")
            {
                this->addQTE(events.at(1).toInt());
            }
        }
    }
}

void Level::addTarget(int timeSeconds)
{
    this->targetsSeconds.append(timeSeconds);
}

void Level::addQTE(int timeSeconds)
{
    this->qtesSeconds.append(timeSeconds);
}
