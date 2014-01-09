#pragma once
#include "WindowTemplate.h"
#include "TextBoxTemplate.h"
#include "resource.h"

using namespace GUIEngine;

class MainWindow : 
	public WindowTemplate
{
public:
	MainWindow(HINSTANCE hInstance, LPCSTR windowName, HWND parent);
	~MainWindow(void);
	LRESULT RealWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnCreate();

private:
	TextBoxTemplate* textBox1;
};

