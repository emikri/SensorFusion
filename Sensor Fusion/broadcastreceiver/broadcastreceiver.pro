QT += core gui network widgets

HEADERS       = receiver.h \
    sensorvalues.h \
    sensor.h \
    madgwickahrscplusplus.h\
    kalman.h \
    staticmethods.h \
    filterloophandler.h \
    filter.h \
    geometryengine.h \
    mainwidget.h \
    MadgwickAHRS.h
SOURCES       = receiver.cpp \
                main.cpp \
    sensorvalues.cpp \
    sensor.cpp \
    MadgwickAHRS.c \
    madgwickahrscplusplus.cpp\
    kalman.cpp \
    filterloophandler.cpp \
    filter.cpp \
    geometryengine.cpp \
    mainwidget.cpp

RESOURCES += \
    shaders.qrc \
    textures.qrc

DISTFILES += \
    fshader.glsl \
    vshader.glsl \
    cube.png
