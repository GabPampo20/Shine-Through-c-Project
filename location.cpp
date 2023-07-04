#include "location.h"

location::location()
{
	gm_choice=0;
}

location::~location()
{
	
}

void location::gm_home(Character& player)
{
	system("cls");
	
	design.gameborder();
	
	player.place="home";
	
	player.cycle(player);
	
	feat.hud(player);
	
	if(player.stress_lvl>=player.max_stress)
	{
		player.panic++;
		player.stress_lvl==player.max_stress;
	}
	
	design.gotoxy(7,4);
	cout<<"You are at Home ";
	cout<<"What are you going to do?";
	cout<<"\t1)Mitigate Stress";
	cout<<"\t2)Change Clothes";
	cout<<"\t3)Eat";
	cout<<"\t4)Write in Diary";
	cout<<"\t5)Sleep";
	cout<<"\t6)Go outisde";
	cin>>gm_choice;
	
	switch(gm_choice)
	{
		case 1:
			if(player.issue=="Anxiety")
			{
				cout<<"You did the meditation routine that the psycologist recommended to you.";
				cout<<"You then drank a vitamin supplement prescribed to you.";
				Sleep(1000);
				player.fitness+=5;
				player.dosage++;
				player.stress_lvl-=15;
			}
			
			else if (player.issue=="Depression")
			{
				cout<<"You drank a pill of your prescription medicine.";
				cout<<"You then did the meditation routine that the psycologist recommended to you.";
				Sleep(1000);
				player.dosage++;
				player.fitness+=5;
				player.stress_lvl-=15;
			}
			event.state(player);
			
			gm_home(player);
			break;
			
		case 2:

			cout<<"Change clothes to?";
			cout<<"1.Uniform";
			cout<<"2.Casual";
			cout<<"3.Pajama";
			cout<<"CHOICE[";
			cout<<"]";
			cin>>gm_choice;
			
			switch(gm_choice)
			{
				case 1:
					if(player.dress=="uniform")
					{
						cout<<"But I'm already wearing my uniform.";
						Sleep(500);
						player.stress_lvl+=10;
						event.state(player);
						gm_home(player);
					}
					player.dress="uniform";
					cout<<"I changed into my uniform";
					Sleep(500);
					gm_home(player);
					break;
				case 2:
					if(player.dress=="casual")
					{
						cout<<"But I'm already wearing new casual clothes.";
						Sleep(500);
						player.stress_lvl+=10;
						event.state(player);
						gm_home(player);
					}
					player.dress="casual";
					cout<<"I changed into my casual clothes";
					Sleep(500);
					gm_home(player);
					break;
				case 3:
					if(player.dress=="pajama")
					{
						cout<<"I'm already wearing a pajama. Why would I change into another one?";
						Sleep(700);
						player.stress_lvl+=10;
						event.state(player);
						gm_home(player);
					}
					else
					{
						if(player.action>3 || player.day_time!="Evening")
						{
							cout<<"I'm not tired yet and besides it is still too early in the day.";
							Sleep(700);
							gm_home(player);
						}
						player.dress="pajama";
						cout<<"I changed into my pajama";
						Sleep(500);
						gm_home(player);
					}
					break;
				default:
					cout<<"I don't have those clothes";
					system("pause>0");
					gm_home(player);
			}
			
			break;
			
		case 3:
			
			cout<<"You ate food";
			system("pause>0");
			player.stress_lvl+=10;
			
			event.state(player);
			
			gm_home(player);
			break;
			
		case 4:
			
			if(player.safespace!=player.place)
			{
				cout<<"I'm uncomfortable to write here.";
				Sleep(3000);
				player.stress_lvl+=15;
				gm_home(player);
			}
			else gameMenu(player);
			break;
			
		case 5:
			
			if(player.dress=="uniform" || player.dress=="casual")
			{
				cout<<"I need to change clothes.Can't sleep out of my pajamas";
				system("pause>0");
				gm_home(player);
			}
			else
			{
				cout<<"You go back to bed and drifted into sleep";
				player.stress_lvl-=35;
				player.day_prog++;
				player.action=12;
				event.state(player);
				feat.dosage(player);
				player.dosage=0;
				Sleep(500);
				gm_home(player);
			}	
			break;
			
		case 6:
			
			if(player.dress=="pajama")
			{
				cout<<"I can't go out in my pajamas";
				player.stress_lvl+=5;
				Sleep(900);	
				gm_home(player);
			}
			if(player.action==0)
			{
				cout<<"I can't go out now. I'm exhausted and it's already night.";
				Sleep(500);
				gm_home(player);
			}
			
			gm_street(player);
			break;
			
		default:
			cout<<"That's something I can't do in the house";
			Sleep(500);
			player.stress_lvl-=5;
			gm_home(player);
	}
}

