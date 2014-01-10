#include "ComboBoxTemplate.h"

namespace GUIEngine
{
	ComboBoxTemplate::ComboBoxTemplate(HWND parent, int id) : ControlTemplate(parent, id)
	{
		txt = NULL;
	}
	ComboBoxTemplate::~ComboBoxTemplate(void)
	{
		if (txt)
		{
			delete txt;
			txt = NULL;
		}
	}

	void ComboBoxTemplate::AddItem(char* str)
	{
		SendMessage(mhwnd, CB_ADDSTRING,0,(LPARAM)str);
	}
	int ComboBoxTemplate::GetSelectedIndexItem()
	{
		return SendMessage(mhwnd, CB_GETCURSEL, 0, 0);
	}
	char* ComboBoxTemplate::GetSelectedItem()
	{
		if (SendMessage(mhwnd, CB_GETCURSEL, 0, 0) == -1)
			return "";

		int len = SendMessage(mhwnd, CB_GETLBTEXT, SendMessage(mhwnd, CB_GETCURSEL, 0, 0), 0);
		txt = new char[len + 1];
		txt[len] = 0;
		SendMessage(mhwnd,CB_GETLBTEXT, SendMessage(mhwnd, CB_GETCURSEL, 0, 0), (LPARAM)txt);
		return txt;
	}
}