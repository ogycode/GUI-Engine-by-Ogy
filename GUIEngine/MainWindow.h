#pragma once
#include "WindowTemplate.h"

class MainWindow : 
	public WindowTemplate
{
public:
	MainWindow(HINSTANCE hInstance, LPCSTR windowName, HWND parent);
	~MainWindow(void);
	LRESULT RealWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnCreate();
};

