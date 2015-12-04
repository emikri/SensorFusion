QT += core gui network widgets

HEADERS       = receiver.h \
    sensorvalues.h \
    sensor.h \
    MadgwickAHRS.h \
    madgwickahrscplusplus.h\
    kalman.h \
    staticmethods.h \
    filterloophandler.h \
    filter.h \
    geometryengine.h \
    mainwidget.h \
    kalman_object.h
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
    mainwidget.cpp \
    kalman_object.cpp

RESOURCES += \
    shaders.qrc \
    textures.qrc

DISTFILES += \
    fshader.glsl \
    vshader.glsl \
    cube.png
