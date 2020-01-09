/***************************************************************
CSCI 240         Program 6     Fall 2017

Programmer: Cory Stojan

Section: 01

Date Due: October 20, 2017

Purpose: Writing functions that can be used to manipulate and test an integer number
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_VALS = 10;       //the maximum number of values to use

/********* Put the function prototypes below this line *********/
int sumDigits(int);
int reverse(int);
int setpercision(int);
bool isPalindrome(int);
bool isPrime(int);
void numerology(int);

// Main
int main()
{
	int number,          //holds the random number that is manipulated and tested
    	loopCnt,         //controls the loop
		result,			 //resulting return number
		sum;			 //(extra credit) sum of the birthdate
	
	
	//set the seed value for the random number generator
	//Note: a value of 1 will generate the same sequence of "random" numbers every
	//      time the program is executed


	// MAX RAND VALUE IS 32,767
	srand(31);
	//srand(time(0));

	cout << "**Extra Credit Attempted**" << endl;
	//Generate 10 random numbers to be manipulated and tested

	for( loopCnt = 1; loopCnt <= NUM_VALS; loopCnt++ )
	  {
	  //Get a random number
	  number = rand();

	  //Display the sum of adding up the digits in the random number, the reversed
	  //random number, and whether or not the number is palindromic or a prime number
  
	  cout << "The number is " << number << endl 
	       << "----------------------------------------" << endl
	       << "Adding the digits result" << setw(16) << sumDigits(number) << endl
	       << "Reversing the digits result" << setw(13) << reverse(number) << endl
	       << "Is the number a palindrome?" << setw(13) << (isPalindrome(number)? "Yes" : "No") << endl
	       << "Is the number prime?" << setw(20) << (isPrime(number)? "Yes" : "No") << endl
		   << endl << endl;
	}

	/** If the extra credit is being attempted, call the extra function below this line **/

	// **Extra Credit**
	int month, day, year;
	cout << "EXTRA CREDIT ATTEMPT" << endl;
	cout << "Enter your birthdate in the form (mm/dd/yyyy): ";

	cin >> month;    // Get the month value from the input buffer

	cin.ignore();    // Remove the 1st / from the input buffer

	cin >> day;      // Get the day value from the input buffer

	cin.ignore();    // Remove the 2nd / from the input buffer

	cin >> year;     // Get the year value from the input buffer
	sum = day + month + year;

	// **numerlogy Function** (Extra Credit)
	numerology(sum);
return 0;
}
/********* Code the functions below this line *********/
//*************************************************************

// **sumDigits**
int sumDigits(int number)
{
/***************************************************************
Function:  int sumDigits( int )

Use: This Function Adds The Individual Numbers Of A Number Between 1 and 1000.

Arguments: an integer, the number to be tested

Returns: a int value that is the sum of the digits in a given number between 1 and 1000.
***************************************************************/
	
	// Local Variables
	int result, edit_num, divisor;

	// **IMPORTANT** (SET VARIABLES TO ZERO)
	divisor = 10000; // <--- number which divideds each power of 10 for the number givin
	result = 0;
	
	// stores number as a usable varible
	edit_num = number;
	
	// seperates, and adds the digits together and stores as a sum
	while (edit_num > 0)
	{
		result = result + (edit_num / divisor);
		edit_num = edit_num % divisor;
		divisor = divisor / 10;
	}
	
	// Returns Resulting Sum
return result;
}
//*************************************************************

