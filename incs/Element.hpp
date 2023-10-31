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
        float*  generateColor(int minRGB, int maxRGB);


    public:
        virtual void    moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y) = 0;
        AElement(int state, int type, float density, bool isFalling);
        virtual ~AElement();
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

        virtual bool isWet() = 0;
        virtual void setWetAs(bool value) = 0;
        virtual void moveHumidity(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y) = 0;

        virtual bool    isFlying(){return false;};
        virtual void    decreaseLifeTime(){};
        virtual int     getLifeTime(){return 0;};
         
};

// template<typename T>
// void    swapElement(T &first, T &second)
// {
//     T temp = first;
//     first = second;
//     second = temp;
// }


#endif