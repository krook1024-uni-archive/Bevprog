#include "std_lib_facilities.h"

int main()
{

	// Swap integers using XOR
	int a = 7;
	int b = 1;

	a = a^b; 		
	b = b^a;  
	a = a^b;

	cout << a << " " << b << "\n";

	return 0;
}
