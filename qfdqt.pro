#-------------------------------------------------
#
# Project created by QtCreator 2019-03-13T15:07:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qfdqt
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
    oneform.cpp \
    twoform.cpp \
    threeform.cpp \
    fourform.cpp \
    fiveform.cpp \
    sixform.cpp \
    sevenform.cpp \
    eightform.cpp \
    nineform.cpp \
    tenform.cpp \
    tableoneform.cpp \
    tabletwoform.cpp \
    tablethree2form.cpp \
    tablethreeform.cpp

HEADERS += \
        mainwindow.h \
    oneform.h \
    twoform.h \
    threeform.h \
    fourform.h \
    fiveform.h \
    sixform.h \
    sevenform.h \
    eightform.h \
    nineform.h \
    tenform.h \
    tableoneform.h \
    tabletwoform.h \
    tablethree2form.h \
    tablethreeform.h

FORMS += \
    mainwindow.ui \
    oneform.ui \
    twoform.ui \
    threeform.ui \
    fourform.ui \
    fiveform.ui \
    sixform.ui \
    sevenform.ui \
    eightform.ui \
    nineform.ui \
    tenform.ui \
    tableoneform.ui \
    tabletwoform.ui \
    tablethree2form.ui \
    tablethreeform.ui


RESOURCES += \
    qttu.qrc \
    tu.qrc
CONFIG += \
    qaxcontainer #excel

SUBDIRS += \
    qfdqt.pro

DISTFILES += \
    qfdqt.pro.user \
    qfd1.jpg \
    qfdjt.jpg \
    qfdjt2.jpg \
    qfdjt3.jpg \
    qfdjt4.jpg \
    README.md

