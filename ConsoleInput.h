#pragma once
using namespace std;
#include <iostream>
#include <limits>
#include <string>

inline int ReadFromConsole(const string& prompt, int minimum, int maximum) {
	int value;

	while (true) {
		cout << prompt;

		if (cin >> value && value >= minimum && value <= maximum) {
			return value;
		}

		cout << "Please enter a number from " << minimum
			<< " to " << maximum << ".\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
