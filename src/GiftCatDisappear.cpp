#include "GiftCatDisappear.h"

GiftCatDisappear::GiftCatDisappear(float x, float y, float size_x, float size_y)
	: Gift(x, y, size_x, size_y) {
	setObjTexture(KILL);
	setMyType(KILL);

}


Object_ID GiftCatDisappear::handleCollision(Object& other)
{
	return other.handleCollision(*this);
}

Object_ID GiftCatDisappear::handleCollision(Mouse& other)
{
	gotEaten();
	return Object_ID::EMPTY_PLACE;
}