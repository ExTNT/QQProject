QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 mysql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QQLogin.cpp \
    QQSignUp.cpp \
    chooseservice.cpp \
    friendmanager_dyh.cpp \
    group_dyh.cpp \
    groupmanager_dyh.cpp \
    main.cpp \
    service_dyh.cpp \
    user_dyh.cpp \
    writeAndRead.cpp

HEADERS += \
    QQLogin.h \
    QQSignUp.h \
    chooseservice.h \
    classHeader.h \
    friendmanager_dyh.h \
    global.h \
    group_dyh.h \
    groupmanager_dyh.h \
    json.hpp \
    service_dyh.h \
    user_dyh.h \
    writeAndread.h

FORMS += \
    QQLogin.ui \
    QQSignUp.ui \
    chooseservice.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico.qrc \
    style.qrc