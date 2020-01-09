/***************************************************************
CSCI 240         Program 7     Fall 2017

Programmer: Cory Stojan

Section: 01

Date Due: November 03, 2017

Purpose: Writing functions that can be used to manipulate and test an integer number
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;




// Main
int main()
{
	// Set Seed Value
	srand(7);
	
	// Declared Variables
	int arraySize;
	
	
	// Declared Constants
	#define LWRBND 0.0
	#define UPRBND 100.0
	#define MINARRAYNUM 2
	#define MAXARRAYNUM 50
	#define NUMPERLINE 10
	#define CONSTANT6 INSERT VALUE
	
	// Declared Arrays
	
	// Declared Functions
	float buildArray();
	double randDouble();
	void printArray(double array[], int numberOfValues, string title);
	void sortArray(double array[], int numberOfValues);

	// Define Array Size
	arraySize = 2 + (rand() % (2 - 50 + 1));
	
	// Create Array Using numArray as Values
	double array[arraySize] = {buildArray()};
	
	return 0;
}

//**************************************************************************************************************************************************

int buildArray(double array[], int arraySize) 
{
	// Declare Variables
	int arrayPos;
	double num;

	float numArray[arraySize];
	for(arrayPos = 0; arrayPos < arraySize; arrayPos++)
	{
		array[arrayPos] = randDouble();
	}
	
	return numArray;
}


// Function That Creates A Random double Number For The Array
double randDouble()
{
	// Declare Variables
	double num;
	
	// Generates A Random Number
	num = LWRBND + (rand() / (RAND_MAX / (UPRBND - LWRBND)));
	
	
	return num;
}


/* 
void printArray( double array[], int numberOfValues, string title )
{
	
}
*/
/*
void sortArray( double array[], int numberOfValues )
{
	
}
*/




