#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Autoshop.h"
#include "Car.h"
using namespace std;
namespace sdds
{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto i = m_vehicles.begin(); i < m_vehicles.end(); i++) {
			(*i)->display(out); 
				out << endl;
		}
		out << "--------------------------------" << std::endl;
	}
	Autoshop::~Autoshop() {
		for (auto& car : m_vehicles)
			delete car;
	}
}
