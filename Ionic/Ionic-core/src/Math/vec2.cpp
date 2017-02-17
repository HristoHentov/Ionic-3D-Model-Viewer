#include "vec2.h"

namespace Ionic { namespace Math
{
	vec2::vec2()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	vec2::vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}

	vec2& vec2::Add(const vec2& other)
	{
		this->x += other.x;
		this->y += other.y;
		
		return *this;
		//return * new vec2(this->x + other.x, this->y + other.y);
	}

	vec2& vec2::Subtract(const vec2& other)
	{
		this->x -= other.x;
		this->y -= other.y;

		return *this;
	}

	vec2& vec2::Multiply(const vec2& other)
	{
		this->x *= other.x;
		this->y *= other.y;

		return *this;
	}

	vec2& vec2::Divide(const vec2& other)
	{
		this->x /= other.x;
		this->y /= other.y;

		return *this;
	}

	float vec2::Dot(const vec2& other) const
	{
		return x * other.x + y * other.y;
	}

	vec2 vec2::Normalise() const
	{
		float length = Magnitude();
		return vec2(x / length, y / length);
	}

	float vec2::Magnitude() const
	{
		return sqrt(x * x + y * y);
	}

	vec2 operator+(vec2 left, const vec2& right)
	{
		return left.Add(right);
	}

	vec2 operator-(vec2 left, const vec2& right)
	{
		return left.Subtract(right);
	}

	vec2 operator*(vec2 left, const vec2& right)
	{
		return left.Multiply(right);
	}

	vec2 operator/(vec2 left, const vec2& right)
	{
		return left.Divide(right);
	}

	vec2& vec2::operator+=(const vec2& other)
	{
		return this->Add(other);
	}

	vec2& vec2::operator-=(const vec2& other)
	{
		return this->Subtract(other);
	}

	vec2& vec2::operator*=(const vec2& other)
	{
		return this->Multiply(other);
	}

	vec2& vec2::operator/=(const vec2& other)
	{
		return this->Divide(other);
	}

	bool vec2::operator==(const vec2& other)
	{
		return (this->x == other.x) && (this->y == other.y);
	}

	bool vec2::operator!=(const vec2& other)
	{
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& os, const vec2& vector)
	{
		os << "[" << vector.x << ", " << vector.y << "]";
		return os;
	}

	std::string vec2::ToString() const
	{
		std::string x = std::to_string(this->x);
		std::string y = std::to_string(this->y);

		return ("[" + x + "," + y + "]");
	}
} }
