#include <cstdlib>
#include <string>
#include "genVarArray.h"

using namespace std;
void testfunc(genVarArray<string>);

int main() {

	genVarArray<int> intArray;
	genVarArray<char> charArray;
	genVarArray<double> dblArray;

	intArray.add(1);
	intArray.add(2);
	intArray.add(3);

	charArray.add('a');
	charArray.add('b');
	charArray.add('c');

	dblArray.add(1.111);
	dblArray.add(2.222);
	dblArray.add(3.333);

} 
