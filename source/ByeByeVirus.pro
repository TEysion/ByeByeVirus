QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia
QT += openglwidgets
QT += gui
CONFIG += c++17
CONFIG += resources_big
RC_FILE = resourse/logo.rc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gameconfig/Config.cpp \
    gameconfig/StageData.cpp \
    gameconfig/PlayerMessage.cpp \
    gameobject/Object.cpp \
    gamescene/AboutScene.cpp \
    gamescene/FileSaveScene.cpp \
    gamescene/GameScene.cpp \
    gamescene/HandBookscene.cpp \
    gamescene/MainMenuScene.cpp \
    gamewidget/RProgressBar.cpp\
    gamewidget/MPushButton.cpp \
    gameobject/VirusDefensive.cpp \
    gameobject/VirusSpike.cpp \
    gameobject/VirusSwell.cpp \
    gameobject/Bullet.cpp\
    gameobject/Cell.cpp\
    gameobject/Material.cpp\
    gameobject/Virus.cpp\
    gameobject/ResourceEngine.cpp \
    main.cpp \

HEADERS += \
    gameconfig/Config.h \
    gameconfig/StageData.h \
    gameconfig/PlayerMessage.h \
    gameobject/Object.h \
    gamescene/AboutScene.h \
    gamescene/FileSaveScene.h \
    gamescene/GameScene.h \
    gamescene/HandBookscene.h \
    gamescene/MainMenuScene.h \
    gamewidget/RProgressBar.h\
    gamewidget/MPushButton.h \
    gameobject/VirusDefensive.h \
    gameobject/VirusSpike.h \
    gameobject/VirusSwell.h \
    gameobject/Bullet.h\
    gameobject/Cell.h\
    gameobject/Material.h\
    gameobject/Virus.h\
    gameobject/ResourceEngine.h \

FORMS += \
    gamescene/handbookscene.ui \
    gamescene/aboutscene.ui \
    gamescene/filesavescene.ui \
    gamescene/gamescene.ui \
    gamescene/mainmenuscene.ui

RESOURCES += \
    resourse/resourse.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


