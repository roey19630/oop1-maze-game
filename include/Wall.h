#pragma once

#include "StaticObject.h"


class Wall : public StaticObject 
{
public:
	Wall(float x, float y, float size_x, float size_y);

	//============-COLISIONS-====================
	
	virtual Object_ID handleCollision(Object& other) override;

	virtual Object_ID handleCollision(Mouse& other) override;

	 
};

