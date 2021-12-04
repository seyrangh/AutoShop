#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utilities.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(istream& in) {
		Vehicle* ptr = nullptr;
		string temp;
		getline(in, temp);
		temp.erase(0, temp.find_first_not_of(' '));
		stringstream line(temp);
		if (!temp.empty()) {
			if (temp[0] == 'c' || temp[0] == 'C') {
				ptr = new Car(line);
			}
			else if (temp[0] == 'r' || temp[0] == 'R') {
				ptr = new Racecar(line);
			}
			else {
				string tag{};
				getline(line, tag, ',');
				throw "Unrecognized record type: [" + tag + "]";
			}
		}
		else {
			ptr = nullptr;
		}
		return ptr;
	}
}
