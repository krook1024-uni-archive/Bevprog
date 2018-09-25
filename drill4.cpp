#include "std_lib_facilities.h"
#include <map>

enum units {
	cm,
	in,
	ft,
	m
};

map<string, units> sUnits;

int main () {
	sUnits["cm"] = cm;
	sUnits["in"] = in;
	sUnits["ft"] = ft;
	sUnits["m"] = m;

	double sum = 0, smallest = TMP_MAX, largest;
	vector<double> values;

	while(true) {
		cout << "\n\nEnter a number: ";

		double input;
		string unit;

		cin >> input >> unit;

		if(cin.fail()) {
			break;
		}

		double converted = 0;

		switch(sUnits[unit]) {
			case cm:
				converted = input/100.0;
				break;
			case in:
				converted = (input * 2.54)/100.0;
				break;
			case ft:
				converted = (input * 12.0 * 2.54);
				break;
			case m:
				converted = input;
				break;
			default:
				simple_error("illegal unit");
				return(0);
				break;
		}

		if(converted <= smallest) {
			smallest = converted;
			cout << "> smallest so far\n";
		}

		if(converted > largest) {
			largest = converted;
			cout << "> largest so far\n";
		}

		values.push_back(converted);
		sum += converted;
	}

	// Sort the values

	sort(values.begin(), values.end());

	// Summary

	cout << "\n===========================================\n";
	cout << "Smallest value: " << smallest << "m\n";
	cout << "Largest value: " << largest << "m\n";
	cout << "Sum of those values: " << sum << "m\n";
	cout << "# of inputs: " << values.size() << "\n";
	cout << "Values one-by-one (increasing order):\n";

	for(long unsigned int i=0; i < values.size(); i++) {
		cout << "- " << values[i] << "m\n";
	}
	cout << "\n===========================================\n";

	return 0;
}
