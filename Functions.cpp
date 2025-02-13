#include "functions.h"
#include <iostream>
#include <fstream>
#include <stdexcept> 
#include <limits>
using namespace std;


//Reads a given .txt file and stores its data within an array.
bool readFile(const string& filename, int arr[], int size) {
	
    // Takes in a file 
	ifstream inputFile(filename);
	if (!inputFile) {
		cerr << "The file didn't open\n";
		return 1;
	}

    // Copies data from the file into the array.
	int index = 0;
	while (inputFile >> arr[index] && index < size) {
		index++;
	}

	inputFile.close();
}


//Given choice "A", user is asked to input a number so that the program may the location of said number.
void findValue(int arr[], int size) {
    int input; // Variable for user input
    bool found = false; // Flag to track if the number was found

    try {
        cout << "What number would you like to find?\n";
        cin >> input;

        // Check for invalid input (non-numeric)
        if (cin.fail()) {
            throw invalid_argument("Invalid input. Please enter a valid numeric value.");
        }

        cout << endl;

        // Moves through the array and finds the location of the user's number.
        for (int i = 0; i < size; i++) {
            if (arr[i] == input) {
                cout << "Your input was found at index " << i << endl << endl;
                found = true;
            }
        }

        // Handles the case of the number not existing.
        if (!found) {
            cout << "The number " << input << " was not found in the array.\n" << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}


//Given choice "B", user is asked to select a location to modify, following with what value.
void modifyValue(int arr[], int size) {
    int pickedIndex;
    int pickedNumber;
    int oldValue;
    string input;

    
    try {
        cout << "What location would you like to change?\n";
        cin >> input; // Read the input as a string

        // Checks if the input is a valid integer
        if (input.find_first_not_of("0123456789") != string::npos) {
            throw invalid_argument("Invalid input. Please enter a numeric value for index.");
        }

        // Converts string to integer
        pickedIndex = stoi(input);

        // Checks if pickedIndex is within bounds
        if (pickedIndex < 0 || pickedIndex >= size) {
            throw out_of_range("Index is out of bounds!");
        }

        cout << endl << "And with what number?\n";
        cin >> input; 

        // Checks if the input is a valid integer
        if (input.find_first_not_of("0123456789") != string::npos) {
            throw invalid_argument("Invalid input. Please enter a numeric value for the number.");
        }

        // Converts string to integer
        pickedNumber = stoi(input);

        // Performs the modification
        oldValue = arr[pickedIndex];
        arr[pickedIndex] = pickedNumber;

        cout << "At location " << pickedIndex << ", you changed the value " << oldValue << " to " << pickedNumber << endl << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl << endl; // Handle index out of bounds
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl << endl; // Handle invalid input
    }
    catch (...) {
        cout << "An unknown error occurred while modifying the array." << endl << endl;
    }
}


//Given choice "C", the array is updated for more space. User is asked what value should be added at the end of the array.
void addValue(int*& arr, int& size) {
    int newValue;
    string input;

    try {
        // Read the new value to be added as a string
        cout << "What value would you like to add at the end of the array?\n";
        cin >> input;

        // Checks if the input is a valid integer
        if (input.find_first_not_of("0123456789") != string::npos) {
            throw invalid_argument("Invalid input. Please enter a valid numeric value.");
        }

        // Converts string to integer
        newValue = stoi(input);

        // Creates a new array with an extra space
        int* newArr = new int[size + 1];

        // Copies existing elements to the new array
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        // Adds the new value at the end of the array
        newArr[size] = newValue;

        // Deletes the old array and update the pointer
        delete[] arr;
        arr = newArr;

        // Increments the size
        size++;

        cout << "Value " << newValue << " added to the array.\n";
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl << endl;
    }
    catch (...) {
        cout << "An unknown error occurred while adding the value.\n" << endl;
    }
}


//Given choice "D", the user is asked to input an index that will be deleted from the array.
void removeAtIndex(int*& arr, int& size) {
    int indexPicked;

    try {
        cout << "What index would you like removed?\n";
        cin >> indexPicked;
        cout << endl;

        // Check for invalid input (non-numeric)
        if (cin.fail()) {
            throw invalid_argument("Invalid input. Please enter a valid numeric value.");
        }

        // Validate the index
        if (indexPicked < 0 || indexPicked >= size) {
            cout << "Invalid index!\n";
            return;
        }

        // Create a new array of size-1
        int* newArr = new int[size - 1];

        // Copy all elements except the one at the index to remove
        for (int i = 0, j = 0; i < size; i++) {
            if (i != indexPicked) {
                newArr[j++] = arr[i];
            }
        }

        // Delete the old array and point arr to the new array
        delete[] arr;
        arr = newArr;
        size--;

        cout << "Value at index " << indexPicked << " has been removed.\n" << endl << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}