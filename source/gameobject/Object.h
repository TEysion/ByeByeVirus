#pragma once
#include <QPixmap>
#include <QPainter>
#include <QOpenGLFunctions>
class Object
{
public:
    enum AreaType{ Circle, Rectangle };
    Object(float openglX, float openglY, float openglR):openglX(openglX),openglY(openglY),openglR(openglR),type(Circle){}
    Object(float openglX, float openglY, float openglW, float openglH):openglX(openglX),openglY(openglY),openglW(openglW),openglH(openglH),type(Rectangle){}
    float getOpenglX();//获取水平坐标
    float getOpenglY();//获取垂直坐标
    void setOpenglX(float cx);//设置中心水平坐标
    void setOpenglY(float cy);//设置中心垂直坐标
    float getOpenglR();//获取半径
    float getOpenglW();//获取宽度
    float getOpenglH();//获取高度
    static float ex;
    static float ey;
    void setImg(const QPixmap& img);
    const QPixmap& getImg();
    bool collide(Object& Object);
	virtual void updatePos();
protected:
    float openglX;//水平座标(-1,+1)
    float openglY;//垂直坐标(-1,+1)
    float openglR;//半径
    float openglW;
    float openglH;
    AreaType type;//区域类型
private:
    QPixmap* img;
};

