#include "std_lib_facilities.h"

int main() {
	cout << "Enter the first name of the person you want to write to:\n";
	string first_name;
	cin >> first_name;

	cout << "Enter another friend's name:\n";
	string friend_name;
	cin >> friend_name;

	char friend_sex = 0;
	cout << "Please enter 'm' if " << friend_name << " is a guy, or 'f' if " << friend_name << " is a girl:\n";
	cin >> friend_sex;

	cout << "Please enter their age:\n";
	int age;
	cin >> age;

	cout << "\n\tDear " << first_name << ",\n\nHow are you doing lately? I miss you a lot. We haven't talked in years...\n";
	cout << "\nHave you seen " << friend_name  << " lately?\n";

	if(friend_sex == 'm') {
		cout << "If you see " << friend_name << " please ask him to call me.";
	}

	if(friend_sex == 'f') {
		cout << "If you see " << friend_name << " please ask her to call me.";
	}

	if(age < 0 || age > 110) simple_error("you're kidding!");

	cout << "I hear you just had a birthday and you are " << age << " years old. ";

	if(age < 12) { cout << "Next year you will be " << age+1 << "."; }
	if(age == 17) {	cout << "Next year you will be able to vote."; }
	if(age > 70) { cout << "I hope you are enjoying retirement."; }

	cout << "\n\nYours sincerely,\n\nAnti\n";

	return 0;
}
