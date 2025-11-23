#pragma once

#include "Object.h"

class MovingObject : public Object
{
public: 
	MovingObject(float x, float y, float size_x, float size_y, float speed);
	sf::Vector2f getStartPos() const;

	sf::Vector2f getLastPos() const;

	void setLastPos(const sf::Vector2f& lastPos);

	void resetToStartPos();

	void setMousePosition(const sf::Vector2f& pacmanPosition);

	static sf::Vector2f getMousePosition();

	void activeFreeze();

	void inactiveFreeze();

	static bool isFrozen();

	float getObjSpeed() const;

	sf::Vector2f getObjDirection() const;

	virtual void move(sf::Time deltaTime) = 0;

	void resetDirection();

	void directionUp();

	void directionDown();

	void directionRight();

	void directionLeft();
private:
	// initial position
	sf::Vector2f m_startPos;
	// position before last move
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	sf::Vector2f m_lastPosition;
	static sf::Vector2f m_mousePosition;
	static bool m_freeze ;
	float m_speed;
};
