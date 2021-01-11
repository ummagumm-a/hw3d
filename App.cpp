#include "App.h"

App::App()
	:
	wnd(800, 600, "The Donkey Fart Box");
{}

int App::Go()
{
	// message pump
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessageA(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);

		DoFrame();
	}

	// check if GetMessage call itself borked
	if (gResult == -1)
	{
		throw CHWND_LAST_EXCEPT();
	}

	return msg.wParam;
}

void App::DoFrame()
{

}