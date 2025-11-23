#pragma once

#include "MovingObject.h"
#include "Mouse.h"


class Cat : public MovingObject {
 public:
  Cat(float x, float y, float size_x, float size_y, float speed);


  
  //============-COLISIONS-====================

  virtual Object_ID handleCollision(Object &other) override;

  virtual Object_ID handleCollision(Mouse &) override;

  virtual Object_ID handleCollision(Wall &) override;

  virtual Object_ID handleCollision(Door &) override;

  
};