#pragma once
#include <Windows.h>

namespace GUIEngine
{
	class ControlTemplate
	{
	public:
		ControlTemplate(HWND parent, int id);
		virtual ~ControlTemplate(void);

		HWND GetHandle();
		HWND GetParent();
		int GetID();
		RECT GetPosition();
		void SetFont (HFONT font);
		HFONT GetFont ();
	protected:
		HWND mhwnd;
		HWND mparent;
		int mid;
	};
}

