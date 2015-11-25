#ifndef SENSOR_H
#define SENSOR_H

#include <QList>

enum SensorType {Accelerometer = 3, Gyrometer = 4, Magnetometer = 5};

class Sensor
{
public:
    float sensorValueX;
    float sensorValueY;
    float sensorValueZ;
    SensorType sType;
    QList<QString> sensorHistory;

public:
    Sensor();
    Sensor(float x, float y, float z, SensorType t);
    void PopulateHistory();
    Sensor ReadOldest(bool old = true);
};

#endif // SENSOR_H
