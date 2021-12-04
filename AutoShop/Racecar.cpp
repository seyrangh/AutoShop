#include <sstream>
#include <iomanip>
#include "Racecar.h"
using namespace std;
namespace sdds
{
	Racecar::Racecar() : Car() {
		setEmpty();
	}
	Racecar::Racecar(istream& in) : Car(in) {
		setEmpty();
		string temp;
		getline(in, temp);
		Car::trimWhiteSpace(temp);
		if (!temp.empty()) {
			m_booster = stod(temp);
		}
	}
	void Racecar::display(ostream& out) const {
		string carLine;
		stringstream os_to_ss;
		Car::display(os_to_ss); 
			carLine = os_to_ss.str(); 
		carLine = carLine.substr(0, 23);
		out << carLine;
		out << " " << setw(6) << setprecision(2) << fixed <<
			this->topSpeed();
		out << " |*";
	}
	double Racecar::topSpeed() const {
		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}
	void Racecar::setEmpty() {
		m_booster = 0;
	}
}
