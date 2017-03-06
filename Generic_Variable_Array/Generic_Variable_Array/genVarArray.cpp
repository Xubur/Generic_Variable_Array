#include "genVarArray.h"
#include <iostream>

template <class Item>
genVarArray<Item>::genVarArray() {
	size = 0;
	dArray = new int[size];
}

template <class Item>
genVarArray<Item>::genVarArray(const genVarArray &tmpArray) {
	size = tmpArray.size;
	dArray = new int[size];
	for (int i = 0; i < size; i++) {
		dArray[i] = tmpArray.dArray[i];
	}
}

template <class Item>
genVarArray<Item> genVarArray::operator=(const genVarArray &variableArray) {
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

template <class Item>
genVarArray<Item>::~genVarArray() {
	size = 0;
	delete[] dArray;
}

template <class Item>
int genVarArray<Item>::check(int number) {
	for (int i = 0; i < size; ++i) {
		if (dArray[i] == number)
			return i;
	}
	return -1;
}

template <class Item>
void genVarArray<Item>::add(int num) {
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

template <class Item>
void genVarArray<Item>::remove(int num) {
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

template <class Item>
void genVarArray<Item>::output()
{
	for (int i = 0; i < size; ++i) {
		std::cout << "{" << dArray[i] << "}";
	}
	std::cout << std::endl;
}