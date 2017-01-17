#include "vec3.h"

namespace Ionic { namespace Math
{
	vec3::vec3()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	vec3::vec3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::Add(const vec3& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		
		return *this;
		//return * new vec3(this->x + other.x, this->y + other.y);
	}

	vec3& vec3::Subtract(const vec3& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;

		return *this;
	}

	vec3& vec3::Multiply(const vec3& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;

		return *this;
	}

	vec3& vec3::Divide(const vec3& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;

		return *this;
	}

	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.Add(right);
	}

	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.Subtract(right);
	}

	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.Multiply(right);
	}

	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.Divide(right);
	}

	vec3& vec3::operator+=(const vec3& other)
	{
		return this->Add(other);
	}

	vec3& vec3::operator-=(const vec3& other)
	{
		return this->Subtract(other);
	}

	vec3& vec3::operator*=(const vec3& other)
	{
		return this->Multiply(other);
	}

	vec3& vec3::operator/=(const vec3& other)
	{
		return this->Divide(other);
	}

	bool vec3::operator==(const vec3& other)
	{
		return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
	}

	bool vec3::operator!=(const vec3& other)
	{
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& os, const vec3& vector)
	{
		os << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
		return os;
	}

	std::string vec3::ToString() const
	{
		std::string x = std::to_string(this->x);
		std::string y = std::to_string(this->y);
		std::string z = std::to_string(this->z);

		return ("[" + x + "," + y + "," + z + "]");
	}
} }
