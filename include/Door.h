#pragma once
 
///#include "Mouse.h"
#include "StaticObject.h"  

class Door : public StaticObject 
{
public:
	Door(float x, float y, float size_x, float size_y);

	//============-COLISIONS-====================
	
	virtual Object_ID handleCollision(Object&) override;

	virtual Object_ID handleCollision(Mouse&) override;
	
};