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

    QString comp;

    for(int i=3; i<=5; i++) {
        QString comp = QString::number(i);
        if(datagramArray.contains(comp)) {
            sensorValue.setSensorType(i);
            int index = datagramArray.indexOf(comp);
            sensorValue.setSensorValues(datagramArray[index+1].toFloat(),
                                         datagramArray[index+2].toFloat(),
                                         datagramArray[index+3].toFloat());
        }
        sensorValues.append(sensorValue);
    }

    printf("Value %f, %f, %f",*sensorValue.getSensorValues();

}

SensorValue SensorValues::getOldest(){
    return sensorValues.takeFirst();
}
