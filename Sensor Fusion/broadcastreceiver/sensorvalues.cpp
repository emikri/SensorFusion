#include "sensorvalues.h"
#include "sensorvalue.h"
#include <QList>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "sensor.h"


// Array of SensorValue
QList<SensorValue> sensorValues;
QList<Sensor> sensors;


SensorValues::SensorValues(QObject *parent) : QObject(parent)
{
    if(sensors.isEmpty()){
        Sensor acc(0.0F, 0.0F, 0.0F, Accelerometer);
        Sensor gyr(0.0F, 0.0F, 0.0F, Gyrometer);
        Sensor mag(0.0F, 0.0F, 0.0F, Magnetometer);
        sensors.append(mag);
        sensors.append(gyr);
        sensors.append(acc);
    }
}

/*void SensorValues::processDatagram(QByteArray datagram){

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
}


SensorValue SensorValues::getOldest(){
    return sensorValues.takeFirst();
}
*/

void SensorValues::processDatagram(QByteArray datagram){

    //SensorValue sensorValue;
    QString sDatagram = datagram.data();
    sDatagram = sDatagram.remove(" ");
    QStringList datagramArray = sDatagram.split(",");

    //qDebug() << datagramArray;

    QString comp;

    for(int i=3; i<=5; i++) {
        QString comp = QString::number(i);
        if(datagramArray.contains(comp)) {
            int index = datagramArray.indexOf(comp);
            for (int j = 0 ; j < sensors.size(); j++){
                if(sensors[j].sType == i){
                   sensors[j].sensorValueX = datagramArray[index+1].toFloat();
                   sensors[j].sensorValueY = datagramArray[index+2].toFloat();
                   sensors[j].sensorValueZ = datagramArray[index+3].toFloat();
                   sensors[j].PopulateHistory();
                }
            }
        }

    }
    qDebug() << getOldest(Accelerometer).sensorValueX;
}

Sensor SensorValues::getOldest(SensorType t){
    Sensor s;
    for (int j = 0 ; j < sensors.size(); j++){
        if(sensors[j].sType == t){
            s = sensors[j].ReadOldest();
            //if we instead need to have the current value we should call the above function with false argument
            //s = sensors[j].ReadOldest(false);
        }
    }
    return s;
}
