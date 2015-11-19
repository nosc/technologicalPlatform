#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T13:26:07
#
#-------------------------------------------------

TEMPLATE = subdirs

QMAKE_CXXFLAGS = -std=c++0x
QMAKE_LFLAGS += -fprofile-arcs

SUBDIRS += lua \
    dbProxierCore \
    dbProxierService

dbproxier.depends = lua dbProxierCore

