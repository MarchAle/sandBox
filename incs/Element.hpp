#ifndef ELEMENT_HPP
# define ELEMENT_HPP

#include "../incs/sandbox.hpp"


class AElement
{
    protected:
        float   *color;
        float   x_velocity;
        float   y_velocity;
        // bool    free;
        int     particule_state;
        int     particule_type;

        bool    falling;
        // float   x;
        // float   y;
        virtual float*  generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue) = 0;

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
        bool isFalling();
        void setFallingAs(bool value);
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