#include "../incs/Element.hpp"

AElement::AElement(int type, int state) : particule_type(type), particule_state(state), x_velocity(0.0f), y_velocity(0.0f)
{
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