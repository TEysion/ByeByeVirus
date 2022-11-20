#pragma once
#include <list>
#include <QPoint>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QOpenGLTexture>
#include "Object.h"
#include "Bullet.h"

class Virus: public Object
{
public:
    enum VirusType{SimpleVirus,SwellVirus,DefensiveVirus,SpikeVirus};
    enum VirusColor{Purple,Cyan,Yellow,Pink,Blue,Green,Red,DarkPurple,DarkBlue};
    Virus(float x = 0, float y = 1, VirusType virusType=SimpleVirus, int blood = 10, float radius = 0.1);
    virtual void updatePos();
    virtual void updateVXY(float& vx,float&vy);
    virtual void onAttacked(const Bullet& bullet);
    int getRotation();
    int getColor();
    int getType();
    int getBlood();
    bool destroyed;
    float bombIndex;
private:
    float vx;
    float vy;
    int rotation;
    float rOnAttacked;
    float rOnNornal;
    int blood;
    VirusType virusType;
    VirusColor virusColor;
};
