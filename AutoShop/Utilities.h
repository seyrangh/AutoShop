#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
using namespace std;
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
namespace sdds {
	Vehicle* createInstance(istream& in);
}
#endif
