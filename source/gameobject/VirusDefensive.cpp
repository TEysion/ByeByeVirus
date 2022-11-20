#include "VirusDefensive.h"

VirusDefensive::VirusDefensive(float x, float y, int blood, float radius):Virus(x, y, Virus::VirusType::DefensiveVirus, blood*2,radius)
{
}

void VirusDefensive::updateVXY(float &vx, float &vy)
{
    Virus::updateVXY(vx,vy);
}
