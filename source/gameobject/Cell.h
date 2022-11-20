#pragma once
#include <list>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include "Object.h"
#include "Bullet.h"
class Cell: public Object, QObject
{
public slots:
    void speedBuff();//发射子弹间隔
    void shootBuff();//发射子弹数量
    void attackBuff();//子弹杀伤力
    void friendBuff();//召唤僚机
    void cancelSpeedBuff();//发射子弹间隔
    void cancelShootBuff();//发射子弹数量
    void cancelAttackBuff();//子弹杀伤力
    void cancelFriendBuff();//召唤僚机
public:
    enum Buff{SpeedBuff,ShootBuff,AttackBuff,FriendBuff};
    Cell(float x = 0, float y = -0.8, float radius = 0.15, int interval = 100, int onceNum = 5, int attack = 1);
    void shoot();
    void updatePos();
    void mouseMoveEvent(QMouseEvent* E);
    void keyPressEvent(QKeyEvent* E);
    void keyReleaseEvent(QKeyEvent* E);
    std::list<Bullet> cBullets;
public:
    float friendX;
    float friendY;
    bool fightWithFriend;
    bool gameWin;
    bool friengAtLeft;
private: 
    int interval;//每隔interval毫秒发射一次子弹
    int onceNum;
    int attack;
    int blood;
    QPixmap friendImg;
};


