QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../config.pri)
include(./sources.pri)

CONFIG += c++17

SOURCES += \
    $$DOMAIN_SOURCES \
    $$APP_ROOT_DIR/src/main.cpp \
    $$APP_ROOT_DIR/src/ui/MainWindow.cpp

HEADERS += \
    $$DOMAIN_HEADERS \
    $$APP_ROOT_DIR/src/ui/MainWindow.hpp

FORMS += \
    $$APP_ROOT_DIR/src/forms/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
