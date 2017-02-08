#include "Arena.h"

void Arena::build()
{
		arenaTransform.m_position = center;

		vec2 vertices[4];
		vertices[0] = { -size.x, size.y };
		vertices[1] = { size.x, size.y };
		vertices[2] = { size.x, -size.y };
		vertices[3] = { -size.x,-size.y };

		arenaCollider = Collider(vertices, 4);
}
	void Arena::update(float deltaTime, GameState & gs)
{

}

void Arena::draw(const mat3 & camera)
{
	drawHull(camera * arenaTransform.getGlobalTransform() * arenaCollider.hull, GREEN);
}
