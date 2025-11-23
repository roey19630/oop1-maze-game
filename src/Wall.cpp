#include "Wall.h"

Wall::Wall(float x, float y, float size_x, float size_y)
	: StaticObject(x, y, size_x, size_y)
{
	setObjTexture(WALL);
	setMyType(WALL);

}



Object_ID Wall::handleCollision(Object& other)
{
	return other.handleCollision(*this);
}

Object_ID Wall::handleCollision(Mouse& other)
{
	return Object_ID::EMPTY_PLACE;
}