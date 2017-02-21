#include "Light.h"
#include <GLFW/glfw3.h>
#include "../Input/InputManager.h"

namespace Ionic {
	namespace Entities {

		Light::Light(Math::vec3 position, float intensity, Math::vec3 color)
			:Position(position), Intensity(intensity), Color(color), _speed(50.0f)
		{

		}

		void Light::Update(GLfloat time)
		{
			float deltaTime = time - _lastUpdateTime;

			if (Input::InputManager::IsKeyPressed(GLFW_KEY_UP))
				Position.y += _speed * deltaTime;
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_DOWN))
				Position.y -= _speed * deltaTime;
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_LEFT))
				Position.x -= _speed * deltaTime;
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_RIGHT))
				Position.x += _speed * deltaTime;

			if (Input::InputManager::IsKeyPressed(GLFW_KEY_R))
				Color = Math::vec3(1.0, 0.4, 0.4);
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_G))
				Color = Math::vec3(0.4, 1.0, 0.4);
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_B))
				Color = Math::vec3(0.4, 0.4, 1.0);
			if (Input::InputManager::IsKeyPressed(GLFW_KEY_L))
				Color = Math::vec3(1.0, 1.0, 1.0);

			_lastUpdateTime = time;
		}
	}
}
