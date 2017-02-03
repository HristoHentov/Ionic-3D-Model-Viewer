#pragma once
#include "../IonicDefinitions.h"
#include "../Graphics/Window.h"
#include "../Math/vec2.h"
#include <string>

namespace Ionic { namespace Input
{
	class InputManager
	{
	public:
		InputManager();
		
		static bool IsKeyPressed(int keycode);
		static bool IsMousePressed(int keycode);
		static double GetScrollOffset();
		static Math::vec2 GetMousePosition();

	private:
		static bool _keys[TOTAL_KEYS];
		static bool _buttons[TOTAL_BUTTONS];
		static double _mouseX, _mouseY;
		static double _scrollY;
	private:
		friend class Graphics::Window;
	private:
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods); // this might not need to be static
		static void ButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void MousePositionCallback(GLFWwindow* window, double x, double y);
		static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);


	};

} }
