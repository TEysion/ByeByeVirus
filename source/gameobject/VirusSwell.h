#ifndef VIRUSSWELL_H
#define VIRUSSWELL_H

#include "Virus.h"
class VirusSwell: public Virus
{
public:
    VirusSwell(float x, float y, int blood, float radius);
    void updateVXY(float& vx,float &vy);
};

#endif // VIRUSSWELL_H
