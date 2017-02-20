#pragma once
#include "../IonicDefinitions.h"
#include "../Math/vec2.h"
#include <string>
#include "../Graphics/Window.h"


namespace Ionic { namespace Input
{
	class InputManager
	{
	public:
		InputManager();
		
		static bool IsKeyPressed(int keycode);
		static bool IsMousePressed(int keycode);
		inline static void ResetScroll() { _scrollY = 0; }
		static double GetScrollOffset();
		static Math::vec2 GetMousePosition();
		static bool MouseMoved();

	private:
		static bool _keys[TOTAL_KEYS];
		static bool _buttons[TOTAL_BUTTONS];
		static double _mouseX, _mouseY;
		static double _scrollY;
		static bool _mouseMoved;
	private:
		friend class Graphics::Window;
	private:
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods); // this might not need to be static
		static void ButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void MousePositionCallback(GLFWwindow* window, double x, double y);
		static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);


	};

} }
