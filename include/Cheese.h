#pragma once

#include "StaticObject.h" 

class Cheese : public StaticObject 
{ 
public:
	Cheese(float x, float y, float size_x, float size_y);

	
	//============-COLISIONS-====================

	virtual Object_ID handleCollision(Object& other) override;

	virtual Object_ID handleCollision(Mouse&);
};