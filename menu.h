#pragma once

#include "location.h"

class Menu
{
	private:
		int page;
		int choice;
		
		Design design;
		Character player;
		Function feat;
		
	public:
		Menu();
		virtual ~Menu();

		void startgame();
		void gamePlay();
		void about();
		void m_health();
		void health_issue();
		void gameInfo();
		void depression_info();
		void anxiety_info();
};
