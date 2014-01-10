#pragma once
#include "ControlTemplate.h"

namespace GUIEngine
{
	class ComboBoxTemplate :
		public ControlTemplate
	{
	public:
		ComboBoxTemplate(HWND parent, int id);
		~ComboBoxTemplate(void);

		void AddItem(char* str);
		char* GetSelectedItem();
		int GetSelectedIndexItem();

	private:
		char* txt;
	};
}
