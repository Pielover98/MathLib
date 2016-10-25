#pragma once
#include "Transform.h"
#include "mat3.h"


class SpaceShipRenderer
{
public:
	unsigned color;

	SpaceShipRenderer();

	void draw(const mat3 &T, const Transform &ship);
};