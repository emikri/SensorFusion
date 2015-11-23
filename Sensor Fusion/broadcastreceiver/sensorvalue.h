#ifndef SENSORVALUE_H
#define SENSORVALUE_H

#include <QObject>

class SensorValue
{
public:
    float* getSensorValues();
    void setSensorValues(float,float,float);
    SensorValue();
private:
    float sensorValueX,
        sensorValueY,
        sensorValueZ;
};

#endif // SENSORVALUE_H
