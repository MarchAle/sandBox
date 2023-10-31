#ifndef SNOW_HPP
# define SNOW_HPP

# include "../incs/Solid.hpp"

class Snow : public ASolid
{
    private:
        int     lifeTime;
        int     flyingTime;
        bool    flying;
    public:
        Snow(/* args */);
        ~Snow();
        void    moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y);
        bool    isFlying() override;
        void    setFlyingAs(bool value);
        void    decreaseLifeTime() override;
        int     getLifeTime() override;
};


#endif