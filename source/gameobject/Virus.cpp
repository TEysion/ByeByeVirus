#include "Virus.h"
#include <QPoint>
#include <QTimer>
#include "gameconfig/Config.h"
#include <list>
using namespace std;

Virus::Virus(float x, float y, VirusType virusType, int blood, float radius) :Object(x, y, radius), blood(blood), virusType(virusType)
{
    virusColor=(VirusColor)(rand()%9);
    vy = -0.3;
    vx = 0;
    rotation=0;
    bombIndex=0;
    destroyed=false;
    rOnAttacked=openglR*0.9;
    rOnNornal=openglR;
}

int Virus::getRotation(){
    return rotation;
}

int Virus::getColor()
{
    return virusColor;
}

int Virus::getType()
{
    return virusType;
}

int Virus::getBlood()
{
    return blood;
}


//更新位置
void Virus::updatePos()
{
    //若帧率为零，不进行刷新
    if (Config::getFps() == 0)return;

    //爆炸动画播放到了第几帧
    if(destroyed&&bombIndex<9){
        openglR*=1.1;//爆炸半径逐渐扩大
        bombIndex++;
    }

    //更新病毒转动角度
    rotation+=rand()%9-5;
    if(rotation>=360||rotation<=-360)rotation=0;

    //更新水平与竖直速度
    updateVXY(vx,vy);

    //通过速度刷新位置
    openglY += vy / (Config::getFps());
    openglX += vx / (Config::getFps());

    //判断是否超出屏幕
    if (openglX < -1)openglX=-1,vx = -vx;
    else if (openglX > 1)openglX=1,vx = -vx;
    if (openglY < -1)openglY = 1;
    else if(openglY > 1 + openglR)openglY = 1 + openglR, vy = -0.1;

}

void Virus::updateVXY(float &vx, float &vy)
{
    vx += (rand() % 3 - 1)/500.0;
}

//受击效果
void Virus::onAttacked(const Bullet& bullet)
{
        openglR-=0.01;
        blood-=bullet.getAttack();
        QTimer::singleShot(10, [=]{
             openglR+=0.01;
        });
//    openglR=rOnAttacked;
//    blood-=bullet.getAttack();
//    QTimer::singleShot(10, [=]{
//         openglR=rOnNornal;
//    });
}
