#include <Windows.h>
#include "MainWindow.h"
#include "resource.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	MainWindow* mainWindow = new MainWindow(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL);
	mainWindow->Show(SW_SHOW);

	while (FALSE != GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}