void location::gm_street(Character& player)
{
	system("cls");
	
	design.gameborder();
	
	player.cycle(player);
	
	feat.hud(player);
	
	design.gotoxy(7,4);
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
			gm_home(player);
			break;
		case 2:
			if(player.day_time=="Evening")
			{
				cout<<"School is already closed. I better not go there.";
				system("pause");
				gm_street(player);
			}
			else if(player.dress!="uniform")
			{
				gm_street(player);
			}
			else gm_school(player);
			break;
		case 3:
			gm_mall(player);
			break;
		case 4:
			gm_park(player);
			break;
		default:
			cout<<"I haven't been there yet. I wonder if I can find it.";
			Sleep(500);
			cout<<"I can't find the place";
			player.stress_lvl+=20;
			player.action-=3;
			system("pause");
			gm_street(player);
	}
}

void location::gm_park(Character& player)
{
	system("cls");
	
	design.gameborder();
	
	player.cycle(player);
	
	player.place="park";
	
	feat.hud(player);
	
	design.gotoxy(7,4);
	cout<<"You are at the city park";
	cout<<"What are you going to do?";
	cout<<"\t1)Enjoy the Scenery";
	cout<<"\t2)Exercise";
	cout<<"\t3)Walk";
	cout<<"\t4)Write in Diary";
	cout<<"\t5)Leave";
	
	cin>>gm_choice;
	
	if(player.action==0)
	{
		cout<<"Its already late. I better go home now.";
		Sleep(500);
		gm_home(player);
	}
	
	switch(gm_choice)
	{
		case 1:
			cout<<"You sat and watched your surroundings";
			system("pause");
			player.stress_lvl-=10;
			event.state(player);
			player.action--;
			
			event.state(player);
			
			gm_park(player);
			break;
		case 2:
			cout<<"You exercised";
			system("pause");
			player.stress_lvl-=15;
			player.fitness+=15;
			player.hunger-=10;
			player.max_hunger+=5;
			event.state(player);
			player.action--;
			
			event.state(player);
			
			gm_park(player);
			break;
		case 3:
			cout<<"You walked around the park";
			system("pause");
			player.stress_lvl-=10;
			player.hunger-=5;
			player.fitness+=5;
			player.action-=2;
			
			event.state(player);
			
			gm_park(player);
			break;
		case 4:
			if(player.safespace!=player.place)
			{
				cout<<"I'm uncomfortable to write here.";
				system("pause");
				player.stress_lvl+=15;
				gm_park(player);
			}
			else gameMenu(player);
			break;
		case 5:
			gm_street(player);
			break;
		default:
			cout<<"That's a new spot at the park. I if I can find it.";
			Sleep(400);
			cout<<"It is not in the park";
			player.stress_lvl+=20;
			player.fitness+=10;
			player.action-=2;
			Sleep(400);
			gm_park(player);
	}
}

