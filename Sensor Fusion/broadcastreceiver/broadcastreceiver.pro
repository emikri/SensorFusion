QT += network widgets

HEADERS       = receiver.h \
    sensorvalues.h \
    sensorvalue.h
    sensorvalue.h
SOURCES       = receiver.cpp \
                main.cpp \
    sensorvalues.cpp \
    sensorvalue.cpp
    sensorvalue.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/broadcastreceiver
INSTALLS += target

