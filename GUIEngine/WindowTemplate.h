#pragma once
#include <Windows.h>

namespace GUIEngine
{
	class WindowTemplate
	{
	public:
		WindowTemplate(HINSTANCE hInstance, LPCSTR windowName, HWND parent);
		virtual ~WindowTemplate(void);
		void Show(int cmd);

	private:
		void createWindow(HINSTANCE hInstance, LPCSTR windowName, HWND parent);
		virtual void OnCreate() = NULL;
		static LRESULT WINAPI WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	protected:
		virtual LRESULT RealWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		HWND mhwnd;
		HBRUSH mbackground;
	};
}

