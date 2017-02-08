#pragma once

#include "Particle.h"

struct Factory
{
	static Particle makeSimpleParticle(float lifeSpan, vec2 pos, vec2 scale)
	{
		Particle part;

		part.lifetime = lifeSpan;
		part.transform.m_position = pos;
		part.transform.m_scale = scale;

		return part;
	}
};