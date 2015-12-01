QT += network widgets

HEADERS       = receiver.h \
    sensorvalues.h \
    sensor.h \
    MadgwickAHRS.h \
    madgwickahrscplusplus.h\
    kalman.h \
    staticmethods.h \
    filterloophandler.h
SOURCES       = receiver.cpp \
                main.cpp \
    sensorvalues.cpp \
    sensor.cpp \
    MadgwickAHRS.c \
    madgwickahrscplusplus.cpp\
    kalman.cpp \
    filterloophandler.cpp
