
#ifndef SENSORVALUES_H
#define SENSORVALUES_H

#include <QObject>
#include "sensorvalue.h"
#include "sensor.h"

class SensorValues : public QObject
{
    Q_OBJECT
public:
    explicit SensorValues(QObject *parent = 0);
    void processDatagram(QByteArray datagram);
    //SensorValue getOldest();
    Sensor getOldest(SensorType t);

private:
    QList<SensorValue> sensorValues;

signals:

public slots:
};

#endif // SENSORVALUES_H
