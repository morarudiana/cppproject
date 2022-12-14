#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Location {
private:
	string locationName = "";
	int noRows = 0;
	int* row = nullptr;
	string zone = "";

	static int NO_LOCATIONS;    
	

public:
	Location() {

	}

	Location(string locationName, int noRows, int* row, string zone) {    
		this->locationName = locationName;
		this->noRows = noRows;
		this->row = new int[noRows];
		for (int i = 0; i < noRows; i++) {
			this->row[i] = row[i];
		}
		this->zone = zone;
		NO_LOCATIONS++;
	}

	Location(const Location& location) {
		this->locationName = location.locationName;
		this->noRows = location.noRows;
		this->row = new int[noRows];
		for (int i = 0; i < noRows; i++) {
			this->row[i] = location.row[i];
		}
		this->zone = location.zone;
	}

	~Location() {
		if(this->row!=nullptr)
		delete[] this->row;
		NO_LOCATIONS--;
	}

	Location& operator=(const Location& location) {
		if (row != nullptr)
			delete[] row;
		this->locationName = location.locationName;
		this->noRows = location.noRows;
		this->row = new int[noRows];
		for (int i = 0; i < noRows; i++) {
			this->row[i] = location.row[i];
		}
		this->zone = location.zone;
		return *this;
	}

	string getLocationName() {
		return this->locationName;
	}

	int getNoRows() {
		return this->noRows;
	}

	int* getRow() { 
		return this->row;
	}

	string getZone() {
		return this->zone;
	}

	static int getNoLocations() {
		return Location::NO_LOCATIONS;
	}

	void setLocationName(string locationName) {
		if (locationName.length() < 1)
			throw new exception  ("You need to input a valid name!");
		else {
			this->locationName = locationName;
		}
	}


	void setRow(int* NewRow, int newNoRows) {
		if (noRows < 1)
			throw new exception  ("You don't have enough rows!");
		else {
			this->noRows = newNoRows;
			if (this->row != nullptr) {
				delete[] this->row;
			}
			this->row = new int[this->noRows];
			for (int i = 0; i < noRows; i++) {
				this->row[i] = NewRow[i];
			}
		}
	}
	void setZone(string zone) {
		if (zone.length() < 1)
			throw new exception  ("You need to input a valid zone!");
		else {
			this->zone = zone;
		}
	}

	bool operator<=(int value) {
		return this->noRows <= value;
	}

	void operator-(int minus) {
		noRows -= minus;
	}

	friend ostream& operator<<(ostream& cout, const Location& l) {
		cout << "Location name: " << l.locationName << endl << "Number of rows: " << l.noRows << endl << "Row: " << l.row << endl << "Zone: " << l.zone;
		return cout;
	}
	friend istream& operator>>(istream& cin, Location& l) {
		cout << "Location name: "; cin >> l.locationName;
		cout << "Number of rows: "; cin >> l.noRows;
		cout << "Row: ";
		l.row = new int[l.noRows];
		for (int i = 0; i < l.noRows; i++)
			cin >> l.row[i];
		cout << "Zone: "; cin >> l.zone;
		return cin;
	}

};