// **reverse**
int reverse(int number)
{
/***************************************************************
Function:  int reverse( int )

Use: This function will reverse and return the digits in an integer number. For example, if num contains 641, the function should return 146.

Arguments: an integer, the number to be reversed

Returns: a int value that is the reverse number of the given number.
***************************************************************/

	// Local Variables
	int num0, num10, num100, num1000, num10000, result, user_num;

	// **IMPORTANT** (SET VARIABLES TO ZERO)
	num0 = 0;
	num10 = 0;
	num100 = 0;
	num1000 = 0;
	num10000 = 0;
	result = 0;
	
	// Seperates Each Digit From The Number Given and stores each value as a speperate variable
	user_num = number;
	if (user_num >= 10000)				//<--- start
	{
		num10000 = user_num / 10000;
		user_num = user_num % 10000;
	}
	if (user_num >= 1000)
	{
		num1000 = user_num / 1000;
		user_num = user_num % 1000;
	}
	
	if (user_num >= 100)
	{
		num100 = user_num / 100;
		user_num = user_num % 100;
	}
	
	if (user_num >= 10)
	{
		num10 = user_num / 10;
		user_num = user_num % 10;
	}
	if (user_num >= 0)
		num0 = user_num / 1;		//<--- finish

	// Reassebles the numbers in reverses order
	result = result + num0;		//<--- start
	if (number >= 10)
		result = result * 10;
	
	if (number >= 10)
	{
		result = result + num10;
		if (number >= 100)
			result = result * 10;
	}
	
	if (number >= 100)
	{
		result = result + num100;
		if (number >= 1000)
			result = result * 10;
	}
	
	if (number >= 1000)
	{
		result = result + num1000;
		if (number >= 10000)
			result = result * 10;
	}
	if (number >= 10000)
		result = result + num10000;		//<--- finish
	
	// Returns The Result
return result;
}
//****************************************************************

// **isPalindrome**
bool isPalindrome(int number)
{
/***************************************************************
Function:  bool isPalindrome( int )

Use: This function determines if a number the same number when reversed.

Arguments: The oraginal number, the reverse number

Returns: A boolean value that determins if the number is the same when the digits are reversed
***************************************************************/
	
	// Determins If The Givin Number Is The Same Number When Reversed (Returns A T/F Value)	
	if (number == reverse(number))
		return true;
	else
		return false;
}
//*************************************************************

// **isPrime**
bool isPrime(int number)
{
/***************************************************************
Function:  bool isPrime( int )

Use: This function determines if a number is a prime number

Arguments: an integer, the number to be tested

Returns: a boolean value that indicates if the number is or
         is not prime
***************************************************************/
	// Local Variables
	int count, sum, num;
	
	// Zeroing
	sum = 0;
	count = 1;
	
	// Determins Which Numbers Evenly Divide The Givin Number
	while (count <= number)
	{
		num = number % count;	// Finds which numbers have remainders
		
		// Adds All The Numbers That Divide Evenly
		if (num == 0)
			sum = number / count + sum;	// Stores numbers that have a remainder of 0
		count++;
	}
	
	// Determins If The Givin Nuber Is Prime (number can only be divided by itself and 1) (Returns A T/F Value)
	if (sum == number + 1)
		return true;
	else
		return false;
}
//***************************************************************

// **numerology**
void numerology(int sum)
{
/***************************************************************
Function:  int numerology( int )

Use: This function determines the numerlogy of a persons birthday

Arguments: three integers (day month year)

Returns: void
***************************************************************/
	
	// Adds Sum Of Digits in the numbers givin until a single digit remains
	while (sum >= 10)
		sum = sumDigits(sum);
	
	// Displays approiate message	
	cout << endl << "Your Life Path number is: " << sum << endl;
	if (sum == 1)
		cout << "This suggest that you are a individualistic, independent, and show leadership and drive" << endl;
	else if (sum == 2)
		cout << "This suggest that you are sensitive, tactful, diplomatic, and cooperative" << endl;
	else if (sum == 3)
		cout << "This suggest that you are creative and a good communicator" << endl;
	else if (sum == 4)
		cout << "This suggest that you are a natural planner, fixer, and builder" << endl;
	else if (sum == 5)
		cout << "This suggest that you are energetic, adventurous, daring, and freedom-loving" << endl;
	else if (sum == 6)
		cout << "This suggest that you are esponsible, loving, self-sacrificing, protective, and compassionate" << endl;
	else if (sum == 7)
		cout << "This suggest that you have a gift for investigation, analysis, and keen observation" << endl;
	else if (sum == 8)
		cout << "This suggest that you have skills to lead, direct, organize and govern" << endl;
	else
		cout << "This suggest that you are helpful, compassionate, sophisticated and generous" << endl;
}
