QT += testlib core gui
#QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TARGET = tests
TEMPLATE = app

include(../config.pri)
include(../src/sources.pri)
include(../3rdparty/catch2/catch2.pri)
include(../3rdparty/trompeloeil/trompeloeil.pri)

INCLUDEPATH += $$APP_ROOT_DIR/src

SOURCES +=  \
    $$DOMAIN_SOURCES \
    domain/factories/tst_ResponseFactory.cpp \
    main.cpp

HEADERS += \
    $$DOMAIN_HEADERS
