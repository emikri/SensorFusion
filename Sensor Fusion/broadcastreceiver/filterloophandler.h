#ifndef FILTERLOOPHANDLER_H
#define FILTERLOOPHANDLER_H

#include <QObject>
#include "sensorvalues.h"
#include <QTimer>

class filterLoopHandler : public QObject
{
    Q_OBJECT

public:
    filterLoopHandler(SensorValues &sv, QObject *parent = 0);

public slots:
    void run();

private:
    float accX, accY, accZ;
    SensorValues& sv;
    QTimer *timer;
};

#endif // FILTERLOOPHANDLER_H
