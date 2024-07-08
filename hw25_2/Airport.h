#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Airplane.h"
using namespace std;

class Airport
{
private:
	vector<Airplane> schedule;

public:
    void addAirplane(const Airplane& airplane);
    void removeAirplane(int flightNumber);
    Airplane* getAirplane(int flightNumber) const;

    Airplane* findAirplane(int flightNumber);
    void sortByFlightNumber();

    void boardPassengers(int flightNumber, int passengers);
    void disembarkPassengers(int flightNumber, int passengers);

    void printSchedule() const;
    void clearSchedule();



};

