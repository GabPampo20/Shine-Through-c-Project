#include "response.h"

Response::Response()
{
	
}

Response::~Response()
{
	
}
		
void Response::state(Character& player)
{
	if(player.issue=="Anxiety")
	{
		if(player.stress_lvl>20 && user.stress_lvl<=45)
		{
			player.stress_lvl+=15;
			player.hunger-=5;
		}
		else if(player.stress_lvl>45 && user.stress_lvl<=65)
		{
			player.stress_lvl+=20;
			player.hunger-=10;
		}
		else if(player.stress_lvl>65)
		{
			player.stress_lvl+=25;
			player.hunger-=15;
		}
	}
	
	else if(player.issue=="Depression")
	{
		if(player.stress_lvl>35 && user.stress_lvl<=55)
		{
			player.action--;
			player.hunger-=5;
		}
		else if(player.stress_lvl>55 && user.stress_lvl<=75)
		{
			player.action-=2;
			player.hunger-=10;
		}
		else if(player.stress_lvl>75)
		{
			player.action-=3;
			player.hunger-=15;
		}
	}
}

void Response::good_grad()
{
	system("cls");
	
	cout<<"After everything that has happened, all the quizzes, projects, classes, P.E sessions, ";
	Sleep(200);
	cout<<"and mental struggles, you now sit in the school's gymnasium with all of the other ";
	Sleep(200);
	cout<<"students. Just in front of you is an assembled stage decorated by banners, flowers ";
	Sleep(200);
}

void Response::mid_grad()
{
	system("cls");
	
	cout<<"After everything that has happened, all the quizzes, projects, classes, P.E sessions, ";
	Sleep(200);
	cout<<"and mental struggles, you now sit in the school's gymnasium with all of the other ";
	Sleep(200);
	cout<<"students. Just in front of you is an assembled stage decorated by banners, flowers ";
	Sleep(200);
}

void Response::bad_grad()
{
	system("cls");
	
	cout<<"After everything that has happened, all the quizzes, projects, classes, P.E sessions, ";
	Sleep(200);
	cout<<"and mental struggles, you now sit in the school's gymnasium with all of the other ";
	Sleep(200);
	cout<<"students. Just in front of you is an assembled stage decorated by banners, flowers ";
	Sleep(200);
}

void Response::panic_end()
{
	
}

void Response::dead_end()
{
	
}

void Response::overdose()
{
	
}

void Response::quiz(Character& player)
{
	cout<<"You took your weekly quiz";
	
	if(player.wisdom<100)
	{
		cout<<"Despite your best effort to answer questions, good or bad, you didn't manage to get a passing score.";
		player.hunger-=10;
		player.stress_lvl+=30;
		player.action-=2;
	}
	else if(player.wisdom>=100 && player.wisdom<130)
	{
		cout<<"With your best effort to answer questions, good or bad, you manage to barely got a passing score.";
		player.hunger-=10;
		player.stress_lvl+=20;
		player.action--;
	}
	else if(player.wisdom>=130 && player.wisdom<160)
	{
		cout<<"With your best effort to answer each question, you got a passing score.";
		player.hunger-=10;
		player.stress_lvl+=10;
	}
	else
	{
		cout<<"With suprising ease in answering each question, you got well over the passing score.";
		player.hunger-=10;
		player.stress_lvl+=10;
	}
	player.action-=3;
}

void Response::exam(Character& player)
{
	cout<<"You took your Departamental Exam";
	
	if(player.wisdom<120)
	{
		cout<<"Despite your best effort to each questions, good or bad, you didn't manage to get a passing score.";
		player.hunger-=10;
		player.stress_lvl+=30;
		player.action-=2;
	}
	else if(player.wisdom>=120 && player.wisdom<150)
	{
		cout<<"With your best effort to answer questions, good or bad, you manage to barely got a passing score.";
		player.hunger-=10;
		player.stress_lvl+=20;
		player.action--;
	}
	else if(player.wisdom>=150 && player.wisdom<170)
	{
		cout<<"With your best effort to answer each question, you got a passing score.";
		player.hunger-=10;
		player.stress_lvl+=10;
	}
	else
	{
		cout<<"With suprising ease in answering each question, you got well over the passing score.";
		player.hunger-=10;
		player.stress_lvl+=10;
	}
	
	player.hunger-=20;
	player.stress_lvl+=30;
	player.action-=6;
}

void Response::gym(Character& player)
{
	cout<<"You attended your P.E Class today. You didn't really paid attention to the class.";
	cout<<"Its usually just a practice of a dance pattern or a sports practice.";
	Sleep(500);
	player.fitness+=10;
	player.stress_lvl-=15;
	player.action-=2;
	player.hunger-=20;
}

void Response::party(Character& player)
{
	cout<<"While you are enjoying your food, a friend of yours in the school approached you with a smile.";
	cout<<"You simply smiled back and greeted them with your own flare of saying 'Hello'.";
	cout<<"They warmly greeted you back then promptly sitted right across you from the table.";
	cout<<"They then excitedly gave you a colored envelope. You curiously looked at it and then at your friend";
	cout<<"You then vaguely remembered that a rich friend of yours is having their birthday tommorow while slowly";
	cout<<" chewing your lunch. After swallowing your food, you then confirmed to your friend if that is the ";
	cout<<" invitation for the party tomorrow. They happily nodded and proceeded to ask if you're going to attend it.";
}

void Response::outing(Character& player)
{
	
}

void Response::prom_night(Character& player)
{
	
}

void Response::theraphy(Character& player)
{
	
}
