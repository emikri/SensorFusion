#ifndef SENSOR_H
#define SENSOR_H

#include <QList>

enum SensorType {Accelerometer = 3, Gyrometer = 4, Magnetometer = 5};

class Sensor
{
public:
    SensorType sensorType;
    Sensor();
    Sensor(SensorType t);
    float* getSensorValues();
    void setSensorValues(float,float,float);
private:
    float sensorValueX;
    float sensorValueY;
    float sensorValueZ;
};

#endif // SENSOR_H
