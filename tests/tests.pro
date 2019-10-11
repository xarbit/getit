QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TARGET = tests
TEMPLATE = app

include(../config.pri)
include(../src/sources.pri)

INCLUDEPATH += $$APP_ROOT_DIR/src

SOURCES +=  \
    $$DOMAIN_SOURCES \

TEMPLATE = app

SOURCES += \
    main.cpp \
    domain/requests/bodies/tst_FormdataRequestBody.cpp

HEADERS += \
    $$DOMAIN_HEADERS
