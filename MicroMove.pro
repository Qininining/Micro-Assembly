QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BaseMotionPlatform.cpp \
    ContactProfilometer.cpp \
    DataSaver.cpp \
    ForceSensor.cpp \
    SerialInterface.cpp \
    TaskThread.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BaseMotionPlatform.h \
    ContactProfilometer.h \
    DataSaver.h \
    ForceSensor.h \
    SerialInterface.h \
    TaskThread.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx|win32: LIBS += -L$$PWD/NanoDrive2.8.11/04_SDK/lib64/ -lNTControl

INCLUDEPATH += $$PWD/NanoDrive2.8.11/04_SDK/lib64
DEPENDPATH += $$PWD/NanoDrive2.8.11/04_SDK/lib64

include($$PWD/QXlsx/QXlsx.pri)             # QXlsx源代码
INCLUDEPATH += $$PWD/QXlsx
