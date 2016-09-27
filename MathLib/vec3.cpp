#include "vec3.h"
#include <cmath>
#include "flops.h"
vec3 operator+(const vec3 &lhs, const vec3 &rhs)
{
	return{ lhs.x + rhs.x, lhs.y + rhs.y };
}
vec3 operator-(const vec3 &lhs, const vec3 &rhs)
{
	return{ lhs.x - rhs.x, lhs.y - rhs.y };
}
vec3 operator/(const vec3 &lhs, float rhs)
{
	return{ lhs.x / rhs, lhs.y / rhs };
}
vec3 operator*(const vec3 &lhs, float rhs)
{
	return{ lhs.x * rhs, lhs.y * rhs };
}
vec3 operator*(float lhs, const vec3 &rhs)
{
	return rhs*lhs;
}
vec3 operator-(const vec3 &v)
{
	return v*-1;
}
vec3 &operator+=(vec3 &lhs, const vec3 &rhs)
{
	return lhs = lhs + rhs;
}
vec3 &operator-=(vec3 &lhs, const vec3 &rhs)
{
	return lhs = lhs - rhs;
}
vec3 &operator*=(vec3 &lhs, float rhs)
{
	return lhs = lhs * rhs;
}
vec3 &operator/=(vec3 &lhs, float rhs)
{
	return lhs = lhs / rhs;
}

bool operator!= (const vec3 &lhs, const vec3 &rhs)
{
	return !fequals(lhs.x, rhs.x) || !fequals(lhs.y, rhs.y);
}
bool operator== (const vec3 &lhs, const vec3 &rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}
float magnitude(const vec3 &v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

vec3 normal(const vec3 & v)
{
	return (v / magnitude(v));
}

float dot(const vec3 & rhs, const vec3 & lhs)
{
	return(rhs.x * lhs.x + rhs.y * lhs.y);
}
float angleBetween(const vec3 & rhs, const vec3 & lhs)
{
	return acos(dot(rhs, lhs));
}
vec3 per(const vec3 & v)
{
	return vec3();
}
vec3 angle(const vec3 & v)
{
	return vec3();
}
