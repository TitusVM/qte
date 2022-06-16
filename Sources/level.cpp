#include <QFileDialog>
#include "level.h"

/**
 * @brief Level::Level Constructor, creates a Level object from given parameters
 * @param filePath path to the custom Level file
 * @param isCustom bool to indicate if it is in deed a custom Level
 */
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

/**
 * @brief Level::Level secondary Constructor for empty Level
 */
Level::Level()
{
    this->totalSeconds = 0;
}

/**
 * @brief Level::importLevel to import all the events of given Level file
 */
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

/**
 * @brief Level::exportLevel save to fil
 * @param isNewLevel bool to indicate if a new file needs to be created first
 * @param parent for the showing of QMessageBox objects
 */
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

/**
 * @brief Level::addTarget atomic action to add a Target to a Level
 * @param timeSeconds time the event has to take place
 *
 * Emits signalLevelChanged()
 */
void Level::addTarget(int timeSeconds)
{
    if(!this->targetsSeconds.contains(timeSeconds))
    {
        this->targetsSeconds.append(timeSeconds);
        emit signalLevelChanged();
    }
}

/**
 * @brief Level::addQTE atomic action to add a Qte to a Level
 * @param timeSeconds time the event has to take place
 *
 * Emits signalLevelChanged()
 */
void Level::addQTE(int timeSeconds)
{
    if(!this->qtesSeconds.contains(timeSeconds))
    {
        this->qtesSeconds.append(timeSeconds);
        emit signalLevelChanged();
    }
}

/**
 * @brief Level::removeTarget atomic action to remove a Target from a Level
 * @param timeSeconds time the event takes place
 *
 * Emits signalLevelChanged()
 */
void Level::removeTarget(int timeSeconds)
{
    if(this->targetsSeconds.contains(timeSeconds))
    {
        this->targetsSeconds.removeOne(timeSeconds);
        emit signalLevelChanged();
    }
}

/**
 * @brief Level::removeQte atomic action to remove a Qte from a Level
 * @param timeSeconds time the event takes place
 *
 * Emits signalLevelChanged()
 */
void Level::removeQte(int timeSeconds)
{
    if(this->qtesSeconds.contains(timeSeconds))
    {
        this->qtesSeconds.removeOne(timeSeconds);
        emit signalLevelChanged();
    }
}

/**
 * @brief Level::updateTarget atomic action to update a Target from a Level
 * @param oldTimeSeconds
 * @param newTimeSeconds
 *
 * Emits signalLevelChanged()
 */
void Level::updateTarget(int oldTimeSeconds, int newTimeSeconds)
{
    if(!this->targetsSeconds.contains(oldTimeSeconds))
    {
        this->targetsSeconds.removeOne(oldTimeSeconds);
        this->targetsSeconds.append(newTimeSeconds);
        emit signalLevelChanged();
    }
}

/**
 * @brief Level::updateQte atomic action to update a Qte from a Level
 * @param oldTimeSeconds
 * @param newTimeSeconds
 *
 * Emits signalLevelChanged()
 */
void Level::updateQte(int oldTimeSeconds, int newTimeSeconds)
{
    if(!this->qtesSeconds.contains(oldTimeSeconds))
    {
        this->qtesSeconds.removeOne(oldTimeSeconds);
        this->qtesSeconds.append(newTimeSeconds);
        emit signalLevelChanged();
    }
}

/**
 * @brief Level::setName
 * @param levelName
 */
void Level::setName(QString levelName)
{
    this->levelName = levelName;
}

/**
 * @brief Level::sortQtes function to sort Qtes for User Interface
 *
 * Emits signalLevelChanged()
 */
void Level::sortQtes()
{
    std::sort(this->qtesSeconds.begin(), this->qtesSeconds.end());
    emit signalLevelChanged();
}

/**
 * @brief Level::sortTargets function to sort Targets for User Interface
 *
 * Emits signalLevelChanged()
 */
void Level::sortTargets()
{
    std::sort(this->targetsSeconds.begin(), this->targetsSeconds.end());
    emit signalLevelChanged();
}
