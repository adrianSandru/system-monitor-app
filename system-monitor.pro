#-------------------------------------------------
#
# Project created by QtCreator 2019-05-04T09:26:58
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = system-monitor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    systeminformation.cpp \
    systemwindowsinfoimpl.cpp \
    sysinfowidget.cpp \
    cpuaveragewidget.cpp \
    cpuusermodewidget.cpp \
    cpukernelmodewidget.cpp \
    cpuidlemodewidget.cpp \
    memoryaverageusagewidget.cpp


HEADERS += \
        mainwindow.h \
    systeminformation.h \
    systemwindowsinfoimpl.h \
    sysinfowidget.h \
    cpuaveragewidget.h \
    cpuusermodewidget.h \
    cpukernelmodewidget.h \
    cpuidlemodewidget.h \
    memoryaverageusagewidget.h

linux {
    SOURCES += systemlinuxinfoimpl.cpp
    HEADERS += systemlinuxinfoimpl.h
}
FORMS += \
        mainwindow.ui
