QT += network widgets

HEADERS       = receiver.h \
    sensorvalues.h
SOURCES       = receiver.cpp \
                main.cpp \
    sensorvalues.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/broadcastreceiver
INSTALLS += target

