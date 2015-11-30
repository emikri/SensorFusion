
#ifndef SENSORVALUES_H
#define SENSORVALUES_H

#include <QObject>
#include "sensor.h"

class SensorValues
{
public:
    SensorValues();
    void processDatagram(QByteArray datagram);

private:
};

#endif // SENSORVALUES_H
