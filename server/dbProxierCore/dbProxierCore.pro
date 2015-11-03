#-------------------------------------------------
#
# Project created by QtCreator 2015-10-30T14:02:51
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = dbProxierCore
TEMPLATE = lib

DEFINES += DBPROXIERCORE_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    include/dbProxier/Core.h \
    include/dbProxier/Core_global.h \
    include/dbProxier/IQuery.h

INCLUDEPATH = include

SOURCES += \
    src/dbProxier/Core.cpp \
    src/dbProxier/IQuery.cpp
