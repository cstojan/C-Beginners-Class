/***************************************************************
CSCI 240         Program 9     Fall 2017

Programmer: Cory Stojan

Section: 01

Date Due: December 01, 2017

Purpose: This Program Caclulates And Displays Results Of A Parabola
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

// Classes
class Parabola
{
	private:
	//Data_Types
	double a_coefficient, b_coefficient, c_coefficient;

	public:
	//Methods
	double calcDiscrim();
	int calcRoots( double&, double& );
	double calcX();
	double calcY();
	void printEquation();
	void printVertex();
	void printRoots();
	void printConcavity();
	void print();

	//Constructor
	Parabola( double a_coefficient, double b_coefficient, double c_coefficient );
};

int main()
{
	// Objects & Calculations (Methods Described Below)
	// Parabola 1
	cout << "*** The First Parabola ***" << endl;
	Parabola Parabola_One( 1, 4, -5 ); // (Values Are In The Order: a_coefficient, b_coefficient, c_coefficient)
	Parabola_One.print();
	
	// Parabola 2
	cout << endl << "*** The Second Parabola ***" << endl;
	Parabola Parabola_Two( 0, 0, 25 ); // (Values Are In The Order: a_coefficient, b_coefficient, c_coefficient)
	Parabola_Two.print();

	// Parabola 3
	cout << endl << "*** The Third Parabola ***" << endl;
	Parabola Parabola_Three( -1, 2, -1 ); // (Values Are In The Order: a_coefficient, b_coefficient, c_coefficient)
	Parabola_Three.printEquation();
	Parabola_Three.printConcavity();

	// Parabola 4
	cout << endl << "*** The Fourth Parabola ***" << endl;
	Parabola Parabola_Four( -12, -2, 3 ); // (Values Are In The Order: a_coefficient, b_coefficient, c_coefficient)
	Parabola_Four.printRoots();

	// Parabola 5
	cout << endl << "*** The Fifth Parabola ***" << endl;
	Parabola Parabola_Five( 12, 2, 3 ); // (Values Are In The Order: a_coefficient, b_coefficient, c_coefficient)
	Parabola_Five.printEquation();
	Parabola_Five.printVertex();

	return 0;
}

//***************************************************************************************************************
// Constructor
Parabola::Parabola(double inta_coefficient, double intb_coefficient, double intc_coefficient)
{
	// Error Checking (a_coefficient cannot be 0)
	if ( inta_coefficient != 0 )
	{
		a_coefficient = inta_coefficient;
	}
	else
	{
		a_coefficient = 1;
	}

	// Remaining Varialbes
	b_coefficient = intb_coefficient;
	c_coefficient = intc_coefficient;
}

//***************************************************************************************************************
double Parabola::calcDiscrim()
/*
Name Of Method: calcDiscrim
Number/Names of Arguments: None
Number/Names of Returns: 1 ( discriminant)
Basic Function: This method calculates and returns the value of the discriminant.
*/
{
	// Delcared Variables
	int discriminant;

	// Calculates discriminant
	discriminant = (b_coefficient * b_coefficient) - 4 * a_coefficient * c_coefficient;

	return discriminant;
}

//***************************************************************************************************************
int Parabola::calcRoots( double &Root1, double &Root2 )
/*
Name Of Method: calcRoots
Number/Names of Arguments: 2 (root1, root2)
Number/Names of Returns: 1 ( NumOfRoots )
Basic Function: This method calculates and passes back the roots for the parabola, if they exist,
 				and returns the number of roots.
*/
{
	// Local Variables
	int NumOfRoots;
	double discriminant;

	// Call calcDiscrim
	discriminant = calcDiscrim();

	//Calculates Roots
	if ( discriminant > 0 )
	{
		Root1 = ( -b_coefficient + sqrt( discriminant )) / ( 2 * a_coefficient );
		Root2 = ( -b_coefficient - sqrt( discriminant )) / ( 2 * a_coefficient );
		NumOfRoots = 2;
	}
	else if ( discriminant == 0)
	{
		Root1 = ( -b_coefficient + sqrt( discriminant )) / ( 2 * a_coefficient );
		NumOfRoots = 1;
	}
	else
	{
		NumOfRoots = 0;
	}

	//Returns # Of Roots
	return NumOfRoots;
}

