#include "sensorvalue.h"

int accelerometer;

SensorValue::SensorValue()
{
    accelerometer = 0; // DUMMY
}

int SensorValue::getAccelerometer()
{
    return accelerometer;
}
