// Generic variable size array class
// Original by  Dr. Alnaeli + Dr. Nesterenko
// New implementation by Jordan Moore


#ifndef GENVARARRAY_H
#define GENVARARRAY_H
#include "genVarArray.template"

template <class Item>
class genVarArray{
public:
	genVarArray(); // void constructor
	int arraySize() const { return size; } // returns the size of the array
	int check(Item item); // returns index of element containg "number" or -1 if none
	void add(Item item);    // adds a member to the array
	void remove(Item item); // deletes the member from the array
	void output();      // prints the members of the array

	// big three
	genVarArray(const genVarArray&); // copy constructor
	genVarArray& operator=(const genVarArray&); // overloaded assignment
	~genVarArray(); // destructor

private:
	Item *dArray; // pointer to the dynamically allocated array
	int size;   // array size
};

#endif