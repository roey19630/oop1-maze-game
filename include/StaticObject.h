#pragma once

#include "Object.h"

class StaticObject : public Object 
{
public:
    StaticObject(float x, float y, float size_x, float size_y);

    bool isEaten() const;

    void gotEaten();

private:
    bool m_isEaten = false;    
};
