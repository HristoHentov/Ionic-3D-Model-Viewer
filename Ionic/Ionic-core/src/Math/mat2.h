#include <cstring>
#pragma once

typedef unsigned short ushort;

namespace Ionic { namespace Math
{	
struct mat2
{
	float elements[2 * 2];

	mat2();
	mat2(float diagonal);

	mat2& Add(const mat2& other);
	mat2& Subtract(const mat2& other);
	mat2& Multiply(const mat2& other);

	friend mat2 operator+(mat2& left, const mat2& right);
	friend mat2 operator-(mat2& left, const mat2& right);
	friend mat2 operator*(mat2& left, const mat2& right);
	 
	mat2& Inverse();
	static mat2 Identity();
};
} }
