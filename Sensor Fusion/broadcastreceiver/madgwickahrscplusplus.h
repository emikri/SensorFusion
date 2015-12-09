#ifndef MADGWICKAHRSCPLUSPLUS_H
#define MADGWICKAHRSCPLUSPLUS_H

#include <QQuaternion>
#include "filter.h"

class MadgwickAHRScplusplus
{
public:
    MadgwickAHRScplusplus();

    float beta;
    float q0, q1, q2, q3;
//    void MadgwickAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
    void MadgwickAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az);
    QList<float> getOrientation();
    void updateOrientation(float, float, float,float, float, float,float, float, float);
    QQuaternion getRotation();
    void setAngles(QList<float> newAngles);
};

#endif // MADGWICKAHRSCPLUSPLUS_H
