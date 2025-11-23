#include "GiftExtraLife.h"


GiftExtraLife::GiftExtraLife(float x, float y, float size_x, float size_y)
    : Gift(x, y, size_x, size_y)
{
    setObjTexture(HEART);
    setMyType(HEART);

}


//============-COLISIONS-====================
Object_ID GiftExtraLife::handleCollision(Object& other)
{
    return other.handleCollision(*this);
}

Object_ID GiftExtraLife::handleCollision(Mouse& other)
{
    gotEaten();
    return Object_ID::EMPTY_PLACE;
}