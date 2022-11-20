#include "Bullet.h"

Bullet::Bullet(float openglX,float openglY, int attack, float speed,float openglW,float openglH):Object(openglX,openglY,openglW,openglH), speed(speed),  attack(attack)
{
}

void Bullet::updatePos() {
    openglY += speed;
    if (openglX < -1)openglX = -openglX;
}

int Bullet::getAttack()const
{
    return attack;
}
