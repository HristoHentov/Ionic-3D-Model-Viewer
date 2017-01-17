#include "mat2.h"
namespace Ionic {
	namespace Math {

		mat2::mat2()
		{
			elements[2 * 2] = { 0.0f };
		}

		mat2::mat2(float diagonal)
		{
			for (int i = 0; i < 4; i++)
			{
				elements[i] = 0.0f;
			}

			elements[0] = diagonal;
			elements[3] = diagonal;
			//elements[2 * 2] = { scalar};
		}

		mat2& mat2::Add(const mat2& other)
		{
			for (ushort i = 0; i < (2 * 2); i++)
			{
				this->elements[i] += other.elements[i];
			}

			return *this;
		}

		mat2& mat2::Subtract(const mat2& other)
		{
			for (ushort i = 0; i < (2 * 2); i++)
			{
				this->elements[i] -= other.elements[i];
			}
			return *this;
		}

		mat2& mat2::Multiply(const mat2& other)
		{
			float tempVals[2 * 2];
			for (int r = 0; r < 2; r++)
			{
				for (ushort c = 0; c < 2; c++)
				{
					float temp = 0.0f;
					for (ushort i = 0; i < 2; i++)
					{
						temp += this->elements[(r * 2) + i] * other.elements[(i * 2) + c];
					}

					tempVals[(r * 2) + c] = temp;
				}
			}

			memcpy(this->elements, tempVals, (2 * 2) * sizeof(float));
			return *this;
		}

		mat2 operator+(mat2& left, const mat2& right)
		{
			return left.Add(right);
		}

		mat2 operator-(mat2& left, const mat2& right)
		{
			return left.Subtract(right);
		}

		mat2 operator*(mat2& left, const mat2& right)
		{
			return left.Multiply(right);
		}

		mat2 mat2::Identity()
		{
			return mat2(1.0);
		}

		mat2& mat2::Inverse()
		{
			float temp = this->elements[0];
			this->elements[0] = this->elements[3];
			this->elements[1] *= -1;
			this->elements[2] *= -1;
			this->elements[3] = temp;
			
			return *this;
		}

		std::string mat2::ToString()
		{
			std::stringstream output;
			output << "-Mat2x2-" << std::endl;
			for (int r = 0; r < 2; ++r)
			{
				for (int c = 0; c < 2; ++c)
				{
					output << elements[r * 2 + c] << " ";
				}
				output << std::endl;
			}
			output << "--------" << std::endl;

			return output.str();
		}
	}
}