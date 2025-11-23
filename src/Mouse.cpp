#include "Mouse.h"

//==========-PUBLICS-==============
Mouse::Mouse(float x, float y, float size_x, float size_y, float speed, int lives)
    : MovingObject(x + size_x / 2, y + size_y / 2, size_x, size_y, speed), m_lives(lives)
{
    setMyType(MOUSE);
    setObjTexture(MOUSE);

    setObjOrigin();
}



void Mouse::move(sf::Time deltaTime)
{
    setLastPos(getObjPosition());

    //  input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //if there is no wall above 
        if (getObjPosition().y < 50.f)
        {
            setObjPosition(sf::Vector2f(getObjPosition().x, 950.f - getObjSize().y));
        }
        faceUp();
        directionUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //if there is no wall below
        if (getObjPosition().y > 950.f + getObjSize().y)
        {
            setObjPosition(sf::Vector2f(getObjPosition().x, 50.f));
        }
        faceDown();
        directionDown();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {

        //if there is no wall to the right
        if (getObjPosition().x > 950)
        {
            setObjPosition(sf::Vector2f(0.f, getObjPosition().y));
        }
        faceRight();
        directionRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {

        //if there is no wall to the left
        if (getObjPosition().x < -getObjSize().x)
        {
            setObjPosition(sf::Vector2f(900.f - getObjSize().x, getObjPosition().y));
        }
        faceRight();
        directionLeft();
    }
    else if (sf::Event::KeyReleased)
    {
        resetDirection();
    }

    sf::Vector2f newPos = sf::Vector2f(getObjPosition() + getObjDirection() * getObjSpeed() * deltaTime.asSeconds());
    setObjPosition(newPos);
    setMousePosition(getObjPosition());
}


int Mouse::getLives() const
{
    return m_lives;
}

int Mouse::getKeys() const
{
    return m_keys;
}

void Mouse::setKeys(int num)
{
    m_keys+=num;
}

//==========-HANDLE-COLLISIONS-================
Object_ID Mouse::handleCollision(Object& other)
{
    return other.handleCollision(*this);
}

Object_ID Mouse::handleCollision(Cat&)
{
    inactiveFreeze();
    return Object_ID::CAT;   //////????????????????????????????????   
}

Object_ID Mouse::handleCollision(Door&)
{
    if (m_keys > 0)
    {
        return Object_ID::DOOR;
    }
    else
    {
        setObjPosition(getLastPos());
    }
    return Object_ID::EMPTY_PLACE;
}

Object_ID Mouse::handleCollision(Key&) 
{
    m_keys++; 
    return Object_ID::KEY; 
}

Object_ID Mouse::handleCollision(Cheese&) { return Object_ID::CHEESE; }

Object_ID Mouse::handleCollision(Wall&)
{
    setObjPosition(getLastPos());
    return Object_ID::EMPTY_PLACE;
}

Object_ID Mouse::handleCollision(GiftExtraLife&) { return Object_ID::HEART; }

Object_ID Mouse::handleCollision(GiftExtraTime&) { return Object_ID::CLOCK; }

Object_ID Mouse::handleCollision(GiftCatFreeze&)
{
    activeFreeze();
    return Object_ID::FREEZE;
}

Object_ID Mouse::handleCollision(GiftCatDisappear&) { return Object_ID::KILL; }