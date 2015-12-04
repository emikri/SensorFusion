#ifndef KALMAN_OBJECT_H
#define KALMAN_OBJECT_H

#include <QQuaternion>


class kalman_object
{
public:
    kalman_object();
    void updateOrientation(float, float, float, float, float, float);
    QQuaternion getRotation();

private:
    QQuaternion orientation;
    float ex, ey, ez;
};

#endif // KALMAN_OBJECT_H
