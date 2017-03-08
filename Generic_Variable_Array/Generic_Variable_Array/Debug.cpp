#include <cstdlib>
#include <string>
#include "genVarArray.h"

using namespace std;
void testfunc(genVarArray<string>);

int main() {

	genVarArray<string> a1;

	a1.add("a1-First");
	a1.add("a1-Second");
	a1.add("a1-Third");
	a1.add("a1-Third"); // trying to add duplicate, should not add it

	a1.output();

	if (a1.check("a1-First") == -1) 
		cout << "'First' is not present in the array" << endl;

	if (a1.check("CompSci") == -1)
		cout << "'CompSci' is not present in the array" << endl;

	a1.output();
	a1.remove("a1-Second");
	a1.output();

	genVarArray<string> a2, a3;

	a2.add("a2-One");
	a2.add("a2-Two");

	a3.add("a3-One");
	a3.add("a3-Two");
	a3.add("a3-Three");

	a3 = a2 = a1; // testing overloaded assignment
	std::cout << "a3 = a2 = a1: \n"; a3.output(); std::cout << std::endl;
	a3 = a3; // testing protection against self-assingment
	std::cout << "a3 = a3"; a3.output(); std::cout << std::endl;

	testfunc(a3); // testing copy constructor
	a3.output(); // if destructor is implemented correctly this should print properly after testfunc completes

} // end of function main.


  // tests pass-by-value for object of class genVarArray<>
void testfunc(genVarArray<string> va)
{ // copy constructor is invoked on "va"
	va.output();
}
