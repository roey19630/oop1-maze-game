#include "Cheese.h"

Cheese::Cheese(float x, float y, float size_x, float size_y)
    : StaticObject(x, y, size_x, size_y)
{
    setMyType(CHEESE);
    setObjTexture(CHEESE);
}

Object_ID Cheese::handleCollision(Object& other)
{
    return other.handleCollision(*this);
}

Object_ID Cheese::handleCollision(Mouse&)
{
    gotEaten();
    return Object_ID::EMPTY_PLACE;
}