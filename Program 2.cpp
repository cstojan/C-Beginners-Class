/***************************************************************
CSCI 240         Program 2     Fall 2017

Programmer: Cory Stojan

Section: 0001

Date Due: September 15, 2017

Purpose: This program calculates and displays a course average for
         the CSCI 240 course.
***************************************************************/

// ** SETUP **

#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

// ** DECLARED VARIABLES **                                                                      ** LEGAND **
float x;                                                                                // x = Program Average
int y2,y3;											                                    // y2 = PTS Avaliable, y3 = # of Quizzes 
float y,y1,y4,y5;                                                                       // Test Average ----> y = Test Average, y1 = Sum of Test Scores,y4 = Sum of Quizzes, y5 = Sum of Two Lowest Quiz Scores
float test_avg,program_avg,class_avg;                                                   // test_avg = Test Average, program_avg = Program Average, class_avg = Class Average

// ** OUTPUT FORMATING **
cout << setiosflags( ios:: fixed ) << setprecision(2);                                                   

// ** INPUT PROGRAM AVERAGE ***/                                                                 **Helpfull Info**
cout << "Enter The Program Average:\n";                                                 // Prompts "Enter the Program Average"
cin >> x;                                                                               // User Defines Program Average
program_avg = x;                                                                        // Stores Program Average As x Value

// ** INPUT TEST AVERAGE **                                                                      
cout << "\nEnter The Sum Of The Test Scores:\n";                                        // Prompts Request
cin >> y1;                                                                              // Stores User Input Values y1^
cout << "\nEnter The Maximum Test Points That Are Available:\n";                        // Prompts Request 
cin >> y2;                                                                              // Stores User Input Values y2^
cout << "\nEnter The Total Number Of Quizzes Taken:\n";                                 // Prompts Request 
cin >> y3;                                                                              // Stores User Input Values y3^
cout << "\nEnter The Sum Of All The Quizzes Taken:\n";                                  // Prompts Request 
cin >> y4;                                                                              // Stores User Input Values y4^ 
cout << "\nEnter The Sum Of The Two Lowest Quiz Scores:\n";                             // Prompts Request 
cin >> y5;                                                                              // Stores User Input Values y5^

// **GRADE CACULATIONS **                                                                                            
y = (y1 + y4 - y5) / (y2 + (10 * (y3 - 2))) * 100;                                      // Formula: (sum of test scores + sum of quiz scores - sum of 2 lowest quiz scores) / (maximum test points available + (10 * (number of quizzes - 2))) * 100
test_avg = y;                                                                           // Test Average Value
class_avg = y * .7 + x * .3;                                                            // Calculates Average (30% Program Average, 70% Test Average)

// ** Display **
cout << "\n*********************************";
cout << "\nGrade Calculator";                                                           // Prompts Grade Calculator 
cout << "\n\nThe Program Average Is:  "  << setw(6) << program_avg;                     // Prompts Value for Program Average
cout << "\nThe Test Average Is:     " << setw(6) <<  test_avg;                          // Prompts Value for Test Average
cout << "\n\nThe Course Average Is:   " << setw(6) << class_avg;                        // Prompts Value for Course Average
cout << "\n*********************************"; 

return 0;
}
