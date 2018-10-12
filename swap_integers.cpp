#include "std_lib_facilities.h"

int main()
{

	// Swap integers using addition
	int a = 7;
	int b = 1;

	a = a+b;
	b = a-b;
	a = a-b;

	cout << a << " " << b << "\n";

	return 0;
}
