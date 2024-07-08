#include "Airport.h"

void Airport::addAirplane(int flightNumber, string destination, int maxPassengers) {
    Airplane airplane(flightNumber, destination, maxPassengers);

    schedule.push_back(airplane);
    cout << "Airplane with flight number " << flightNumber << " added to schedule!" << endl;
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

Airplane* Airport::getAirplane(int flightNumber) const
{
    for (const Airplane& airplane : schedule) {
        if (airplane.getFlightNumber() == flightNumber) {
            return const_cast<Airplane*>(&airplane);
        }
    }
    return nullptr;
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

//void Airport::boardPassengers(int flightNumber, int passengers) {
//    Airplane* airplane = findAirplane(flightNumber);
//    if (airplane) {
//        int availableSeats = airplane->getMaxPassengers() - airplane->getCurrentPassengers();
//        if (passengers <= availableSeats && passengers > 0) {
//            airplane->addPassenger(passengers);
//            cout << passengers << " passengers successfully boarded on flight " << flightNumber << endl;
//        }
//        else {
//            if (passengers <= 0) {
//                cout << "Invalid number of passengers. Please enter a positive number." << endl;
//            }
//            else {
//                cout << "Not enough seats on flight " << flightNumber << ".\n";
//            }
//        }
//    }
//    else {
//        cout << "Airplane with flight number " << flightNumber << " not found!" << endl;
//    }
//}
//
//void Airport::disembarkPassengers(int flightNumber, int passengers) {
//    Airplane* airplane = findAirplane(flightNumber);
//    if (airplane) {
//        if (passengers <= airplane->getCurrentPassengers() && passengers > 0) {
//            airplane->removePassenger(passengers);
//            cout << passengers << " passengers successfully disembarked from flight " << flightNumber << endl;
//        }
//        else {
//            if (passengers <= 0) {
//                cout << "Invalid number of passengers" << endl;
//            }
//            else {
//                cout << "Not enough passengers on flight " << flightNumber << ".\n";
//            }
//        }
//    }
//    else {
//        cout << "Airplane with flight number " << flightNumber << " not found!" << endl;
//    }
//}


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


