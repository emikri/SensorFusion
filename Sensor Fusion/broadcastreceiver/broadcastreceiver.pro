QT += network widgets

HEADERS       = receiver.h \
    sensorvalue.h
SOURCES       = receiver.cpp \
                main.cpp \
    sensorvalue.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/broadcastreceiver
INSTALLS += target

