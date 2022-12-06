//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Event.h"
#include "Ticket.h"
#include "Location.h"

using namespace std;

void main() {
	Ticket t1(1,(char*)"Romexpo","Popescu Andrei",300);
	cout << t1.getLocation()<<endl;
	cout << t1<<endl;
}
