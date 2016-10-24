#pragma once
#include "Transform.h"

class SpaceShipRenderer
{
public:
	unsigned color;

	SpaceShipRenderer();

	void draw(const mat3 &T, const Transform &ship);
};