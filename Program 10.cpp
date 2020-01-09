/***************************************************************
CSCI 240         Program 10     Fall 2017

Programmer: Cory Stojan

Section: 01

Date Due: December 08, 2017

Purpose: This Program Implements And Uses A Class That
		 Represents Information About A Salesperson.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

// **Classes**
class Seller
/*
This Class Displays Information About A Seller.
*/
{
	private:
	// Data Members
	char firstName[20];
	char lastName[30];
	char ID[7];
	double salesTotal;

	public:
	// Constructors
	Seller();
	Seller(const char fistName[], const char lastName[], const char ID[], double salesTotal);

	// Methods
	void print();
	void setFirstName(const char []);
	void setLastName(const char []);
	void setID(const char []);
	void setSalesTotal(double);
	double getSalesTotal();
};

int main()
{
	// **Initial Setteings**
	cout << setiosflags(ios::fixed) << setprecision(2);

	// **Objects**
	// Seller One
	cout << "\n*** The First Seller Object ***" << endl;
	Seller Seller_One("Cory", "Stojan", "CSI240", 1234.56); // <-- Intital Settings
	Seller_One.print();

	// Seller Two
	cout << "\n*** The Second Seller Object ***" << endl; 
	Seller Seller_Two; // <-- Intital Settings
	Seller_Two.print();
	Seller_Two.setFirstName("Terry"); // <-- Change from intial Setting
	Seller_Two.setLastName("Bollea"); // <-- Change from intial Setting
	Seller_Two.setID("HULK96");  // <-- Change from intial Setting
	Seller_Two.setSalesTotal(246.8); // <-- Change from intial Setting
	Seller_Two.print();

	// Seller Three 
	cout << "\n*** The Third Seller Object ***" << endl; 
	Seller Seller_Three("", "Johnson", "TOOBIG999", 876.34); // <-- Intital Settings
	Seller_Three.print();
	Seller_Three.setFirstName("Dwayne"); // <-- Change to intial Setting
	Seller_Three.setID("ROCK89"); // <-- Change from intial Setting
	Seller_Three.print();

	// Seller Four 
	cout << "\n*** The Fourth Seller Object ***" << endl; 
	Seller Seller_Four("James", "Hellwig", "ULTWAR", 13579.11); // <-- Intital Settings
	cout << "The Sales Total Is $" << Seller_Four.getSalesTotal() << endl;

	// Seller Five 
	cout << "\n*** The Fifth Seller Object ***" << endl; 
	Seller Seller_Five("Roderick", "Toombs", "PIPER4", 24680.24); // <-- Intital Settings
	Seller_Five.print();
	Seller_Five.setFirstName(""); // <-- Change from intial Setting
	Seller_Five.setLastName(""); // <-- Change from intial Setting
	Seller_Five.setID(""); // <-- Change friom intial Setting
	Seller_Five.setSalesTotal(-19.88); // <-- Change from intial Setting
	Seller_Five.print();

	return 0;
}

//***************************************************************************************************************
// **Constructors**
// Constructor #1 (Default)
Seller::Seller()
{
	// Copies An Empty String Into Each Data Member (and a double for salesTotal) And Passes It To A Method.
	strcpy(firstName, "");
	strcpy(lastName, "");
	strcpy(ID, "");
	salesTotal = 0.00;
	// Initalizes Default Settings.
	setFirstName(firstName);
	setLastName(lastName);
	setID(ID);
	setSalesTotal(salesTotal);
}

// Constructor #2
Seller::Seller(const char NewFirstName[], const char NewLastName[], const char NewID[], double NewSalesTotal)
{
	setFirstName(NewFirstName);
	setLastName(NewLastName);
	setID(NewID);
	setSalesTotal(NewSalesTotal);
}

// **Methods**
//***************************************************************************************************************
void Seller::print()
/*
Name Of Method: print
Number/Names of Arguments: None
Number/Names of Returns: None
Basic Function: This method displays the Seller information. (Last Name, First Name, ID, Salaes Total)
*/
{
	//Example
	//Giant, Andre               BIG357               678.53
	cout << left << lastName << ", " << setw(10) << firstName << "\t" << ID << "\t" << "$" << salesTotal << endl;
}

//***************************************************************************************************************
void Seller::setFirstName(const char NewFirstName[])
/*
Name Of Method: setFirstName
Number/Names of Arguments: 1 (The Seller's first Name)
Number/Names of Returns: None
Basic Function: This method changes a Seller's first name.
*/
{
	if ( strlen(NewFirstName) > 0 )
	{
		strcpy( firstName, NewFirstName );
	}
	else
	{
		strcpy(firstName, "None");
	}
}

//***************************************************************************************************************
void Seller::setLastName(const char NewLastName[])
/*
Name Of Method: setLastName
Number/Names of Arguments: 1 (The Seller's Last Name)
Number/Names of Returns: None
Basic Function: This method changes a Seller's last name.
*/
{
	if (strlen(NewLastName) > 0)
	{
		strcpy(lastName, NewLastName);
	}
	else
	{
		strcpy(lastName, "None");
	}
}

//***************************************************************************************************************
void Seller::setID(const char NewID[])
/*
Name Of Method: setID
Number/Names of Arguments: 1 (The Seller's ID Number)
Number/Names of Returns: None
Basic Function: This method changes a Seller's id number.
*/
{
	if (strlen(NewID) < 7 && strlen(NewID) > 0)
	{
		strcpy(ID, NewID);
	}
	else
	{
		strcpy(ID, "ZZZ000");
	}
}

//***************************************************************************************************************
void Seller::setSalesTotal( double NewSalesTotal )
/*
Name Of Method: setSalesTotal
Number/Names of Arguments: 1 (The Seller's Sales Total)
Number/Names of Returns: None
Basic Function: This method changes a Seller's sales total.
*/
{
	if (NewSalesTotal >= 0.00)
	{
		salesTotal = NewSalesTotal;
	}
	else
	salesTotal = 0.00;	
}

//***************************************************************************************************************
double Seller::getSalesTotal()
/*
Name Of Method: getSalesTotal
Number/Names of Arguments: None
Number/Names of Returns: 1 (The Seller's Sales)
Basic Function: This method returns a Seller's sales total data member.
*/
{
	// Get Sales Total
	int get_salesTotal;

	return salesTotal;
}
