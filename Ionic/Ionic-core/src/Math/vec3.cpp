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

	vec3& vec3::Add(float other)
	{
		x += other;
		y += other;
		z += other;

		return *this;
	}

	vec3& vec3::Subtract(float other)
	{
		x -= other;
		y -= other;
		z -= other;

		return *this;
	}

	vec3& vec3::Multiply(float other)
	{
		x *= other;
		y *= other;
		z *= other;

		return *this;
	}

	vec3& vec3::Divide(float other)
	{
		x /= other;
		y /= other;
		z /= other;

		return *this;
	}

	float vec3::Magnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	float vec3::Dot(const vec3& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	vec3 vec3::Cross(const vec3& other) const
	{
		return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}

	vec3 vec3::Normalize() const
	{
		float length = Magnitude();
		return vec3(x / length, y / length, z / length);
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

	vec3 operator+(vec3 left, float right)
	{
		return left.Add(right);
	}

	vec3 operator-(vec3 left, float right)
	{
		return left.Subtract(right);
	}

	vec3 operator*(vec3 left, float right)
	{
		return left.Multiply(right);
	}

	vec3 operator/(vec3 left, float right)
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

	vec3& vec3::operator+=(float other)
	{
		return Add(other);
	}

	vec3& vec3::operator-=(float other)
	{
		return Subtract(other);

	}

	vec3& vec3::operator*=(float other)
	{
		return Multiply(other);

	}

	vec3& vec3::operator/=(float other)
	{
		return Divide(other);

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
