#include "GiftCatFreeze.h"

GiftCatFreeze::GiftCatFreeze(float x, float y, float size_x, float size_y)
    : Gift(x, y, size_x, size_y) {
    setObjTexture(FREEZE);
    setMyType(FREEZE);

}

//============-COLISIONS-====================
Object_ID GiftCatFreeze::handleCollision(Object& other)
{
    return other.handleCollision(*this);
}

Object_ID GiftCatFreeze::handleCollision(Mouse& other)
{
    gotEaten();
    return Object_ID::EMPTY_PLACE;
}