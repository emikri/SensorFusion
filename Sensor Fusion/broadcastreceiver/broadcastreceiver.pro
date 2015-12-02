QT += core gui network widgets

HEADERS       = receiver.h \
    sensorvalues.h \
    sensor.h \
    kalman.h \
    staticmethods.h \
    filterloophandler.h \
    renderwidget.h
SOURCES       = receiver.cpp \
                main.cpp \
    sensorvalues.cpp \
    sensor.cpp \
    kalman.cpp \
    filterloophandler.cpp \
    renderwidget.cpp
