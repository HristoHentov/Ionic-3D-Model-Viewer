#include "mat3.h"
namespace Ionic {
	namespace Math {

		mat3::mat3()
		{
			for (int i = 0; i < 9; i++)
			{
				elements[i] = 0.0f;
			}
		}

		mat3::mat3(float diagonal)
		{
			for (int i = 0; i < 9; i++)
			{
				elements[i] = 0.0f;
			}

			elements[0] = diagonal;
			elements[4] = diagonal;
			elements[8] = diagonal;
		}

		mat3& mat3::Add(const mat3& other)
		{
			for (ushort i = 0; i < (3 * 3); i++)
			{
				this->elements[i] += other.elements[i];
			}

			return *this;
		}

		mat3& mat3::Subtract(const mat3& other)
		{
			for (ushort i = 0; i < (3 * 3); i++)
			{
				this->elements[i] -= other.elements[i];
			}
			return *this;
		}

		mat3& mat3::Multiply(const mat3& other)
		{
			float tempVals[3 * 3];
			for (int r = 0; r < 3; r++)
			{
				for (ushort c = 0; c < 3; c++)
				{
					float temp = 0.0f;
					for (ushort i = 0; i < 3; i++)
					{
						temp += this->elements[(r * 3) + i] * other.elements[(i * 3) + c];
					}

					tempVals[(r * 3) + c] = temp;
				}
			}

			memcpy(this->elements, tempVals, (3 * 3) * sizeof(float));
			return *this;
		}

		mat3& mat3::Multiply(const float scalar)
		{
			for (int i = 0; i < 3 * 3; i++)
			{
				elements[i] *= scalar;
			}
			return *this;
		}

		mat3 operator+(mat3& left, const mat3& right)
		{
			return left.Add(right);
		}

		mat3 operator-(mat3& left, const mat3& right)
		{
			return left.Subtract(right);
		}

		mat3 operator*(mat3& left, const mat3& right)
		{
			return left.Multiply(right);
		}

		mat3 operator*(mat3& left, const float right)
		{
			return left.Multiply(right);
		}

		mat3 mat3::Identity()
		{
			return mat3(1.0);
		}
		mat3 mat3::Inverse()
		{
			mat3 minorsMatrix;
			
			minorsMatrix.elements[0] = (elements[4] * elements[8]) - (elements[5] * elements[7]); //d
			minorsMatrix.elements[3] = ((elements[3] * elements[8]) - (elements[5] * elements[6])) * -1;
			minorsMatrix.elements[6] = (elements[3] * elements[7]) - (elements[4] * elements[6]);
			
			minorsMatrix.elements[1] = ((elements[1] * elements[8]) - (elements[2] * elements[7])) * -1;
			minorsMatrix.elements[4] = (elements[0] * elements[8]) - (elements[2] * elements[6]); //d 
			minorsMatrix.elements[7] = ((elements[0] * elements[7]) - (elements[1] * elements[6])) * -1;
			
			minorsMatrix.elements[2] = (elements[1] * elements[5]) - (elements[2] * elements[4]);
			minorsMatrix.elements[5] = ((elements[0] * elements[5]) - (elements[2] * elements[3])) * -1;
			minorsMatrix.elements[8] = (elements[0] * elements[4]) - (elements[1] * elements[3]); //d
			
			float determinant = elements[0] * minorsMatrix.elements[0] - elements[1] * minorsMatrix.elements[3] + elements[2] * minorsMatrix.elements[6];
			return minorsMatrix * (1 / determinant);
			
		}

		std::string mat3::ToString()
		{
			std::stringstream output;
			output << "-Mat3x3-" << std::endl;
			for (int r = 0; r < 3; ++r)
			{
				for (int c = 0; c < 3; ++c)
				{
					output << elements[r * 3 + c] << " ";
				}
				output << std::endl;
			}
			output << "--------" << std::endl;

			return output.str();
		}
	}
}