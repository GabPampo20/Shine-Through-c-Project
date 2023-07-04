#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

//DESIGNS
void menuborder();
void gotoxy(int x,int y);
void loading();
//MENU
void startgame();
void charCreate();
void loadFile();
void about();
void tutorial();
void gamePlay();
//ABOUT
void m_health();
void health_issue();
void gameInfo();
void adhd_info();
void ocd_info();
void anger_info();
//LOCATIONs
void gm_home();
void gm_street();
void gm_park();	
void gm_school();
void gm_mall();

int main()
{
	system("cls");
	system("color 3c");
	startgame();
	menuborder();
}


void gotoxy(int x,int y)
{
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

void menuborder()
{
	int x=0,style=220;

	for (x=30;x<=90;x++)//horizontal
	{
		gotoxy(x,3);
		printf ("%c",style);
		gotoxy (x,25);
		printf ("%c",style);
	}
	
	int y=0;
	
	for (y=4;y<=25;y++)//vertical
	{
		gotoxy (30,y);
		printf ("%c",style);
		gotoxy (90,y);
		printf ("%c",style);
	}
}

void loading()
{
	int load=0;
	system("cls");
	gotoxy(52,14);
	cout<<"THINKING\n\t\t\t ";

	for(;load<30;load++)
	{
		cout<<"±";
		Sleep(150);
	}
}

void startgame()
{
	int choice;
	
	gotoxy(54,8);
	cout<<"SHINE THROUGH";
	gotoxy(54,15);
	cout<<"1) Start Life";
	gotoxy(54,16);
	cout<<"2) Continue Life";
	gotoxy(54,17);
	cout<<"3) About Life";
	gotoxy(54,18);
	cout<<"4) Tutorial";
	gotoxy(54,19);
	cout<<"5) Rest";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			charCreate();
			break;
		case 2:
			loadFile();
			break;
		case 3:
			about();
			break;
		case 4:
			tutorial();
			break;
		case 5:
			exit(0);
		default:
			cout<<"Invalid Input";
			startgame();
	}
}

void charCreate()
{
	string name="";
	int issue=0;
	
	system("cls");
	
	cout<<"What is your Name?";
	getline(cin,name);
	cout<<"What are you going through?";
	cout<<"\t1) A.D.H.D";
	cout<<"\t2) 0.C.D";
	cout<<"\t3) Anxiety Disorder";
	cin>>issue;
	cin.ignore();
	
	gamePlay();
}

void loadFile()
{
}

void about()
{
	int choice;
	
	system("cls");
	
	loading();
	
	cout<<"ABOUT PAGE";
	cout<<"\t1) About Mental Health";
	cout<<"\t2) About Mental Health Issues";
	cout<<"\t3) About Game";
	cout<<"\t4) Exit";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			m_health();
			break;
		case 2:
			health_issue();
			break;
		case 3:
			gameInfo();
			break;
		case 4:
			startgame();
			break;
		default:
			cout<<"Invalid Input";
			about();
	}
}

void tutorial()
{
	system("cls");
	
	cout<<"TUTORIAL";
	
	system("pause");
}

void gamePlay()
{
	system("cls");
	
	gm_home();
}

void m_health()
{
	system("cls");
	
	int page=0;
	
	cout<<"WHAT IS MENTAL HEALTH";
	cin>>page;
}

void health_issue()
{
	system("cls");
	
	int choice=0;
	
	cout<<"MENTAL HEALTH ISSUES";
	cout<<"========================================";
	cout<<"\t1)What is A.D.H.D?";
	cout<<"\t2)What is O.C.D?";
	cout<<"\t3)What is Anger Issues?";
	cout<<"\t4)Return to Previous Menu";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			adhd_info();
			break;
		case 2:
			ocd_info();
			break;
		case 3:
			anger_info();
			break;
		case 4:
			about();
			break;
		default:
			cout<<"Invalid Input";
			health_issue();
	}
}

void gameInfo()
{
	system("cls");
	
	cout<<"SHINE THROUGH: A TEXT-BASED CHOOSE-YOUR-ADVENTURE GAME";
	
	system("pause");
	health_issue();
}

