#include "WindowTemplate.h"

namespace GUIEngine
{
	WindowTemplate::WindowTemplate(HINSTANCE hInstance, LPCSTR windowName, HWND parent) : mbackground(NULL)
	{
		createWindow(hInstance,windowName,parent);
	}
	WindowTemplate::~WindowTemplate(void)
	{
	}

	void WindowTemplate::createWindow(HINSTANCE hInstance, LPCSTR windowName, HWND parent)
	{
		mhwnd = CreateDialog(hInstance, windowName, parent, (DLGPROC)WindowProc);
		SetWindowLongPtr(mhwnd,GWLP_USERDATA,(LONG_PTR)this);
	}
	LRESULT CALLBACK WindowTemplate::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		WindowTemplate* pwindow = NULL;
		pwindow = (WindowTemplate*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		if (pwindow !=NULL)
			return pwindow->RealWindowProc(hwnd,uMsg,wParam,lParam);
		return 0;
	}
	void WindowTemplate::Show (int cmd)
	{
		ShowWindow(mhwnd, cmd);
	}
	LRESULT WindowTemplate::RealWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_INITDIALOG:
			break;
		case WM_CLOSE:
			EndDialog(hwnd, wParam);
			PostQuitMessage(0);
			break;
		case WM_CTLCOLORDLG:
			if (mbackground == NULL)
				break;
			return (LPARAM)mbackground;
			break;
		}
		return 0;
	}
}
