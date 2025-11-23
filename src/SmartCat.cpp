#include "SmartCat.h"

SmartCat::SmartCat(float x, float y, float size_x, float size_y, float speed)
    : Cat(x, y, size_x, size_y, speed)
{
    setMyType(SMART_CAT);
    setObjTexture(Object_ID::SMART_CAT);
}


/*
* this a simple bfs algorithm for the smart cat to follow the mouse.
* if the mouse is on the left the cat goes to the left until it's parallel to it
* if it's on the right it moves to the right and so on
*/

void SmartCat::move(sf::Time deltaTime)
{
    if (isFrozen())
    {
        setObjTexture(Object_ID::FROZEN_CAT);
        return;
    }

    setObjTexture(Object_ID::SMART_CAT);
    setLastPos(getObjPosition());

    if (10 <= (getMousePosition().x - getObjPosition().x))
    {
        directionRight();

    }
    else if (10 <= (getObjPosition().x - getMousePosition().x)) {
        directionLeft();
    }

    if (10 <= (getMousePosition().y - getObjPosition().y))
    {
        directionDown();
    }
    if (10 <= (getObjPosition().y - getMousePosition().y))
    {
        directionUp();
    }
    sf::Vector2f newPos = sf::Vector2f(getObjPosition() + getObjDirection() * getObjSpeed() * deltaTime.asSeconds());
    setObjPosition(newPos);
}