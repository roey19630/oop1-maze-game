#include "GiftExtraTime.h"

GiftExtraTime::GiftExtraTime(float x, float y, float size_x, float size_y)
    : Gift(x, y, size_x, size_y) {
    setObjTexture(CLOCK);
    setMyType(CLOCK);

}

//============-COLISIONS-====================
Object_ID GiftExtraTime::handleCollision(Object& other)
{
    return other.handleCollision(*this);
}

Object_ID GiftExtraTime::handleCollision(Mouse& other)
{
    gotEaten();
    return Object_ID::EMPTY_PLACE;
}