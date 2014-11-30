#include "baan.h"



baan::baan(float _startX, float _startY, float _startZ, float _offsetX, float _offsetY, float _speed, float _outOfSpace)    {

    startX=_startX;
    startY=_startY;
    startZ=_startZ;
    offsetX=_offsetX;
    offsetY=_offsetY;
    speed=_speed;
    outOfSpace=_outOfSpace;


}

float baan::getStartX ()  {
    return startX;
}