//***************************************************************************************************************
double Parabola::calcX()
/*
Name Of Method: calcX
Number/Names of Arguments: None
Number/Names of Returns: 1 (X-Coordinate)
Basic Function: This method calculates and returns the x-coordinate of the vertex of the parabola
*/
{
	//Local Variables
	double X_Coordinate;

	X_Coordinate = -b_coefficient / ( 2 * a_coefficient);

	return X_Coordinate;
}

//***************************************************************************************************************
double Parabola::calcY()
/*
Name Of Method: calcY
Number/Names of Arguments: None
Number/Names of Returns: 1 (Y-Coordinate)
Basic Function: This method calculates and returns the y-coordinate of the vertex of the parabola.
*/
{
	// Local Variables
	double Y_Coordinate, X_Coordinate;

	// Call calcX
	X_Coordinate = calcX();

	// Calculate Y_Coordinate
	Y_Coordinate = ( a_coefficient * (X_Coordinate * X_Coordinate) ) + ( b_coefficient * X_Coordinate ) + c_coefficient;

	// Returns Y_Coordinate
	return Y_Coordinate;
}

//***************************************************************************************************************
void Parabola::printEquation()
/*
Name Of Method: printEquation
Number/Names of Arguments: None
Number/Names of Returns: None
Basic Function: This method displays the parabola in the form of a quadratic equation.
*/
{
	cout << setiosflags( ios:: fixed ) << setprecision(1);
	cout << a_coefficient << "x^2 + " << b_coefficient << "x + " << c_coefficient << endl;
}

//***************************************************************************************************************
void Parabola::printVertex()
/*
Name Of Method: printVertex
Number/Names of Arguments: None
Number/Names of Returns: None
Basic Function: This method displays the x and y-coordinates of the vertex of the parabola.
*/
{
	//Local Variables
	double X_Coordinate, Y_Coordinate;

	// call calc x and calc y
	X_Coordinate = calcX();
	Y_Coordinate = calcY();
	cout << setiosflags( ios:: fixed) << setprecision(3);
	cout << "	Vertex Coordinates: (" << X_Coordinate << ", " << Y_Coordinate << ")" << endl;
}

//***************************************************************************************************************
void Parabola::printRoots()
/*
Name Of Method: printRoots
Number/Names of Arguments: None
Number/Names of Returns: None
Basic Function: This method displays the roots of the parabola (if they exist).
*/
{
	// calc roots method
	// replace root values with actual variables
	int NumOfRoots;
	double Root1, Root2;
	
	// Retreive # Of Roots
	NumOfRoots = calcRoots(Root1, Root2);

	// Display Roots
	cout << setiosflags( ios:: fixed ) << setprecision(3);
	if (NumOfRoots == 0)
	{
		cout << "	There Are No Real Roots." << endl;
	}
	else if (NumOfRoots == 1)
	{
		cout << "	There Is One Real Root With X-Coordinate " << Root1 << endl;
	}
	else
	{
		cout << "	There Are Two Real Roots With X-Coordinates " << Root1 << " and " << Root2 << endl;
	}
}

//***************************************************************************************************************
void Parabola::printConcavity()
/*
Name Of Method: printConcavity
Number/Names of Arguments: None
Number/Names of Returns: None
Basic Function: This method displays the direction that the parabola opens.
*/
{
	if ( a_coefficient > 0 )
	{
		cout << "	The Parabola Opens UPWARDS" << endl;
	}
	else
	{
		cout << "	The Parabola Opens DOWNWARDS" << endl;
	}
}

//***************************************************************************************************************
void Parabola::print()
/*
Name Of Method: print
Number/Names of Arguments: None
Number/Names of Returns: None
Basic Function: This method displays everything related to the parabola.
*/
{
	printEquation();
	printVertex();
	printConcavity();
	printRoots();
}
