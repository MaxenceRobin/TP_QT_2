#-------------------------------------------------
#
# Project created by QtCreator 2018-02-14T14:32:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP_QT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    authentificationcontroller.cpp \
    addclientdialog.cpp \
    aboutdialog.cpp \
    client.cpp \
    person.cpp \
    ittech.cpp \
    addresourcestoclientdialog.cpp \
    c_init_bd.cpp \
    dbmanager.cpp \
    selfmanageddatabase.cpp \
    resource.cpp \
    addresourcedialog.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    authentificationcontroller.h \
    addclientdialog.h \
    aboutdialog.h \
    client.h \
    person.h \
    ittech.h \
    addresourcestoclientdialog.h \
    c_init_bd.h \
    dbmanager.h \
    selfmanageddatabase.h \
    resource.h \
    addresourcedialog.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    addclientdialog.ui \
    aboutdialog.ui \
    addresourcestoclientdialog.ui \
    addresourcedialog.ui

RESOURCES += \
    ressources.qrc
