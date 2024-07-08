#include "Airport.h"

void Airport::addAirplane(const Airplane& airplane)
{
	schedule.push_back(airplane);
	cout << "Airplane with number " << airplane.getFlightNumber() << " added to schedule" << endl;
}

void Airport::removeAirplane(int flightNumber)
{
    auto it = find_if(schedule.begin(), schedule.end(), [&](const Airplane& airplane) {
        return airplane.getFlightNumber() == flightNumber;
        });

    if (it != schedule.end()) {
        schedule.erase(it);
        cout << "Airplane with number " << flightNumber << " deleted from schedule" << endl;
    }
    else {
        cout << "Airplane with number " << flightNumber << " not found in the schedule" << endl;
    }
}

Airplane* Airport::findAirplane(int flightNumber)
{
    for (Airplane& airplane : schedule) {
        if (airplane.getFlightNumber() == flightNumber) {
            return &airplane;
        }
    }
    return nullptr;
}

void Airport::sortByFlightNumber()
{
    sort(schedule.begin(), schedule.end(), [](const Airplane& a1, const Airplane& a2) {
        return a1.getFlightNumber() < a2.getFlightNumber();
        });
}

void Airport::printSchedule() const
{
    if (schedule.empty()) {
        cout << "Airport schedule is empty!" << endl;
        return;
    }

    cout << "Airport Schedule:" << endl;
    for (const Airplane& airplane : schedule) {
        cout << "----------------------------------" << endl;
        cout << "Flight number: " << airplane.getFlightNumber() << endl;
        cout << "Destination: " << airplane.getDestination() << endl;
        cout << "Current passengers: " << airplane.getCurrentPassengers() << endl;
        cout << "Maximum capacity: " << airplane.getMaxPassengers() << endl;
    }
}

void Airport::clearSchedule()
{
    schedule.clear();
    cout << "Airport schedule cleared" << endl;
}


