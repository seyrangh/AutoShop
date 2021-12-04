#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"
using namespace std;
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar();
		Racecar(istream& in);
		void display(ostream& out) const;
		double topSpeed() const;
		void setEmpty();
	};
}
#endif
