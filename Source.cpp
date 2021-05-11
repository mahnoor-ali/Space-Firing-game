//bsef19m027-mahnoor
//copyrights
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include"Header.h"
using namespace std;

//Spaceship
int Spaceship::score = 0;

//FireBall
char FireBall::fireball_image(char type)  //call this b4 firing in fire() of all classes
{

	if (type == 'm') //if its martian ship, fire ball looks like 'l'
		fire = 'l';
	else if (type == 's') //if its star ship, fire ball looks like '!'
		fire = '!';
	else if (type == 'r') //if its rocket, fire ball looks like 'o'
		fire = 'o';

	return fire;
}

void FireBall::Fireball_Count(int fire_no) //call this only for rocket object
{
	COORD Co;
	Co.X = 0, Co.Y = 41;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Co);
	cout << "Remaining fireballs are: " << fire_no;
	Sleep(300);
}



//Starship

void MartianShip::draw(int x, int y) //location of xloc, yloc updates by x,y as a new spaceship is drawn
{
	if (life_status == 0) //draw if the spaceship has not been destroyed
	{
		xloc = x;
		yloc = y;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); 
		COORD coord;
		coord.X = x;
		coord.Y = y;
		for (int drw_m = 0; drw_m < 10; drw_m++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << martian[drw_m];
			coord.Y++;
		}
	}
}

void MartianShip::move(int N, char Direction)
{
	static int X_temp, Y_temp;
	X_temp = xloc;
	Y_temp = yloc;
	for (int mov = 0; mov < N; mov++) //spaceship moves N coordinates towards -ve y-axis
	{
		Sleep(100);
		system("CLS");
		if ((Direction == 'u') || (Direction == 'U')) //spaceship moves up when direction is equal to u
			Y_temp--;
		else if ((Direction == 'd') || (Direction == 'D')) //spaceship moves down when direction is equal to d
			Y_temp++;
		draw(X_temp, Y_temp);
	}
}

void MartianShip::fire(int a)
{
		if ((life_status == 0)&& (fire_count >= 0)) //fire, only if there are available fire balls in fireball object and martianship is alive
		{
			char fire = '0';
			static int fire_check = 0;
			int f_x, f_y;
			f_x = xloc + 14;   //centre of martianship is 14 unit from its starting point on x axis
			f_y = yloc + 10;   //height of martianship is 10 units from its starting point on y axis
			COORD coord;
			coord.X = f_x;

			if (a == 0)
				coord.Y = f_y;
			else if (a == 1)
				coord.Y = fire_check;

			for (int f = (a * 13); f < 26; f++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				fire = M_FireB[fire_count].fireball_image('m');
				cout << fire;
				Sleep(50);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				fire = M_FireB[fire_count].fireball_image('m');
				cout << fire;
				coord.Y++;
				if ((a == 0) && (f == 12))	//fire halfway in first call to allow user for defense
					break;
			}
			if (a == 0)
				fire_check = coord.Y;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

			fire_loc = f_x; //save location of fire coming from spaceship
			fire_count--; //Decrement fire balls
		}
}

int MartianShip::get_locationX()
{
	return xloc;
}

int MartianShip::get_locationY()
{
	return yloc;
}

int MartianShip::get_score()
{
	return score;
}

bool MartianShip::life_()
{
	return life_status;
}

int MartianShip::get_fireLocx()
{
	return fire_loc;
}


void MartianShip::destroy(int x)
{
	int x_origin = xloc + 1;
	int x_end = xloc + 27;
	if ((x <= x_end) && (x >= x_origin))  //check if the fire ball is within the boundary of martainship
	{
		if (attack > 0) //check: if the attack variable is already 0, then don't decrement it
			attack--;
	}
}

int MartianShip::spaceship_Status()
{
	if (life_status == 0)  //execute this chunk of code if the ship is getting destroyed for the first tym
	{
		if (attack == 0) //don't count score for more than once a ship is destroyed
		{
			score += 10; //add score for destroying a spaceship
			life_status = 1;
		}
	}
	return life_status;
}

//starship



void StarShip::draw(int x2, int y2) //location of xloc, yloc updates by x2,y2 as a new spaceship is drawn
{
	if (life_status == 0) //draw if the spaceship has not been destroyed
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		xloc = x2; //location of spaceship by x,y coordinates
		yloc = y2;
		COORD coord;
		coord.X = x2;
		coord.Y = y2;
		for (int drw_s = 0; drw_s < 9; drw_s++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << star[drw_s];
			coord.Y++;
		}
	}
}

void StarShip::move(int n, char direction)
{
	static int x_temp, y_temp;
	x_temp = xloc;
	y_temp = yloc;
	for (int mov = 0; mov < n; mov++) //spaceship moves n coordinates towards -ve y-axis
	{
		Sleep(100);
		system("CLS");
		if ((direction == 'u') || (direction == 'U')) //spaceship moves up when direction is equal to u
			y_temp--;
		else if ((direction == 'd') || (direction == 'D')) //spaceship moves down when direction is equal to d
			y_temp++;
		draw(x_temp, y_temp);
	}
}

