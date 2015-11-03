QT += core
QT -= gui
QT += network
QT += sql

QMAKE_CXXFLAGS += -std=c++0x

TARGET = dbProxierService
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/dbproxier/RouterService.cpp \
    src/dbproxier/RouterDaemon.cpp \
    src/dbproxier/Channel.cpp \
    src/dbproxier/IChannel.cpp \
    src/dbproxier/ExecutorFactory.cpp

HEADERS += \
    include/dbproxier/RouterService.h \
    include/dbproxier/RouterDaemon.h \
    include/dbproxier/IChannel.h \
    include/dbproxier/Channel.h \
    include/dbproxier/IExecutor.h \
    include/dbproxier/IExecutorFactory.h \
    include/dbproxier/ExecutorFactory.h

INCLUDEPATH += include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qtservice/lib/ -lQtSolutions_Service-head
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qtservice/lib/ -lQtSolutions_Service-headd
else:unix: LIBS += -L$$PWD/../qtservice/lib/ -lQtSolutions_Service-head

INCLUDEPATH += $$PWD/../qtservice/src
DEPENDPATH += $$PWD/../qtservice/src

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../dbProxierCore/release/ -ldbProxierCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../dbProxierCore/debug/ -ldbProxierCore
else:unix: LIBS += -L$$OUT_PWD/../dbProxierCore/ -ldbProxierCore

INCLUDEPATH += $$PWD/../dbProxierCore/include
DEPENDPATH += $$PWD/../dbProxierCore/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lua/luacpp/release/ -lluacpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lua/luacpp/debug/ -lluacpp
else:unix: LIBS += -L$$OUT_PWD/../lua/luacpp/ -lluacpp

INCLUDEPATH += $$PWD/../lua/luacpp/include
DEPENDPATH += $$PWD/../lua/luacpp/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/luacpp/release/libluacpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/luacpp/debug/libluacpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/luacpp/release/luacpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/luacpp/debug/luacpp.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lua/luacpp/libluacpp.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lua/lua/release/ -llua
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lua/lua/debug/ -llua
else:unix: LIBS += -L$$OUT_PWD/../lua/lua/ -llua

INCLUDEPATH += $$PWD/../lua/lua/include
DEPENDPATH += $$PWD/../lua/lua/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/lua/release/liblua.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/lua/debug/liblua.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/lua/release/lua.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lua/lua/debug/lua.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lua/lua/liblua.a
