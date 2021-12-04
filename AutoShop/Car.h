#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
using namespace std;
namespace sdds
{
	class Car :public Vehicle
	{
		string c_maker;
		string c_condition;
		double c_topSpeed;
	public:
		Car();
		Car(istream&);
		string condition() const;
		double topSpeed() const;
		void display(ostream& out) const;
		string& trimWhiteSpace(string& st);
		~Car();
		bool isNumber(string&) const;
	};
}
#endif
