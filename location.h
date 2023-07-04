#pragma once

#include "function.h"
#include "menu.h"

class location
{
	private:
		int gm_choice;

		Function feat;
		Design design;
		Response event;
		
	public:
		location();
		virtual ~location();
		
	//LOCATIONs
		void gm_home(Character& player);
		void gm_street(Character& player);
		void gm_park(Character& player);	
		void gm_school(Character& player);
		void gm_mall(Character& player);
		
		void gameMenu(Character& player);
};
