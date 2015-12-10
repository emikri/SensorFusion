#ifndef FILTER_H
#define FILTER_H

#include <QList>


class Filter
{
public:
    Filter();
    QList<float> getOrientation();
    virtual void updateOrientation(float, float, float,float, float, float,float, float, float) = 0;
protected:

};

#endif // FILTER_H
