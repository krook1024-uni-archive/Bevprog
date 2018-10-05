#include "std_lib_facilities.h"

int square(int x);

int main() {
	for(int i=0; i<=99; i++) {
		cout << "|\t" << i << " " << square(i);
		cout << "\t\t|\t" << ++i << " " << square(i);
		cout << "\t\t|\t" << ++i << " " << square(i);
		cout << "\t\t|\t" << ++i << " " << square(i) << "\t\t|" << endl;
	}

	return 0;
}

int square(int x) {
	return x*x;
}
