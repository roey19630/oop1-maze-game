#include "Door.h"

Door::Door(float x, float y, float size_x, float size_y)
    : StaticObject(x, y, size_x, size_y) {
    setObjTexture(DOOR);
    setMyType(DOOR);

}

Object_ID Door::handleCollision(Object& other)
{
    return other.handleCollision(*this);
}

Object_ID Door::handleCollision(Mouse& other) 
{
    return Object_ID::DOOR; //???????? to delete??
   // return Object_ID::EMPTY_PLACE;       //// to keep 
}