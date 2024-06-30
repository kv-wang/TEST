QT       += core gui multimedia \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allcats.cpp \
    buttonhoverwatcher.cpp \
    cat.cpp \
    catinfo.cpp \
    catlist.cpp \
    interact.cpp \
    knowledge.cpp \
    main.cpp \
    mainwindow.cpp \
    notice.cpp \
    setting.cpp \
    stories.cpp

HEADERS += \
    allcats.h \
    buttonhoverwatcher.h \
    cat.h \
    catinfo.h \
    catlist.h \
    interact.h \
    knowledge.h \
    mainwindow.h \
    notice.h \
    setting.h \
    stories.h

FORMS += \
    allcats.ui \
    catinfo.ui \
    catlist.ui \
    interact.ui \
    knowledge.ui \
    mainwindow.ui \
    notice.ui \
    setting.ui \
    stories.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    1Cat.qrc
