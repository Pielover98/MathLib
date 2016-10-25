#pragma once
#include "Transform.h"

class PlanetaryRenderer
{
public:
	PlanetaryRenderer(unsigned a_color = 0xffffffff, float a_size = 20.f);

	unsigned int color;
	float size;			

	void draw(const mat3& T, Transform &planetTrans);
};