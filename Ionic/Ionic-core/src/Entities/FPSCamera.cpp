#include "FPSCamera.h"

namespace Ionic {
	namespace Entities {

		Entities::FPSCamera::FPSCamera(float sensitivity, float near, float far, float fov, float aspectRatio)
			:_x(0), _y(0), _z(0), _speed(sensitivity), _lastUpdateTime(0), yaw(-90.0f), pitch(0.0f), lastX(WINDOW_WIDTH / 2), lastY(WINDOW_WIDTH / 2)
		{
			camDirection = Math::vec3(0.0f, 0.0f, -1.0f);
			camPosition = Math::vec3(0.0f, 8.0f, 20.0f);
			camUp = Math::vec3(0.0f, 1.0f, 0.0f);
			this->_projectionMatrix = Math::mat4::Perspective(near, far, fov, aspectRatio);
		}

		Math::mat4 FPSCamera::GetView()
		{
			return this->_viewMatrix;
		}

		Math::mat4 FPSCamera::GetProjection()
		{
			return this->_projectionMatrix;
		}

		void FPSCamera::Update(GLfloat time)
		{
			float deltaTime = time - _lastUpdateTime;

			if (Input::InputManager::IsMousePressed(GLFW_MOUSE_BUTTON_1))
			{
				if (Input::InputManager::MouseMoved())
				{
					if (firstMouse)
					{
						lastX = Input::InputManager::GetMousePosition().x;
						lastY = Input::InputManager::GetMousePosition().y;
						firstMouse = false;
					}

					GLfloat xoffset = Input::InputManager::GetMousePosition().x - lastX;
					GLfloat yoffset = lastY - Input::InputManager::GetMousePosition().y; // Reversed since y-coordinates go from bottom to left
					lastX = Input::InputManager::GetMousePosition().x;
					lastY = Input::InputManager::GetMousePosition().y;

					GLfloat sensitivity = 0.15;	// Change this value to your liking
					xoffset *= sensitivity;
					yoffset *= sensitivity;

					yaw += xoffset;
					pitch += yoffset;

					if (pitch > 89.0f)
						pitch = 89.0f;
					if (pitch < -89.0f)
						pitch = -89.0f;

					float rYaw = yaw * (3.1415f / 180.0f);
					float rPitch = pitch * (3.1415f / 180.0f);
					Math::vec3 front;

					front.x = cos(rYaw) * cos(rPitch);
					front.y = sin(rPitch);
					front.z = sin(rYaw) * cos(rPitch);
					camDirection = front.Normalize();
				}


			}

			else
			{
				lastX = Input::InputManager::GetMousePosition().x;
				lastY = Input::InputManager::GetMousePosition().y;
			}

			if (Input::InputManager::IsKeyPressed(GLFW_KEY_A))
			{
				_x += _speed * deltaTime;
				camPosition -= camDirection.Cross(camUp).Normalize() * _speed * deltaTime;
			}
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_D))
			{
				_x -= _speed * deltaTime;
				camPosition += camDirection.Cross(camUp).Normalize() * _speed * deltaTime;
			}
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_W))
			{
				_y -= _speed * deltaTime;
				camPosition += camDirection * _speed * deltaTime;

			}
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_S))
			{
				_y += _speed * deltaTime;
				camPosition -= camDirection * _speed * deltaTime;

			}
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_Q))
			{
				_z += _speed * deltaTime;
			}
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_E))
			{
				_z -= _speed * deltaTime;
			}
			if (Input::InputManager::GetScrollOffset() != 0)
			{
				if (Input::InputManager::GetScrollOffset() > 0)
					_z += _speed * 50;
				else
					_z -= _speed * 50;

				Input::InputManager::ResetScroll();
			}



			_lastUpdateTime = time;

			//this->_viewMatrix = Math::mat4::Translation(Math::vec3(_x, _y, _z));

			glm::vec3 cPos(camPosition.x, camPosition.y, camPosition.z);
			glm::vec3 cDir(camDirection.x, camDirection.y, camDirection.z);
			glm::vec3 cUp(camUp.x, camUp.y, camUp.z);

			this->test = glm::lookAt(cPos, cPos + cDir, cUp);
			this->_viewMatrix = Math::mat4::LookAt(camPosition, camPosition + camDirection, camUp);

		}

	}
}
