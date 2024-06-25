QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_num_test.cpp ../main-proj/num.cpp
HEADERS += ../main-proj/num.h
