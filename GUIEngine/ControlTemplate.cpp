#include "ControlTemplate.h"

namespace GUIEngine
{
	ControlTemplate::ControlTemplate(HWND parent, int id)
	{
		mhwnd = GetDlgItem(parent, id);
		mparent = parent;
	}
	ControlTemplate::~ControlTemplate(void)
	{
	}

	HWND ControlTemplate::GetHandle()
	{
		return this->mhwnd;
	}
	HWND ControlTemplate::GetParent()
	{
		return this->mparent;
	}
	int ControlTemplate::GetID()
	{
		return this->mid;
	}
	void ControlTemplate::SetFont(HFONT font)
	{
		SendMessage(mhwnd, WM_SETFONT, (WPARAM)font, true);
	}
	HFONT ControlTemplate::GetFont()
	{
		return (HFONT)SendMessage(mhwnd,WM_GETFONT,0,0);
	}
	RECT ControlTemplate::GetPosition()
	{
		RECT rect = {0};
		GetWindowRect(mhwnd,&rect);
		POINT p1 = {rect.left, rect.top};
		POINT p2 = {rect.right, rect.bottom};
		ScreenToClient(mhwnd, &p1);
		ScreenToClient(mhwnd, &p2);

		rect.left = p1.x;
		rect.top = p1.y;
		rect.right = p2.x;
		rect.bottom = p2.y;

		return rect;
	}
}