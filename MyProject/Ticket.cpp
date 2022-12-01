#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Ticket {
private:
	const int id;
	char* location = nullptr;
	string customerName = "";
	int price;

};