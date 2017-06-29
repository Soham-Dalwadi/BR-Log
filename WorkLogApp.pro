TEMPLATE = app

QT += qml quick sql

SOURCES += main.cpp \
    mainmodel.cpp \
    maindatabasemodel.cpp \
    packetlistmodel.cpp

RESOURCES += qml.qrc

OTHER_FILES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mainmodel.h \
    maindatabasemodel.h \
    datatypes.h \
    packetlistmodel.h
