#include "sensorvalues.h"
#include "sensorvalue.h"
#include <QList>

// Array of SensorValue
QList<SensorValue> sensorValues;

SensorValues::SensorValues(QObject *parent) : QObject(parent)
{

}

void SensorValues::processDatagram(QByteArray datagram){
    SensorValue sensorValue; // dummy
    //= new Sens§orValue();
    sensorValues.append(sensorValue);
}

SensorValue SensorValues::getOldest(){
    return sensorValues.takeFirst();
}