void location::gm_school(Character& player)
{
	Menu menu;
	
	system("cls");
	
	design.gameborder();
	
	player.cycle(player);
	
	player.place="school";
	
	feat.hud(player);
	
	if(player.day_prog==100)
	{
		if(player.stress_lvl<=25)
		{
			event.good_grad();
			menu.startgame();
		}
		
		else if(player.stress_lvl>25 && player.stress_lvl<=50)
		{
			event.mid_grad();
			menu.startgame();
		}
		
		else 
		{
			event.bad_grad();
			menu.startgame();
		}
	}
	
	else if(player.day_prog==83)
	{
		event.prom_night(player);
		gm_home(player);
	}
	
	else if(player.action==3 || player.day_name=="Saturday" || player.day_name=="Sunday")
	{
		cout<<"School is already closed. Everyone has gone home. I better go home too.";
		Sleep(700);
		gm_home(player);
	}
	
	design.gotoxy(7,4);
	cout<<"You are at your school";
	
	design.gotoxy(10,9);
	cout<<"What are you going to do?";
	design.gotoxy(10,10);
	cout<<"1)Chat with Friends";
	design.gotoxy(10,11);
	cout<<"2)Go to Class";
	design.gotoxy(10,12);
	cout<<"3)Library";
	design.gotoxy(20,10);
	cout<<"4)Gymnasium";
	design.gotoxy(20,11);
	cout<<"5)Cafeteria";
	design.gotoxy(20,12);
	cout<<"6)Leave";
	cin>>gm_choice;
	
	switch(gm_choice)
	{
		case 1:
			cout<<"You chatted with your friends";
			Sleep(2000);
			player.stress_lvl-=10;
			event.state(player);
			player.action--;
			gm_school(player);
			break;
			
		case 2:
			if(player.day_name=="Friday" && player.day_time=="Morning")
			{
				event.quiz(player);
				event.state(player);
				gm_school(player);
			}
			else if(player.day_prog==85 && player.day_prog==89)
			{
				if(player.action>=6)
				{
					event.exam(player);
					event.state(player);
					gm_school(player);
				}
				else
				{
					cout<<"The examinations today is over. I'm not taking it again today.";
					Sleep(1000);
					gm_school(player);
				}
				
			}
			else
			{
				cout<<"You listened through your classes";
				Sleep(400);
				player.stress_lvl+=25;
				player.wisdom+=10;
				player.hunger-=15;
				event.state(player);
				player.action-=2;
				gm_school(player);
			}
			
			break;
			
		case 3:
			cout<<"You entered the library";
			cout<<"1)Read Books";
			cout<<"2)Write in Diary";
			cin>>gm_choice;
			
			switch(gm_choice)
			{
				case 1:
					cout<<"You read books of different subjects";
					system("pause>0");
					player.hunger-=10;
					event.state(player);
					player.wisdom+=2;
					gm_school(player);
					break;
				case 2:
					if(player.safespace!=player.place)
					{
						cout<<"I'm uncomfortable to write here.";
						player.stress_lvl+=15;
						system("pause>0");
						gm_school(player);
					}
					else gameMenu(player);
					break;
					
				default:
					cout<<"I can't do that in the library.";
					player.stress_lvl+=5;
					Sleep(500);
					gm_school(player);
			}
			break;
			
		case 4:
			event.gym(player);
			
			event.state(player);
			
			gm_school(player);
			break;
			
		case 5:
			if(player.day_prog==27)
			{
				system("cls");
				design.gotoxy(5,5);
				cout<<"While you are enjoying your food, a friend of yours in the school approached you with a smile.";
				cout<<"You simply smiled back and greeted them with your own flare of saying 'Hello'.";
				Sleep(1000);
				cout<<"They warmly greeted you back then promptly sitted right across you from the table.";
				cout<<"They then excitedly gave you a colored envelope. You curiously looked at it and then at your friend";
				Sleep(1000);
				cout<<"You then vaguely remembered that a rich friend of yours is having their birthday tommorow while slowly";
				cout<<" chewing your lunch. After swallowing your food, you then confirmed to your friend if that is the ";
				Sleep(1000);
				cout<<" invitation for the party tomorrow. They happily nodded and proceeded to ask if you're going to attend it.";
				
				system("color 4f");
				
				cin>>gm_choice;
				
				system("color 79");
				
				switch(gm_choice)
				{
					case 1:
						event.party(player);
						break;
					case 2:
						design.gotoxy(5,5);
						cout<<"You declined the offer and politely said that you are just going to stay home instead";
						Sleep(1000);
						break;
						
				}
			}
			cout<<"You ate in the cafeteria";
			Sleep(500);
			player.stress_lvl-=10;
			player.hunger+=15;
			player.action--;
			
			event.state(player);
			
			gm_school(player);
			break;
		case 6:
			if(player.action!=4)
			{
				cout<<"I can't go out yet. School is not over.";
			}
			gm_street(player);
			break;
		default:
			cout<<"I haven't been to that place. Maybe I passed it before?";
			Sleep(500);
			cout<<"It's not in the school";
			player.stress_lvl+=20;
			player.fitness+=5;
			player.hunger-=10;
			player.action-=2;
			event.state(player);
			system("pause>0");
			gm_school(player);
	}
}

