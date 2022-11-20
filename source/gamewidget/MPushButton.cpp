#include "MPushButton.h"

#include <QDebug>
#include <QPropertyAnimation>



MPushButton::MPushButton(QString normalImg, QString pressImg,int width,int height)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;
    QPixmap pix;
    pix.load(normalImg);

    //设置图片固定大小
    //this->setFixedSize(pix.width(), pix.height());

    //设置不规则图片样式
    //this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    //this->setIcon(pix);
    //设置图标大小
    //this->setIconSize(QSize(pix.width(), pix.height()));

    this->resize(width, 200);
}

void MPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation* animation1 = new QPropertyAnimation(this, "geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //创建结束位置
    animation1->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
}

void MPushButton::zoom2()
{
    QPropertyAnimation* animation1 = new QPropertyAnimation(this, "geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    animation1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
}

MPushButton::~MPushButton()
{
}
