#include "sensorvalues.h"
#include "sensorvalue.h"
#include <QList>
#include <QString>
#include <QStringList>
#include <QDebug>

// Array of SensorValue
QList<SensorValue> sensorValues;

SensorValues::SensorValues(QObject *parent) : QObject(parent)
{

}

void SensorValues::processDatagram(QByteArray datagram){
    SensorValue sensorValue;
    QString sDatagram = datagram.data();
    sDatagram = sDatagram.remove(" ");
    QStringList datagramArray = sDatagram.split(",");

    qDebug() << datagramArray;

    QString comp = "3";

    if(datagramArray.contains(comp)) {
        int index = datagramArray.indexOf(comp);
        sensorValue.setSensorValues(datagramArray[index+1].toFloat(),
                                     datagramArray[index+2].toFloat(),
                                     datagramArray[index+3].toFloat());
    }

    sensorValues.append(sensorValue);
}

SensorValue SensorValues::getOldest(){
    return sensorValues.takeFirst();
}
