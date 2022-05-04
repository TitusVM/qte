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
    if (line == "Qt-eMitus\n")
    {
        line = file.readLine();
        this->totalSeconds = line.toInt();
        qDebug() << line.toInt();
        while (!file.atEnd())
        {
            line = file.readLine();
            events = line.split(';');

            if (events.at(0) == "Target")
            {
                this->addTarget(events.at(1).toInt());
            }
            else if (events.at(0) == "QTE")
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