void StarShip::fire(int a)
{
		if ((life_status == 0)&& (fire_count >= 0)) ///fire, only if there are available fire balls in fireball object and if starship is alive
		{
			char fire;
			static int fire_check = 0;
			int f_x, f_y;
			f_x = xloc + 12;   //centre of starship is 12 unit from its starting point on x axis
			f_y = yloc + 9;    //height of starship is 9 units from its starting point on y axis
			COORD coord;
			coord.X = f_x;
			if (a == 0)
				coord.Y = f_y;
			else if (a == 1)
				coord.Y = fire_check;

			for (int f = (a * 13); f < 27; f++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				fire = S_FireB[fire_count].fireball_image('s');
				cout << fire;
				Sleep(50);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				fire = S_FireB[fire_count].fireball_image('s');
				cout << fire;
				coord.Y++;
				if ((a == 0) && (f == 12))	//fire halfway in first call to allow user for defense
					break;
			}
			if (a == 0)
				fire_check = coord.Y;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			fire_loc = f_x; //save location of fire coming from spaceship
			fire_count--; //Decrement fire balls
		}
}


int StarShip::get_locationX()
{
	return xloc;
}

int StarShip::get_locationY()
{
	return yloc;
}

bool StarShip::life_()
{
	return life_status;
}

int StarShip::get_score()
{
	return score;
}

int StarShip::get_fireLocx()
{
	return fire_loc;
}

void StarShip::destroy(int x)
{
	int x_origin = xloc + 1;
	int x_end = xloc + 23;
	if ((x <= x_end) && (x >= x_origin)) //check if the fire ball is within the boundary of starship
	{
		if (attack > 0) //check: if the attack variable is already 0, then don't decrement it
			attack--;
	}
}

int StarShip::spaceship_Status()
{
	if (life_status == 0) //execute this chunk of code if the ship is getting destroyed for the first tym
	{
		if (attack == 0) //don't count score for more than once a ship is destroyed
		{
			score += 5; //add score for destroying a spaceship
			life_status = 1;
		}
	}
	return life_status;
}


//Rocket

void Rocket::draw(int R_x, int R_y)
{
	x_loc = R_x; //location of rocket given by x,y coordinates
	y_loc = R_y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	COORD coord;
	coord.X = R_x;
	coord.Y = R_y;
	for (int drw_R = 0; drw_R < 12; drw_R++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << rocket[drw_R];
		coord.Y++;
	}
}

void Rocket::move(char direction)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); //overwrite the rocket on previous position by black color,in order to move it to desired direction
	COORD coord;
	coord.X = x_loc;
	coord.Y = y_loc;
	for (int drw_R = 0; drw_R < 12; drw_R++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << rocket[drw_R];
		coord.Y++;
	}

	switch (direction)
	{
	case 'l':
	case 'L':
		x_loc--;
		break;

	case 'r':
	case 'R':
		x_loc++;
		break;

	case 'u':
	case 'U':
		y_loc--;
		break;

	case 'd':
	case 'D':
		y_loc++;
		break;
	}
	draw(x_loc, y_loc);
}

int Rocket::fire()
{
	int xx = 0;
	if (fire_count >= 0) //fire, only if there are available fire balls in fireball object
	{
		int fire_yCOR = y_loc;
		COORD coordnate;
		while (fire_yCOR > 7)
		{
			fire_yCOR--;
			coordnate.X = x_loc + 9;
			coordnate.Y = fire_yCOR;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordnate);
			cout << R_FireB[fire_count].fireball_image('r');
			Sleep(50);
			coordnate.X = x_loc + 9;
			coordnate.Y = fire_yCOR;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordnate);
			cout << R_FireB[fire_count].fireball_image('r');
			xx = coordnate.X;
		}
		coordnate.Y += 20;
		coordnate.X = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordnate);
		R_FireB[fire_count].Fireball_Count(fire_count);
		fire_count--; //Decrement fire balls
		return xx;
	}

	else return 0;
}

int Rocket::get_xLOC()
{
	return x_loc;
}
int Rocket::get_yLOC()
{
	return y_loc;
}

void Rocket::life_status(int fire_locatn , int L)
{
	if (L == 0)	//check that don't decrement the no of lives of rocket, after a spaceship has been destroyed
	{
		int R_End = x_loc + 17;	 // starting point of rocket on x-coordinate
		int R_origin = x_loc;	 //  ending point of rocket on x-coordinate

		if ((fire_locatn <= R_End) && (fire_locatn >= R_origin))
			no_of_lives--;
	}
}

int Rocket::getNo_of_Lives()
{
	return no_of_lives;
}

int Rocket::Remaining_Fire()
{
	return fire_count;
}

void Rocket::GetLives_notf()
{
	COORD C;
	C.X = 0, C.Y = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), C);
	cout << "Remaining lives = " << no_of_lives;
}



