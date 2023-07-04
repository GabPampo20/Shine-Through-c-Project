#pragma once

#include "LIBRARIES.h"

class Design
{
	private:
		int load;
		int x;
		int y;
		int style;
		
	public:
	//DESIGNS
		Design();
		virtual ~Design();
		
		void menuborder();
		void infoborder();
		void gameborder();
		void gotoxy(int x,int y);
		void loading();
};
