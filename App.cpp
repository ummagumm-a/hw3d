#include "App.h"
#include <sstream>

App::App()
	:
	wnd(800, 600, "The Donkey Fart Box")
{}

int App::Go()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessagesA())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	wnd.Gfx().EndFrame();
}