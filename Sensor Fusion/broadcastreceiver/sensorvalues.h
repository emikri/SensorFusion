
#ifndef SENSORVALUES_H
#define SENSORVALUES_H

#include <QObject>

class SensorValues : public QObject
{
    Q_OBJECT
public:
    explicit SensorValues(QObject *parent = 0);
    void processDatagram(QByteArray datagram);

private:
    QByteArray datagram;

signals:

public slots:
};

#endif // SENSORVALUES_H
