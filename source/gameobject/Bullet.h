#pragma once
#include <QString>
#include <QPixmap>
#include "Object.h"
class Bullet: public Object
{
public:
    Bullet(float openglX,float openglY, int attack = 1, float speed = 0.1,float openglW=0.05,float openglH=0.08);
    void updatePos();
    int getAttack()const;
private:
    float speed;//秒速
    int attack;//攻击力
};
