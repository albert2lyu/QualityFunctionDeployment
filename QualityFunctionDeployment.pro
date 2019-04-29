#-------------------------------------------------
#
# Project created by QtCreator 2019-03-13T15:07:40
#
#-------------------------------------------------

QT       += core gui
QT+=axcontainer
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QualityFunctionDeployment
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
    Step1Data.cpp \
    excelengine.cpp \
    Step4_1.cpp \
    Step5_1.cpp \
    Step6_1.cpp \
    Step7_1.cpp \
    Step9_1.cpp \
    Step10_1.cpp \
    Step8_1.cpp \
    Step2Data.cpp \
    Step3Data.cpp \
    Step4Data.cpp \
    Step5Data.cpp \
    Step6Data.cpp \
    Step7Data.cpp \
    Step8Data.cpp \
    Step9Data.cpp \
    Step10Data.cpp \
    Step6_2.cpp \
    Step7_2.cpp \
    Step9_2.cpp \
    Step9_3.cpp \
    Step3_3.cpp \
    Step2_3.cpp \
    sqlite.cpp \
    entity_step1.cpp \
    entity_step2.cpp \
    entity_step2_2.cpp \
    matlabfunction.cpp \
    entity_step3_2.cpp \
    entity_step3_3.cpp \
    step3_4.cpp \
    entity_step3_4.cpp \
    entity_step4_1.cpp \
    entity_step5.cpp \
    entity_step4_2.cpp \
    entity_step6_1.cpp \
    entity_step6_2.cpp \
    entity_step7_2.cpp \
    entity_step7_1.cpp \
    entity_step7_3.cpp \
    entity_step6_3.cpp \
    entity_step8.cpp \
    entity_step10.cpp \
    step9_4.cpp \
    entity_step9_2.cpp \
    entity_step9_3.cpp \
    entity_step9_4.cpp \
    initialize_db.cpp

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
    Step1Data.h \
    excelengine.h \
    Step5_1.h \
    Step6_1.h \
    Step7_1.h \
    Step8_1.h \
    Step9_1.h \
    Step10_1.h \
    Step4_1.h \
    Step2Data.h \
    Step3Data.h \
    Step4Data.h \
    Step5Data.h \
    Step6Data.h \
    Step7Data.h \
    Step8Data.h \
    Step9Data.h \
    Step10Data.h \
    Step6_2.h \
    Step7_2.h \
    Step9_2.h \
    Step9_3.h \
    Step3_3.h \
    Step2_3.h \
    sqlite.h \
    entity_step1.h \
    entity_step2.h \
    entity_step2_2.h \
    matlabfunction.h \
    include/matBasic.h \
    entity_step3_2.h \
    include/step3.h \
    entity_step3_3.h \
    step3_4.h \
    entity_step3_4.h \
    entity_step4_1.h \
    entity_step5.h \
    include/matStep67810.h \
    entity_step4_2.h \
    entity_step6_1.h \
    entity_step6_2.h \
    entity_step7_2.h \
    entity_step7_1.h \
    entity_step7_3.h \
    entity_step6_3.h \
    entity_step8.h \
    entity_step10.h \
    step9_4.h \
    entity_step9_2.h \
    entity_step9_3.h \
    entity_step9_4.h \
    initialize_db.h

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
    Step2_1.ui \
    Step2_2.ui \
    Step1Data.ui \
    Step4_1.ui \
    Step5_1.ui \
    Step6_1.ui \
    Step7_1.ui \
    Step8_1.ui \
    Step9_1.ui \
    Step10_1.ui \
    Step2Data.ui \
    Step3Data.ui \
    Step4Data.ui \
    Step5Data.ui \
    Step6Data.ui \
    Step7Data.ui \
    Step8Data.ui \
    Step9Data.ui \
    Step10Data.ui \
    Step6_2.ui \
    Step7_2.ui \
    Step9_2.ui \
    Step9_3.ui \
    Step3_3.ui \
    Step2_3.ui \
    step3_4.ui \
    step9_4.ui



CONFIG += C++ 11
SUBDIRS += \
    qfdqt.pro
QMAKE_CXXFLAGS += -std=c++0x

    README.md
QT       += core gui sql



INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include


# .h文件搜索路径D:\gitqfd\test1\includex
INCLUDEPATH+=$$PWD/include/extern/include/
INCLUDEPATH+=$$PWD/include/extern/include/


# 用到的MATLAB 的.lib库文件 及其搜索路径
INCLUDEPATH+=$$PWD/include/extern/lib/win64/microsoft
DEPENDPATH +=$$PWD/include/extern/lib/win64/microsoft

LIBS+=-L$$PWD/include/extern/lib/win64/microsoft -llibmex
LIBS+=-L$$PWD/include/extern/lib/win64/microsoft -llibmx
LIBS+=-L$$PWD/include/extern/lib/win64/microsoft -llibmat
LIBS+=-L$$PWD/include/extern/lib/win64/microsoft -llibeng
LIBS+=-L$$PWD/include/extern/lib/win64/microsoft -lmclmcr
LIBS+=-L$$PWD/include/extern/lib/win64/microsoft -lmclmcrrt



win32: LIBS += -L$$PWD/include/ -lmatBasic

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32: LIBS += -L$$PWD/include/ -lstep3

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32: LIBS += -L$$PWD/include/ -lmatStep67810

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

RESOURCES += \
    qfd.qrc
