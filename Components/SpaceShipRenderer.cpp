#include "SpaceShipRenderer.h"
#include "sfwdraw.h"

#include "SpaceshipRenderer.h"
#include "sfwdraw.h"

SpaceShipRenderer::SpaceShipRenderer()
{
	color = MAGENTA;
}

void SpaceShipRenderer::draw(const mat3 & T, const Transform & ship)
{
	mat3 glob = T * ship.getGlobalTransform();

	vec3 F = glob * vec3{ 0, 2, 1 };
	vec3 L = glob * vec3{ -1,-1, 1 };
	vec3 R = glob * vec3{ 1,-1, 1 };

	sfw::drawLine(L.x, L.y, F.x, F.y, color);
	sfw::drawLine(F.x, F.y, R.x, R.y, color);
	sfw::drawLine(R.x, R.y, L.x, L.y, color);
}