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
};

