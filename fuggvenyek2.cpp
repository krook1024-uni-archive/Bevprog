#include "std_lib_facilities.h"

int max(int a, int b);

int main() {
	cout << max(7,9) << "\t" << max(19, -27) << "\t" << max(20, 20) << endl;

	return 0;
}

int max(int a, int b) {
	return (a>b ? a : b);
}
