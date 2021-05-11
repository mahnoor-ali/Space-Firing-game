//copyrights
//mahnoor
#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;


class FireBall
{
private:
	char fire;

public:
	FireBall()
	{
		fire = '0';
	}

	char fireball_image(char type);  //call this b4 firing in fire() of all classes
	void Fireball_Count(int fire_no); //call this only for rocket object
};


class Spaceship
{
protected:
	static int score;
	int xloc;
	int yloc;
	int attack;

public:
	Spaceship()
	{
		attack = 0;
		xloc = 0;
		yloc = 0;
	}
	virtual void draw(int, int) = 0;
	virtual void move(int, char)
	{	}
	virtual void fire(int)
	{	}
	virtual void destroy(int) = 0;
	virtual int spaceship_Status() = 0;
	virtual int get_score() = 0;
	virtual int get_fireLocx() = 0;
	virtual bool life_() = 0;
};


class MartianShip : public Spaceship
{
private:
	const char* martian[10];
	bool life_status;
	int attack;
	int fire_loc;
	int fire_count;
	FireBall M_FireB[35];

public:
	MartianShip() //width=28
	{
		life_status = 0; //spaceship is alive
		attack = 5;
		fire_loc = 0;
		fire_count = 34; //34 means 0 to 34 i.e total of 35

		martian[0] = "         -* * * * *-   ";
		martian[1] = "       *             *";
		martian[2] = "       *             *";
		martian[3] = "    *    * * * * * *    *";
		martian[4] = "  *                       *";
		martian[5] = " *                         *";
		martian[6] = " * *                     * *";
		martian[7] = "  * *                   * *";
		martian[8] = "    *  *             *  *";
		martian[9] = "       * * - * * - * *";
	}


	void draw(int, int);
	void move(int, char);
	void fire(int);
	int get_locationX();
	int get_locationY();
	int get_score();
	void destroy(int);
	int spaceship_Status();
	int get_fireLocx();
	bool life_();

};





class StarShip : public Spaceship
{
private:
	const char* star[9];
	bool life_status;
	int attack;
	int fire_loc;
	int fire_count;
	FireBall S_FireB[30];
public:
	StarShip() //width=24
	{
		life_status = 0; //spaceship is alive
		attack = 3;
		fire_loc = 0;
		fire_count = 29; //29 means 0 to 29 i.e total of 30 

		star[0] = "        -*  *  *-";
		star[1] = "      *           *";
		star[2] = "      *           *";
		star[3] = "    *    * * * *    *";
		star[4] = "  *                   *";
		star[5] = " *                     *";
		star[6] = "  *                   *";
		star[7] = "     * *   * *   * *";
		star[8] = "        * * * * *";
	}


	void draw(int, int);
	void move(int, char);
	void fire(int);
	int get_score();
	int get_locationX();
	int get_locationY();
	void destroy(int);
	int spaceship_Status();
	int get_fireLocx();
	bool life_();
};

class Rocket
{
private:
	int no_of_lives;
	int x_loc;
	int y_loc;
	const char* rocket[12];
	int fire_count;
	FireBall R_FireB[25];
public:
	Rocket()
	{
		fire_count = 24; //24 means 0 to 24 i.e total of 25 
		no_of_lives = 3;
		x_loc = 0;
		y_loc = 0;
		rocket[0] = "         *";
		rocket[1] = "        ***";
		rocket[2] = "       ** **";
		rocket[3] = "      '''''''";
		rocket[4] = "     **     **";
		rocket[5] = "    ***     ***";
		rocket[6] = "    ***     ***";
		rocket[7] = "   |****   ****| ";
		rocket[8] = "  ||***** *****|| ";
		rocket[9] = " |||***** *****|||";
		rocket[10] = "    ***********";
		rocket[11] = "    ***********";
	}

	void draw(int, int);
	void move(char);
	int fire();
	int get_xLOC();
	int get_yLOC();
	void life_status(int, int);
	int getNo_of_Lives();
	void GetLives_notf();
	int Remaining_Fire();
};
