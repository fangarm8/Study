QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    num.cpp \
    primaryform.cpp \
    sinform.cpp \
    sqeqform.cpp

HEADERS += \
    mainwindow.h \
    num.h \
    primaryform.h \
    sinform.h \
    sqeqform.h

FORMS += \
    mainwindow.ui \
    primaryform.ui \
    sinform.ui \
    sqeqform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
