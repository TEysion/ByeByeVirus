#include <QPoint>
#include <QPixmap>
#include <list>
#include "gameconfig/Config.h"
#include "gameobject/ResourceEngine.h"
#include "Material.h"
#include "Virus.h"

using namespace std;

Material::Material(float x, float y, float speed, float radius) :Object(x, y, radius), speed(speed)
{
    materialType = (MaterialType)(rand() % 4);
    lastTime = 5000;
    rotation=0;
    switch (materialType) {
    case BUFF_FRIEND:
        imgPath = ":img/images/friendbuffdrop.png";
        setImg(QPixmap::fromImage(ResourceEngine::getRes("friendbuffdrop")));
        break;
    case BUFF_SPEED:
        imgPath = ":img/images/speedbuffdrop.png";
        break;
    case BUFF_SHOOT:
        imgPath = ":img/images/shootbuffdrop.png";
        break;
    case BUFF_ATTACK:
        imgPath = ":img/images/attackbuffdrop.png";
        break;
    }
}


void Material::updatePos()
{
    openglY += speed;
    openglX += (rand() % 9 - 4)/200.0;//-1 0 1
    if (openglX < -1)openglX += 0.1;
    if (openglX > 1)openglX -= 0.1;
    //判断是否超出屏幕
    if (openglY < -1)openglY = 1;
    if((rotation+=3.0)>=360)rotation=0;
}

float Material::getRotation()
{
    return rotation;
}
