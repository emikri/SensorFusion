//#ifndef STATICMETHODS_H
//#define STATICMETHODS_H

#include <QList>
#include "math.h"

namespace StaticMethods {

    float radianToDegree(float rad){

        return rad * 180 / M_PI;
    }

    QList<float> getAngleFromVectorDegree(float x, float y, float z){

        float thetaXDeg =radianToDegree(atan2(x,sqrt(pow(y,2) + pow(z,2))));
        float thetaYDeg = atan2(y,sqrt(pow(x,2) + pow(z,2)));
        float thetaZDeg = atan2(sqrt(pow(x,2) + pow(y,2)), z);
        QList<float> angleDeg;
        angleDeg.append(thetaXDeg);
        angleDeg.append(thetaYDeg);
        angleDeg.append(thetaZDeg);
        return angleDeg;

    }    

}

//#endif // STATICMETHODS_H
