#include "MainWindow.h"
#include "resource.h"

using namespace GUIEngine;

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
	comboBox1 = new ComboBoxTemplate(mhwnd, IDC_COMBO1);

	comboBox1->AddItem("RED");
	comboBox1->AddItem("BLACK");
	comboBox1->AddItem("IMAGE");
}
LRESULT MainWindow::RealWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		//Buttun OK
		if (wParam == IDOK)
			MessageBox(mhwnd, "Button pressed!","!!!", MB_OK | MB_ICONASTERISK);

		//Buttun Cncel
		if (wParam == IDCANCEL)
			exit(0);

		//Buttun GetText
		if (wParam == IDC_BUTTON1)
			MessageBox(mhwnd,textBox1->GetText(),"!!!", MB_OK);

		//ComboBox
		switch (HIWORD(wParam))
		{
			case CBN_SELCHANGE:
				{
					int index = comboBox1->GetSelectedIndexItem();
					//MessageBox(hwnd,comboBox1->GetSelectedItem(),"!!!", MB_OK);
					switch (index)
					{
					case 0:
						this->mbackground = CreateSolidBrush(0x00ff);
						break;
					case 1:
						this->mbackground = CreateSolidBrush(0);
						break;
					case 2:
						//this->mbackground = CreateSolidBrush(0);;
						break;
					}
				}
				InvalidateRect(hwnd,NULL, true);
			break;
		}

		break;
	}
	return WindowTemplate::RealWindowProc(hwnd,uMsg,wParam,lParam);
}
