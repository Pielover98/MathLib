#include <cassert>
#include <cstdio>
#include "Test.h"

#include "vec2.h"
#include "vec3.h"
#include "flops.h"


int main()
{
	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);


	assert(test_quad(0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad(1) == -4);


	assert(quad(1, 0, 0).roots == 1);
	assert(quad(1, -2, 0).roots == 2);
	assert(quad(1, 0, 4).roots == 0);


	assert(quad(1, -2, 0).left_root == 0);
	assert(quad(1, -2, 0).right_root == 2);
	assert(quad(1, 0, 0).left_root == quad(1, 0, 0).right_root);


	assert(lerp(0, 1, 0) == 0);
	assert(lerp(0, 1, 1) == 1);
	assert(lerp(0, 1, -1) == -1);
	assert(lerp(1, -1, .5f) == 0);


	assert(distance({ 0, 0 }, { 0,0 }) == 0);
	assert(distance({ 0, 0 }, { 5,0 }) == 5);
	assert(distance({ 0,-5 }, { 0,0 }) == 5);
	assert(distance({ 3,0 }, { 0,4 }) == 5);


	assert(inner({ 1,1,0 }, { -1,1,0 }) == 0);
	assert(inner({ 1,1,1 }, { 1,1,1 }) == 3);


	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,0 }) == 0);
	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,1 }) == 1);


	assert(bezier(0, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 0);
	assert(bezier(1, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 3);
	assert(bezier(0.5f, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 1.5);

	assert((vec2{ 1,1 } +vec2{ -1,0 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } -vec2{ 0,0 } == vec2{ 1,1 }));
	assert(((vec2{ 1,1 } / 1.f) == vec2{ 1, 1 }));
	assert(((vec2{ 1,1 } *1.f) == vec2{ 1, 1 }));
	assert(((1.f * vec2{ 1,1 }) == vec2{ 1, 1 }));
	assert(((vec2{ 10 , -10 }*-1) == vec2{ -10 , 10 }));

	assert((vec2{ 10,10 }) == (vec2{ 5,5 } +(vec2{ 5,5 })));
	assert((vec2{ 5,5 }) == (vec2{ 10,10 } -(vec2{ 5,5 })));
	assert((vec2{ 10,10 }) == (vec2{ 5,5 } *2.0f));
	assert((vec2{ 5,5 }) == (vec2{ 10,10 } / 2.0f));

	assert(normal(vec2{ 0,1 }) == (vec2{ 0,1 }));
	assert(fequals(0, 0.000001));


	vec2 N = normal(vec2{ 1,1 });


	assert(fequals(magnitude(vec2{ 5,0 }), 5));


	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,3 } != vec2{ 2,3 }));


	assert(fequals(magnitude(N), 1));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));
	assert(fequals(angleBetween(vec2{ 1,0 }, vec2{ 0,1 }), deg2rad(90)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	assert((cross(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));


	assert(fequals(hermiteSpline(15, 40, 21, 10, 0), 15));
	assert(fequals(hermiteSpline(15, 40, 21, 10, 1), 21));


	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));


	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));


	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 1), 124));


	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));
	assert((fromAngle(deg2rad(45))) == normal(vec2{ 1,1 }));


	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));


	return 0;
}

