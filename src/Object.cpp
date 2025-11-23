#include "Object.h"

Object::Object(float x, float y, float size_x, float size_y) {
	////m_current_pos = sf::Vector2f(x, y); 
	m_shape.setPosition(x, y);
	m_shape.setSize(sf::Vector2f(size_x, size_y));
}


void Object::render(sf::RenderWindow* window) 
{
	window->draw(m_shape); 
}


void Object::setObjPosition(sf::Vector2f Newpos) 
{
	///m_current_pos = Newpos;
	m_shape.setPosition(Newpos);
}


void Object::setObjOrigin() 
{
	m_shape.setOrigin(m_shape.getSize().x / 2, m_shape.getSize().y / 2);
}


void Object::faceRight()
{
	m_shape.setRotation(0.f); 
}

void Object::faceDown()
{
	m_shape.setRotation(90.f); 
}

void Object::faceLeft()
{
	m_shape.setRotation(180.f); 
}

void Object::faceUp()
{
	m_shape.setRotation(270.f); 
}

void Object:: setMyType(Object_ID obj)
{
	m_myType = obj;
}

Object_ID Object:: getMyType()
{
	return m_myType;
}


void Object::setObjTexture(int objNum)  
{
	m_shape.setTexture(TextureHandler::getInstance().getObjTexture(objNum));
}

 
sf::Vector2f Object::getObjPosition() const
{
	return m_shape.getPosition(); 
}

sf::FloatRect Object::getObjBound() const
{
	return m_shape.getGlobalBounds();
}

sf::Vector2f Object::getObjSize() const
{ 
	return m_shape.getSize(); 
}



