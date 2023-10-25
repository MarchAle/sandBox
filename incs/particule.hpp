#ifndef PARTICULE_HPP
# define PARTICULE_HPP

class Particule
{
    private:
        float x;
        float y;

    public:
        Particule();
        Particule(float x, float y);
        ~Particule();
        float    getX();
        float    getY();
};

#endif