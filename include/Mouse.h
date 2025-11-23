#pragma once


#include "MovingObject.h"

class Mouse : public MovingObject
{
public:
	Mouse(float x, float y, float size_x, float size_y, float speed, int lives);

	void move(sf::Time deltaTime) override;

	int getLives() const;

	int getKeys() const;	/////??????????? to delete?????

	void setKeys(int num);	////???????? to delete??????
	
	//============-COLISIONS-====================

	virtual Object_ID handleCollision(Object&);

	virtual Object_ID handleCollision(Cat&) override;

	virtual Object_ID handleCollision(Door&) override;

	virtual Object_ID handleCollision(Key&) override;

	virtual Object_ID handleCollision(Cheese&) override;

	virtual Object_ID handleCollision(Wall&) override;

	virtual Object_ID handleCollision(GiftCatDisappear&) override;

	virtual Object_ID handleCollision(GiftCatFreeze&) override;

	virtual Object_ID handleCollision(GiftExtraTime&) override;

	virtual Object_ID handleCollision(GiftExtraLife&) override;
	
private:
	sf::Texture m_mouseTexture;
	int m_lives;
	int m_keys=0; ///??????????????? to delete???
};