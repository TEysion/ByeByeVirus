#ifndef VIRUSSPIKE_H
#define VIRUSSPIKE_H

#include "Virus.h"
class VirusSpike: public Virus
{
public:
    VirusSpike(float x, float y, int blood, float radius);
    void updateVXY(float& vx,float &vy);
};

#endif // VIRUSSPIKE_H
