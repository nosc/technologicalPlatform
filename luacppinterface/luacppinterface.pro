#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T20:33:28
#
#-------------------------------------------------

QT       -= core gui

TARGET = luacppinterface
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH = include lua/include

unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS += -std=c++0x -g -ftest-coverage -fprofile-arcs

HEADERS += \
    include/lua/cpp/luacoroutine.h \
    include/lua/cpp/luacppinterface.h \
    include/lua/cpp/luafunction.h \
    include/lua/cpp/luafunctionbase.h \
    include/lua/cpp/luageneralgenericfunctions.h \
    include/lua/cpp/luagenericfunction.h \
    include/lua/cpp/lualightuserdata.h \
    include/lua/cpp/luareference.h \
    include/lua/cpp/luatable.h \
    include/lua/cpp/luatype.h \
    include/lua/cpp/luatypetemplates.h \
    include/lua/cpp/luauserdata.h \
    include/lua/cpp/luauserdatabindtemplates.h \
    include/lua/cpp/luauserdataforwards.h \
    include/lua/cpp/luavoidgenericfunctions.h

SOURCES += \
    src/lua/cpp/luacoroutine.cpp \
    src/lua/cpp/luacppinterface.cpp \
    src/lua/cpp/luafunction.cpp \
    src/lua/cpp/luareference.cpp \
    src/lua/cpp/luatable.cpp
