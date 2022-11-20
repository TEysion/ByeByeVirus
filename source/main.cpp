#include <QtWidgets/QApplication>
#include <QFile>
#include <QIcon>
#include <thread>
#include "gamescene/GameScene.h"
#include "gamescene/FileSaveScene.h"
#include "gameobject/ResourceEngine.h"

/**
 * @brief   程序入口
 * @date    2022/5/18
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":img/images/icon.png"));
    //设置全局样式表
    QFile file(":qss/style/global.qss");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = (file.readAll());//读取样式表文件
        a.setStyleSheet(styleSheet);//把文件内容传参
        file.close();
    }

    //在线程中初始化游戏资源
    std::thread initThread([=]{
        ResourceEngine::initRes();
    });
    initThread.detach();
    //打开存档界面
    (new FileSaveScene())->show();
    return a.exec();
}
