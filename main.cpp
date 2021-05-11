//bsef19m027-mahnoor
//copyrights
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<string>
#include<ctime>
#include"Header.h"
using namespace std;

int main()
{
	srand(static_cast <unsigned int>(time(0)));
	int f = 0; //saves the location of fire, coming from spaceship
	char movement = '0';
	int game_decision = 0;
	bool life_check_;
	int R_lives = 0;
	int scoree = 0; //player's score 
	int fireball_num = 0;
	int random_no = 0;
	int fire_part = 0;
	int dead_ship = 0;
	int scor;
	int fire_loc;
	char R_status;
	char begin; //variable that is used to keep console static, after displaying game controls
	const char s_directD = 'd';
	const char s_directU = 'u';
	int a, b;
	int Rocket_x = 55;
	int Rocket_y = 29;
	char status;

	//spaceship locations on screen
	const int S0_x = 29, S0_y = 2;
	const int S1_x = 86, S1_y = 2;
	const int S2_x = 1, S2_y = 2;
	const int S3_x = 59, S3_y = 2;


	//starting of the game or the welcome window
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "WELCOME TO SPACE FIRING GAME :)\n";
	Rocket r;

	r.draw(Rocket_x, Rocket_y);
	COORD coord;
	a = r.get_xLOC(); //get location of rocket in x-y coordinates
	b = r.get_yLOC();
	coord.X = a + 8, coord.Y = b + 12;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "START\nPress s to start the game  ";
	cin >> status;
	coord.X = a + 8, coord.Y = b + 12;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "START\nPress s to start the game  s";
	coord.X = 0, coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "WELCOME TO SPACE FIRING GAME :)\n";
	coord.X = 0, coord.Y = 20;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	if ((status == 's') || (status == 'S'))
	{

		COORD coordnt;
		coordnt.X = 0, coordnt.Y = 0;

		Spaceship* Ship[4];
		MartianShip Martian[2];
		StarShip Star[2];
		for (int i = 0; i < 2; i++)
			Ship[i] = &Martian[i];
		for (int i = 2; i < 4; i++)
			Ship[i] = &Star[i - 2];


		while (1)
		{	
			//show all spaceships coming from the top

			Ship[2]->draw(S2_x, S2_y);		//1st spaceship
			for (int i = 0; i < 7; i++)
			{
				Ship[2]->move(1, s_directD);
				r.draw(Rocket_x, Rocket_y);
			}
			for (int i = 0; i < 7; i++)
			{
				Ship[2]->move(1, s_directU);
				r.draw(Rocket_x, Rocket_y);
			}

			Ship[0]->draw(S0_x, S0_y);			//2nd spaceship
			for (int i = 0; i < 7; i++)
			{
				Ship[0]->move(1, s_directD);
				r.draw(Rocket_x, Rocket_y);
				Ship[2]->draw(S2_x, S2_y);
			}
			for (int i = 0; i < 7; i++)
			{
				Ship[0]->move(1, s_directU);
				r.draw(Rocket_x, Rocket_y);
				Ship[2]->draw(S2_x, S2_y);
			}

			Ship[3]->draw(S3_x, S3_y);			//3rd spaceship
			for (int i = 0; i < 7; i++)
			{
				Ship[3]->move(1, s_directD);
				r.draw(Rocket_x, Rocket_y);
				Ship[2]->draw(S2_x, S2_y);
				Ship[0]->draw(S0_x, S0_y);
			}
			for (int i = 0; i < 7; i++)
			{
				Ship[3]->move(1, s_directU);
				r.draw(Rocket_x, Rocket_y);
				Ship[2]->draw(S2_x, S2_y);
				Ship[0]->draw(S0_x, S0_y);
			}

			Ship[1]->draw(S1_x, S1_y);			//4th spaceship
			for (int i = 0; i < 7; i++)
			{
				Ship[1]->move(1, s_directD);
				r.draw(Rocket_x, Rocket_y);
				Ship[2]->draw(S2_x, S2_y);
				Ship[0]->draw(S0_x, S0_y);
				Ship[3]->draw(S3_x, S3_y);
			}
			for (int i = 0; i < 7; i++)
			{
				Ship[1]->move(1, s_directU);
				r.draw(Rocket_x, Rocket_y);
				Ship[2]->draw(S2_x, S2_y);
				Ship[0]->draw(S0_x, S0_y);
				Ship[3]->draw(S3_x, S3_y);
			}

			//display controls for moving rocket
			char Moves = '0';
			coordnt.X = 0, coordnt.Y = 41;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordnt);
			cout << "\nIn order to move the spaceship to right/left/up/down, press r/l/u/d key respectively.\nIf not, press 'n'?\nFor firing, you've to press 'f'\n";
			cout << "ARE YOU READY? :p Then Press any Key!";
			cin >> begin;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordnt);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			cout << "\nIn order to move the spaceship to right/left/up/down, press r/l/u/d key respectively.\nIf not, press 'n'?\nFor firing, you've to press 'f'\n";
			cout << "ARE YOU READY? :p Then Press Enter Key! a";


			while (1)
			{
				random_no = 0 + rand() % 4;
				Ship[random_no]->fire(0);
				Ship[random_no]->fire(1);

				//get the location of fireball and if it collides the rocket, decrement its life by 1
				f = Ship[random_no]->get_fireLocx();
				life_check_ = Ship[random_no]->life_();
				r.life_status(f, life_check_);
				R_lives = r.getNo_of_Lives();
				r.GetLives_notf();		//display no of lives
				if (R_lives == 0)
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t*** YOU LOST THE BATTLE ***\n\n\n";
					return 0;
				}
				COORD coordn;
				coordn.X = 0, coordn.Y = 41;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordn);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

				cout << "Press 'm' to move or 'f' to fire";
				cin >> R_status;

				coordn.X = 0, coordn.Y = 41;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordn);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				cout << "Press 'm' to move or 'f' to fire x";


				switch (R_status)
				{

				case 'm':
				case 'M':
				{
					R_lives = r.getNo_of_Lives(); //if user has lost all of his lives, then exit the infinite loop
					r.GetLives_notf();		//display no of lives
					if (R_lives == 0)
					{
						cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t*** YOU LOST THE BATTLE ***\n\n\n";
						return 0;
					}
					Moves = 'm'; //reinitialize the variable Moves in order to enter the below loop once

					while (Moves != 'n') //keep moving till player wants to move
					{
						random_no = 0 + rand() % 4; //generate random no between 0 and 3 incl. both
						fire_part = 0;

						Ship[random_no]->fire(fire_part); //fire halfway from user to allow him to move for his defense

						coordn.X = 0, coordn.Y = 41;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordn);
						cout << "press left/right/up/down arrow key to move. press 'n' if you want want to move anymore";
						movement = _getch();
						
							if (movement == 72)
							{
								Moves = 'u';
								r.move(Moves);
							}

							else if (movement == 80)
							{
								Moves = 'd';
								r.move(Moves);
							}

							else if (movement == 75)
							{
								Moves = 'l';
								r.move(Moves);
							}
							else if (movement == 77)
							{
								Moves = 'r';
								r.move(Moves);
							}

							else if ((movement == 'n') || (movement == 'N'))
							{
								Moves = 'n';
								coordn.X = 0, coordn.Y = 27;
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordn);
								cout << "invalid move!";
								Sleep(900);
								coordn.X = 0, coordn.Y = 27;
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordn); //remove the displayed message from console
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
								cout << "invalid move!";
							}
							fire_part++;
							Ship[random_no]->fire(fire_part); //complete the fire from halfway towards rocket

							f = Ship[random_no]->get_fireLocx();
							life_check_ = Ship[random_no]->life_();
							r.life_status(f, life_check_);
							R_lives = r.getNo_of_Lives();
							r.GetLives_notf();		//display no of lives
							if (R_lives == 0)
							{
								cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t*** YOU LOST THE BATTLE ***\n\n\n";
								return 0;
							}
					}
					//close the move controls prompt
					coordn.X = 0, coordn.Y = 41;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordn);
					cout << "press left/right/up/down arrow key to move. press 'n' if you want want to move anymore";
					break;
				}

				case 'f':
				case 'F':
				{
					R_lives = r.getNo_of_Lives(); //if user has lost all of his lives, then exit the infinite loop
					r.GetLives_notf();		//display no of lives
					if (R_lives == 0)
					{
						cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t*** YOU LOST THE BATTLE ***\n\n\n";
						return 0;
					}
					COORD cord;
					char fire_status = 'f';
					while ((fire_status == 'f') || (fire_status == 'F'))
					{
						fireball_num = r.Remaining_Fire();
						if (fireball_num == 0)
							break;
						random_no = 0 + rand() % 4; //generate random no between 0 and 3 incl. both
						fire_part = 0;

						fire_loc = r.fire();

						Ship[random_no]->fire(fire_part); //fire halfway to user

						scor = Ship[0]->get_score();
						if (scor == 30)	//if player has used all fireballs but scored 30, then he won the game
						{
							cout << "\n\n\n\n\n\n\n\n\t\t*** WELL DONE! YOU WON THE BATTLE ***\n\n\n";
							return 0;
						}

						fire_part++;
						Ship[random_no]->fire(fire_part); //complete the fire from halfway towards rocket

						f = Ship[random_no]->get_fireLocx();
						life_check_= Ship[random_no]->life_();
						r.life_status(f, life_check_);
						R_lives = r.getNo_of_Lives();
						r.GetLives_notf();		//display no of lives
						if (R_lives == 0)
						{
							cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t*** YOU LOST THE BATTLE ***\n\n\n";
							return 0;
						}
						for (int i = 0; i < 4; i++)
						{
							Ship[i]->destroy(fire_loc); //check whether the rocket fire hit the spaceship or not
							dead_ship = Ship[i]->spaceship_Status();
							if (dead_ship == 1)
							{
								game_decision++;
								system("CLS");
								Ship[2]->draw(S2_x, S2_y);
								Ship[0]->draw(S0_x, S0_y);
								Ship[3]->draw(S3_x, S3_y);
								Ship[1]->draw(S1_x, S1_y);
								Rocket_x = r.get_xLOC();
								Rocket_y = r.get_yLOC();
								r.draw(Rocket_x, Rocket_y);
							}
						}
						random_no = 0 + rand() % 4; //generate random no between 0 and 3 incl. both
						Ship[random_no]->fire(0);
						Ship[random_no]->fire(1);

						f = Ship[random_no]->get_fireLocx();
						life_check_ = Ship[random_no]->life_();
						r.life_status(f, life_check_);			
						R_lives = r.getNo_of_Lives();
						r.GetLives_notf();		//display no of lives
						if (R_lives == 0)
						{
							cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t*** YOU LOST THE BATTLE ***\n\n\n";
							return 0;
						}
						cord.X = 0, cord.Y = 41;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << "\nto keep firing, press 'f' else press any key";
						cin >> fire_status;
					}
					cord.X = 0, cord.Y = 41;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);  //remove the displayed message from console
					cout << "\nto keep firing, press 'f' else press any key";
					break;
				}
				default:
				{
					R_lives = r.getNo_of_Lives(); //if user has lost all of his lives, then exit the infinite loop
					r.GetLives_notf();		//display no of lives
						if (R_lives == 0)
						{
							cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t*** YOU LOST THE BATTLE ***\n\n\n";
							return 0;
						}
					COORD cor;
					cor.X = 0, cor.Y = 41;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  //remove the displayed message from console
					cout << "Invalid input";
					Sleep(500);
					cor.X = 0, cor.Y = 41;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);  //remove the displayed message from console
					cout << "Invalid input";
				}


				R_lives = r.getNo_of_Lives();  //if user has lost all of his lives, then exit the infinite loop
				if (R_lives == 0)
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t*** YOU LOST THE BATTLE ***\n\n\n";
					return 0;
				}

				fireball_num = r.Remaining_Fire();
				if (fireball_num == 0)
					break;

				} //end of switch statement



				COORD pos;
				pos.X = 0, pos.Y = 1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				scor = Ship[0]->get_score(); //since score is a static data member, so it can be accessed by any one of the pointer to object
				cout << "Your current score is: " << scor;
				

				fireball_num = r.Remaining_Fire();	//remaining fireballs, playerhave
				R_lives = r.getNo_of_Lives();	//remaining no of lives of player

				//end the game in these 3 scenarios :
				if ((R_lives == 0) || (fireball_num == 0) || (game_decision == 4) || (scoree == 30))	//if player lost all his lives
					break;
			}


			fireball_num = r.Remaining_Fire();	//remaining fireballs, playerhave
			R_lives = r.getNo_of_Lives();	//remaining no of lives of player

			//end the game in these 3 scenarios :
			if ((R_lives == 0) || (fireball_num == 0) || (game_decision == 4) || (scoree == 30))	//if player lost all his lives
				break;


		} //end of game


		//game decisions
		system("CLS");

		COORD cor;
		cor.X = 46, cor.Y = 22;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);

		scoree = Ship[0]->get_score();	//player's score
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		
		if (scoree < 30)	
		{
			cout << "*** YOU LOST THE BATTLE ***\n\n\n";
			return 0;
		}
		 if  (scoree == 30)	//if player has used all fireballs but scored 30, then he won the game
		{
			cout << "*** WELL DONE! YOU WON THE BATTLE ***\n\n\n";
			return 0;
		}
	}

	else
		return 0;
}