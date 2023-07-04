#pragma once

#include "design.h"

class Character
{
	private:
		
		Design design;
		
	public:
		Character();
		Character(string name,string issue, string dress,
		string safespace, string place, int stress_lvl,int max_stress,
		int wisdom,int fitness,int week_count,int day_prog,
		int action,int panic,int dosage);
		virtual ~Character();
		
		//STATS	
		string name;
		string issue;
		string day_name;
		string day_time;
		string dress;
		string safespace;
		string place;
		int stress_lvl;
		int max_stress;
		int m_issue;
		int wisdom;
		int grade;
		int fitness;
		int hunger;
		int max_hunger;
		int week_count;
		int day_prog;
		int action;
		int panic;
		int dosage;
		
		//FUNCTIONS
		void charCreate(Character& player);
		void week(Character& player);
		void cycle(Character& player);
		void getString();
};
