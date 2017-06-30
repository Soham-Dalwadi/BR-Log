TEMPLATE = app
TARGET = ProjectLog
QT += qml quick sql

#Header Files
HEADERS += \
    header/mainmodel.h \
    header/maindatabasemodel.h \
    header/packetlistmodel.h \
    datatype/datatypes.h

#Source Files
SOURCES += \
    source/main.cpp \
    source/mainmodel.cpp \
    source/maindatabasemodel.cpp \
    source/packetlistmodel.cpp

#Include path - Specifies the #include directories which should be searched when compiling the project.
INCLUDEPATH += "header" "datatype"

OTHER_FILES += \
    qml/main.qml \
    qml/LoginScreen.qml \
    qml/MainUserScreen.qml \
    qml/PacketDetailScreen.qml \
    qml/SignUpPage.qml \
    database/workbook.db

target.files = $$OTHER_FILES
target.path = $$OUT_PWD
DEPLOYMENT = target
INSTALLS += target

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

