#pragma once
#include "../Math/IonicMath.h"
#include <GLEW/glew.h>

namespace Ionic {
	namespace Entities {

		class Light
		{
		public:
			Light(Math::vec3 Position, float intensity = 1.0f, Math::vec3 Color = Math::vec3(1.0f, 1.0f, 1.0f));

			Math::vec3 Position;
			Math::vec3 Color;
			float Intensity;

			void Update(GLfloat time);
		private:
			GLfloat _lastUpdateTime;
			GLfloat _speed;
		};

	}
}
