#pragma once
#include <Windows.h>

#include "ControlTemplate.h"

namespace GUIEngine
{
	class ButtonTemplate :
		public ControlTemplate
	{
	public:
		ButtonTemplate(HWND parent, int id);
		~ButtonTemplate(void);
	};
}

