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
    filterLoopHandler(SensorValues &sv, MadgwickAHRScplusplus &mad, Kalman &kal , QObject *parent = 0);
    void addFilter(MadgwickAHRScplusplus* filter);
    void addKFilter(Kalman* kFilter);
public slots:
    void run();

private:
    float accX, accY, accZ;
    SensorValues& sv;
    QTimer *timer;
    QList<MadgwickAHRScplusplus*> filters;
    QList<Kalman*> kFilters;
};

#endif // FILTERLOOPHANDLER_H
