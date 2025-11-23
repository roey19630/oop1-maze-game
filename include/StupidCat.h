#pragma once

#include "Cat.h"

enum DIRECTION { UP, RIGHT, DOWN, LEFT };


class StupidCat : public Cat 
{
public:
    StupidCat(float x, float y, float size_x, float size_y, float speed);

    void move(sf::Time deltaTime);

private:
    int m_direction = DIRECTION(rand() % 4);
};
