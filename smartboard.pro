#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T19:55:44
#
#-------------------------------------------------

QT       += core gui printsupport
INCLUDEPATH += \
                /usr/include/opencv4
                /usr/include
LIBS += -L/usr/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
INCLUDEPATH  += /usr/include/poppler/qt5
LIBS         += -L/usr/lib/ -lpoppler-qt5


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smartboard
TEMPLATE = app


SOURCES += main.cpp\
    depo.cpp \
    dotsignal.cpp \
    gridlines.cpp \
    mainwindow.cpp \
    popupmenu.cpp \
    scene.cpp \
    toolKalem.cpp \
    toolkalemmenu.cpp \
    toolpagemenu.cpp \
    tooltahta.cpp \
    verectangle.cpp

HEADERS  += \
    depo.h \
    diagramitem.h \
    dotsignal.h \
    filecrud.h \
    gridlines.h \
    mainwindow.h \
    popupmenu.h \
    scene.h \
    toolKalem.h \
    toolkalemmenu.h \
    toolpagemenu.h \
    tooltahta.h \
    verectangle.h

FORMS    +=

RESOURCES += \
    icon.qrc
