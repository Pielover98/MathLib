#pragma once

#include "mat3.h"



struct Circle
{
	vec2  pos; 
	float rad;
};
Circle operator*(const mat3 &T, const Circle &C);




bool  operator==(const Circle &A, const Circle &B);




struct AABB
{
	vec2 pos,
		he; 
			
			

	vec2 min() const; 
	vec2 max() const; 
};

AABB  operator*(const mat3 &T, const AABB  &A);
bool  operator==(const AABB &A, const AABB &B);


struct Plane { };
struct Ray { };
struct Hull { };



Plane  operator*(const mat3 &T, const Plane  &P);
Ray    operator*(const mat3 &T, const Ray    &R);
Hull   operator*(const mat3 &T, const Hull   &H);