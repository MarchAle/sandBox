#ifndef ELEMENT_HPP
# define ELEMENT_HPP

#include "../incs/sandbox.hpp"


class AElement
{
    public:
        float   x_velocity;
        float   y_velocity;

    protected:
        float   *color;
        // bool    free;
        int     particule_state;
        int     particule_type;
        float   density;

        bool    falling;
        // float   x;
        // float   y;
        float*  generateColor(int minRed, int maxRed, int minGreen, int maxGreen, int minBlue, int maxBlue);

    public:
        virtual void    moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y) = 0;
        AElement(int state, int type, float density);
        ~AElement();
        // void set_free_as(const bool status);
        // void set_particule_type(const int type);
        // bool is_free();
        float* get_color();
        int  get_particule_type();
        int  get_particule_state();
        bool isFalling();
        void setFallingAs(bool value);
        float   get_density();
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