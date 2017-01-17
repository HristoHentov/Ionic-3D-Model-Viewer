#include "mat4.h"
namespace Ionic { namespace Math 
{
		mat4::mat4()
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = 0.0f;
			}
		}

		mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = 0.0f;
			}

			elements[0] = diagonal;
			elements[5] = diagonal;
			elements[10] = diagonal;
			elements[15] = diagonal;
		}

		mat4& mat4::Multiply(const mat4& other)
		{
			float tempVals[4 * 4];
			for (int r = 0; r < 4; r++)
			{
				for (ushort c = 0; c < 4; c++)
				{
					float temp = 0.0f;
					for (ushort i = 0; i < 4; i++)
					{
						temp += this->elements[(r * 4) + i] * other.elements[(i * 4) + c];
					}

					tempVals[(r * 4) + c] = temp;
				}
			}

			memcpy(this->elements, tempVals, (4 * 4) * sizeof(float));
			return *this;
		}

	


	mat4& mat4::Multiply(const float scalar)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] *= scalar;
			}
			return *this;
		}

		mat4 operator*(mat4& left, const mat4& right)
		{
			return left.Multiply(right);
		}

	mat4 operator*(mat4& left, const float right)
		{
			return left.Multiply(right);
		}

	mat4& mat4::operator*=(const float scalar)
	{
		return this->Multiply(scalar);
	}


	mat4& mat4::operator*=(const mat4& other)
	{
		return this->Multiply(other);
	}

	mat4 mat4::Identity()
		{
			return mat4(1.0);
		}
		mat4& mat4::Inverse()
		{
			float temp[16];

			temp[0] = elements[5] * elements[10] * elements[15] -
				elements[5] * elements[11] * elements[14] -
				elements[9] * elements[6] * elements[15] +
				elements[9] * elements[7] * elements[14] +
				elements[13] * elements[6] * elements[11] -
				elements[13] * elements[7] * elements[10];

			temp[4] = -elements[4] * elements[10] * elements[15] +
				elements[4] * elements[11] * elements[14] +
				elements[8] * elements[6] * elements[15] -
				elements[8] * elements[7] * elements[14] -
				elements[12] * elements[6] * elements[11] +
				elements[12] * elements[7] * elements[10];

			temp[8] = elements[4] * elements[9] * elements[15] -
				elements[4] * elements[11] * elements[13] -
				elements[8] * elements[5] * elements[15] +
				elements[8] * elements[7] * elements[13] +
				elements[12] * elements[5] * elements[11] -
				elements[12] * elements[7] * elements[9];

			temp[12] = -elements[4] * elements[9] * elements[14] +
				elements[4] * elements[10] * elements[13] +
				elements[8] * elements[5] * elements[14] -
				elements[8] * elements[6] * elements[13] -
				elements[12] * elements[5] * elements[10] +
				elements[12] * elements[6] * elements[9];

			temp[1] = -elements[1] * elements[10] * elements[15] +
				elements[1] * elements[11] * elements[14] +
				elements[9] * elements[2] * elements[15] -
				elements[9] * elements[3] * elements[14] -
				elements[13] * elements[2] * elements[11] +
				elements[13] * elements[3] * elements[10];

			temp[5] = elements[0] * elements[10] * elements[15] -
				elements[0] * elements[11] * elements[14] -
				elements[8] * elements[2] * elements[15] +
				elements[8] * elements[3] * elements[14] +
				elements[12] * elements[2] * elements[11] -
				elements[12] * elements[3] * elements[10];

			temp[9] = -elements[0] * elements[9] * elements[15] +
				elements[0] * elements[11] * elements[13] +
				elements[8] * elements[1] * elements[15] -
				elements[8] * elements[3] * elements[13] -
				elements[12] * elements[1] * elements[11] +
				elements[12] * elements[3] * elements[9];

			temp[13] = elements[0] * elements[9] * elements[14] -
				elements[0] * elements[10] * elements[13] -
				elements[8] * elements[1] * elements[14] +
				elements[8] * elements[2] * elements[13] +
				elements[12] * elements[1] * elements[10] -
				elements[12] * elements[2] * elements[9];

			temp[2] = elements[1] * elements[6] * elements[15] -
				elements[1] * elements[7] * elements[14] -
				elements[5] * elements[2] * elements[15] +
				elements[5] * elements[3] * elements[14] +
				elements[13] * elements[2] * elements[7] -
				elements[13] * elements[3] * elements[6];

			temp[6] = -elements[0] * elements[6] * elements[15] +
				elements[0] * elements[7] * elements[14] +
				elements[4] * elements[2] * elements[15] -
				elements[4] * elements[3] * elements[14] -
				elements[12] * elements[2] * elements[7] +
				elements[12] * elements[3] * elements[6];

			temp[10] = elements[0] * elements[5] * elements[15] -
				elements[0] * elements[7] * elements[13] -
				elements[4] * elements[1] * elements[15] +
				elements[4] * elements[3] * elements[13] +
				elements[12] * elements[1] * elements[7] -
				elements[12] * elements[3] * elements[5];

			temp[14] = -elements[0] * elements[5] * elements[14] +
				elements[0] * elements[6] * elements[13] +
				elements[4] * elements[1] * elements[14] -
				elements[4] * elements[2] * elements[13] -
				elements[12] * elements[1] * elements[6] +
				elements[12] * elements[2] * elements[5];

			temp[3] = -elements[1] * elements[6] * elements[11] +
				elements[1] * elements[7] * elements[10] +
				elements[5] * elements[2] * elements[11] -
				elements[5] * elements[3] * elements[10] -
				elements[9] * elements[2] * elements[7] +
				elements[9] * elements[3] * elements[6];

			temp[7] = elements[0] * elements[6] * elements[11] -
				elements[0] * elements[7] * elements[10] -
				elements[4] * elements[2] * elements[11] +
				elements[4] * elements[3] * elements[10] +
				elements[8] * elements[2] * elements[7] -
				elements[8] * elements[3] * elements[6];

			temp[11] = -elements[0] * elements[5] * elements[11] +
				elements[0] * elements[7] * elements[9] +
				elements[4] * elements[1] * elements[11] -
				elements[4] * elements[3] * elements[9] -
				elements[8] * elements[1] * elements[7] +
				elements[8] * elements[3] * elements[5];

			temp[15] = elements[0] * elements[5] * elements[10] -
				elements[0] * elements[6] * elements[9] -
				elements[4] * elements[1] * elements[10] +
				elements[4] * elements[2] * elements[9] +
				elements[8] * elements[1] * elements[6] -
				elements[8] * elements[2] * elements[5];

			float determinant = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];
			determinant = 1.0f / determinant;

			for (int i = 0; i < 4 * 4; i++)
				elements[i] = temp[i] * determinant;

			return *this;
		}

		mat4 mat4::Perspective(float near, float far, float fov, float aspectRatio)
		{
			mat4 perspective;
			
			float rads = (fov / 2) * (3.1415f / 180.0f);
			perspective.elements[0 * 4 + 0] = 1.0f / tan(rads);
			perspective.elements[1 * 4 + 1] = 1.0f / tan(rads) / aspectRatio;
			perspective.elements[2 * 4 + 2] = (near + far) / (near - far);
			perspective.elements[2 * 4 + 3] = 2.0f * (far * near) / (near - far);
			perspective.elements[3 * 4 + 2] = 1.0f; // might need to be -1.0f

			return perspective;
 		}

		mat4 mat4::Ortographic(float near, float far, float left, float right, float top, float bottom)
		{
			mat4 ortographic(1.0f);
			ortographic.elements[0 * 4 + 0] = 2.0f / (right - left);
			ortographic.elements[1 * 4 + 1] = 2.0f / (top - bottom);
			ortographic.elements[2 * 4 + 2] = 2.0f / (far - near);

			ortographic.elements[0 * 4 + 3] = ((right + left) / (right - left));
			ortographic.elements[1 * 4 + 3] = ((top + bottom) / (top - bottom));
			ortographic.elements[2 * 4 + 3] = ((far + near) / (far - near));

			return ortographic;

		}

		mat4 mat4::Translation(const vec3 tVector)
		{
			mat4 translation(1.0f);
			translation.elements[0 * 4 + 3] = tVector.x;
			translation.elements[1 * 4 + 3] = tVector.y;
			translation.elements[2 * 4 + 3] = tVector.z;

			return translation;
		}

		mat4 mat4::Scale(const vec3 sVector)
		{
			mat4 scale(1.0f);
			scale.elements[0 * 4 + 0] = sVector.x;
			scale.elements[1 * 4 + 1] = sVector.y;
			scale.elements[2 * 4 + 2] = sVector.z;

			return scale;
		}

		mat4 mat4::Rotation(float angle, const vec3 axis)
		{
			mat4 result;

			float rads = angle * (3.141593f / 180.0f);
			float sinA = sin(rads);
			float cosA = cos(rads);

			float c = 1.0f - cosA;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.elements[0 * 4 + 0] = x * x * c + cosA;
			result.elements[0 * 4 + 1] = x * y * c - z * sinA;
			result.elements[0 * 4 + 2] = x * z * c + y * sinA;

			result.elements[1 * 4 + 0] = y * x * c + z * sinA;
			result.elements[1 * 4 + 1] = y * y * c + cosA;
			result.elements[1 * 4 + 2] = y * z * c - x * sinA;

			result.elements[2 * 4 + 0] = x * z * c - y * sinA;
			result.elements[2 * 4 + 1] = y * z * c + x * sinA;
			result.elements[2 * 4 + 2] = z * z * c + cosA;

			result.elements[3 * 4 + 3] = 1.0f;

			return result;
		}


		std::string mat4::ToString()
		{
			std::stringstream output;
			output << "-Mat4x4-" << std::endl;
			for (int r = 0; r < 4; ++r)
			{
				for (int c = 0; c < 4; ++c)
				{
					output << elements[r * 4 + c] << " ";
				}
				output << std::endl;
			}
			output << "--------" << std::endl;

			return output.str();
		}
	}
}