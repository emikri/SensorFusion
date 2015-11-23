#include "sensorvalue.h"

float accelerometerX,
    accelerometerY,
    accelerometerZ;

SensorValue::SensorValue()
{
    accelerometerX = 0;
    accelerometerY = 0;
    accelerometerZ = 0;
}

float* SensorValue::getAccelerometer()
{
    static float out[3];
    out[0] = accelerometerX;
    out[1] = accelerometerY;
    out[2] = accelerometerZ;
    return out;
}

void SensorValue::setAccelerometer(float accelerometerX,float accelerometerY,float accelerometerZ){
    this->accelerometerX = accelerometerX;
    this->accelerometerY = accelerometerY;
    this->accelerometerZ = accelerometerZ;
}
