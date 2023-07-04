#include "design.h"

Design::Design()
{
	load=0;
	x=0;
	style=220;
	y=0;
}

Design::~Design()
{
	
}

void Design::gotoxy(int x,int y)
{
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
	
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

void Design::menuborder()
{

	for (x=52;x<=112;x++)//horizontal
	{
		gotoxy(x,9);
		printf ("%c",style);
		gotoxy (x,30);
		printf ("%c",style);
	}
	
	for (y=10;y<=30;y++)//vertical
	{
		gotoxy (52,y);
		printf ("%c",style);
		gotoxy (112,y);
		printf ("%c",style);
	}
}

void Design::infoborder()
{
	for (x=30;x<=130;x++)//horizontal
	{
		gotoxy(x,2);
		printf ("%c",style);
		gotoxy (x,28);
		printf ("%c",style);
	}
	
	for (y=3;y<=28;y++)//vertical
	{
		gotoxy (30,y);
		printf ("%c",style);
		gotoxy (130,y);
		printf ("%c",style);
	}
}

void Design::gameborder()
{
	for (x=3;x<=157;x++)//horizontal
	{
		gotoxy(x,2);
		printf ("%c",style);
		gotoxy (x,35);
		printf ("%c",style);
	}
	
	for (y=3;y<=35;y++)//vertical
	{
		gotoxy (3,y);
		printf ("%c",style);
		gotoxy (157,y);
		printf ("%c",style);
	}
}

void Design::loading()
{
	
	system("cls");
	
	gotoxy(78,20);
		cout<<"THINKING";

	gotoxy(67,21);
	for(;load<30;load++)
	{
		cout<<"±";
		Sleep(100);
	}
}
