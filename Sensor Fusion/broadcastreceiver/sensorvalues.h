
#ifndef SENSORVALUES_H
#define SENSORVALUES_H

#include <QObject>
#include "sensorvalue.h"

class SensorValues : public QObject
{
    Q_OBJECT
public:
    explicit SensorValues(QObject *parent = 0);
    void processDatagram(QByteArray datagram);
    SensorValue getOldest();

private:
    QList<SensorValue> sensorValues;

signals:

public slots:
};

#endif // SENSORVALUES_H
