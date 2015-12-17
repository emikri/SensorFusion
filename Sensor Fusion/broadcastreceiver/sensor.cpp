#include "sensor.h"

using namespace std;

Sensor::Sensor(SensorType t)
{
    this->sensorValueX = 0.0F;
    this->sensorValueY = 0.0F;
    this->sensorValueZ = 0.0F;
    this->sensorType = t;
}

void Sensor::setSensorValues(float sensorValueX,float sensorValueY,float sensorValueZ){
    this->sensorValueX = sensorValueX;
    this->sensorValueY = sensorValueY;
    this->sensorValueZ = sensorValueZ;
}

float* Sensor::getSensorValues()
{
    static float out[3];
    out[0] = sensorValueX;
    out[1] = sensorValueY;
    out[2] = sensorValueZ;
    return out;
}
