#include "VirusSwell.h"

VirusSwell::VirusSwell(float x, float y, int blood, float radius):Virus(x, y, Virus::VirusType::SwellVirus, blood,radius)
{

}

void VirusSwell::updateVXY(float &vx, float &vy)
{
    Virus::updateVXY(vx,vy);
    openglR+=(rand()%9-4)/500.0;
    if(openglR>0.4)openglR=0.4;
    else if(openglR<0.2)openglR=0.2;
}
