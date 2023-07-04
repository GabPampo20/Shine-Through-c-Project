#pragma once

#include "character.h"

class Response
{
	private:
		Character user;
		
	public:
		Response();
		virtual ~Response();
		
		//Response
		void state(Character& player);
		//Endings
		void good_grad();
		void mid_grad();
		void bad_grad();
		void panic_end();
		void dead_end();
		void overdose();
		//Events
		void quiz(Character& player);
		void exam(Character& player);
		void gym(Character& player);
		
		void party(Character& player);
		void outing(Character& player);
		void prom_night(Character& player);
		void theraphy(Character& player);
};
