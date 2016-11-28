#include "InputManager.h"
#include "../Logging/Logger.h"


namespace Ionic { namespace Input
{
	using namespace Graphics;

	bool InputManager::_keys[TOTAL_KEYS];
	bool InputManager::_buttons[TOTAL_BUTTONS];

	InputManager::InputManager()
	{
		for (int i = 0; i < TOTAL_KEYS; ++i)
		{
			_keys[i] = false;
		}
		//_keys[TOTAL_KEYS] = { false };
		_buttons[TOTAL_BUTTONS] = { false };
	}

	bool InputManager::IsKeyPressed(int keycode)
	{
		if(keycode < 0 || keycode > TOTAL_KEYS)
		{
			///TODO: Log Error
			return false;
		}
		return _keys[keycode];
	}

	void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window * win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		_keys[key] = action != GLFW_RELEASE; // Sets the current key in the bool array to ture if its pressed in ANY way.
	}
} }
