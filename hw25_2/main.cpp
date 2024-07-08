#include <iostream>
#include "Airplane.h"
#include "Airport.h"

int main() {
	Airport airport;

	airport.addAirplane(123, "Dubai", 100);

	airport.boardPassengers(123, 50);

	cout << "Current number of passengers on flight 123: " << airport.getAirplane(123)->getCurrentPassengers() << endl;


}
