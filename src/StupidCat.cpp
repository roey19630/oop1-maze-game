#include "StupidCat.h"

StupidCat::StupidCat(float x, float y, float size_x, float size_y,
    float speed)
    : Cat(x, y, size_x, size_y, speed)
{
    setMyType(STUPID_CAT);
    setObjTexture(Object_ID::STUPID_CAT);
}

void StupidCat::move(sf::Time deltaTime)
{
    if (isFrozen())
    {
        setObjTexture(Object_ID::FROZEN_STUPID_CAT);
        return;
    }
    setObjTexture(Object_ID::STUPID_CAT);
    setLastPos(getObjPosition());

    /*
     * draw a random number (1-30) if it hits 10
     * the cat draws another random drection
     */
    int switchD = rand() % 30;
    if (switchD == 15)
    {
        m_direction = DIRECTION(rand() % 4);
    }

    switch (m_direction) {
    case DIRECTION::UP:
        directionUp();
        break;
    case DIRECTION::RIGHT:
        directionRight();
        break;
    case DIRECTION::DOWN:
        directionDown();
        break;
    case DIRECTION::LEFT:
        directionLeft();
        break;

    default:
        break;
    }

    sf::Vector2f newPos = sf::Vector2f(getObjPosition() + getObjDirection() * getObjSpeed() * deltaTime.asSeconds());
    setObjPosition(newPos);
}