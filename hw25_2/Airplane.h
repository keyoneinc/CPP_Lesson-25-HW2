#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Airplane {
private:
	int flightNumber;
	string destination;
	int currentPassengers;
	int maxPassengers;

public:
	Airplane(int flightNumber, string destination, int maxPassengers);

	int getFlightNumber() const;
	void setFlightNumber(int flightNumber);
	string getDestination() const;
	void setDestination(string destination);

	int getCurrentPassengers() const;
	void addPassenger();
	void removePassenger();

	int getMaxPassengers() const;

	void printInfo() const;

	bool operator==(const Airplane& other) const;
	bool operator!=(const Airplane& other) const;

	Airplane &operator++();
	Airplane &operator--();
	Airplane operator++(int);
	Airplane operator--(int);

	bool operator>(const Airplane& other) const;
	bool operator>=(const Airplane& other) const;
	bool operator<(const Airplane& other) const;
	bool operator<=(const Airplane& other) const;


};

