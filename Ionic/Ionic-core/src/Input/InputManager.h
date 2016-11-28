#pragma once
#include "../IonicDefinitions.h"
#include "../Graphics/Window.h"

namespace Ionic { namespace Input
{
	class InputManager
	{
	public:
		InputManager();
		
		static bool IsKeyPressed(int keycode);

	private:
		static bool _keys[TOTAL_KEYS];
		static bool _buttons[TOTAL_BUTTONS];
	private:
		friend class Graphics::Window;
	private:
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods); // this might not need to be static


	};

} }
