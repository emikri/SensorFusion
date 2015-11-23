#include "sensorvalue.h"

float sensorValueX,
    sensorValueY,
    sensorValueZ;

SensorValue::SensorValue()
{
    sensorValueX = 0;
    sensorValueY = 0;
    sensorValueZ = 0;
}

float* SensorValue::getSensorValues()
{
    static float out[3];
    out[0] = sensorValueX;
    out[1] = sensorValueY;
    out[2] = sensorValueZ;
    return out;
}

void SensorValue::setSensorValues(float sensorValueX,float sensorValueY,float sensorValueZ){
    this->sensorValueX = sensorValueX;
    this->sensorValueY = sensorValueY;
    this->sensorValueZ = sensorValueZ;
}
