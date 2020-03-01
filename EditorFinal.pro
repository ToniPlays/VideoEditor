QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appsplash.cpp \
    ui/previewwindow.cpp \
    interface/process/initializationprocess.cpp \
    interface/projectmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    rendering/decoder/decoder.cpp \
    ui/timeline.cpp \
    ui/uicontroller.cpp \
    utility/fileutils.cpp \
    utility/sequence.cpp \
    utility/settingsmanager.cpp

HEADERS += \
    appsplash.h \
    ui/previewwindow.h \
    interface/process/initializationprocess.h \
    interface/projectmanager.h \
    mainwindow.h \
    rendering/decoder/decoder.h \
    ui/Timeline.h \
    ui/uicontroller.h \
    utility/fileutils.h \
    utility/sequence.h \
    utility/settingsmanager.h

FORMS += \
    ui/AppSplash.ui \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


INCLUDEPATH += D:/Development/CPP/ffmpeg/include
LIBS += -LD:/Development/CPP/ffmpeg/lib -lavcodec -lavformat -lavutil -lswscale

DISTFILES += \
    ffmpeg/avcodec-58.dll \
    ffmpeg/avdevice-58.dll \
    ffmpeg/avfilter-7.dll \
    ffmpeg/avformat-58.dll \
    ffmpeg/avutil-56.dll \
    ffmpeg/postproc-55.dll \
    ffmpeg/swresample-3.dll \
    ffmpeg/swscale-5.dll \
    resources/img/splash.jpg
