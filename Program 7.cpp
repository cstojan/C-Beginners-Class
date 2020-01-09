/***************************************************************
CSCI 240         Program 7     Fall 2017

Programmer: Cory Stojan

Section: 01

Date Due: November 03, 2017

Purpose: Writing functions that can be used to manipulate and test an integer number
***************************************************************/

// Include Statements
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>

// Standard Namespaces
using namespace std;

// Functions
double randDouble();
int buildArray(double array[]);
void printArray(double array[], int numberOfValues, char headder[]);
void sortArray(double array[], int numberOfValues);
void mergeArrays(double array1[], int array1Size, double array2[], int array2Size, double extraCredit1[]);
void countValues( double array[], int arraySize );

// Global Constants
#define LWRBND 0.0
#define UPRBND 100.0
#define MINARRAYNUM 2
#define MAXARRAYNUM 50
#define NUMPERLINE 10
#define CONSTANT6 INSERT VALUE
#define MAXARRAYSIZE 50
#define ECARRAYSIZE 100
#define ZERO 0

// Gloabal Variables
int arraySize, array1Size, array2Size, mergeArraysSize;
char headder[30] = "Unsorted Numbers";


// Main
int main()
{
	// Set Seed Value
	srand(7);
//	srand(time(0));

	// Set Signifant Digit After Decimal To 1
	cout << setiosflags( ios:: fixed ) << setprecision(1);

	// Create Two Arrays (fill with random digit(0)) (50 reserved spaces)
	double array1[MAXARRAYSIZE];
	double array2[MAXARRAYSIZE];

	// *Extra Credit*
	double extraCredit1[ECARRAYSIZE]; // <--- ECARRAYSIZE (EXTRA CREDIT ARRAY SIZE)

	// ** Array1 **
	// Build Array1
	buildArray(array1);			// Remember That The Return Value Is The Number Of Elements Used

	// Print Array1
	cout << "There Are " << arraySize << " Numbers In Array 1 " << endl;
	printArray(array1, arraySize, headder);

	// Sort And Pring Array1
	sortArray(array1, arraySize);
	array1Size = arraySize;

	//Extra Credit 2
	countValues(array1, array1Size);

	// ** Array2 **
	// Build Array 2
	buildArray(array2);			// Remember That The Return Value Is The Number Of Elements Use

	// Print Array 2
	cout << "There Are " << arraySize << " Numbers In Array2 " << endl;
	printArray(array2, arraySize, headder);

	// Sort And Print Array2
	sortArray(array2, arraySize);
	array2Size = arraySize;

	// Extra Credit 2
	countValues(array2, array2Size);

	// **EXTRA CREDIT 1**
	mergeArraysSize = array1Size + array2Size;
	cout << "There Are " << mergeArraysSize << " Merged Numbers " << endl;
	cout << "**Extra Credit 1**" << endl << endl;
	extraCredit1[ECARRAYSIZE];
	mergeArrays(array1, array1Size, array2, array2Size, extraCredit1);

	// Extra Credit 2
	countValues(extraCredit1, mergeArraysSize);

return 0;
}

//*******************************************************************************************************************************************

double randDouble()
{
	// Local Variables
	double num;

	// Generates A Random Number
	num = LWRBND + (rand() / (RAND_MAX / (UPRBND - LWRBND)));

	return num;	
}

//*******************************************************************************************************************************************

int buildArray(double array[])
{
	// Local VAriables
	int num;

	// Local Constants
	#define ARRAYMIN 2
	#define ARRAYMAX 50

	// Create Random # Between 2 and 50 (used for the size of the array)
	arraySize = ARRAYMIN + (rand() % (ARRAYMAX - ARRAYMIN + 1));

	// Fill Array With Random Values
	for (int arrayPos = 0; arrayPos < arraySize; arrayPos++)
	{
		array[arrayPos] = randDouble();
	}

	return arraySize;
}

//*******************************************************************************************************************************************

void printArray(double array[], int arraySize, char headder[])
{
	// Local Varibles
	int count, rowCount, arrayPos;

	// Reset Variables
	arrayPos = 0;
	rowCount = 0;

	// Headder
	cout << headder << endl;
	cout << "-----------------------------" << endl;

	//Display Values In Array (10 Per Line)
	while (arrayPos < arraySize)
	{
		if (rowCount == 10)
		{
			cout << endl;
			rowCount = 0;
		}

		cout << setw(5) << array[arrayPos] << " ";
		arrayPos++;
		rowCount++;
	}

	cout << endl << endl;

}

//*******************************************************************************************************************************************

