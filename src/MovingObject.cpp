#include "MovingObject.h"



sf::Vector2f MovingObject::m_mousePosition = sf::Vector2f(600.f, 350.f);  

bool MovingObject::m_freeze = false;

MovingObject::MovingObject(float x, float y, float size_x, float size_y,float speed)
    : Object(x, y, size_x, size_y),
    m_startPos(sf::Vector2f(x, y)),
    m_lastPosition(sf::Vector2f(x, y)),
    m_speed(speed)
    {}  

// returns the initial position of the object at the start of the game
sf::Vector2f MovingObject::getStartPos() const
{
    return m_startPos;
}

// returns last position before the last move
sf::Vector2f MovingObject::getLastPos() const 
{ 
    return m_lastPosition; 
}

void MovingObject::setLastPos(const sf::Vector2f& lastPos)
{ 
    m_lastPosition = sf::Vector2f(lastPos);
}

void MovingObject::resetToStartPos() 
{ 
    setObjPosition(m_startPos);
}

// updates the mouse position so all the moving objects know where mouse is
void MovingObject::setMousePosition(const sf::Vector2f& mousePosition) 
{
    m_mousePosition = mousePosition; 
}
 
sf::Vector2f MovingObject::getMousePosition() 
{
    return m_mousePosition; 
}

// sets the freeze flag to true so the demons know not to move
void MovingObject::activeFreeze() 
{
    m_freeze = true; 
}

void MovingObject::inactiveFreeze() 
{ 
    m_freeze = false; 
} 

bool MovingObject::isFrozen()
{
    return m_freeze; 
}

float MovingObject::getObjSpeed() const
{ 
    return m_speed;
}

sf::Vector2f MovingObject::getObjDirection() const 
{ 
    return m_direction; 
}


//sets the direction of the object
void MovingObject::resetDirection()
{
    m_direction = sf::Vector2f(0, 0);
}

void MovingObject::directionUp()
{ 
    m_direction = sf::Vector2f(0, -1); 
}

void MovingObject::directionDown()
{ 
    m_direction = sf::Vector2f(0, 1); 
}

void MovingObject::directionRight()
{
    m_direction = sf::Vector2f(1, 0); 
}

void MovingObject::directionLeft() 
{
    m_direction = sf::Vector2f(-1, 0); 
}
