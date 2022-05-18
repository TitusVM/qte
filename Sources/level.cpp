#include "level.h"
#include <QFile>

Level::Level(QString filePath)
{
    this->filePath = filePath;
    this->totalSeconds = 0;
}

Level::Level()
{
    this->filePath = "";
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
                if (!this->targetsSeconds.contains(events.at(1).toInt()))
                {
                    this->addTarget(events.at(1).toInt());
                }
            }
            else if (events.at(0) == "qte")
            {
                if (!this->qtesSeconds.contains(events.at(1).toInt()))
                {
                    this->addQTE(events.at(1).toInt());
                }

            }
        }
    }
}


void Level::exportLevel()
{
    QFile file(levelName); // TODO dynamic name
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "Qt-eMitus;";
    out << totalSeconds;
    for(int i = 0; i <=totalSeconds;i++)
    {
        if (qtesSeconds.contains(i))
        {
            out << "qte;" << i;
        }

        if (targetsSeconds.contains(i))
        {
            out << "target;" << i;
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

void Level::removeTarget(int timeSeconds)
{
    this->targetsSeconds.removeAt(timeSeconds);
}

void Level::removeQte(int timeSeconds)
{
    this->qtesSeconds.removeAt(timeSeconds);
}

void Level::updateTarget(int oldTimeSeconds, int newTimeSeconds)
{
    this->targetsSeconds.removeAt(oldTimeSeconds);
    this->targetsSeconds.append(newTimeSeconds);
}

void Level::updateQte(int oldTimeSeconds, int newTimeSeconds)
{
    this->qtesSeconds.removeAt(oldTimeSeconds);
    this->qtesSeconds.append(newTimeSeconds);
}

void Level::setName(QString levelName)
{
    this->levelName = levelName;
}
