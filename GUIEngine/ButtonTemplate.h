#pragma once
#include <Windows.h>

#include "ControlTemplate.h"


class ButtonTemplate :
	public ControlTemplate
{
public:
	ButtonTemplate(HWND parent, int id);
	~ButtonTemplate(void);
};

