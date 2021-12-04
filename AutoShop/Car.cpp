define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "Car.h"
using namespace std;
namespace sdds
{
	string& Car::trimWhiteSpace(string& st) {
		st.erase(0, st.find_first_not_of(' '));
		st.erase(st.find_last_not_of(' ') + 1);
		return st;
	}
	Car::Car() : c_maker{ "" }, c_condition{ "" }, c_topSpeed{ 0 } {}
	Car::Car(std::istream& is) : c_maker{ "" }, c_condition{ "" }, c_topSpeed{
	0 } {
		string temp;
		for (size_t i = 0u; i < 4; i++) {
			getline(is, temp, ',');
			trimWhiteSpace(temp);
			switch (i) {
			case 0: //tag
				break;
			case 1: //maker
				c_maker = temp;
				trimWhiteSpace(c_maker);
				break;
			case 2: //condition
				if (!temp.empty()) {
					trimWhiteSpace(temp);
					if (temp == "n" || temp == "u" || temp == "b") {
						if (temp == "n")
							c_condition = "new";
						else if (temp == "u")
							c_condition = "used";
						else if (temp == "b")
							c_condition = "broken";
					}
					else {
						throw string("Invalid record!");
					}
				}
				else {
					c_condition = "new";
				}
				break;
			case 3:
				if (isNumber(temp)) {
					c_topSpeed = double(stod(temp));
				}
				else {
					throw string("Invalid record!");
				}
				break;
			}
		}
	}
	string Car::condition() const {
		return c_condition;
	}
	double Car::topSpeed() const {
		return c_topSpeed;
	}
	void Car::display(ostream& out) const {
		out << "| " << setw(10) << right << c_maker;
		out << " | " << setw(6) << left << condition();
		out << " | " << setw(6) << fixed << setprecision(2)
			<< c_topSpeed << " |";
	}
	Car::~Car() {}
	bool Car::isNumber(string& str) const {
		bool isNumber = false;
	
			isNumber = (str.find_first_not_of("0123456789.") ==
				string::npos);
		return isNumber;
	}
}
