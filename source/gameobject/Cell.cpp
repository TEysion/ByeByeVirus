#include "Cell.h"
#include <QTimer>
#include <QDateTime>
#include "gameconfig/Config.h"
void Cell::speedBuff()
{
    interval /= 2;
}

void Cell::shootBuff()
{
    onceNum *= 2;
}

void Cell::attackBuff()
{
    attack *= 2;
    qDebug()<<"attack="<<attack;
}


void Cell::friendBuff()
{
    fightWithFriend = true;
}

void Cell::cancelSpeedBuff()
{
    interval *= 2;
}

void Cell::cancelShootBuff()
{
    onceNum /= 2;
    qDebug()<<"cancel oncenum="<<onceNum;
}

void Cell::cancelAttackBuff()
{
    attack/=2;
    qDebug()<<"attack="<<attack;
}

void Cell::cancelFriendBuff()
{
    fightWithFriend = false;
}

Cell::Cell(float x,float y,float radius,int interval,int onceNum,int attack) :Object(x, y, radius), interval(interval), onceNum(onceNum), attack(attack)
{
    friendX = 0;
    friendY = -1.5;
    fightWithFriend = false;
    gameWin=false;
}

void Cell::updatePos()
{
    if(gameWin){
        openglY+=0.05f;
        if (fightWithFriend)friendY+=0.05f;
    }
    if (fightWithFriend)
    {

        if(friendX - openglX>0) friengAtLeft=false;
        else friengAtLeft=true;

        if (friendX - openglX > getOpenglR() * 2) {
            friendX += (openglX - friendX + getOpenglR() * 2) / 5;
        }
        else if (friendX - openglX < -getOpenglR() * 2) {
            friendX += (openglX - friendX - getOpenglR() * 2) / 5;
        }
        friendY += (openglY - friendY) / 10.0;
    }
    else if (friendY > -1.5)
    {
        friendY += -0.01f;
    }
}

void Cell::mouseMoveEvent(QMouseEvent* E)
{
    int ex = E->x();
    int ey = E->y();
    if (ex > 0 && ex < Config::getW())
        setOpenglX(Config::mapping(ex,0, Config::getW(),-1,1)+openglR);
    if (ey > 0 && ey < Config::getH())
        setOpenglY(Config::mapping(ey,0, Config::getH(),1,-1)+openglR);
}

QTimer keyTimer;
void Cell::keyPressEvent(QKeyEvent *E)
{
    if(!E->isAutoRepeat()){
        keyTimer.setInterval(10);
        float step=0.03f;
        switch(E->key()){
        case Qt::Key_W:
            connect(&keyTimer,&QTimer::timeout,this,[=]{openglY+=step;});
            break;
        case Qt::Key_S:
            connect(&keyTimer,&QTimer::timeout,this,[=]{openglY-=step;});
            break;
        case Qt::Key_A:
            connect(&keyTimer,&QTimer::timeout,this,[=]{openglX-=step;});
            break;
        case Qt::Key_D:
            connect(&keyTimer,&QTimer::timeout,this,[=]{openglX+=step;});
            break;
        }
        keyTimer.start();
    }
}

void Cell::keyReleaseEvent(QKeyEvent *E)
{
    if(!E->isAutoRepeat()){
        keyTimer.stop();
        disconnect(&keyTimer, 0, 0, 0);
    }
}

void Cell::shoot()
{
    static int lastTime = 0;
    static float shootNum=1;

    if((int)shootNum<(int)onceNum)shootNum+=0.05f;
    else if((int)shootNum>(int)onceNum)shootNum-=0.05f;
    int t = Config::getMills();

    qDebug()<<"lasttime="<<lastTime<<" "<<"t="<<t;

    if (lastTime > 0 && (t - lastTime) < interval) {
        return;
    }
    lastTime = t;
    float firstBulletX;
    float bulletInterval = 0.05f;

    if ((int)shootNum % 2 == 0)
        firstBulletX = openglX  - ((int)shootNum + 1) / 2 * bulletInterval - bulletInterval / 2;
    else
        firstBulletX = openglX  - ((int)shootNum + 1) / 2 * bulletInterval;
    for (int i = 0; i < (int)shootNum; i++) {
        float x = firstBulletX += bulletInterval;
        if(fightWithFriend)cBullets.push_back(Bullet(x+friendX-this->openglX, friendY - 0.01, attack));
        if (x < -1)continue;
        cBullets.push_back(Bullet(x, openglY - 0.01, attack));
    }
}
