#include "sensor.h"

using namespace std;

Sensor::Sensor()
{
    this->sensorValueX = 0.0F;
    this->sensorValueY = 0.0F;
    this->sensorValueZ = 0.0F;
}

Sensor::Sensor(float x, float y, float z, SensorType t){
    this->sensorValueX = x;
    this->sensorValueY = y;
    this->sensorValueZ = z;
    this->sType = t;
    //PopulateHistory();
}

void Sensor::PopulateHistory(){
    QString currentReading = QString::number(this->sensorValueX) + "," + QString::number(this->sensorValueY) + "," + QString::number(this->sensorValueZ);
    sensorHistory.append(currentReading);
}

Sensor Sensor::ReadOldest(bool old){
    Sensor oldest;
    oldest.sType = this->sType;
    // the following takeFirst() function removes the first item and returns it
    if (!this->sensorHistory.isEmpty()){
        QString lastReading;
        if (old){
            lastReading = this->sensorHistory.takeFirst();
        }
        else {
            lastReading = this->sensorHistory.takeLast();
        }
        QStringList xyz = lastReading.split(",");
        oldest.sensorValueX = xyz[0].toFloat();
        oldest.sensorValueY = xyz[1].toFloat();
        oldest.sensorValueZ = xyz[2].toFloat();
    }
    return oldest;
}


