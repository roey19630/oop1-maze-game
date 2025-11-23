#pragma once

#include "Cat.h"

class SmartCat : public Cat 
{
public:
    SmartCat(float x, float y, float size_x, float size_y, float speed);
    void move(sf::Time deltaTime);
};
