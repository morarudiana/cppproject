//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Event.h"
#include "Ticket.h"
#include "Location.h"

using namespace std;

int Location::NO_LOCATIONS = 0; //asa e pe net...

void main() {

	//-----------------------------------------------TICKET CLASS-------------------------------------------------------

	Ticket t1(1,(char*)"Romexpo","Popescu Andrei",300); //constr with parameters

	cout << t1.getLocation()<<endl; //getter for location

	cout << t1.getCustomerName() << endl;//getter for name

	cout << t1<<endl;//displaying the info

	Ticket t2 = t1;//copy constr
	cout << t2;

	//testing the price validation
	try
	{
		t2.setPrice(0);
		cout << t2.getPrice();
	}
	catch (exception* ex)
	{
		cout << "Exceptie: " << ex->what() << endl;
	}

	//testing  * operator
	t1 * 2;
	cout << t1;

	//testing >> operator	
	//cin >> t1;   //it throws an error when I read the price

	//testing [] operator	
	char secondLocationChar = t1[1];
	t1[1] = 'X';
	cout << t1;

	//-----------------------------------------------EVENT CLASS-------------------------------------------------------

	Event e1("Nostalgia", "12/12/2022", 2030, "Herastrau");//constr with parameters
	cout << e1;

	//testing >> and <<
	Event e2;
	cin >> e2;
	cout << e2;

	//! op
	if (!e1) {
		cout << endl << "The hour is 0";
	}

	//----------------------------------------------LOCATION CLASS---------------------------------------------------

	//string x = "Arena Nationala";
	int v[4] = { 1,2,3,4 };
	Location l1("Arena Nationala", 3, v, "B");   //constr with parameters
	cout << l1<<endl;
	Location l2 = l1; //copy constr
	cout << l2;
	
	//<= op
	if (l2 <= 6)
		cout << endl << "The number of rows is less than 6"<<endl;

	//- op
	l2 - 1;
	cout << l2;

	Location l3;
	cin >> l3;
	cout << l3;
}
