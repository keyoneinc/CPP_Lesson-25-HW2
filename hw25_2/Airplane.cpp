#include "Airplane.h"

Airplane::Airplane(int flightNumber, string destination, int maxPassengers) {
    this->flightNumber = flightNumber;
    this->destination = destination;
    this->currentPassengers = 0;
    this->maxPassengers = maxPassengers;
}

int Airplane::getFlightNumber() const {
    return flightNumber;
}

void Airplane::setFlightNumber(int flightNumber) {
    this->flightNumber = flightNumber;
}

string Airplane::getDestination() const {
    return destination;
}

void Airplane::setDestination(string destination) {
    this->destination = destination;
}

int Airplane::getCurrentPassengers() const {
    return currentPassengers;
}

void Airplane::addPassenger() {
    if (currentPassengers < maxPassengers) {
        currentPassengers++;
    }
    else {
        cout << "The plane is full" << endl;
    }
}

void Airplane::removePassenger() {
    if (currentPassengers > 0) {
        currentPassengers--;
    }
    else {
        cout << "There isn't any passengers in the plane" << endl;
    }
}

int Airplane::getMaxPassengers() const {
    return maxPassengers;
}

void Airplane::printInfo() const {
    cout << "Flight number: " << flightNumber << endl;
    cout << "Destination: " << destination << endl;
    cout << "Passengers count: " << currentPassengers << endl;
    cout << "Maximum passengers in the plane: " << maxPassengers << endl;
}

bool Airplane::operator==(const Airplane& other) const
{
    return this->flightNumber == other.flightNumber;
}

bool Airplane::operator!=(const Airplane& other) const
{
    return !(*this == other);
}
