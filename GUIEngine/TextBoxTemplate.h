#pragma once
#include <Windows.h>

#include "ControlTemplate.h"

namespace GUIEngine
{
	class TextBoxTemplate :
		public ControlTemplate
	{
	public:
		TextBoxTemplate(HWND parent, int id);
		~TextBoxTemplate(void);

		char* GetText ();
		void SetText(char* text);
		void AppendText(char* text);

	private:
		char* txt;
	};
}

