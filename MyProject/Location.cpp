#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Location {
private:
	string locationNname = "";
	int noRows = 0;
	int* row = nullptr;
	string zone = "";

	static int NO_LOCATIONS;
};