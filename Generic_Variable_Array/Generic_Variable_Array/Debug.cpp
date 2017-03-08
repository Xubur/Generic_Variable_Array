#include <cstdlib>
#include <string>
#include "genVarArray.h"

using namespace std;
void testfunc(genVarArray<char>);

int main() {

	genVarArray<char> a1;
	// testing regular member functions
	a1.add('a');
	a1.add('b');
	a1.add('c');
	a1.add('c'); // trying to add duplicate, should not add it

	a1.output();

	if (a1.check('a') == -1) // check() returns -1 if number not present
		cout << "1 is not present in the array" << endl;

	if (a1.check('g') == -1)
		cout << "g is not present in the array" << endl;

	a1.output();
	a1.remove('b');
	a1.output();

	genVarArray<char> a2, a3;

	a2.add('a');
	a2.add('b');

	a3.add('b');
	a3.add('c');
	a3.add('a');

	a3 = a2 = a1; // testing overloaded assignment
	std::cout << "a3 = a2 = a1: \n"; a3.output(); std::cout << std::endl;
	a3 = a3; // testing protection against self-assingment
	std::cout << "a3 = a3"; a3.output(); std::cout << std::endl;

	testfunc(a3); // testing copy constructor
	a3.output(); // if destructor is implemented correctly
				 // this should print properly after testfunc completes

} // end of function main.


  // tests pass-by-value for object of class genVarArray<>
void testfunc(genVarArray<char> va)
{ // copy constructor is invoked on "va"
	va.output();
}
