#include "Object.h"

float Object::ey=7.0/5.0;

void Object::setImg(const QPixmap& img)
{
    this->img = (QPixmap *)&img;
}

const QPixmap& Object::getImg()
{
    return *img;
}

bool Object::collide(Object& object)
{
    if (type == Circle && object.type == Circle)
        return sqrt(pow((openglX - object.openglX),2) + pow((openglY*ey- object.openglY*ey),2)) < openglR + object.openglR;
    else if (type == Object::Circle && object.type == Rectangle)
    {
        float vrcx=abs(object.openglX-openglX);
        float vrcy=abs(object.openglY*ey-openglY*ey);
        float vrhx=object.openglW/2;
        float vrhy=object.openglH*ey/2;
        float vhcx=vrcx-vrhx;if(vhcx<0)vhcx=0;
        float vhcy=vrcy-vrhy;if(vhcy<0)vhcy=0;
        return (vhcx*vhcx+vhcy*vhcy<pow(openglR,2));
    }
    else if (type == Rectangle && object.type == Circle)
    {
        float vrcx=abs(object.openglX-openglX);
        float vrcy=abs(object.openglY*ey-openglY*ey);
        float vrhx=openglW/2;
        float vrhy=openglH*ey/2;
        float vhcx=vrcx-vrhx;if(vhcx<0)vhcx=0;
        float vhcy=vrcy-vrhy;if(vhcy<0)vhcy=0;
        return (vhcx*vhcx+vhcy*vhcy<pow(object.openglR,2));
    }
    else if (type == Rectangle && object.type == Rectangle)
        return (((openglX - object.openglX > 0 && (openglX - object.openglX) < object.openglW) || (object.openglX - openglX > 0 && (object.openglX - openglX) < openglW))
            && ((openglY - object.openglY > 0 && (openglY - object.openglY) < object.openglH) || (object.openglY - openglY > 0 && (object.openglY - openglY) < openglH)));
    throw "Error Type";
}

void Object::updatePos()
{
}

float Object::getOpenglX()
{
    return openglX;
}

float Object::getOpenglY()
{
    return openglY;
}

void Object::setOpenglX(float cx)
{
    if (type == Circle)
        openglX = cx - openglR;
    else if (type == Rectangle)
        openglX = cx - openglW / 2;
    else throw "Error Type";
}

void Object::setOpenglY(float cy)
{
    if (type == Circle)
        openglY = cy - openglR;
    else if (type == Rectangle)
        openglY = cy - openglH / 2;
    else throw "Error Type";
}

float Object::getOpenglR()
{
    return openglR;
}

float Object::getOpenglW()
{
    return openglW;
}

float Object::getOpenglH()
{
    return openglH;
}

