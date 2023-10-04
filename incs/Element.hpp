#ifndef ELEMENT_HPP
# define ELEMENT_HPP

#include "../incs/sandbox.hpp"


class AElement
{
    protected:
        float   color[3];
        float   x_velocity;
        float   y_velocity;
        // bool    free;
        int     particule_state;
        int     particule_type;
        // float   x;
        // float   y;

    public:
        virtual void    moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y) = 0;
        AElement(int state, int type);
        ~AElement();
        // void set_free_as(const bool status);
        // void set_particule_type(const int type);
        // bool is_free();
        float* get_color();
        int  get_particule_type();
        int  get_particule_state();
        // float   getX();
        // float   getY();
};

// template<typename T>
// void    swapElement(T &first, T &second)
// {
//     T temp = first;
//     first = second;
//     second = temp;
// }


#endif