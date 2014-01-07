#include "TextBoxTemplate.h"


TextBoxTemplate::TextBoxTemplate(HWND parent, int id) : ControlTemplate(parent, id)
{
	txt = NULL;
}
TextBoxTemplate::~TextBoxTemplate(void)
{
	if (txt)
		delete txt;
}

char* TextBoxTemplate::GetText()
{
	if (txt)
	{
		delete(txt);
		txt = NULL;
	}

	int count = SendMessage(mhwnd, EM_GETLINECOUNT, 0, 0);
	if (count)
	{
		int len = count;
		if (count == 1)
		{
			len = SendMessage(mhwnd,EM_LINELENGTH,0,0);
			if (len)
			{
				txt = new char[len + 1];
				txt[len] = 0;
				SendMessage(mhwnd, WM_GETTEXT, len + 1, (LPARAM)txt);
				return txt;
			}
			return "";
		}

		for (int i = 0; i < count; i++)
		{
			len += SendMessage(mhwnd, EM_LINELENGTH, SendMessage(mhwnd, EM_LINEINDEX, i, 0), 0);
		}

		txt = new char[len + 1];
		((WORD*)txt)[0] = len + 1;
		txt[len] = 0;

		for (int i = 0; i < count; i++)
		{
			int currentLen = SendMessage(mhwnd, EM_LINELENGTH, SendMessage(mhwnd, EM_LINEINDEX, i, 0), 0);
			SendMessage(mhwnd, EM_GETLINE, i, (LPARAM)txt);
			txt[currentLen] = '\n';
			txt += currentLen + 1;
		}

		txt -= len;
		//((WORD*)txt)[0] = len + 1;
		//SendMessage(mhwnd, EM_GETLINE, 0, (LPARAM)txt);
		return txt;
	}
	return "";
}
void TextBoxTemplate::SetText(char* text)
{
	SendMessage(mhwnd, WM_SETTEXT, 0, (LPARAM)text);
}
void TextBoxTemplate::AppendText(char* text)
{
	DWORD start, end = 0;
	SendMessage(mhwnd,EM_GETSEL, (WPARAM)&start, (LPARAM)&end);
	int len = GetWindowTextLength(mhwnd);
	SendMessage(mhwnd, EM_SETSEL, len, len);
	SendMessage(mhwnd, EM_REPLACESEL, true, (LPARAM)text);
	SendMessage(mhwnd,EM_SETSEL, start, end);
}
