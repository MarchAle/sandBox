#include "../incs/Void.hpp"

Void::Void() : AElement(LIQUID, VOID)
{
    this->color[0] = 0.1f;
    this->color[1] = 0.9f;
    this->color[2] = 0.3f;
}

Void::~Void()
{
}

void  Void::moveElement(std::vector<std::vector<std::unique_ptr<AElement> > > &map, int x, int y)
{
    (void)map;
    (void)x;
    (void)y;
}