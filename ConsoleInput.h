#pragma once

#include <iostream>
#include <limits>
#include <string>

inline int ReadFromConsole(const std::string& prompt, int minimum, int maximum) {
	int value;

	while (true) {
		std::cout << prompt;

		if (std::cin >> value && value >= minimum && value <= maximum) {
			return value;
		}

		std::cout << "Please enter a number from " << minimum
			<< " to " << maximum << ".\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
