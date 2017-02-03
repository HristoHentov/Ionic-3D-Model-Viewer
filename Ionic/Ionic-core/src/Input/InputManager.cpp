#include "InputManager.h"


namespace Ionic { namespace Input
{
	using namespace Graphics;

	bool InputManager::_keys[TOTAL_KEYS];
	bool InputManager::_buttons[TOTAL_BUTTONS];

	double InputManager::_mouseX;
	double InputManager::_mouseY;
	double InputManager::_scrollY;


	InputManager::InputManager()
	{
		for (int i = 0; i < TOTAL_KEYS; ++i)
		{
			_keys[i] = false;
		}
		_buttons[TOTAL_BUTTONS] = { false };
		_scrollY = 0.0f;
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
	bool InputManager::IsMousePressed(int keycode)
	{
		if(keycode < 0 || keycode > TOTAL_BUTTONS)
		{
			///TODO: Log Error
			return false;
		}

		return _buttons[keycode];
	}

	double InputManager::GetScrollOffset()
	{
		return _scrollY;
	}

	Math::vec2 InputManager::GetMousePosition()
	{
		return Math::vec2(_mouseX, _mouseY);
	}

	//TODO : the Window* in all the callbacks is redundant, check if it will be used for anything and if not, remove it.
	void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window * win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		_keys[key] = action != GLFW_RELEASE; // Sets the current key in the bool array to ture if its pressed in ANY way.
	}

	void InputManager::ButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		Window * win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		_buttons[button] = action != GLFW_RELEASE;
	}

	void InputManager::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Window * win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		_scrollY = yoffset;
	}

	void InputManager::MousePositionCallback(GLFWwindow* window, double x, double y)
	{
		Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
		_mouseX = x;
		_mouseY = y;
	}


} }
