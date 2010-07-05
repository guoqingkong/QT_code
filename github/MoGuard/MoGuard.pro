#-------------------------------------------------
#
# Project created by QtCreator 2010-06-23T17:26:03
#
#-------------------------------------------------

QT       += core gui maemo5

TARGET = MoGuard
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    context.cpp \
    newwindow.cpp \
    networkwindow.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    context.h \
    newwindow.h \
    networkwindow.h

FORMS    += mainwindow.ui \
    dialog.ui \
    newwindow.ui \
    networkwindow.ui

CONFIG += mobility
MOBILITY += contacts
MOBILITY += systeminfo
MOBILITY += bearer
MOBILITY += messaging
MOBILITY += systeminfo
MOBILITY += versit
MOBILITY += publishsubscribe
MOBILITY += location
MOBILITY += serviceframework

symbian {
    TARGET.UID3 = 0xee734215
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
