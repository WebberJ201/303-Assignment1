#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

bool readFile(const string& filename, int arr[], int size);

void findValue(int arr[], int size);

void modifyValue(int arr[], int size);

void addValue(int*& arr, int& size);

void removeAtIndex(int*& arr, int& size);

#endif // FUNCTIONS_H