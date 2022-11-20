#ifndef STAGEDATA_H
#define STAGEDATA_H

#include <QString>
#include <list>
#include "gameobject/Virus.h"
#include "gameobject/Material.h"
#include "gameobject/Object.h"

/**
 * 信息类
 * 存储一条信息，可能是：病毒，物资，提示，警告，赋予式buff，掉落式buff
 */

class Message{
public:
    enum MessageType{VIRUS,MATERIAL,TIP,WARN,BUFF,DROPBUFF};//病毒，物资，提示，警告，赋予式buff，掉落式buff
    Message(int mills,Object* pObject,MessageType type);
    Message(int mills,QString tip,MessageType type);
    Message(int mills,int buff);
    int mills;//毫秒数
    int buff;
    MessageType type;//信息类型
    QString tip;
    Object* pObject;
};

/**
 * 关卡信息类
 * 存储关卡所有Message
 */

class GStageData
{
public:
    GStageData();
    GStageData(int stage);
    bool operator>>(Message &msg);//读取一条消息
    void operator<<(const Message &msg);//向消息表加入消息
    Message& getMessage();
    bool next();//将信息表迭代器下一一位，若已至列表尾部，返回false
    void setAll();//至少调用一次setAll之后才能调用下面的getAllNum
    int getAllNum();//获取Message表中类型为Virus的总数（即敌人总数）
    void sort();//将所有Message按mills排序
    int getStage();//获取关卡等级（第几关）
private:
    std::list<Message> messages;
    std::list<Message>::iterator it;
    int all,at;
    int stage;
};
#endif // STAGEDATA_H
