/***************************************************************
CSCI 240         Program 8     Fall 2017

Programmer: Cory Stojan

Section: 01

Date Due: November 10, 2017

Purpose: This Program Simulates A Game Of Dice
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//**********   Put the Die class definition after this line   **********

class Die
{
	public: // Constructor and Methods
	//Constructor
	Die();

	// Methods
	void roll();
	int getValue();
	void PrintDie(int);

	private: // Data Members
	// Data Members
	int DieNum;

	// Constants
	static const int NUM_SIDES;		
};

// Prototypes
void roll();

// Symbolic Constants
const int Die::NUM_SIDES = 6;

int main()
{
	//seed the random number generator
	//Note: this must be done before creating any Die class objects
  	srand(35);
//	srand(time(0));

	//Create a Die class object and display the side that is currently up
	Die die1;
	Die die2;

	// Main Variables
	double Cash, Bet, NewBet;
	int RollNum, RollCnt, Roll1, Roll2, DieNum, RollSum, TotalSum, Result, PlayerSum, DealerSum;
	char NewGame, NewPlayer, Waiger, Leagal, GameResult;

	// Default Variables
	Cash = 5000.00; // <---- **INITAL CASH**
	NewGame = 'Y';
	NewPlayer = 'N';

	// Intro For New Players
	cout << "EXTRA CREDIT ATTEMPTED" << endl;
	cout << setiosflags(ios:: fixed) << setprecision(2);
	cout << "Is This Your First Time Playing (y/n) ";
	cin >> NewPlayer;
	cout << endl;
	if (NewPlayer == 'y' || NewPlayer == 'Y')
	{
		cout << "Your Objective Is To Guess If The Sum Of Two Random Dice That Are Rolled Is Either Odd Or Even." <<
				" \nIf You Guess Right On The Current Roll, You Get A Point. If Not, The Dealer Gets A Point. \nAt" <<
				" The End, If You Have More Points, You Win. If You Have The Same Amount, \nThe Game Ends In A Tie And You" <<
				" Dont Loose Your Bet. If You Have Less Points Than The Dealer, You Loose. ";
		cout << "\nYou Will Start With: $" << Cash << endl;
		NewPlayer = 'n';
	}

	// Game
	while (NewGame == 'y' || NewGame == 'Y')
	{
		Bet = 0;
		NewBet = 0;
		PlayerSum = 0;
		DealerSum = 0;

		// Number Of Rolls For The Game
		cout << endl << "The Dice Should Be Rolled How Many Times? ";
		cin >> RollNum;
		cout << "Ok! The Dice Will Be Rolled " << RollNum << " Times" << endl << endl;

		// User Guess (Outcome Being Odd Or Even)
		cout << "Will The Sum Of Each Roll Be (O)dd Or (E)ven? ";
		cin >> Waiger;
		if (Waiger == 'E' || Waiger == 'e')
		{
			Waiger = 'E';
		}
		else
		{
			Waiger = 'O';
		}

		// User Bet
		Leagal = 'n';
		cout << "How Much Cash Will You Bet? ";
		while (Leagal == 'n')
		{
			// User Enters Bet Amount
			cin >> NewBet;
			if (Cash - NewBet < 0)
			{
				cout << "You Do Not Have Enough Cash For That. Renter An Amount." << endl;
			}
			else if (NewBet <= 0)
			{
				cout << "Invalid Amount. Renter An Amount." << endl;
			}
			else
			{
				Bet = NewBet;
				cout << "You Bet $" << Bet << endl << endl;
				Leagal = 'y';
			}
		}

		//Dice Roll And Display
		RollCnt = 1;
		TotalSum = 0;

		while (RollCnt <= RollNum)
		{
			RollSum = 0; // <-- Resets To Zero Each Sequence Of Rolling

			// Roll Count
			cout << "\n\nRoll # " << RollCnt << endl;

			// First Dice
			die1.roll();
 			Roll1 = die1.getValue();
 			die1.PrintDie(Roll1);

 			// Second Dice
 			die2.roll();
 			Roll2 = die2.getValue();
 			die1.PrintDie(Roll2);

 			// Display Sum
 			RollSum = Roll1 + Roll2;
			Result = RollSum % 2;

			// Game Result
			if (Result == 0)
			{
				GameResult = 'E';
			}
			else
			{
				GameResult = 'O';
			}

			// Display Player Or Dealer Winner
			if (Waiger == GameResult)
			{
				PlayerSum++;
				cout << "You Guessed Right!" << endl;
			}
			else
			{
				DealerSum++;
				cout << "You Guessed Wrong." << endl;
			}

			// Increase The Roll #
			RollCnt++;
		}

		// Display Outcome Of User Bet
		cout << endl << "Your Final Score Is: " << PlayerSum << ".\nDealers Final Score Is: " << DealerSum << endl;
		if (PlayerSum > DealerSum)
		{
			cout << endl << "Congratulation, You Win!" << endl;
			Cash = Cash + Bet;
			cout << "Your Bet Of " << Bet << " Has Been Added To Your Cash!" << endl;
			cout << "You Have $" << Cash << " Left!" << endl << endl;
		}
		else if (PlayerSum == DealerSum)
		{
			cout << "The Game Ended In A Tie." << endl;
		}
		else
		{
			cout << "Sorry You Lost." << endl;
			Cash = Cash - Bet;
			cout << "You Have $" << Cash << " Remaining." << endl << endl;
		}

		// New Game?
		if (Cash > 0)
		{
			cout << "Do You Wish To Play Agian?" << endl;
			cin >> NewGame;
			cout << endl << endl;
		}
		else
		{
			cout << "Game Over";
			NewGame = 'n';
		}
	}

	return 0;
}

//**********   Code the Die class constructor and methods after this line   **********

// Constructor Code
Die::Die()
{
	roll();
}

//**************************************************************************************************************************************************

void Die::PrintDie(int DieNum)
{
	// Local Varibles

	if (DieNum == 1)
	{
		cout <<  " -----" << endl << "|     |" << endl << "|  O  |" << endl << "|     |" << endl << " -----" << endl;
	}
	
	else if (DieNum == 2)
	{
		cout <<  " -----" << endl << "|O    |" << endl << "|     |" << endl << "|    O|" << endl << " -----" << endl;
	}

	else if (DieNum == 3)
	{
		cout << " -----" << endl << "|O    |" << endl << "|  O  |" << endl << "|    O|" << endl << " -----" << endl;
	}

	else if (DieNum == 4)
	{
		cout << " -----" << endl << "|O   O|" << endl << "|     |" << endl << "|O   O|" << endl << " -----" << endl;
	}

	else if (DieNum == 5)
	{
		cout << " -----" << endl << "|O   O|" << endl << "|  O  |" << endl << "|O   O|" << endl << " -----" << endl;
	}

	else 
	{
		cout << " -----" << endl << "|O   O|" << endl << "|O   O|" << endl << "|O   O|" << endl << " -----" << endl;
	}

}

//**************************************************************************************************************************************************

void Die::roll()
{
	// Local Variables
	//int DieNum;
	
	// Local Constants
	#define MINROLL 1
	
	// Roll Random Number
	DieNum = MINROLL + (rand()) % (NUM_SIDES - MINROLL + 1);

}

//**************************************************************************************************************************************************

int Die::getValue()
{
	return DieNum;
}

//**************************************************************************************************************************************************
