#include "std_lib_facilities.h"

void errorline();

int main () {
	// Define global variables and vectors
	double sum = 0, smallest = numeric_limits<float>::max(), largest;
	vector<double> values;

	// Let the user know of the valid formats
	cout << "[!] Valid formats are: cm, in, ft, m.\n";
	cout << "[!] Examples: '3m', '4in', '9ft', '20cm'.\n";
	cout << "[!] To print the summary, enter '|'.";

	// Main loop
	while(true) {
		cout << "\n> Enter a value: ";

		// Local variables
		bool isValid;
		double input = 0.0;
		string unit = "";

		if(cin >> input >> unit) {
			isValid = true;
		} else {
			isValid = false;
			cin.clear();
			cin.ignore();
			break;
		}

		double converted = 0;

		// Unit conversion
		if(isValid) {
			if(unit == "cm") { converted = input/100.0; }
			else if(unit == "in") { converted = (input * 2.54)/100.0; }
			else if(unit == "ft") { converted = ((input * 12.0 * 2.54)/100.0); }
			else if(unit == "m") { converted = input; }
			else { errorline(); continue;}

			if(converted <= smallest) {
				smallest = converted;
				cout << "+ smallest so far\n";
			}

			if(converted > largest) {
				largest = converted;
				cout << "+ largest so far\n";
			}

			values.push_back(converted);
			sum += converted;
		}
	}

	// Only print summary if there are valid inputs stored
	if(values.size() > 0) {
		// Sort the values
		sort(values.begin(), values.end());

		// Summary
		cout << "\n================SUMMARY====================\n";
		cout << "Smallest value: " << smallest << "m\n";
		cout << "Largest value: " << largest << "m\n";
		cout << "Sum of those values: " << sum << "m\n";
		cout << "# of inputs: " << values.size() << "\n";
		cout << "Values one-by-one (in increasing order):\n";

		for(long unsigned int i=0; i < values.size(); i++) {
			cout << "- " << values[i] << "m\n";
		}
		cout << "\n===========================================\n";
	}

	return 0;
}

void errorline() {
	cout << "[!] ERROR: Wrong format." << endl;
}
