#include <QThread>
#include <QTimer>
#include "filterloophandler.h"
#include "sensorvalues.h"


filterLoopHandler::filterLoopHandler(SensorValues &sv, QObject *parent) : QObject(parent), sv(sv)
{
    float accX, accY, accZ;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(run()));
    timer->start(200);
}

void filterLoopHandler::run(){
    accX = sv.getSensors()[0].getSensorValues()[0];
}
