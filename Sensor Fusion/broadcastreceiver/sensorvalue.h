#ifndef SENSORVALUE_H
#define SENSORVALUE_H

#include <QObject>

class SensorValue
{
public:
    float* getAccelerometer();
    void setAccelerometer(float,float,float);
    SensorValue();
private:
    float accelerometerX,
        accelerometerY,
        accelerometerZ;
};

#endif // SENSORVALUE_H
