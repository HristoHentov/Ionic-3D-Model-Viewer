#pragma once

#include <cstring>
#include <sstream>
#include "vec3.h"
#include <math.h>

#define ushort unsigned short
namespace Ionic { namespace Math {

		struct  mat4
		{
			float elements[4 * 4];

			mat4();
			mat4(float diagonal);


			mat4& Multiply(float scalar);
			mat4& Multiply(const mat4& other);

			friend mat4 operator *(mat4& left, const mat4& right);
			mat4& operator *=(const float scalar);

			friend mat4 operator *(mat4& matrix, const float scalar);
			mat4& operator *=(const mat4& other);

			static mat4 Identity();
			mat4& Inverse();

			static mat4 LookAt(const vec3& camera, const vec3& object, const vec3& up);
			static mat4 Perspective(float near, float far, float fov, float aspectRatio);
			static mat4 Ortographic(float near, float far, float left, float right, float top, float bottom);

			static mat4 Translation(const vec3 translation);
			static mat4 Rotation(float angle, const vec3 axis);
			static mat4 Scale(const vec3 scale);

			std::string ToString();
		};

	}
}