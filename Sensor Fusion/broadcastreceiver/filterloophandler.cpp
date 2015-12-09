#include <QThread>
#include <QTimer>
#include "filterloophandler.h"
#include "sensorvalues.h"
#include <QDebug>
#include <QFile>


filterLoopHandler::filterLoopHandler(SensorValues &sv, MadgwickAHRScplusplus &mad, Kalman &kal , QObject *parent) : QObject(parent), sv(sv)
{
    this->addFilter(&mad);
    this->addKFilter(&kal);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(run()));
    timer->start(2);
}

void filterLoopHandler::run(){
    float accX = sv.getSensors()[0].getSensorValues()[0],
          accY = sv.getSensors()[0].getSensorValues()[1],
          accZ = sv.getSensors()[0].getSensorValues()[2],
          gyrX = sv.getSensors()[1].getSensorValues()[0],
          gyrY = sv.getSensors()[1].getSensorValues()[1],
          gyrZ = sv.getSensors()[1].getSensorValues()[2],
          magX = sv.getSensors()[2].getSensorValues()[0],
          magY = sv.getSensors()[2].getSensorValues()[1],
          magZ = sv.getSensors()[2].getSensorValues()[2]
          ;
//    for (const int& i : v) { std::cout << i << "\n"; }
    for (int i = 0; i < filters.length(); i++) {
        filters.at(i)->updateOrientation(gyrX, gyrY, gyrZ ,accX, accY, accZ, magX, magY, magZ);
    }

    for (int i = 0; i < kFilters.length(); i++) {
        kFilters.at(i)->updateOrientation(gyrX, gyrY, gyrZ ,accX, accY, accZ, magX, magY, magZ);
    }

    QFile file("sensorvalues.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text)){
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            out << QString::number(sv.getSensors()[i].getSensorValues()[j]) + " ";
        }
    }
    out << "\n";
    file.close();
}

void filterLoopHandler::addFilter(MadgwickAHRScplusplus* filter) {
    filters.append(filter);
}

void filterLoopHandler::addKFilter(Kalman* kFilter) {
    kFilters.append(kFilter);
}
