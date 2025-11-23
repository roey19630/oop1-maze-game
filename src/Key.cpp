#include "Key.h"

Key::Key(float x, float y, float size_x, float size_y)
    : StaticObject(x, y, size_x, size_y) {
    setObjTexture(KEY);
    setMyType(KEY);

}


//============-COLISIONS-====================
Object_ID Key::handleCollision(Object& other)
{
    return other.handleCollision(*this);
}

Object_ID Key::handleCollision(Mouse& other)
{
    gotEaten();
    return Object_ID::EMPTY_PLACE;
}