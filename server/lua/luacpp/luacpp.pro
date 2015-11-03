#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T20:33:28
#
#-------------------------------------------------

QT       -= core gui

TARGET = luacpp
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH = include

unix {
    target.path = /usr/lib
    INSTALLS += target
}	

HEADERS += \
    include/lua/cpp/coroutine.h \
    include/lua/cpp/machine.h \
    include/lua/cpp/reference.h \
    include/lua/cpp/table.h \
    include/lua/cpp/functionbase.h \
    include/lua/cpp/function.h \
    include/lua/cpp/generalgenericfunctions.h \
    include/lua/cpp/genericfunction.h \
    include/lua/cpp/lightuserdata.h \
    include/lua/cpp/typetemplates.h \
    include/lua/cpp/value.h \
    include/lua/cpp/userdata.h \
    include/lua/cpp/userdatabindtemplates.h \
    include/lua/cpp/userdataforwards.h \
    include/lua/cpp/voidgenericfunctions.h \
    include/lua/cpp/state.h

SOURCES += \
    src/lua/cpp/coroutine.cpp \
    src/lua/cpp/machine.cpp \
    src/lua/cpp/reference.cpp \
    src/lua/cpp/table.cpp \
    src/lua/cpp/function.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lua/release/ -llua
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lua/debug/ -llua
else:unix: LIBS += -L$$OUT_PWD/../lua/ -llua

INCLUDEPATH += $$PWD/../lua/include
DEPENDPATH += $$PWD/../lua/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/release/liblua.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/debug/liblua.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/release/lua.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/debug/lua.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lua/liblua.a
