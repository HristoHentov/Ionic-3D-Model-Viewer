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

		vec3& Add(float other);
		vec3& Subtract(float other);
		vec3& Multiply(float other);
		vec3& Divide(float other);


		friend vec3 operator+(vec3 left, const vec3& right);
		friend vec3 operator-(vec3 left, const vec3& right);
		friend vec3 operator*(vec3 left, const vec3& right);
		friend vec3 operator/(vec3 left, const vec3& right);

		friend vec3 operator+(vec3 left, float right);
		friend vec3 operator-(vec3 left, float right);
		friend vec3 operator*(vec3 left, float right);
		friend vec3 operator/(vec3 left, float right);

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		vec3& operator+=(float other);
		vec3& operator-=(float other);
		vec3& operator*=(float other);
		vec3& operator/=(float other);

		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);


		vec3 Normalize() const;
		vec3 Cross(const vec3& other) const;
		float Dot(const vec3& other) const;
		float Magnitude() const;

		friend std::ostream& operator<<(std::ostream& os ,const vec3& vector);
		std::string ToString() const;
	};

} }