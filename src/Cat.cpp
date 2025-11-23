#include "Cat.h"

Cat::Cat(float x, float y, float size_x, float size_y, float speed)
    : MovingObject(x, y, size_x, size_y, speed) {
    inactiveFreeze();
}



Object_ID Cat::handleCollision(Object& other) 
{
    return other.handleCollision(*this);
} 

Object_ID Cat::handleCollision(Mouse&) 
{
    return Object_ID::EMPTY_PLACE; 
}

Object_ID Cat::handleCollision(Wall&)
{
    setObjPosition(getLastPos());
    return Object_ID::EMPTY_PLACE;
}

Object_ID Cat::handleCollision(Door&)
{
    setObjPosition(getLastPos());
    return Object_ID::EMPTY_PLACE;
}

