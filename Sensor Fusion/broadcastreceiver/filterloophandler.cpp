#include <QThread>
#include <QTimer>
#include "filterloophandler.h"
#include "sensorvalues.h"
#include <QDebug>


filterLoopHandler::filterLoopHandler(SensorValues &sv, QObject *parent) : QObject(parent), sv(sv)
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(run()));
    timer->start(200);
}
int counter1 = 0;
void filterLoopHandler::run(){
    float accX = sv.getSensors()[0].getSensorValues()[0],
          accY = sv.getSensors()[0].getSensorValues()[1],
          accZ = sv.getSensors()[0].getSensorValues()[2]

            ;
//    for (const int& i : v) { std::cout << i << "\n"; }
    for (int i = 0; i < filters.length(); i++) {
        filters.at(i)->updateOrientation(accX, accY, accZ,accX, accY, accZ, accX, accY, accZ);
    }

}

void filterLoopHandler::addFilter(MadgwickAHRScplusplus* filter) {
    filters.append(filter);
}
