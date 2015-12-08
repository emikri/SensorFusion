#include "kalman_object.h"
#include "kalman.h"


kalman_object::kalman_object()
{
    orientation = QQuaternion(1.0f, 0.0f, 0.0f, 0.0f);
    ex = 0;
    ey = 0;
    ez = 0;
}

void kalman_object::updateOrientation(float gx, float gy, float gz, float ax, float ay, float az)
{
    //TODO: fix units
    Kalman kalman;
    ex = kalman.getAngle(ax, gx, 0.001f);
    ey = kalman.getAngle(ay, gy, 0.001f);
    ez = kalman.getAngle(az, gz, 0.001f);
    orientation = QQuaternion::fromEulerAngles(ex, ey, ez);
}

QQuaternion kalman_object::getRotation()
{
    return orientation;
}

