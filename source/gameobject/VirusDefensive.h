#ifndef VIRUSDEFENSIVE_H
#define VIRUSDEFENSIVE_H

#include "Virus.h"
class VirusDefensive: public Virus
{
public:
    VirusDefensive(float x, float y, int blood, float radius);
    void updateVXY(float& vx,float &vy);
};

#endif // VIRUSDEFENSIVE_H
