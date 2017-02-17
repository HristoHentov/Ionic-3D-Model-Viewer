#include "vec4.h"

namespace Ionic { namespace Math
{
	vec4::vec4()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	vec4::vec4(const float& x, const float& y, const float& z, const float& w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4& vec4::Add(const vec4& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
		
		return *this;
		//return * new vec4(this->x + other.x, this->y + other.y);
	}

	vec4& vec4::Subtract(const vec4& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;

		return *this;
	}

	vec4& vec4::Multiply(const vec4& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		this->w *= other.w;

		return *this;
	}

	vec4& vec4::Divide(const vec4& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		this->w /= other.w;

		return *this;
	}

	float vec4::Dot(const vec4& other) const
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}


	vec4 operator+(vec4 left, const vec4& right)
	{
		return left.Add(right);
	}

	vec4 operator-(vec4 left, const vec4& right)
	{
		return left.Subtract(right);
	}

	vec4 operator*(vec4 left, const vec4& right)
	{
		return left.Multiply(right);
	}

	vec4 operator/(vec4 left, const vec4& right)
	{
		return left.Divide(right);
	}

	vec4& vec4::operator+=(const vec4& other)
	{
		return this->Add(other);
	}

	vec4& vec4::operator-=(const vec4& other)
	{
		return this->Subtract(other);
	}

	vec4& vec4::operator*=(const vec4& other)
	{
		return this->Multiply(other);
	}

	vec4& vec4::operator/=(const vec4& other)
	{
		return this->Divide(other);
	}

	bool vec4::operator==(const vec4& other)
	{
		return (this->x == other.x) && (this->y == other.y) && (this->z == other.z) && (this->w == other.w);
	}

	bool vec4::operator!=(const vec4& other)
	{
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& os, const vec4& vector)
	{
		os << "[" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "]";
		return os;
	}

	std::string vec4::ToString() const
	{
		std::string x = std::to_string(this->x);
		std::string y = std::to_string(this->y);
		std::string z = std::to_string(this->z);
		std::string w = std::to_string(this->w);

		return ("[" + x + "," + y + "," + z + "," + w + "]");

	}
} }
