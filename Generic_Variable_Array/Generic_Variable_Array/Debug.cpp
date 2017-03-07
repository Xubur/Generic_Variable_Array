#include <cstdlib>
#include <string>
#include "genVarArray.h"

using namespace std;
int main(void)
{
	genVarArray<int> intArray;
	genVarArray<double> dblArray;
	genVarArray<char> charArray;
	genVarArray<string> strArray;

	intArray.add(1);
	dblArray.add(0.001);
	charArray.add('a');
	strArray.add("apple");

	intArray.output();
	dblArray.output();
	charArray.output();
	strArray.output();

}