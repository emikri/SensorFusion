#ifndef SENSORVALUE_H
#define SENSORVALUE_H

#include <QObject>

class SensorValue
{
public:
    int getAccelerometer();
    SensorValue();
private:
    int accelerometer;
};

#endif // SENSORVALUE_H
