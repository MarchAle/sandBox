#include "../incs/Element.hpp"

AElement::AElement(int state, int type, float density) : x_velocity(1.0f), y_velocity(1.0f), particule_state(state), particule_type(type), density(density)
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

float   AElement::get_density()
{
    return (density);
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

float*    AElement::generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue)
{
    int redInterval = maxRed - minRed;
    int redOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * redInterval;
    float   redValue = static_cast<float> (static_cast<float> (minRed + redOffset) / 255);
    int greenInterval = maxGreen - minGreen;
    int greenOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * greenInterval;
    float   greenValue = static_cast<float> (static_cast<float> (minGreen + greenOffset) / 255);
    int blueInterval = maxBlue - minBlue;
    int blueOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * blueInterval;
    float   blueValue = static_cast<float> (static_cast<float> (minBlue + blueOffset) / 255);

    float *colorArray = new float[3]{redValue, greenValue, blueValue};
    return (colorArray);
}

float*    AElement::generateColor(int minRGB, int maxRGB)
{
    int rgbInterval = maxRGB - minRGB;
    int rgbOffset = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) * rgbInterval;
    float   redValue = static_cast<float> (static_cast<float> (minRGB + rgbOffset) / 255);
    float   greenValue = static_cast<float> (static_cast<float> (minRGB + rgbOffset) / 255);
    float   blueValue = static_cast<float> (static_cast<float> (minRGB + rgbOffset) / 255);

    float *colorArray = new float[3]{redValue, greenValue, blueValue};
    return (colorArray);
}