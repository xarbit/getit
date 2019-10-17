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
    ../../getit/tests/domain/requests/tst_Request.cpp \
    domain/requests/bodies/tst_JsonRequestBody.cpp \
    domain/requests/bodies/tst_FormdataRequestBody.cpp \
    domain/requests/bodies/tst_RawRequestBody.cpp \
    main.cpp \
    mocks/MockQNetworkManager.cpp \
    mocks/MockQNetworkReply.cpp

HEADERS += \
    $$DOMAIN_HEADERS \
    ../../getit/tests/domain/requests/tst_Request.hpp \
    domain/requests/bodies/tst_FormdataRequestBody.hpp \
    domain/requests/bodies/tst_JsonRequestBody.hpp \
    domain/requests/bodies/tst_RawRequestBody.hpp \
    mocks/MockQNetworkManager.hpp \
    mocks/MockQNetworkReply.hpp
