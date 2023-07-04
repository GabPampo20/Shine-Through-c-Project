#pragma once

#include "response.h"

class Function
{
	private:
		int count;
		int choice;
		
		Response event;
		Design design;
		
	public:
		Function();
		virtual ~Function();
		
		string textfile;
		
		void loadFile(Character& player);

		void saveFile(Character& player);
		void deleteFile(Character& player);
		void tutorial();
		void dosage(Character& player);
		void hud(Character& player);
};
