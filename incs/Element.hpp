#ifndef ELEMENT_HPP
# define ELEMENT_HPP

#include "../incs/sandbox.hpp"

# define AIR 0
# define SAND 1

# define SOLID 0
# define LIQUID 1

class AElement
{
    protected:
        float   color[3];
        float   x_velocity;
        float   y_velocity;
        // bool    free;
        int     particule_type;
        int     particule_state;
        // float   x;
        // float   y;
        // virtual void    moveElement() = 0;

    public:
        AElement(int type, int state);
        ~AElement();
        // void set_free_as(const bool status);
        // void set_particule_type(const int type);
        // bool is_free();
        int  get_particule_type();
        int  get_particule_state();
        // float   getX();
        // float   getY();
};

template<typename T>
void    swapElement(T &first, T &second)
{
    T temp = first;
    first = second;
    second = temp;
}


#endif