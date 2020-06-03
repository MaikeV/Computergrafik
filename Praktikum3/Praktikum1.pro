QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    MyGLWidget.cpp \
    main.cpp \
    mainwindow.cpp \
    modelloader/model.cpp \
    skybox.cpp

HEADERS += \
    MyGLWidget.h \
    mainwindow.h \
    modelloader/model.h \
    modelloader/modelloader/modelloader.h \
    skybox.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    colorShader.frag \
    gimbal.obj \
    sample.frag \
    sample.vert \
    skybox.frag \
    skybox.vert \
    sphere.obj

RESOURCES += \
    res.qrc

win32 {
    contains(QT_ARCH,i386) {
        #for 32 bit windows applications
        message(Target:win32)
        LIBS += -L../assimp-mingw32-4.1.0/bin-lassimp
        INCLUDEPATH += ../assimp-mingw32-4.1.0/include
    } else {
        #for 64 bit windows applications
        message(Target:x64)
        LIBS += -L../assimp-mingw_w64-5.01/bin-lassimp
        INCLUDEPATH += ../assimp-mingw_w64-5.01/include
    }
}

unix {
    message(Target:unix)
    CONFIG += link_pkgconfig
    PKGCONFIG += assimp
}
