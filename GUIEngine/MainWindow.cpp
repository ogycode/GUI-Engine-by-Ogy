#include "MainWindow.h"
#include "resource.h"


MainWindow::MainWindow(HINSTANCE hInstance, LPCSTR windowName, HWND parent) : WindowTemplate(hInstance, windowName, parent)
{
	OnCreate();
}
MainWindow::~MainWindow(void)
{
}

void MainWindow::OnCreate()
{
	textBox1 = new TextBoxTemplate(mhwnd, IDC_EDIT1);
}
LRESULT MainWindow::RealWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_COMMAND:
			if (wParam == IDOK)
				MessageBox(mhwnd, "Button pressed!","!!!", MB_OK | MB_ICONASTERISK);
			if (wParam == IDCANCEL)
				exit(0);
			if (wParam == IDC_BUTTON1)
				//textBox1->AppendText("Hello World!");
					MessageBox(mhwnd,textBox1->GetText(),"!!!", MB_OK);
			break;
	}
	return WindowTemplate::RealWindowProc(hwnd,uMsg,wParam,lParam);
}
