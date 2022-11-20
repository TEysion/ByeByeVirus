#ifndef PLAYERMESSAGE_H
#define PLAYERMESSAGE_H

#include <QString>
#include <fstream>

/**
 * 玩家信息类
 * 存储玩家昵称，通关数等
 */

class PlayerMessage
{
public:
    PlayerMessage(QString nickname);
    QString getNickname();//获取昵称
    void setProgress(int progress);//设置当前通关数
    int getProgress();//获取当前通关数
    friend std::ifstream& operator>>(std::ifstream& is,PlayerMessage& pmsg);//从文件读取
    friend std::ofstream& operator<<(std::ofstream& os,PlayerMessage& pmsg);//写入文件
private:
    QString nickname;//玩家昵称
    int progress;//通关数
};

#endif // PLAYERMESSAGE_H
