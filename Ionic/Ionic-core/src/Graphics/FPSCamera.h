#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Input/InputManager.h"

namespace Ionic {
	namespace Graphics {

		class FPSCamera : Camera
		{
		public :
			FPSCamera(float sensitivity, float near, float far, float fov, float aspectRatio);

			Math::mat4 GetView() override;
			Math::mat4 GetProjection() override;
			void Update(GLfloat time) override;
			glm::mat4 test;

			inline Math::vec3 GetPosition() const { return camPosition; };
		private:
			float _x, _y, _z;
			float _speed;
			bool firstMouse;
			GLfloat _lastUpdateTime, yaw, pitch, lastX, lastY;
			Math::vec3 camDirection;
			Math::vec3 camPosition;
			Math::vec3 camUp;

		};

	}
}