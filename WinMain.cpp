#include "App.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int		  nCmdShow)
{
	try
	{
		return App{}.Go();
	}
	catch (const ChiliException& e)
	{
		SetWindowLongPtr(GetActiveWindow(), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&DefWindowProc));
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		SetWindowLongPtr(GetActiveWindow(), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&DefWindowProc));
		MessageBoxA(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		SetWindowLongPtr(GetActiveWindow(), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&DefWindowProc));
		MessageBoxA(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}