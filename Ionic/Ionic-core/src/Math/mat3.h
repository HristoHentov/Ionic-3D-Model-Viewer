#include <cstring>
#include <string>
#include <sstream>
#pragma once

typedef unsigned short ushort;

namespace Ionic {
	namespace Math
	{
		struct mat3
		{
			float elements[3 * 3];

			mat3();
			mat3(float diagonal);

			mat3& Add(const mat3& other);
			mat3& Subtract(const mat3& other);
			mat3& Multiply(const mat3& other);
			mat3& Multiply(const float scalar);

			static mat3 Identity();
			mat3 Inverse();

			friend mat3 operator+(mat3& left, const mat3& right);
			friend mat3 operator-(mat3& left, const mat3& right);
			friend mat3 operator*(mat3& left, const mat3& right);
			friend mat3 operator*(mat3& left, const float right);

			std::string ToString();

		};
	}
}
