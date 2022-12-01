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
	int price=0;

public:
	//constr fara par
	Ticket():id(0) {

	}

	//constr cu par
	Ticket(int id, char* location, string customerName, int price):id(id) {
		location = new char[strlen(location) + 1];
		strcpy(this->location, location);
		this->customerName = customerName;
		this->price = price;
	}

	//copy constr
	Ticket(const Ticket& ticket):id(ticket.id) {
		location = new char[strlen(location) + 1];
		strcpy(this->location,ticket.location);
		this->customerName = ticket.customerName;
		this->price = ticket.price;
	}

	//operator =
	Ticket& operator=(const Ticket& ticket) {
		delete[] location;
		location = new char[strlen(location) + 1];
		strcpy(this->location, ticket.location);
		this->customerName = ticket.customerName;
		this->price = ticket.price;
	}

	//destructor
	~Ticket() {
		delete[] location;
	}

	char* getLocation() {
		return this->location;
	}

	string getCustomerName() {
		return this->customerName;
	}

	int getPrice() {
		return this->price;
	}

	void setLocation(char* newLocation) {
		if (this->location != nullptr) {
			delete[] location;
		}
		if (strlen(newLocation) < 1) {
			throw "You don't have a valid location!";
		}
		else {
			location = new char[strlen(newLocation) + 1];
			strcpy(this->location, newLocation);
		}
	}

	void setCustomerName(string customerName) {
		if (customerName.length() < 1) {
		throw "You don't have a valid name!";
		}
		else {
			this->customerName = customerName;
		}
	}

	void setPrice(int price) {
		if (price < 1) {
			throw "The price is too low!";
		}
		else {
			this->price = price;
		}
	}
};