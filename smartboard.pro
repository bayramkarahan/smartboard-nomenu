#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T19:55:44
#
#-------------------------------------------------
#sudo apt-get install qtmultimedia5-dev
#sudo apt install gstreamer1.0-libav
QT       += core gui printsupport multimedia multimediawidgets
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
    shiftlabel.cpp \
    toolKalem.cpp \
    toolkalemmenu.cpp \
    toolpagemenu.cpp \
    toolpromter.cpp \
    toolsayac.cpp \
    tooltahta.cpp \
    verectangle.cpp

HEADERS  += \
    depo.h \
    diagramitem.h \
    dotsignal.h \
    filecrud.h \
    gridlines.h \
    mainwindow.h \
    popMenus.h \
    popupmenu.h \
    sayfaFunctions.h \
    scene.h \
    shiftlabel.h \
    toolKalem.h \
    toolKalemFunction.h \
    toolKalemSignalSlots.h \
    toolKalemSlots.h \
    toolkalemmenu.h \
    toolpagemenu.h \
    toolpromter.h \
    toolsayac.h \
    tooltahta.h \
    topMenus.h \
    verectangle.h

FORMS    +=

RESOURCES += \
    icon.qrc

    target.path = /usr/bin

    desktop_file.files = smartboard.desktop
    desktop_file.path = /usr/share/applications/
    icon.files = icons/smartboard.svg
    icon.path = /usr/share/smartboard/

    config_file.files = smartboard.ini
    config_file.path = /usr/share/smartboard/

    auto_start.files = esmartboard-autostart.desktop
    auto_start.path = /etc/xdg/autostart/

    desktopfile.files = smartboardxdglink.sh
    desktopfile.path = /usr/bin/


    INSTALLS += target desktop_file icon config_file auto_start desktopfile
    #INSTALLS += libopencvimgcodecs libopencvcore libopencvhighgui libopencvimgproc
    DISTFILES += \
        icons/smartboard.svg \
        smartboard.ini\
        smartboard-autostart.desktop\
        smartboardxdglink.sh
