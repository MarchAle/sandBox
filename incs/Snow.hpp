#ifndef SNOW_HPP
# define SNOW_HPP

# include "../incs/Solid.hpp"

class Snow : public ASolid
{
    private:
        /* data */
    public:
        Snow(/* args */);
        ~Snow();
        void    moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y);

};


#endif