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
    Step1.cpp \
    Step2.cpp \
    Step3.cpp \
    Step4.cpp \
    Step5.cpp \
    Step6.cpp \
    Step7.cpp \
    Step8.cpp \
    Step9.cpp \
    Step10.cpp \
    Step1_1.cpp \
    Step1_2.cpp \
    Step3_2.cpp \
    Step3_1.cpp \
    Step2_2.cpp \
    Step2_1.cpp \
    qnavigationwidget.cpp \
    step1data.cpp \
    excelengine.cpp

HEADERS += \
        mainwindow.h \
    Step1.h \
    Step2.h \
    Step3.h \
    Step4.h \
    Step5.h \
    Step6.h \
    Step7.h \
    Step8.h \
    Step9.h \
    Step10.h \
    Step1_1.h \
    Step1_2.h \
    Step3_2.h \
    Step3_1.h \
    qnavigationwidget.h \
    Step2_1.h \
    Step2_2.h \
    step1data.h \
    excelengine.h

FORMS += \
    mainwindow.ui \
    Step1.ui \
    Step2.ui \
    Step3.ui \
    Step4.ui \
    Step5.ui \
    Step6.ui \
    Step7.ui \
    Step8.ui \
    Step9.ui \
    Step10.ui \
    Step1_1.ui \
    Step1_2.ui \
    Step3_2.ui \
    Step3_1.ui \
    step2_1.ui \
    step2_2.ui \
    step1data.ui


RESOURCES += \
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

