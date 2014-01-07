#include <Windows.h>
#include <Commctrl.h>

#include "MainWindow.h"
#include "resource.h"

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib,"Comctl32.lib")

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	MSG msg;
	INITCOMMONCONTROLSEX init = {sizeof(INITCOMMONCONTROLSEX), ICC_WIN95_CLASSES};
	if (!InitCommonControlsEx(&init))
		exit(1000);

	MainWindow* mainWindow = new MainWindow(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL);
	mainWindow->Show(SW_SHOW);

	while (FALSE != GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}