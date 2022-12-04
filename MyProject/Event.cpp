#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Event {
private:
	string eventName = "";
	string date = "";
	int time = 0;
	string location = "";

public:
	Event() {

	}

	Event(string eventName, string date, int time, string location) {
		this->eventName = eventName;
		this->date = date;
		this->time = time;
		this->location = location;
	}
	
	Event(const Event& event) {
		this->eventName = event.eventName;
		this->date = event.date;
		this->time = event.time;
		this->location = event.location;
	}

	~Event() {

	}

	Event& operator=(const Event& event) {
		this->eventName = event.eventName;
		this->date = event.date;
		this->time = event.time;
		this->location = event.location;
		return *this;
	}

	string getEventName() {
		return this->eventName;
	}

	string getDate() {
		return this->date;
	}

	int getTime() {
		return this->time;
	}

	string getLocation() {
		return this->location;
	}

	void setEventName(string eventName) {
		if (eventName.length() < 1)
			throw "Invalid event name!";
		else this->eventName = eventName;
	}

	void setDate() {
		if (date.length() < 8)
			throw "Invalid date!";
		else this->date = date;
	}

	void setTime() {
		if (time > 2359)
			throw "Invalid hour!";
		else this->time = time;
	}

	void setLocation() {
		if (location.length() < 1)
			throw "Invalid location!";
		else this->location = location;
	}

	Event operator+(int nr) {
		Event copy = *this;
		copy.time += nr;
		return copy;
	}

	friend ostream& operator<<(ostream& cout, const Event& e);
	friend istream& operator>>(istream& cin, Event& e);

};

bool operator==(Event& e1, Event& e2) {
	return e1.getTime() == e2.getTime();
}

ostream& operator<<(ostream& cout, const Event& e) {
	cout << "Event name: " << e.eventName << endl << "Date: " << e.date << endl;
	cout << "Time: " << e.time << endl << "Location: " << e.location << endl;
	return cout;
}

istream& operator>>(istream& cin, Event& e) {
	cout << "Event name: "; cin >> e.eventName;
	cout << "Date: "; cin >> e.date;
	cout << "Time: "; cin >> e.time;
	cout << "Location: "; cin >> e.location;
	return cin;
}