#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T20:33:28
#
#-------------------------------------------------

QT       -= core gui

TARGET = lua
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH = include

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \
	src/lapi.c \
	src/lauxlib.c \
	src/lbaselib.c \
	src/lbitlib.c \
	src/lcode.c \
	src/lcorolib.c \
	src/lctype.c \
	src/ldblib.c \
	src/ldebug.c \
	src/ldo.c \
	src/ldump.c \
	src/lfunc.c \
	src/lgc.c \
	src/linit.c \
	src/liolib.c \
	src/llex.c \
	src/lmathlib.c \
	src/lmem.c \
	src/loadlib.c \
	src/lobject.c \
	src/lopcodes.c \
	src/loslib.c \
	src/lparser.c \
	src/lstate.c \
	src/lstring.c \
	src/lstrlib.c \
	src/ltable.c \
	src/ltablib.c \
	src/ltm.c \
	src/lundump.c \
	src/lvm.c \
	src/lzio.c
	

HEADERS += \
    include/lua/lapi.h \
    include/lua/lauxlib.h \
    include/lua/lcode.h \
    include/lua/lctype.h \
    include/lua/ldebug.h \
    include/lua/ldo.h \
    include/lua/lfunc.h \
    include/lua/lgc.h \
    include/lua/llex.h \
    include/lua/llimits.h \
    include/lua/lmem.h \
    include/lua/lobject.h \
    include/lua/lopcodes.h \
    include/lua/lparser.h \
    include/lua/lstate.h \
    include/lua/lstring.h \
    include/lua/ltable.h \
    include/lua/ltm.h \
    include/lua/lua.h \
    include/lua/lua.hpp \
    include/lua/luaconf.h \
    include/lua/lualib.h \
    include/lua/lundump.h \
    include/lua/lvm.h \
    include/lua/lzio.h