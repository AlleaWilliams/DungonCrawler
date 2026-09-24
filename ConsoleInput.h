#pragma once
using namespace std;
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <sstream>

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


string ChoseFromConsole(const string& prompt) {
    std::string input;

    // Display prompt
    std::cout << prompt;

    // Use getline to read the entire line (including spaces)
    if (!std::getline(std::cin, input)) {
        // Handle input failure
        std::cerr << "Error reading input.\n";
        return "";
    }

    // Trim leading/trailing spaces (optional)
    size_t start = input.find_first_not_of(" \t\r\n");
    size_t end = input.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) {
        return ""; // String was all whitespace
    }
    return input.substr(start, end - start + 1);
}

//// String Utility Testing
//inline void TestStringUtilities()
//{
//    ofstream logFile("StringUtilityTestLog.txt");
//
//    if (!logFile.is_open())
//    {
//        cout << "Could not open log file.\n";
//        return;
//    }
//
//    int totalTests = 0;
//    int passedTests = 0;
//    int failedTests = 0;
//
//    // Test ChoseFromConsole
//    {
//        totalTests++;
//
//        string expected = "hello world";
//
//        // Test the trimming part of the function
//        string testInput = "   hello world   ";
//
//        size_t start = testInput.find_first_not_of(" \t\r\n");
//        size_t end = testInput.find_last_not_of(" \t\r\n");
//
//        string actual;
//
//        if (start == string::npos)
//        {
//            actual = "";
//        }
//        else
//        {
//            actual = testInput.substr(start, end - start + 1);
//        }
//
//        if (actual == expected)
//        {
//            passedTests++;
//
//            logFile << "PASS: ChoseFromConsole()\n";
//            logFile << "Expected: " << expected << "\n";
//            logFile << "Actual: " << actual << "\n\n";
//        }
//        else
//        {
//            failedTests++;
//
//            logFile << "FAIL: ChoseFromConsole()\n";
//            logFile << "Expected: " << expected << "\n";
//            logFile << "Actual: " << actual << "\n\n";
//        }
//    }
//
//
//    // Test another string case
//    {
//        totalTests++;
//
//        string expected = "Player";
//
//        string testInput = "   Player   ";
//
//        size_t start = testInput.find_first_not_of(" \t\r\n");
//        size_t end = testInput.find_last_not_of(" \t\r\n");
//
//        string actual;
//
//        if (start == string::npos)
//        {
//            actual = "";
//        }
//        else
//        {
//            actual = testInput.substr(start, end - start + 1);
//        }
//
//        if (actual == expected)
//        {
//            passedTests++;
//
//            logFile << "PASS: ChoseFromConsole() second test\n";
//            logFile << "Expected: " << expected << "\n";
//            logFile << "Actual: " << actual << "\n\n";
//        }
//        else
//        {
//            failedTests++;
//
//            logFile << "FAIL: ChoseFromConsole() second test\n";
//            logFile << "Expected: " << expected << "\n";
//            logFile << "Actual: " << actual << "\n\n";
//        }
//    }
//
//
//    // Final log summary
//    logFile << "============================\n";
//    logFile << "TEST SUMMARY\n";
//    logFile << "============================\n";
//    logFile << "Total Tests: " << totalTests << "\n";
//    logFile << "Passed: " << passedTests << "\n";
//    logFile << "Failed: " << failedTests << "\n";
//
//    logFile.close();
//
//
//    // Final console summary
//    cout << "\n============================\n";
//    cout << "STRING UTILITY TEST SUMMARY\n";
//    cout << "============================\n";
//    cout << "Total Tests: " << totalTests << endl;
//    cout << "Passed: " << passedTests << endl;
//    cout << "Failed: " << failedTests << endl;
//
//    if (failedTests == 0)
//    {
//        cout << "All tests passed!\n";
//    }
//    else
//    {
//        cout << "Some tests failed. Check StringUtilityTestLog.txt\n";
//    }
//}

// String Utility Testing
inline void TestStringUtilities()
{
    ofstream logFile("StringUtilityTestLog.txt");

    if (!logFile.is_open())
    {
        cout << "Could not open log file.\n";
        return;
    }

    int totalTests = 0;
    int passedTests = 0;
    int failedTests = 0;

    // Test ChoseFromConsole
    {
        totalTests++;

        string expected = "hello world";

        // Test the trimming part of the function
        string testInput = "   hello world   ";

        size_t start = testInput.find_first_not_of(" \t\r\n");
        size_t end = testInput.find_last_not_of(" \t\r\n");

        string actual;

        if (start == string::npos)
        {
            actual = "";
        }
        else
        {
            actual = testInput.substr(start, end - start + 1);
        }

        if (actual == expected)
        {
            passedTests++;

            logFile << "PASS: ChoseFromConsole()\n";
            logFile << "Expected: " << expected << "\n";
            logFile << "Actual: " << actual << "\n\n";
        }
        else
        {
            failedTests++;

            logFile << "FAIL: ChoseFromConsole()\n";
            logFile << "Expected: " << expected << "\n";
            logFile << "Actual: " << actual << "\n\n";
        }
    }


    // Test another string case
    {
        totalTests++;

        string expected = "Player";

        string testInput = "   Player   ";

        size_t start = testInput.find_first_not_of(" \t\r\n");
        size_t end = testInput.find_last_not_of(" \t\r\n");

        string actual;

        if (start == string::npos)
        {
            actual = "";
        }
        else
        {
            actual = testInput.substr(start, end - start + 1);
        }

        if (actual == expected)
        {
            passedTests++;

            logFile << "PASS: ChoseFromConsole() second test\n";
            logFile << "Expected: " << expected << "\n";
            logFile << "Actual: " << actual << "\n\n";
        }
        else
        {
            failedTests++;

            logFile << "FAIL: ChoseFromConsole() second test\n";
            logFile << "Expected: " << expected << "\n";
            logFile << "Actual: " << actual << "\n\n";
        }
    }


    // Final log summary
    logFile << "============================\n";
    logFile << "TEST SUMMARY\n";
    logFile << "============================\n";
    logFile << "Total Tests: " << totalTests << "\n";
    logFile << "Passed: " << passedTests << "\n";
    logFile << "Failed: " << failedTests << "\n";

    logFile.close();


    // Final console summary
    cout << "\n============================\n";
    cout << "STRING UTILITY TEST SUMMARY\n";
    cout << "============================\n";
    cout << "Total Tests: " << totalTests << endl;
    cout << "Passed: " << passedTests << endl;
    cout << "Failed: " << failedTests << endl;

    if (failedTests == 0)
    {
        cout << "All tests passed!\n";
    }
    else
    {
        cout << "Some tests failed. Check StringUtilityTestLog.txt\n";
    }
}