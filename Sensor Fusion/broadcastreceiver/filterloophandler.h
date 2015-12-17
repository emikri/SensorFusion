#ifndef FILTERLOOPHANDLER_H
#define FILTERLOOPHANDLER_H

#include <QObject>
#include "sensorvalues.h"
#include <QTimer>
#include <filter.h>
#include <QList>
#include "madgwickahrscplusplus.h"
#include "kalman.h"

class filterLoopHandler : public QObject
{
    Q_OBJECT

public:
    filterLoopHandler(SensorValues &sv, QObject *parent = 0);
    void addFilter(Filter* filter);
public slots:
    void run();

private:
    float accX, accY, accZ;
    SensorValues& sv;
    QTimer *timer;
    QList<Filter*> filters;
};

#endif // FILTERLOOPHANDLER_H
