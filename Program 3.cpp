/***************************************************************
CSCI 240         Program 3     Fall 2017

Programmer: Cory Stojan

Section: 0001

Date Due: September 15, 2017

Purpose: This program calculates and displays a course average for
         the CSCI 240 course.
***************************************************************/


/**************************************************************/
//Setup

#include <iostream>
#include <iomanip>


using namespace std;
int main()
{

cout << setiosflags( ios:: fixed ) << setprecision(2);
cout << "Extra Credit 1 And 2 Attempted" << endl;
/**************************************************************/
// Declared Variables
//                                                                     ** LEGAND **
float x;                                              // Program Average ----> x = Program Average
int y2,y3;                                            // y2 = PTS Avaliable, y3 = # of Quizzes
float y,y1,y4,y5;                                     // Test Average ----> y = Test Average, y1 = Sum of Test Scores,, y4 = Sum of Quizzes, y5 = Sum of Two Lowest Quiz Scores
float class_avg,test_avg,program_avg;                 // class_avg = Class Average, test_avg = Test Average, program_avg = Program Average
/**************************************************************/

// ** PROGRAM AVERAGE **
cout << "******************************\n" << "\nEnter The Program Average:" << endl;               // Prompts "Enter the Program Average"
cin >> x;                                                                      						// User Defines Program Average
program_avg = x;                                                              					    // Stores Program Average As x Value
	
// ** TEST AVERAGE **                                                                       
cout << "\nEnter The Sum Of The Test Scores:\n";                               // Prompts Info
cin >> y1;                                                                     // Stores User Input Values y1^
cout << "\nEnter The Maximum Test Points That Are Available:\n";               // Prompts Info 
cin >> y2;                                                                     // Stores User Input Values y2^
cout << "\nEnter The Total Number Of Quizzes Taken:\n";                        // Prompts Info 
cin >> y3;                                                                     // Stores User Input Values y3^
cout << "\nEnter The Sum Of All The Quizzes Taken:" << endl;                   // Prompts Info 
cin >> y4;                                                                     // Stores User Input Values y4^ 
if (y3 > 2)
	{
	cout << "\nEnter The Sum Of The Two Lowest Quiz Scores:" << endl;          // Prompts Info 
	cin >> y5;                                                                 // Stores User Input Values y5^ if more than two quizzes were taken
	}                                                                          
// ** CACULATIONS **
if (y3 <= 2)
	y = (y1 + y4) / (y2 + (10 * y3)) * 100;                                    // (sum of test scores + sum of quiz scores) / (maximum test points available + (10 * number of quizzes)) * 100
if (y3 > 2)	
	y = (y1 + y4 - y5) / (y2 + (10 * (y3 - 2))) * 100;                         // (sum of test scores + sum of quiz scores - sum of 2 lowest quiz scores) / (maximum test points available + (10 * (number of quizzes - 2))) * 100
test_avg = y;                                                                  // Test Average Value
class_avg = y * .7 + x * .3;                                                   // Calculates Average (30% Program Average, 70% Test Average)

// ** Display **
cout << "\n*********************************";
cout << "\nGrade Calculator" << endl;                                                        // Prompts Grade Calculator 
cout << "\nThe Program Average Is:   " << setw(6) <<  program_avg << endl;                    // Prompts Value for Program Average
cout << "The Quiz/Test Average Is: " << setw(6) <<  test_avg << endl;                    // Prompts Value for Test Average
cout << "\nThe Course Average Is:    " << setw(6)  << class_avg << endl;                      // Prompts Value for Course Average
cout << "*********************************\n" << endl; 
// ** EXTRA CREDIT 1 & 2 **	
// Displays Grade That Have Passing Program And Test Averages
if (program_avg >= 55.00) 
if (test_avg >= 55.00)		
	{
	if (class_avg >= 90.00)
			cout << "Grade: A\n";
	if (class_avg >= 80.00)
	if (class_avg < 90.00)
			cout << "Grade: B\n";
	if (class_avg >= 70.00)
	if (class_avg < 80.00)
			cout << "Grade: C\n";
	if (class_avg >= 60.00) 
	if (class_avg < 70.00)
			cout << "Grade: D\n";
	}
// Displays Grade With A Passing Class Average And A Failing Program Average Or Test Average
	{
if (class_avg >= 60.00)
if (program_avg < 55.00)
	cout << "You Have A Passing Average But, You Still Failed The Course Because Your Program Average Was Below A 55%." << "\nResulting Grade: F";
if (class_avg >= 60.00)
if (test_avg < 55.00)
	cout << "You Have A Passing Average But, You Still Failed The Course Because Your Test Average Was Below A 55%." << "\nResulting Grade: F";
	}
// Grades With Class Average Below 60%
if (class_avg < 60.00)
	cout << "You Failed The Course." << "\nResulting Grade: F";
		
// Congratulations Statement For Passing Grades Higher Than "C"
if (test_avg >= 70.00)
if (program_avg >= 70.00)
	cout << "Congratulations... You Passed";

return 0;
}
