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

	void setLocationName(string locationName) {
		if (locationName.length() < 1)
			throw "You need to input a valid name!";
		else {
			this->locationName = locationName;
		}
	}


	void setRow(int* NewRow, int newNoRows) {
		if (noRows < 1)
			throw "You don't have enough rows!";
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
			throw "You need to input a valid zone!";
		else {
			this->zone = zone;
		}
	}
};