#pragma once

#include "Gift.h"

class GiftExtraLife : public Gift 
{
public:
	GiftExtraLife(float x, float y, float size_x, float size_y);

	
	//============-COLISIONS-====================

	virtual Object_ID handleCollision(Object&) override;

	virtual Object_ID handleCollision(Mouse&) override;
	
};
