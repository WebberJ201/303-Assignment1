#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;


int main()
{
	int SIZE = 100; // The number of elements
	int* numbers = new int[SIZE]; // Declaring array
	char userChoice = ' '; // Placeholder for user's choices


	// Makes sure that the assignment's file is readable.
	if (readFile("TextFile2.txt", numbers, SIZE)) {
		cout << "File was opened and read successfully.\n" << endl;
	}

	// Visual menu for choices, following user input.
	cout << "Welcome to Assignment 1! Please pick a function to run.\n"
		"A: Find the location of a given integer.\n"
		"B: Modify an integer using its location.\n"
		"C: Add an integer to the end of the array\n"
		"D: Remove an integer based on location\n"
		"Q: Quit the program\n" << endl;
	cin >> userChoice;
	cout << endl << endl;

	//While loop that facilitates continuation of the program. Program ends after 'Q'/'q' is recorded.
	while (userChoice != 'Q' && userChoice != 'q') {
		// Choice A
		if (userChoice == 'A' || userChoice == 'a') {
			findValue(numbers, SIZE);
		}
		
		// Choice B
		else if (userChoice == 'B' || userChoice == 'b') {
			modifyValue(numbers, SIZE);
		}

		// Choice C
		else if (userChoice == 'C' || userChoice == 'c') {
			addValue(numbers, SIZE);
		}

		// Choice D
		else if (userChoice == 'D' || userChoice == 'd') {
			removeAtIndex(numbers, SIZE);
		}

		//Continuation after a function is ran through.
		cout << "Please pick a function to run.\n"
			"A: Find the location of a given integer.\n"
			"B: Modify an integer using its location.\n"
			"C: Add an integer to the end of the array\n"
			"D: Remove an integer based on location\n"
			"Q: Quit the program\n" << endl;
		cin >> userChoice;
		cout << endl << endl;
	}

	return 0;
}
