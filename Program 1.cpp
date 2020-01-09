/***************************************************************
CSCI 240         Program 1     Fall 2017

Programmer: Cory Stojan

Section: 0001

Date Due: September 8, 2017

Purpose: This program calculates and displays a course average for
         the CSCI 240 course.
***************************************************************/


/**************************************************************/
//Setup

#include <iostream>
#include <iomanip>

using namespace std;
int main()

{float x, y;
/**************************************************************/

float program_avg;
// Prompt User for Program Average
cout << "Enter the Program Average:\n";                             // Prompts "Enter the Program Average"
cin >> x;                                                           // User Defines Program Average
program_avg = x;                                              // Stores Program Average As x Value


// Prompt User for Test Average
cout << "\nEnter the Test Average:\n";                              // Prompts "Enter the Test Average"
cin >> y;                                                           // User Defines Test Average
float test_avg = y;                                                 // Stores Test Average As y Value

// Calculate Average (30% Program Average, 70% Test Average)
float class_avg = y * .7 + x * .3;                                  // Calculates Average
 
// Display Average
cout << "\n*******************************";
cout << "\nGrade Calculator";                                       // Prompts Grade Calculator 
cout << "\n\nProgram Average:        " << program_avg;              // Prompts Value for Program Average
cout << "\nTest Average:           " << test_avg;                   // Prompts Value for Test Average
cout << "\n\nThe Course Average is:  " << class_avg;                // Prompts Course Average
cout << "\n*******************************"; 
 
return 0;
}
