#include <QFileDialog>
#include "level.h"

Level::Level(QString filePath, bool isCustom)
{
    if(isCustom)
    {
        this->fileName = filePath;
    }
    else
    {
        this->fileName = ":/Levels/" + filePath;
    }
    this->totalSeconds = 0;
}

Level::Level()
{
    this->totalSeconds = 0;
}

void Level::importLevel()
{
    QFile file(this->fileName);
    qDebug() << "Importing from " + this->fileName;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error reading file " + this->fileName;
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
        file.close();
    }
}


void Level::exportLevel(bool isNewLevel, QWidget* parent)
{
    qDebug() << "1";
    if (qtesSeconds.isEmpty() && targetsSeconds.isEmpty()) {
        this->totalSeconds = 0;
    }
    else if(this->qtesSeconds.last() >= this->targetsSeconds.last())
    {

        this->totalSeconds = this->qtesSeconds.last();
    }
    else
    {
        this->totalSeconds = this->targetsSeconds.last();
    }
    qDebug() << "2";
    if(isNewLevel)
    {
        this->fileName = QFileDialog::getSaveFileName(parent, tr("Save Level"), ".", tr("Level Files (*.csv)"));
    }
    qDebug() << "3";
    QFile file(this->fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug() << "Error reading file " + this->fileName;
        return;
    }

    QTextStream out(&file);
    out << "Qt-eMitus;\n";
    out << totalSeconds << "\n";
    for(int i = 0; i <= totalSeconds; i++)
    {
        if (qtesSeconds.contains(i))
        {
            out << "qte;" + QString::number(i) << "\n";
        }

        if (targetsSeconds.contains(i))
        {
            out << "target;" + QString::number(i) << "\n";
        }
    }
    file.close();
}

void Level::addTarget(int timeSeconds)
{
    if(!this->targetsSeconds.contains(timeSeconds))
    {
        this->targetsSeconds.append(timeSeconds);
        emit signalLevelChanged();
    }
}

void Level::addQTE(int timeSeconds)
{
    if(!this->qtesSeconds.contains(timeSeconds))
    {
        this->qtesSeconds.append(timeSeconds);
        emit signalLevelChanged();
    }
}

void Level::removeTarget(int timeSeconds)
{
    if(this->targetsSeconds.contains(timeSeconds))
    {
        this->targetsSeconds.removeOne(timeSeconds);
        emit signalLevelChanged();
    }
}

void Level::removeQte(int timeSeconds)
{
    if(this->qtesSeconds.contains(timeSeconds))
    {
        this->qtesSeconds.removeOne(timeSeconds);
        emit signalLevelChanged();
    }
}

void Level::updateTarget(int oldTimeSeconds, int newTimeSeconds)
{
    if(!this->targetsSeconds.contains(oldTimeSeconds))
    {
        this->targetsSeconds.removeOne(oldTimeSeconds);
        this->targetsSeconds.append(newTimeSeconds);
        emit signalLevelChanged();
    }
}

void Level::updateQte(int oldTimeSeconds, int newTimeSeconds)
{
    if(!this->qtesSeconds.contains(oldTimeSeconds))
    {
        this->qtesSeconds.removeOne(oldTimeSeconds);
        this->qtesSeconds.append(newTimeSeconds);
        emit signalLevelChanged();
    }
}

void Level::setName(QString levelName)
{
    this->levelName = levelName;
}

void Level::sortQtes()
{
    std::sort(this->qtesSeconds.begin(), this->qtesSeconds.end());
    emit signalLevelChanged();
}

void Level::sortTargets()
{
    std::sort(this->targetsSeconds.begin(), this->targetsSeconds.end());
    emit signalLevelChanged();
}
