#ifndef LEVELTRACK_H
#define LEVELTRACK_H

#include <QWidget>
#include <QTimeLine>
#include <QHBoxLayout>
#include <QGraphicsWidget>


class LevelTrack : public QWidget
{
    Q_OBJECT
public:
    LevelTrack();

private:
    QTimeLine *timeLine;
    QGraphicsWidget *qgraphicswidget;


// UI
private:
    void createUI();
    QHBoxLayout *hbox;
};

#endif // LEVELTRACK_H
