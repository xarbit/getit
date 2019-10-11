QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../config.pri)
include(./sources.pri)

CONFIG += c++17

SOURCES += \
    $$DOMAIN_SOURCES \
    main.cpp

HEADERS += \
    $$DOMAIN_HEADERS

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
