#include "../incs/particule.hpp"

Particule::Particule()
{

}

Particule::Particule(float x, float y) : x(x), y(y)
{
}

Particule::~Particule()
{
}

float    Particule::getX()
{
    return (x);
}

float    Particule::getY()
{
    return (y);
}