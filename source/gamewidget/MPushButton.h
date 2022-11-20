#ifndef MPUSHBUTTON_H
#define MPUSHBUTTON_H
#include <QPushButton>

class MPushButton:public QPushButton
{
    Q_OBJECT
public:
    //构造函数 参数1正常显示的图片路径 参数2按下后显示的图片路径
    MPushButton(QString normalImg="", QString pressImg = "",int width=20,int height=20);

    void zoom1();

    void zoom2();

    //成员属性 保存用户传入的默认图片路径 和 按下后的路径
    QString normalImgPath;

    QString pressImgPath;

    ~MPushButton();
signals:

public slots:
};

#endif // MPUSHBUTTON_H


