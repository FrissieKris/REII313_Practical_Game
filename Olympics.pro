QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemy.cpp \
    gamescene.cpp \
    grass.cpp \
    main.cpp \
    mainwindow.cpp \
    objects.cpp \
    player.cpp \
    powerups.cpp \
    sand.cpp \
    sprite.cpp \
    track.cpp \
    trackbarrier.cpp \
    tree.cpp

HEADERS += \
    enemy.h \
    gamescene.h \
    grass.h \
    mainwindow.h \
    objects.h \
    player.h \
    powerups.h \
    sand.h \
    sprite.h \
    track.h \
    trackbarrier.h \
    tree.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
