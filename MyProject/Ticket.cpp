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
		this->location = new char[strlen(location) + 1];
		strcpy(this->location, location);
		this->customerName = customerName;
		this->price = price;
	}

	//copy constr
	Ticket(const Ticket& ticket):id(ticket.id) {
		this->location = new char[strlen(location) + 1];
		strcpy(this->location,ticket.location);
		this->customerName = ticket.customerName;
		this->price = ticket.price;
	}

	//destructor
	~Ticket() {
		if (this->location != nullptr)
			delete[] location;
	}

	//operator =
	Ticket & operator=(const Ticket& ticket) {
		if(location!=nullptr)
		delete[] location;
		location = new char[strlen(location) + 1];
		strcpy(this->location, ticket.location);
		this->customerName = ticket.customerName;
		this->price = ticket.price;
		return *this;
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

	//operator []
	char& operator[](int index) {
		if (index < 0 || index >= strlen(this->location)) {
			throw "Wrong index";
		}
		return this->location[index];
	}

	//operator <=
	bool operator<=(float price) {
		return this->price <= price;
	}

	friend ostream& operator<<(ostream& cout, const Ticket& t);
	friend istream& operator>>(istream& cin, Ticket& t);
};

ostream& operator<<(ostream& cout, const Ticket& t) {
	cout << "Location: " << t.location << endl << "Customer name: " << t.customerName << endl;
	cout << "Price: " << t.price<<endl;
	return cout;
}

istream& operator>>(istream& cin, Ticket& t) {
	char buffer[200];
	cout << "Location: ";
	cin >> buffer;
	if (t.location != nullptr) delete[] t.location;
	t.location = new char[strlen(buffer) + 1];
	strcpy(t.location, buffer);
	cout <<endl<< "Customer name :";
	cin >> t.customerName;
	return cin;
}




