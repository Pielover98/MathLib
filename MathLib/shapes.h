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


struct Plane
{
	vec2 pos, dir;
};

Plane  operator*(const mat3 &T, const Plane  &P);
bool  operator==(const Plane &A, const Plane &B);




struct Ray { };
struct Hull
{
	vec2 vertices[16];
	vec2 normals[16];
	size_t vsize, nsize;
	unsigned int vsize, nsize;

	Hull(const vec2 *vertices, unsigned vsize);

};




Ray    operator*(const mat3 &T, const Ray &R);
Hull   operator*(const mat3 &T, const Hull   &H);
