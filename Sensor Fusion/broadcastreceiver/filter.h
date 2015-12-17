#ifndef FILTER_H
#define FILTER_H

#include <QList>
#include <QQuaternion>

class Filter
{
public:
    Filter();
    QList<float> getOrientation();
    virtual void updateOrientation(float, float, float,float, float, float,float, float, float) = 0;
    virtual QQuaternion getRotation() = 0;
protected:

};

#endif // FILTER_H
