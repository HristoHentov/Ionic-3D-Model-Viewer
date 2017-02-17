#pragma once
#include <GLEW/glew.h>
#include "../Math/mat4.h"

namespace Ionic { namespace Graphics {

	class Camera
	{
		public:

			virtual Math::mat4 GetProjection() = 0;
			virtual Math::mat4 GetView() = 0;
			virtual void Update(GLfloat time) = 0;

			virtual ~Camera() {};

	protected:
		Math::mat4 _projectionMatrix;
		Math::mat4 _viewMatrix;
		
	};
}
}