void adhd_info()
{
	system("cls");
	
	int page=0;
	
	cout<<"WHAT IS ATTENTION DEFICIT HYPER-DISORDER";
	cin>>page;
}

void ocd_info()
{
	system("cls");
	
	int page=0;
	
	cout<<"WHAT IS OBSESSIVE-COMPULSIVE DISORDER";
	cin>>page;
}

void anger_info()
{
	system("cls");
	
	int page=0;
	
	cout<<"WHAT IS ANGER ISSUES";
	cin>>page;
}

void gm_home()
{
	system("cls");
	
	int gm_choice=0;
	
	cout<<"You are at Home";
	cout<<"What are you going to do?";
	cout<<"\t1)Medicine";
	cout<<"\t2)Clothes";
	cout<<"\t3)Breakfast";
	cout<<"\t4)Go outisde";
	cin>>gm_choice;
	
	switch(gm_choice)
	{
		case 1:
			cout<<"You drank your prescription";
			break;
		case 2:
			cout<<"You changed clothes";
			break;
		case 3:
			cout<<"You ate breakfast";
			break;
		case 4:
			gm_street();
			break;
		default:
			cout<<"Invalid Input";
			gm_home();
	}
}

void gm_street()
{
	system("cls");
	
	int gm_choice=0;
	
	cout<<"You are outside";
	cout<<"What are you going to do?";
	cout<<"\t1)Home";
	cout<<"\t2)School";
	cout<<"\t3)Mall";
	cout<<"\t4)Park";
	cin>>gm_choice;
	
	switch(gm_choice)
	{
		case 1:
			gm_home();
			break;
		case 2:
			gm_school();
			break;
		case 3:
			gm_mall();
			break;
		case 4:
			gm_park();
			break;
		default:
			cout<<"Invalid Input";
			gm_street();
	}
}

void gm_park()
{
	system("cls");
	
	int gm_choice=0;
	
	cout<<"You are at the city park";
	cout<<"What are you going to do?";
	cout<<"\t1)Enjoy the Scenery";
	cout<<"\t2)Exercise";
	cout<<"\t3)Walk";
	cout<<"\t4)Leave";
	
	cin>>gm_choice;
	
	switch(gm_choice)
	{
		case 1:
			cout<<"You sat and watched your surroundings";
			break;
		case 2:
			cout<<"You exercised";
			break;
		case 3:
			cout<<"You walked around the park";
			break;
		case 4:
			gm_street();
			break;
		default:
			cout<<"Invalid Input";
			gm_park();
	}
}

void gm_school()
{
	system("cls");
	
	int gm_choice=0;
	
	cout<<"You are your school";
	cout<<"What are you going to do?";
	cout<<"\t1)Chat with Friends";
	cout<<"\t2)Go to Class";
	cout<<"\t3)Library";
	cout<<"\t4)Leave";
	cin>>gm_choice;
	
	switch(gm_choice)
	{
		case 1:
			cout<<"You chatted with your friends";
			break;
		case 2:
			cout<<"You listened through your class";
			break;
		case 3:
			cout<<"You entered the library";
			break;
		case 4:
			gm_street();
			break;
		default:
			cout<<"Invalid Input";
			gm_school();
	}
}

void gm_mall()
{
	system("cls");
	
	int gm_choice=0;
	
	cout<<"You are the city mall";
	cout<<"What are you going to do?";
	cout<<"\t1)Pharmacy";
	cout<<"\t2)Arcade";
	cout<<"\t3)Restaurant";
	cout<<"\t4)Supermarket";
	cout<<"\t5)Department Store";
	cout<<"\t6)Chill Out";
	cout<<"\t7)Leave";
	cin>>gm_choice;
	
	switch(gm_choice)
	{
		case 1:
			cout<<"You purchased more medicine";
			break;
		case 2:
			cout<<"You played several games";
			break;
		case 3:
			cout<<"You ate at a restaurant";
			break;
		case 4:
			cout<<"You entered the Market";
			break;
		case 5:
			cout<<"You entered the Department Store";
			break;
		case 6:
			cout<<"You walked around the mall, enjoying the stores";
			break;
		case 7:
			gm_street();
			break;
		default:
			cout<<"Invalid Input";
			gm_mall();
	}
}