void sortArray(double array[], int arraySize)
{
	// Local Variables
	double saveNum;
	int count, testNum, exeCount, lowestNum, arrayPos;

	// Resets Numbers
	arrayPos = 0;
	count = 1;

	// Sorts Array Numbers (least to greatest)
	for (exeCount = 0; exeCount < arraySize; exeCount++)
	{
		while(count < arraySize)
		{
			if (array[arrayPos] > array[count])
			{
				saveNum = array[arrayPos];
				array[arrayPos] = array[count];
				array[count] = saveNum;
				count++;
			}
			
			else
			{
				count++;
			}
		}

		arrayPos++;
		count = arrayPos + 1;
	}

	char headder[] = "Sorted Numbers";
	//Prints sorted array
	printArray(array, arraySize, headder);
	cout << endl << endl;
}

//*******************************************************************************************************************************************

void mergeArrays(double array1[], int array1Size, double array2[], int array2Size, double extraCredit1[])
{
	//Local Varibles
	int insertPos, arraySize, array1Pos, array2Pos, arrayPos;

	// Set Variables To Default
	array1Pos = 0;
	array2Pos = 0;
	arrayPos = 0;
	insertPos = 0;

	// Combines And Sorts Two Sorted Arrays Into One Array
	for (arraySize = array1Size + array2Size; arrayPos < arraySize; arrayPos++)
	{
		if (array2Pos < array2Size && array1Pos < array1Size)
		{ 
			if (array1[array1Pos] > array2[array2Pos])
			{ 
				extraCredit1[insertPos] = array2[array2Pos];
				array2Pos++;
				insertPos++;
			}

			else
			{ 
				extraCredit1[insertPos] = array1[array1Pos];
				array1Pos++;
				insertPos++;
			}
		}

		else if (array1Pos >= array1Size && array2Pos < array2Size)
		{
			extraCredit1[insertPos] = array2[array2Pos];
			array2Pos++;
			insertPos++;
		}

		else 
		{
			extraCredit1[insertPos] = array1[array1Pos];
			array1Pos++;
			insertPos++;
		}
	}

	// Print Combined Numbers

	char headder[] = "Combined Array Numbers";
	printArray(extraCredit1, arraySize, headder);
}

//*******************************************************************************************************************************************

void countValues(double array[], int arraySize)
{
	// Local Variables
	int count, arrayPos, count0, count10, count20, count30, count40, count50, count60, count70, count80, count90;

	//Local Constants
	#define LESTEN 10
	#define LESTWENTY 20
	#define LESTHIRTY 30
	#define LESFOURTY 40
	#define LESFIFTY 50
	#define LESSIXTY 60
	#define LESSEVENTY 70
	#define LESEIGHTY 80
	#define LESNINTY 90
	#define LESHUNDRED 100

	// Set Variables To Default
	count = 0;
	arrayPos = 0;
	count0 = 0;
	count10 = 0;
	count20 = 0;
	count30 = 0;
	count40 = 0;
	count50 = 0;
	count60 = 0;
	count70 = 0;
	count80 = 0;
	count90 = 0;

	// Counts Numbers Between The Values
	while (count < arraySize)
	{
		if (array[arrayPos] < LESTEN)
		{
			count0++;
		}

		else if (array[arrayPos] < LESTWENTY)
		{
			count10++;
		}

		else if (array[arrayPos] < LESTHIRTY)
		{
			count20++;
		}

		else if (array[arrayPos] < LESFOURTY)
		{
			count30++;
		}

		else if (array[arrayPos] < LESFIFTY)
		{
			count40++;
		}

		else if (array[arrayPos] < LESSIXTY)
		{
			count50++;
		}

		else if (array[arrayPos] < LESSEVENTY)
		{
			count60++;
		}

		else if (array[arrayPos] < LESEIGHTY)
		{
			count70++;
		}

		else if (array[arrayPos] < LESNINTY)
		{
			count80++;
		}

		else
		{
			count90++;
		}

		count++;
		arrayPos++;
	}

	// Display Values
	cout << setw(3)
	<< "Number Of Values Between  0 And  9.9 is: " << count0  << endl
	<< "Number Of Values Between 10 And 19.9 is: " << count10 << endl
	<< "Number Of Values Between 20 And 29.9 is: " << count20 << endl
	<< "Number Of Values Between 30 And 39.9 is: " << count30 << endl
	<< "Number Of Values Between 40 And 49.9 is: " << count40 << endl
	<< "Number Of Values Between 50 And 59.9 is: " << count50 << endl
	<< "Number Of Values Between 60 And 69.9 is: " << count60 << endl
	<< "Number Of Values Between 70 And 79.9 is: " << count70 << endl
	<< "Number Of Values Between 80 And 89.9 is: " << count80 << endl
	<< "Number Of Values Between 90 And 99.9 is: " << count90 << endl
	<< endl;
}
