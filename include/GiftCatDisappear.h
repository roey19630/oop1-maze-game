#pragma once

#include "Gift.h"

class GiftCatDisappear : public Gift {
public:
    GiftCatDisappear(float x, float y, float size_x, float size_y);

    //============-COLISIONS-====================

    virtual Object_ID handleCollision(Object&) override;

    virtual Object_ID handleCollision(Mouse&) override;

};