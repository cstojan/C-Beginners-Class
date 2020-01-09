/***************************************************************
CSCI 240         Program 5     Fall 2017

Programmer: Cory Stojan

Section: 0001

Date Due: October 13, 2017

Purpose: This program simulates a game of crabs.
***************************************************************/


/**************************************************************/
// Setup
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()

{

// Variables
int ran_num1, ran_num2, ran_sum, point, loop_exit, game_over, point_roll;
char answer, y, Y, n;
char newbie;

// Constants
const int SEVEN = 7;
const int ROLL_MIN = 1;
const int ROLL_MAX = 6;

// Random Generator Setting
srand(time(0));
//srand(8);

// Zeroing
answer = 'y';
newbie = 'y';
point_roll = 0;
game_over = 0;

// Crabs Game
while (answer == 'y' || answer == 'Y')
{
	// Newbie Statement (Displays The Rules If A User Selects y (for yes))
	if (newbie == 'y' || newbie == 'Y')
	{
		cout << "Are You New To The Game? (y/n)" << endl;
		cin >> newbie;
	}
	if (newbie == 'y' || newbie == 'Y')
	{
		cout << "The Game Rules Are As Follows:" << endl;
		cout << "You Roll Two Dice." << endl << "If Your Sum Of The Two Die Is Either A, 2,12,3, You Loose." << endl;
		cout << "If Your Sum is A 7 or 11, You Win." << endl << "If Your Sum Is Any Other Digit, That Digit Is Your Point. You Must Keep Rolling Until Your Sum";
		cout << "\nEquals The Point, In Which You Win. Or If Your Sum Is A 7, In Which You Will Loose.\n" << endl;
		newbie = 'n';
	}
	// Zeroing
	ran_num1 = 0;
	ran_num2 = 0;
	cout << "\n**Good Luck!**" << endl;
	
	// First Roll
	while (point_roll != 1)
	{
		//Random Six Sided Die Roll
		ran_num1 = ROLL_MIN + (rand()) % (ROLL_MAX - ROLL_MIN + 1);
		ran_num2 = ROLL_MIN + (rand()) % (ROLL_MAX - ROLL_MIN + 1);
		ran_sum = ran_num1 + ran_num2;
		
		// Roll Results Outcome Statements (win or loose or creating a pont)
		cout << "The Come Out Roll Is: " << ran_sum << endl;
	
		if (ran_sum == SEVEN)
		{
			cout << "Congratulation, You Win!" << endl;
			game_over = ran_sum;
			point_roll = 1; // allows for non repeating games without asking first (ditto for all point_roll in first roll sequence)
		}
		else if (ran_sum == 11)
		{
			cout << "Congratulation, You Win!" << endl;
			game_over = ran_sum;
			point_roll = 1;
		}
		else if (ran_sum == 2)
		{
			cout << "Craps! You lost!" << endl;
			game_over = ran_sum;
			point_roll = 1;
		}
		else if (ran_sum == 12)
		{
			cout << "Craps! You lost!" << endl;
			game_over = ran_sum;
			point_roll = 1;
		}
		else if (ran_sum == 3)
		{
			cout << "Craps! You lost!" << endl;
			game_over = ran_sum;
			point_roll = 1;
		}
		else
		{
			point = ran_sum;
			cout << "Game Continues, Your Point Number Is: " << point << endl << endl;
			point_roll = 1;
		}
	}
	


	// Second or More Rolls
	while (ran_sum != game_over)
	{
		// Random Six Sided Die Roll
		ran_num1 = ROLL_MIN + (rand()) % (ROLL_MAX - ROLL_MIN + 1);
		ran_num2 = ROLL_MIN + (rand()) % (ROLL_MAX - ROLL_MIN + 1);
		ran_sum = ran_num1 + ran_num2;
		cout << "The Next Sum Is: " << ran_sum << endl;
		
		// Outcome for result of random dice roll
		if (ran_sum == 7)
		{
			cout << "\nAww Crabs... You Landed On 7.\nYou Loose!" << endl;
			ran_sum = 7;
			game_over = ran_sum;
		}

		if (ran_sum == point)
		{
			loop_exit = ran_sum;
			cout << "\nYour Sum Is The Same As Your Point Number!" << endl;
			cout << "Congratulations, You're Awesome, You Win!" << endl;
			loop_exit = ran_sum;
			game_over = ran_sum;
		}
	}
	// Asks User if they want to play agian
	cout << "\nWould You Like To Play Agian? (y/n)" << endl;
	cin >> answer;
	cout << endl;
	if (answer == 'y' || answer == 'Y')
	{
		point_roll = 0;    // resets first roll
	}
}
cout << "\nThanks For Playing!" << endl;

return 0;
}
