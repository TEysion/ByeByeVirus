#include "VirusSpike.h"

VirusSpike::VirusSpike(float x, float y, int blood, float radius) :Virus(x, y, Virus::VirusType::SpikeVirus, blood,radius)
{
}


void VirusSpike::updateVXY(float &vx, float &vy)
{
    Virus::updateVXY(vx,vy);
    vx += (rand() % 3 - 1)/500.0;
    bool back=false;
    if(rand()%5>3)back=true;
    if(vy<=0&&back)vy+=0.1;
    else if(vy>0&&back){
        vy=0.1;
    }else{
        vy=-(rand() % 9 - 1)/5.0;
        if(vy>0)vy=0;
    }
}
