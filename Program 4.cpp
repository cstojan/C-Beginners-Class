/***************************************************************
CSCI 240         Program 4     Fall 2017

Programmer: Cory Stojan

Section: 0001

Date Due: September 29, 2017

Purpose: This program generate a random numbers using three
different loop types.
***************************************************************/


/**************************************************************/
// **Setup**

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()

{
// Declared Variables
int loop_count,remainder,ran_num,loop_constant,current_count;           // Loop Variables  
int even,odd,zeros;              					                    // Random Digit Type
int odd_graph,even_graph,zeros_graph,graph_count,graph_total;           // Graph Variables

/**************************************************************/

// Constants
const int RANDOM_MAX = 20;
const int RANDOM_MIN = 2;
const int LOOP_MAX = 99;
const int LOOP_MIN = 0;

// Reset To Zero                                 
ran_num = 0;
even = 0;
odd = 0;
zeros = 0;
loop_constant = 0; 

// Random # Type
srand(15);
cout << "Extra Credit Attempted\n" << endl;

// ** For Loop **
cout << "**For Loop**" << endl;
loop_constant = RANDOM_MIN + (rand()) % (RANDOM_MAX - RANDOM_MIN +1);
cout << "The Random Number Generator Will Generate " << loop_constant << " Random Numbers." << endl;
for (current_count = 0; current_count < loop_constant; current_count++)
	{
	ran_num = LOOP_MIN + (rand()) % (LOOP_MAX - LOOP_MIN +1);                               // minimum_value + (rand() % (maximum_value - minimum_value + 1));
	cout << ran_num << " ";
	if (ran_num == 0)
		zeros++;
	else
		{
		remainder = ran_num % 2;
	if (remainder == 0)
		even++;
	else
		odd++;
		}
	}
cout << "\nThere is " << odd << " odd numbers and " << even << " even numbers and " << zeros << " zeros." << endl;

// **Extra Credit (Addition For Graph)**
odd_graph = 0;
even_graph = 0;
zeros_graph = 0;

if (odd >= 1 )
	odd_graph = odd;
if (even >= 1)
	even_graph = even;
if (zeros >= 1)
	zeros_graph = zeros;
/******************************/

// ** While loop **
// Reset To Zero
ran_num = 0;
current_count = 0;
loop_constant = 0;
zeros = 0;
even = 0;
odd = 0;

// Loop
cout << "\n**While Loop**" << endl;
loop_constant = RANDOM_MIN + (rand()) % (RANDOM_MAX - RANDOM_MIN +1);
cout << "The Random Number Generator Will Generate " << loop_constant << " Random Number." << endl;
while (current_count < loop_constant)
	{
	ran_num = LOOP_MIN + (rand()) % (LOOP_MAX - LOOP_MIN +1);                               // minimum_value + (rand() % (maximum_value - minimum_value + 1));
	cout << ran_num << " ";
	if (ran_num == 0)
		zeros++;
	else
		{
		remainder = ran_num % 2;
		if (remainder == 1)
			odd++;
		else
			even++;
		}
	current_count++;
	}
cout << "\nThere is " << odd << " odd numbers and " << even << " even numbers and " << zeros << " zeros." << endl;

// **Extra Credit (Addition For Math)**
if (odd >= 1)
	odd_graph = odd_graph + odd;
if (even >= 1)
	even_graph = even_graph + even;
if (zeros >= 1)
	zeros_graph = zeros_graph + zeros;
/*********************************************/

// ** Do While **
// Reset To Zero
ran_num = 0;
current_count = 0;
loop_constant = 0;
zeros = 0;
even = 0;
odd = 0;

// Loop
cout << "\n**Do.. While**" << endl;
loop_constant = RANDOM_MIN + (rand()) % (RANDOM_MAX - RANDOM_MIN + 1);
cout << "The Random Number Generator Will Generate " << loop_constant << " Random Numbers." << endl;
do 
{
	ran_num = LOOP_MIN + (rand()) % (LOOP_MAX - LOOP_MIN +1);                               // minimum_value + (rand() % (maximum_value - minimum_value + 1));
	cout << ran_num << " ";
	if (ran_num == 0)
		zeros++;
	else
	{
		remainder = ran_num % 2;
	if (remainder == 1)
		odd++;
	else
		even++;
	}
	current_count++;
}
while (current_count < loop_constant);
cout << "\nThere is " << odd << " odd numbers and " << even << " even numbers and " << zeros << " zeros." << endl;

// **EXTRA CREDIT**
cout << "\n**EXTRA CREDIT**" << endl;
// Extra Credit Additon (For Graph)
if (odd >=  1)
	odd_graph = odd_graph + odd;
if (even >= 1)
	even_graph = even_graph + even;
if (zeros >= 1)
	zeros_graph = zeros_graph + zeros;
graph_total = zeros_graph + even_graph + odd_graph;
cout << "The Total Amount Of Numbers Is: " << graph_total;

// Odd Graph
graph_count = 0;
cout << endl << setw(3) << odd_graph << " Number of Odd Numbers  = ";
while (graph_count < odd_graph)
{
	if (odd_graph > 0)
	{
	cout << "*";
	graph_count++;
	}
	else
	{
		graph_count = odd_graph + 1;
		cout << "None." << endl;
	}
}

// Even Graph
graph_count = 0;
cout << endl << setw(3) << even_graph << " Number of Even Numbers = ";
while (graph_count < even_graph)
{
	if (even_graph > 0)
	{
		cout << "*";
		graph_count++;
	}
	else
	{
		graph_count = even_graph + 1;
		cout << "None." << endl;
	}
}

// Zeros Graph
graph_count = 0;
cout << endl << setw(3) << zeros_graph <<" Number of Zero Numbers = ";
while (graph_count < zeros_graph)
{
	if (zeros_graph > 0)
	{
		cout << "*";
		graph_count++;
	}
	else 
	{
		graph_count = zeros_graph + 1;
		cout << "None." << endl;
	}
} 

return 0;

}


