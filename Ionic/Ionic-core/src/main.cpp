#include "Application/Ionic.h"

int main()
{
#ifndef DEBUG
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
#endif
	Ionic::Application::Ionic ionic;
	ionic.Run();

	return 0;
}

