#include "function.h"

Function::Function()
{
	count=1;
	choice=0;
	textfile="life.txt";

}

Function::~Function()
{
	
}

void Function::saveFile(Character& player)
{
	ofstream save;
	
	save.open(textfile);
	save<<count<<endl;
	for(int i=0;i<count;i++)
	{
		save<<player.name<<",";
		save<<player.issue<<",";
		save<<player.dress<<",";
		save<<player.safespace<<",";
		save<<player.day_prog<<",";
		save<<player.action<<",";
		save<<player.stress_lvl<<",";
		save<<player.max_stress<<",";
		save<<player.panic<<",";
		save<<player.dosage<<",";
		save<<player.wisdom<<",";
		save<<player.grade<<",";
		save<<player.fitness<<",";
		save<<player.hunger<<",";
		save<<player.max_hunger<<",";
		save<<player.week_count<<endl;
	}
	save.close();
}

void Function::loadFile(Character& player)
{
	ifstream load;

	string prog;
	string moves;
	string stress;
	string mx_stress;
	string panic_lvl;
	string dose;
	string intelligence;
	string grading;
	string dex;
	string food;
	string food_limit;
	string w_count;
		
	load.open(textfile);
	load>>count;
	load.ignore();
	
	for(int i=0;i<count;i++)
	{
		getline(load,player.name,',');
		getline(load,player.issue,',');
		getline(load,player.dress,',');
		getline(load,player.safespace,',');
		
		getline(load,prog,',');
		getline(load,moves,',');
		getline(load,stress,',');
		getline(load,mx_stress,',');
		getline(load,panic_lvl,',');
		getline(load,dose,',');
		getline(load,intelligence,',');
		getline(load,grading,',');
		getline(load,dex,',');
		getline(load,food,',');
		getline(load,food_limit,',');
		getline(load,w_count,',');
		
		player.day_prog = stoi(prog);
		player.action = stoi(moves);
		player.stress_lvl = stoi(stress);
		player.max_stress = stoi(mx_stress);
		player.panic = stoi(panic_lvl);
		player.dosage = stoi(dose);
		player.wisdom = stoi(intelligence);
		player.grade = stoi(grading);
		player.fitness = stoi(dex);
		player.hunger = stoi(food);
		player.max_hunger = stoi(food_limit);
		player.week_count = stoi(w_count);
	}
	
	load.close();

}

void Function::tutorial()
{
	system("cls");
	
	cout<<"TUTORIAL";
	
	system("pause");
	
}

void Function::hud(Character& player)
{
	player.week(player);
	
	design.gotoxy(5,39);
		cout<<"DAY "<<player.day_prog<<" ";
		cout<<player.day_name<<" ";
		cout<<"TIME: "<<player.day_time<<" ";
		cout<<"Stress LVL:"<<player.stress_lvl<<" / "<<player.max_stress<<" ";
		cout<<"HUNGER: "<<player.hunger<<" / "<<player.max_hunger<<" ";
		cout<<"KNOWLEDGE: "<<player.wisdom<<" ";
		cout<<"FITNESS: "<<player.fitness<<" ";
		cout<<"Action: "<<player.action<<" ";
}

void Function::dosage(Character& player)
{
	if(player.dosage<5 && player.dosage>2)
	{
		cout<<"You woke up still groggy, but not feeling great.";
		Sleep(300);
		cout<<"You feel your stomach grumble and start to feel naseaus.";
		Sleep(400);
		cout<<"You rushed to the nearest bathroom and vomitted in the toilet";
		Sleep(600);
		
		player.dosage=0;
		player.stress_lvl+=45;
		player.action-=2;
	}
	else if(player.dosage>=5)
	{
		event.overdose();
	}
}

void Function::deleteFile(Character& player)
{
	
}