void location::gm_mall(Character& player)
{
	event.state(player);
	
	system("cls");
	
	design.gameborder();
	
	player.cycle(player);
	
	
	player.place="mall";
	
	feat.hud(player);
	
	cout<<"You are the city mall";
	cout<<"What are you going to do?";
	cout<<"\t1)Pharmacy";
	cout<<"\t2)Arcade";
	cout<<"\t3)Restaurant";
	cout<<"\t4)Supermarket";
	cout<<"\t5)Department Store";
	cout<<"\t6)Chill Out";
	cout<<"\t7)Write In Diary";
	cout<<"\t8)Leave";
	
	cin>>gm_choice;
	
	if(player.action==0)
	{
		cout<<"The mall is already closing. I better go home now.";
		gm_home(player);
	}
	
	switch(gm_choice)
	{
		case 1:
			cout<<"You purchased more of your prescription meds.";
			player.action--;
			player.stress_lvl+=10;
			player.hunger-=5;
			
			event.state(player);
			
			Sleep(1000);
			gm_mall(player);
			break;
		case 2:
			cout<<"You played several games";
			player.action--;
			player.stress_lvl-=10;
			player.wisdom-=5;
			player.hunger-=10;
			
			event.state(player);
			
			Sleep(1000);
			gm_mall(player);
			break;
		case 3:
			cout<<"You ate at a restaurant";
			Sleep(1000);
			player.action--;
			player.stress_lvl-=10;
			player.hunger+=20;
			
			event.state(player);
			
			gm_mall(player);
			break;
		case 4:
			cout<<"You entered the Market";
			player.action--;
			player.stress_lvl-=10;
			player.hunger-=10;
			
			event.state(player);
			
			Sleep(1000);
			gm_mall(player);
			break;
		case 5:
			cout<<"You entered the Department Store. Despite not having any extra money, you window shopped";
			player.action--;
			player.stress_lvl-=10;
			player.hunger-=10;
			
			event.state(player);
			
			Sleep(1000);
			gm_mall(player);
			break;
		case 6:
			cout<<"You walked around the mall, enjoying the stores";
			player.action--;
			player.stress_lvl-=10;
			player.hunger-=15;
			
			event.state(player);
			
			Sleep(1000);
			gm_mall(player);
			break;
		case 7:
			if(player.safespace!=player.place)
			{
				cout<<"I'm uncomfortable to write here.";
				system("pause");
				player.stress_lvl+=15;
				gm_mall(player);
			}
			else gameMenu(player);
			break;
		case 8:
			gm_street(player);
			break;
		default:
			cout<<"Is that a new store in the mall?";
			Sleep(1000);
			cout<<"I can't find that store.";
			system("pause");
			player.stress_lvl+=20;
			player.fitness+=10;
			player.hunger-=10;
			player.action-=2;
			
			event.state(player);
			
			gm_mall(player);
	}
}

void location::gameMenu(Character& player)
{

	Menu menu;
		
	system("cls");
	
	design.menuborder();
	
	design.gotoxy(54,8);
		cout<<"DIARY MENU";
	design.gotoxy(50,14);
		cout<<"1) Save Day";
	design.gotoxy(50,15);
		cout<<"2) Tutorial";
	design.gotoxy(50,16);
		cout<<"3) Take a Rest";
	design.gotoxy(50,17);
		cout<<"4) Go Back";
		
	design.gotoxy(54,18);
		cout<<"CHOICE[";
	design.gotoxy(64,18);
		cout<<"]";
	design.gotoxy(62,18);
		cin>>gm_choice;
		
	switch(gm_choice)
	{
		case 1:
			feat.saveFile(player);
			cout<<"Day Recorded";
			system("pause");
			gameMenu(player);
			break;
		case 2:
			feat.tutorial();
			gameMenu(player);
			break;
		case 3:
			cout<<"Recording Day..";
			Sleep(400);
			cout<<"Day Recorded";
			system("pause");
			menu.startgame();
			break;
		case 4:
			if(player.place=="home") gm_home(player);
			else if(player.place=="school") gm_school(player);
			else if(player.place=="mall") gm_mall(player);
			else gm_park(player);
			break;
		default:
			cout<<"I tried to write my day but, I can't seem to focus";
			player.stress_lvl+=35;
			system("pause");
	}
}
