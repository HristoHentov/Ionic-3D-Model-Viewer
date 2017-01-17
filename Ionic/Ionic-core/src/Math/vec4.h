#pragma once
#include <string>

namespace Ionic { namespace Math
{
	
	struct vec4
	{
		float x, y, z, w;

		vec4();
		vec4(const float& x, const float& y, const float& z, const float& w);

		vec4& Add(const vec4& other);
		vec4& Subtract(const vec4& other);
		vec4& Multiply(const vec4& other);
		vec4& Divide(const vec4& other);

		friend vec4 operator+(vec4 left, const vec4& right);
		friend vec4 operator-(vec4 left, const vec4& right);
		friend vec4 operator*(vec4 left, const vec4& right);
		friend vec4 operator/(vec4 left, const vec4& right);

		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		vec4& operator*=(const vec4& other);
		vec4& operator/=(const vec4& other);

		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);

		friend std::ostream& operator<<(std::ostream& os ,const vec4& vector);
		std::string ToString() const;
	};

} }