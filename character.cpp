#include "character.h"

Character::Character()
{
	this->name="";
	this->issue="";
	this->day_name="";
	this->day_time="";
	this->dress="";
	this->safespace="";
	this->place="";
	this->stress_lvl=15;
	this->max_stress=100;
	this->wisdom=70;
	this->fitness=20;
	this->hunger=10;
	this->max_hunger=75;
	this->m_issue=0;
	this->day_prog=1;
	this->week_count=0;
	this->action=12;
	this->panic=0;
	this->dosage=0;
}

Character::Character(string name,string issue, string dress,
		string safespace, string place, int stress_lvl,int max_stress,
		int wisdom,int fitness,int week_count,int day_prog,
		int action,int panic,int dosage)
{
	this->name=name;
	this->issue=issue;
	this->day_name=day_name;
	this->day_time=day_time;
	this->dress=dress;
	this->safespace=safespace;
	this->place=place;
	this->stress_lvl=stress_lvl;
	this->max_stress=max_stress;
	this->hunger=10;
	this->max_hunger=75;
	this->wisdom=wisdom;
	this->fitness=fitness;
	this->m_issue=m_issue;
	this->day_prog=1;
	this->week_count=0;
	this->action=action;
	this->panic=0;
	this->dosage=0;
}

Character::~Character()
{
	
}

void Character::charCreate(Character& player)
{
	
	design.loading();
	
	system("cls");

	design.infoborder();
	
	design.gotoxy(40,5);
		cout<<"What is your Name?";
	cin.ignore();
	design.gotoxy(59,5);
		getline(cin,name);
	design.gotoxy(40,7);
		cout<<"What are you going through, "<<name<<"?";
	design.gotoxy(44,8);
		cout<<"1) Anxiety Issues";
	design.gotoxy(44,9);
		cout<<"2) Depression";
	design.gotoxy(64,10);
		cout<<"CHOICE[";
	design.gotoxy(74,10);
		cout<<"]";
	design.gotoxy(72,10);
		cin>>m_issue;
	
	switch(m_issue)
	{
		case 1:
			issue="Anxiety";
			break;
		case 2:
			issue="Depression";
			break;
		default:
			cout<<"That mental health issue is unrecorded yet.Try Again.";
			system("pause");
			charCreate(player);
	}
	
	design.gotoxy(40,12);
		cout<<"Where is your safe place, "<<name<<"?";
	design.gotoxy(44,13);
		cout<<"1) Home";
	design.gotoxy(44,14);
		cout<<"2) School";
	design.gotoxy(44,15);
		cout<<"3) Super Mall";
	design.gotoxy(44,16);
		cout<<"4) City Park";
	design.gotoxy(54,16);
		cout<<"CHOICE[";
	design.gotoxy(64,16);
		cout<<"]";
	design.gotoxy(62,16);
		cin>>m_issue;
	
	switch(m_issue)
	{
		case 1:
			safespace="home";
			break;
		case 2:
			safespace="school";
			break;
		case 3:
			safespace="mall";
			break;
		case 4:
			safespace="park";
			break;
		default:
			cout<<"You haven't visted that place.Try Again.";
			system("pause");
			charCreate(player);
	}
	
	player.dress="pajama";
	
	player.cycle(player);

}

void Character::week(Character& player)
{
	if(day_prog==(1+(7*week_count)))
	{
		day_name="Monday";
	}
	else if(day_prog==(2+(7*week_count)))
	{
		day_name="Tuesday";
	}
	else if(day_prog==(3+(7*week_count)))
	{
		day_name="Wednesday";
	}
	else if(day_prog==(4+(7*week_count)))
	{
		day_name="Thursday";
	}
	else if(day_prog==(5+(7*week_count)))
	{
		day_name="Friday";
	}
	else if(day_prog==(6+(7*week_count)))
	{
		day_name="Saturday";
	}
	else if(day_prog==(7+(7*week_count)))
	{
		day_name="Sunday";
	}
}

void Character::cycle(Character& player)
{
	
	if(action>9)
	{
		day_time="Morning";
	}
	else if(action>6)
	{
		day_time="Noon";
	}
	else if(action>3)
	{
		day_time="Afternoon";
	}
	else if(player.action>0)
	{
		day_time="Evening";
	}
}

void Character::getString()
{
	to_string(stress_lvl);
	to_string(m_issue);
	to_string(week_count);
	to_string(day_prog);
	to_string(wisdom);
}
