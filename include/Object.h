#pragma once

// TO DO: deete this, probably
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "TextureHandler.h"

//============-INCLUDES-FOR-COLLISION-===============

class Cheese;
class Cat;
class StupidCat;
class SmartCat;
class Door;
class GiftExtraLife;
class GiftExtraTime;
class GiftCatFreeze;
class GiftCatDisappear;
class Gift;
class Key;
class MovingObject;
class Mouse;
class StaticObject;
class Wall;

class Object 
{
public:
	Object(float x, float y, float size_x, float size_y);

	void render(sf::RenderWindow* window);

	void setObjPosition(sf::Vector2f Newpos);
	void setObjOrigin();
	void faceRight();
	void faceDown();
	void faceLeft();
	void faceUp();
	void setMyType(Object_ID obj);
	Object_ID getMyType();

	void setObjTexture(int objNum);

	sf::Vector2f getObjPosition() const;

	sf::FloatRect getObjBound() const;

	sf::Vector2f getObjSize() const;

	virtual ~Object() = default;
	

	//============-COLISIONS-====================
	virtual Object_ID handleCollision(Object&) { return Object_ID::EMPTY_PLACE; }

	virtual Object_ID handleCollision(Mouse&) { return Object_ID::EMPTY_PLACE; }

	virtual Object_ID handleCollision(Cat&) { return Object_ID::EMPTY_PLACE; }

	virtual Object_ID handleCollision(Door&) { return Object_ID::EMPTY_PLACE; }

	virtual Object_ID handleCollision(Key&) { return Object_ID::EMPTY_PLACE; }

	virtual Object_ID handleCollision(Cheese&) { return Object_ID::EMPTY_PLACE; }

	virtual Object_ID handleCollision(Wall&) { return Object_ID::EMPTY_PLACE; }
	
	virtual Object_ID handleCollision(GiftExtraTime&) { return Object_ID::EMPTY_PLACE; }
	virtual Object_ID handleCollision(GiftExtraLife&) { return Object_ID::EMPTY_PLACE; }
	virtual Object_ID handleCollision(GiftCatFreeze&) { return Object_ID::EMPTY_PLACE; }
	virtual Object_ID handleCollision(GiftCatDisappear&) { return Object_ID::EMPTY_PLACE; }




private:
	////sf::Vector2f m_current_pos;  // x, y
	sf::Texture m_texture;       // image
	sf::RectangleShape m_shape;
	Object_ID m_myType;
};