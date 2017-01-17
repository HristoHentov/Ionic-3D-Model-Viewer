#pragma once
#include <string>

namespace Ionic { namespace Math
{
	struct vec3
	{
		float x, y, z;

		vec3();
		vec3(const float& x, const float& y, const float& z);

		vec3& Add(const vec3& other);
		vec3& Subtract(const vec3& other);
		vec3& Multiply(const vec3& other);
		vec3& Divide(const vec3& other);

		friend vec3 operator+(vec3 left, const vec3& right);
		friend vec3 operator-(vec3 left, const vec3& right);
		friend vec3 operator*(vec3 left, const vec3& right);
		friend vec3 operator/(vec3 left, const vec3& right);

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);

		friend std::ostream& operator<<(std::ostream& os ,const vec3& vector);
		std::string ToString() const;
	};

} }