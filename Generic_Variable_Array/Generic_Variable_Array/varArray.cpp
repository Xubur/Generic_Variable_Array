#include "varArray.h"
#include <iostream>

varArray::varArray() {
	size = 0;
	dArray = new int[size];
}

varArray::varArray(const varArray &tmpArray) {
	size = tmpArray.size;
	dArray = new int[size];
	for (int i = 0; i < size; i++) {
		dArray[i] = tmpArray.dArray[i];
	}
}

varArray& varArray::operator=(const varArray &variableArray) {
	if (this != &variableArray) {
		size = variableArray.size;
		delete[] dArray;
		dArray = new int[size];
		for (int i = 0; i < size; i++) {
			dArray[i] = variableArray.dArray[i];
		}
	}
	return *this;
}

varArray::~varArray() {
	size = 0;
	delete[] dArray;
}

int varArray::check(int number) {
	for (int i = 0; i < size; ++i) {
		if (dArray[i] == number)
			return i;
	}
	return -1;
}

void varArray::addNumber(int num) {
	int *tmpArray;
	if (check(num) == -1) {
		++size;
		tmpArray = new int[size];
		for (int i = 0; i < size - 1; ++i) {
			tmpArray[i] = dArray[i];
		}
		tmpArray[size - 1] = num;
		delete[] dArray;
		dArray = tmpArray;
	}
}


void varArray::removeNumber(int num) {
	int *tmpArray;
	int dI = 0, tI = 0;
	if (check(num) != -1) {
		--size;
		tmpArray = new int[size];
		while (tI < size && dI < size + 1) {
			if (dArray[dI] != num) {
				tmpArray[tI] = dArray[dI];
				dI++;
				tI++;
			}
			else {
				dI++;
			}
		}
		delete[] dArray;
		dArray = tmpArray;
	}
}

void varArray::output()
{
	for (int i = 0; i < size; ++i) {
		std::cout << "{" << dArray[i] << "}";
	}
	std::cout << std::endl;
}