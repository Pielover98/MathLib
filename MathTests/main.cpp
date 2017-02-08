#include <cassert>
#include <cstdio>


#include "vec2.h"
#include "vec3.h"
#include "flops.h"


#include "Mat2.h"
#include "Mat3.h"


#include "shapes.h"


#include "Collision.h"


#include <cmath>


int main()
{
	/*assert(doNothing(0) == 5);
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
	assert(bezier(0.5f, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 1.5);*/

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

	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,2,1 };
	vec2 v0 = vec2{ 1,0 };
	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI*-1 == -mI);

	assert(mI * mI == mI);
	assert((mat2{ 1,2,3,4 }) * mI == (mat2{ 1,2,3,4 }));
	assert((mat2{ 1,5,2,9 } *(mat2{ 3,1,4,12 }) == (mat2{5, 24, 28, 128})));

	assert(mI * v0 == v0);
	assert((t0 * v0 == vec2{ 4,3 }));

	assert(transpose(mI) == mI);
	assert(inverse(mI) == mI);

	assert(t0*inverse(t0) == mI);

	mat3 t03 = {};
	mat3 mI3 = mat3Identity();

	assert(mI3*inverse(mI3) == mI3);



	vec3 j = { 2,5,1 };

	assert((scale(5, 1) * j == vec3{ 10,5,1 }));

	assert((rotate(deg2rad(90)) * j == vec3{ -5,2,1 }));

	assert((translate(0, 3)*j == vec3{ 2,8,1 }));

	mat3 S = scale(2, 1);
	mat3 T = translate(4, 3);
	mat3 R = rotate(deg2rad(90));

	/*mat3 RES = { 0,-1,0, 2,0,0, 4,3,1 };

	bool r0 = (S*T*R == RES);
	bool r1 = (S*R*T == RES);
	bool r2 = (R*S*T == RES);
	bool r3 = (R*T*S == RES);
	bool r4 = (T*S*R == RES);
	bool r5 = (T*R*S == RES);*/


	vec3 test
		= rotate(deg2rad(-90)) * translate(10, 0) *
		rotate(deg2rad(45))  * translate(4, 0) *
		rotate(deg2rad(45))  * translate(-6, 0) *
		translate(6, 4)      *  vec3 { 0, 0, 1 };

	assert((test == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2) , 1 }));


	vec2 WP[] = { { 12,-8 },{ 15,18 },{ 5,8 },{ -22,-5 },
	{ 4,-2 },{ -6,9 },{ 18,88 },{ -22,-90 } };

	mat3 RES = translate(12, -8) * rotate(deg2rad(80));

	for (int i = 0; i < 8 - 1; ++i)
	{
		vec2 D = WP[i + 1] - WP[i];

		float current = atan2f(RES[0].y, RES[0].x);
		float target = atan2f(D.y, D.x);
		float distance = magnitude(D);

		mat3 R = rotate(target - current);
		mat3 T = translate(distance, 0);

		RES = RES * R * T;
	}


	Circle c = { 0, 0, 5 };


	assert((translate(4, 0) * c == Circle{ 4, 0, 5 }));

	assert((scale(2, 1) * c == Circle{ 0, 0, 10 }));
	assert((scale(2, 2) * c == Circle{ 0, 0, 10 }));
	assert((scale(1, 2) * c == Circle{ 0, 0, 10 }));

	assert((scale(-1, 1) * c == Circle{ 0, 0, 5 }));
	assert((rotate(45) * c == Circle{ 0,0,5 }));


	AABB testA = { 1,2, 3,4 };

	assert((testA.min() == vec2{ -2,-2 }));
	assert((testA.max() == vec2{ 4, 6 }));

	AABB testB = {0,0,2,1};
	mat3 rot = rotate(deg2rad(90));

	//assert((rot*testB == AABB{0,0,1,2}));




	assert(collisionDetection1D(0, 2, 1, 3).result() == true);


	assert(collisionDetection1D(0, 2, 1, 3).penetrationDepth == 1);
	assert(collisionDetection1D(1, 3, 0, 2).penetrationDepth == 1);

	assert(collisionDetection1D(0, 2, 1, 3).collisionNormal == 1);
	assert(collisionDetection1D(1, 3, 0, 2).collisionNormal == -1);

	SweptCollisionData1D swcd = sweptDetection1D(0, 1, 2, 3, 4, 0);

	assert(sweptDetection1D(0, 1, 2, 3, 4, 0).entryTime == 1.f);
	assert(sweptDetection1D(0, 1, 5, 3, 4, 0).entryTime == .4f);

	assert(sweptDetection1D(0, 1, -5, 3, 4, 10).result() == false);


	AABB A = { 0,0, 2,4 };
	AABB B = { 2,2, 2,4 };

	assert(boxCollision(A, B).penetrationDepth == 2);
	assert((boxCollision(A, B).collisionNormal == vec2{ 1, 0 }));
	assert((boxCollision(B, A).collisionNormal == vec2{ -1, 0 }));


	AABB As = { 0,0, 1,1 };
	AABB Bs = { 0,10, 1,1 };

	CollisionDataSwept testing =
		boxCollisionSwept(As, vec2{ 0,1 }, Bs, vec2{ 0 ,-1 });

	assert(fequals(boxCollisionSwept(As, vec2{ 0, 1 },
		Bs, vec2{ 0,-1 }).entryTime, 4));

	assert(fequals(boxCollisionSwept(As, vec2{ 0, 1 },
		Bs, vec2{ 0,-1 }).exitTime, 6));


	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 },
		Bs, vec2{ 0 ,1 }).exitTime, -4));


	AABB Bp = { 0,0, 4,4 };

	Plane P1 = { 0,0,0,1 }; 
	Plane P2 = { 0,-10,0,1 };
	Plane P3 = { 0, 10,0,1 }; 

	Plane P4 = { vec2{ 6,6 }, normal(vec2{ -1,1 }) }; 
	Plane P5 = { vec2{ 6,6 }, normal(vec2{ -1,-1 }) };

	assert(planeBoxCollision(P1, Bp).result());
	assert(!planeBoxCollision(P2, Bp).result());
	assert(planeBoxCollision(P3, Bp).result());
	assert(planeBoxCollision(P4, Bp).result());
	assert(!planeBoxCollision(P5, Bp).result());

	Plane P6 = { 10, 0,-1,0 }; 
	assert(
		fequals(
			planeBoxCollisionSwept(P6, vec2{ 0,0 },
				Bp, vec2{ 1,0 }).entryTime,
			6.f));


	vec2 verts[] = { { 0,1 },{ 1,1 },{ 1,0 },{ 0,0 } };

	vec2 verts2[] = { { -1,-1 },{ -1,1 },{ 0,0 } };

	Hull myHull(verts, 4);
	Hull otherHull(verts2, 3);

	assert((myHull.normals[0] == vec2{ 0, 1 }));
	assert((myHull.normals[1] == vec2{ 1, 0 }));
	assert((myHull.normals[2] == vec2{ 0,-1 }));
	assert((myHull.normals[3] == vec2{ -1,0 }));


	Hull tHull = translate(1, 0) * myHull;

	assert((tHull.vertices[0] == vec2{ 1, 1 }));
	assert((tHull.vertices[1] == vec2{ 2, 1 }));
	assert((tHull.vertices[2] == vec2{ 2, 0 }));
	assert((tHull.vertices[3] == vec2{ 1, 0 }));

	assert(fequals(HullCollision(myHull, otherHull).penetrationDepth, 0));
	assert(fequals(HullCollision(otherHull, tHull).penetrationDepth, -1));

	vec2 I = vec2{ -1, -1 }; 
	vec2 xaxis = vec2{ 1,  0 }; 
	vec2 Ref = vec2{ 1, -1 };

	assert(project(I, xaxis) == -xaxis);
	assert(reflect(I, xaxis) == Ref);


}
