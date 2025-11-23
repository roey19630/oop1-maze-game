

#include "StaticObject.h"

StaticObject::StaticObject(float x, float y, float size_x, float size_y)
    : Object(x, y, size_x, size_y) 
{
}

bool StaticObject::isEaten() const
{
    return m_isEaten; 
}

void StaticObject::gotEaten() 
{
    m_isEaten = true; 
}
