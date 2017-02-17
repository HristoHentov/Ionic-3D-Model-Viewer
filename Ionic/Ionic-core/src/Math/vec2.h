#pragma once
#include <string>

namespace Ionic { namespace Math
{
	
	struct vec2
	{
		float x, y;

		vec2();
		vec2(const float& x, const float& y);

		vec2& Add(const vec2& other);
		vec2& Subtract(const vec2& other);
		vec2& Multiply(const vec2& other);
		vec2& Divide(const vec2& other);


		friend vec2 operator+(vec2 left, const vec2& right);
		friend vec2 operator-(vec2 left, const vec2& right);
		friend vec2 operator*(vec2 left, const vec2& right);
		friend vec2 operator/(vec2 left, const vec2& right);

		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);
		vec2& operator*=(const vec2& other);
		vec2& operator/=(const vec2& other);

		bool operator==(const vec2& other);
		bool operator!=(const vec2& other);

		vec2 Normalise() const;
		float Dot(const vec2& other) const;
		float Magnitude() const;

		friend std::ostream& operator<<(std::ostream& os ,const vec2& vector);
		std::string ToString() const;
	};

} }