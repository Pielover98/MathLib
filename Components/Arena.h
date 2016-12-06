#pragma once
#include "shapes.h"
#include "shapeDraw.h"
#include "sfwdraw.h"
#include "Rigidbody.h"
#include "Camera.h"
#include "Collider.h"
#include "ObjectCollision.h"


struct Arena
{
public:
	Transform arenaTransform;
	Collider arenaCollider;

	vec2 center;
	vec2 size;

	void build();
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};