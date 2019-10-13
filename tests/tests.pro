QT += testlib network
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
    domain/requests/bodies/tst_JsonRequestBody.cpp \
    domain/requests/bodies/tst_FormdataRequestBody.cpp \
    domain/requests/bodies/tst_RawRequestBody.cpp \
    main.cpp

HEADERS += \
    $$DOMAIN_HEADERS \
    domain/requests/bodies/tst_FormdataRequestBody.hpp \
    domain/requests/bodies/tst_JsonRequestBody.hpp \
    domain/requests/bodies/tst_RawRequestBody.hpp
