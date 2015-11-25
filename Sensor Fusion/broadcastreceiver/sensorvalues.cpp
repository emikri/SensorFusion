#include "sensorvalues.h"
#include <QList>
#include <QString>
#include <QStringList>
#include "sensor.h"


QList<Sensor> sensors;

SensorValues::SensorValues(QObject *parent) : QObject(parent)
{
    Sensor acc(Accelerometer);
    Sensor gyr(Gyrometer);
    Sensor mag(Magnetometer);
    sensors.append(acc);
    sensors.append(gyr);
    sensors.append(mag);
}

void SensorValues::processDatagram(QByteArray datagram){
    QString sDatagram = datagram.data();
    sDatagram = sDatagram.remove(" ");
    QStringList datagramArray = sDatagram.split(",");

    QString comp;
    for(int i=3; i<=5; i++) {
        comp = QString::number(i);
        if(datagramArray.contains(comp)) {
            int index = datagramArray.indexOf(comp);
            for (int j = 0 ; j < sensors.size(); j++){
                if(sensors[j].sensorType == i){
                    sensors[j].setSensorValues(datagramArray[index+1].toFloat(),
                                                 datagramArray[index+2].toFloat(),
                                                 datagramArray[index+3].toFloat());
                }
            }
        }
    }
}
