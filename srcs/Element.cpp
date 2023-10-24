#include "../incs/Element.hpp"

AElement::AElement(int state, int type) : x_velocity(1.0f), y_velocity(1.0f), particule_state(state), particule_type(type)
{
    falling = true;
    // free = true;
    // particule_type = AIR;
}

AElement::~AElement()
{
}

// void    AElement::set_free_as(const bool status)
// {
//     free = status;
// }

// void    AElement::set_particule_type(const int type)
// {
//     particule_type = type;
// }

// bool    AElement::is_free()
// {
//     return (free);
// }

float*  AElement::get_color()
{
    return (color);
}

int     AElement::get_particule_type()
{
    return (particule_type);
}

int     AElement::get_particule_state()
{
    return (particule_state);
}

// float   AElement::getX()
// {
//     return (x);
// }

// float   AElement::getY()
// {
//     return (y);
// }


bool    AElement::isFalling()
{
    return (falling);
}

void    AElement::setFallingAs(bool value)
{
    falling = value;
}
