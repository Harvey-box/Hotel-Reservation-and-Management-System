#-------------------------------------------------
#
# Project created by QtCreator 2018-07-26T20:31:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
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
    signupinterface.cpp \
    people.cpp \
    mydatabase.cpp \
    hoteldata.cpp \
    order.cpp \
    lisboawin.cpp \
    alldata.cpp \
    customerwin.cpp \
    roomforcustomer.cpp \
    bookroomwin.cpp \
    orderwidget.cpp \
    userinformation.cpp \
    usercheckorderwidget.cpp \
    parisianwin.cpp \
    venetianwin.cpp \
    emperorwin.cpp \
    hotelcheckorderwidget.cpp \
    changepassworddialog.cpp \
    adminwin.cpp \
    roomforadmin.cpp

HEADERS += \
        mainwindow.h \
    signupinterface.h \
    people.h \
    mydatabase.h \
    hoteldata.h \
    order.h \
    lisboawin.h \
    alldata.h \
    customerwin.h \
    roomforcustomer.h \
    bookroomwin.h \
    orderwidget.h \
    userinformation.h \
    usercheckorderwidget.h \
    parisianwin.h \
    venetianwin.h \
    emperorwin.h \
    hotelcheckorderwidget.h \
    changepassworddialog.h \
    adminwin.h \
    roomforadmin.h

FORMS += \
        mainwindow.ui \
    signupinterface.ui \
    lisboawin.ui \
    customerwin.ui \
    roomforcustomer.ui \
    bookroomwin.ui \
    orderwidget.ui \
    userinformation.ui \
    usercheckorderwidget.ui \
    parisianwin.ui \
    venetianwin.ui \
    emperorwin.ui \
    hotelcheckorderwidget.ui \
    changepassworddialog.ui \
    adminwin.ui \
    roomforadmin.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    images/parisian/p_room1.jpg \
    images/parisian/p_room2.jpg \
    images/parisian/p_room3.jpg \
    images/parisian/p_room4.jpg \
    images/parisian/photel.jpg
