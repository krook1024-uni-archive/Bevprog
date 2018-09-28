#include "std_lib_facilities.h"

int main () {
	int a = 1, count = 0;

	while(a != 0)
	{
		a <<= 1;
		cout << a << endl;
		count ++;
	}

	cout << "\nAz a " << count << " lépés után lesz hamis.\n";

	return 0;
}
