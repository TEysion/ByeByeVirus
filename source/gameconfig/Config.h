#pragma once
#include <QString>
#include <QPixmap>
#include "PlayerMessage.h"

/**
 * 游戏信息类
 * 存储/获取窗口大小、帧率、玩家信息、文件路径等
 */

class Config
{
public slots:
    static void fpsCount();//帧率计数，应每绘制一帧调用一次
public:

    static void updateWH(int w,int h);//窗口大小更改时调用，传入新的窗口宽高
    static int getW();//获取当前存储的窗口宽度
    static int getH();//获取当前存储的窗口高度
    static int getFps();//获取当前帧率（根据调用fpsCount()的频率计算）
    static float mapping(float v, float startOld, float endOld, float startNew, float endNew);//坐标映射
    static void setPlayerMessage(PlayerMessage* playerMessage);//设置玩家信息
    static PlayerMessage* getPlayerMessage();//获取玩家信息
    static void initPlayerMessage(QString nickname);//从文件初始化玩家信息
    static void savePlayerMessage();//保存玩家信息到文件
    static QString getDataFileDir();//获取文件存储路径（结尾不含"/"）
    static int getMills();//获取时间戳
private:
    static int WIDTH;//界面宽度
    static int HEIGHT;//界面高度
    static PlayerMessage* playerMessage;//玩家信息
    static int fps;//帧率
};
