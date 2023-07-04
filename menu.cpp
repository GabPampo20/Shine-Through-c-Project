#include "menu.h"

Menu::Menu()
{
	page=0;
	choice=0;
}

Menu::~Menu()
{

	
}

void Menu::startgame()
{	

	location local;
	ifstream ifile;
	
	system("cls");
	
	design.menuborder();
	
	design.gotoxy(76,13);
		cout<<"SHINE THROUGH";
	design.gotoxy(76,16);
		cout<<"1) Start Life";
	design.gotoxy(76,17);
		cout<<"2) Continue Life";
	design.gotoxy(76,18);
		cout<<"3) About Life";
	design.gotoxy(76,19);
		cout<<"4) Tutorial";
	design.gotoxy(76,20);
		cout<<"5) Rest";
	design.gotoxy(76,22);
		cout<<"CHOICE[";
	design.gotoxy(86,22);
		cout<<"]";
	design.gotoxy(84,22);
		cin>>choice;
	
	switch(choice)
	{
		case 1:
			
			ifile.open("life.txt");
   			
			if(ifile) 
			{
      			system("cls");
      			
      			design.menuborder();
      			
      			ifile.close();
				
				design.gotoxy(76,13);  
				cout<<"NOTICE:";
				design.gotoxy(65,16);
				cout<<"YOU ALREADY HAVE AN EXISTING SAVE FILE";
				design.gotoxy(60,17);
				cout<<"STARTING A NEW GAME WOULD OVERWRITE THE FILE";
				design.gotoxy(66,18);
				cout<<"ALL PROGRESS MADE WOULD BE LOST";
				design.gotoxy(65,20);
				cout<<"Continue? \t1)YES \t2)NO";
				design.gotoxy(76,22);
				cout<<"CHOICE[";
				design.gotoxy(86,22);
				cout<<"]";
				design.gotoxy(84,22);
				cin>>choice;
				
				switch(choice)
				{
					case 1:
						player.charCreate(player);
						gamePlay();
						break;
					case 2:
						startgame();
						break;
					default:
						cout<<"Invalid Input Choice";
						Sleep(1000);
						startgame();
				}
  			} 
			
			else 
			{
      			player.charCreate(player);
				gamePlay();
   			}
			
			break;
		case 2:
			feat.loadFile(player);
			if(player.safespace=="home") local.gm_home(player);
			else if(player.safespace=="school") local.gm_school(player);
			else if(player.safespace=="mall") local.gm_mall(player);
			else local.gm_park(player);
			break;
		case 3:
			about();
			break;
		case 4:
			feat.tutorial();
			about();
			break;
		case 5:
			exit(0);
		default:
			cout<<"Invalid Input";
			startgame();
	}
}

void Menu::gamePlay()
{
	system("cls");
	location local;
	
	local.gm_home(player);
	
}

void Menu::about()
{
	
	design.loading();
	
	system("cls");
	
	design.menuborder();
	design.gotoxy(78,13);
		cout<<"ABOUT PAGE";
	design.gotoxy(74,15);
		cout<<"1) About Mental Health";
	design.gotoxy(74,16);
		cout<<"2) About Mental Health Issues";
	design.gotoxy(74,17);
		cout<<"3) About Game";
	design.gotoxy(74,18);
		cout<<"4) Exit";
	design.gotoxy(76,20);
		cout<<"CHOICE[";
	design.gotoxy(86,20);
		cout<<"]";
	design.gotoxy(84,20);
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

void Menu::m_health()
{
	system("cls");
	
	cout<<"WHAT IS MENTAL HEALTH?";
	cin>>page;
}

void Menu::health_issue()
{
	design.loading();
	
	system("cls");
	
	design.menuborder();
	
	cout<<"MENTAL HEALTH ISSUES";
	cout<<"========================================";
	cout<<"1)What is Depression?";
	cout<<"2)What is Anxiety?";
	cout<<"3)Return to Previous Menu";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			depression_info();
			break;
		case 2:
			anxiety_info();
			break;
		case 3:
			about();
			break;
		default:
			cout<<"Invalid Input";
			health_issue();
	}
}

void Menu::gameInfo()
{
	system("cls");
	
	cout<<"SHINE THROUGH: A TEXT-BASED CHOOSE-YOUR-ADVENTURE GAME";
	
	system("pause");
	health_issue();
}

void Menu::depression_info()
{
	system("cls");
	
	cout<<"WHAT IS DEPRESSION";
	cin>>page;
}

void Menu::anxiety_info()
{
	system("cls");
	
	cout<<"WHAT IS ANXIETY ISSUES";
	cin>>page;
}

