#include "level.h"
#include <QFile>

Level::Level()
{

}

void Level::importLevel()
{
    QFile file("Levels/easy.txt");
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
    if (line == "Qt-eMitus")
    {
        line = file.readLine();
        this->totalSeconds = line.toInt();
        while (!file.atEnd())
        {
            line = file.readLine();
            events = line.split(';');

            if (events.at(0) == "Target")
            {
                //this->addTarget(events.at(1).toInt(), false, false);
            }
            else if (events.at(0) == "QTE")
            {
                //this->addQTE(events.at(1).toInt());
            }
        }
    }
}
