#pragma once
#include <QPainter>
#include "Object.h"

class Material : public Object
{
public:
    enum MaterialType{BUFF_ATTACK,BUFF_FRIEND,BUFF_SHOOT,BUFF_SPEED};
    MaterialType materialType;
    Material(float x = 0, float y = 1, float speed = -0.005, float radius = 0.15);
    void updatePos();
    float speed;
    QString imgPath;
    float getRotation();
private:
    float rotation;
    int lastTime;
};

