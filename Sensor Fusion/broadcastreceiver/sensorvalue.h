#ifndef SENSORVALUE_H
#define SENSORVALUE_H

#include <QObject>

class SensorValue
{

public:
    float* getSensorValues();
    void setSensorValues(float,float,float);
    void setSensorType(int);
    SensorValue();
private:
    float sensorValueX,
        sensorValueY,
        sensorValueZ;
    int sensorType;
};

#endif // SENSORVALUE_H
