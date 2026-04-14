#include <iostream>
#include <string>
#include "utils.hpp"
#include <stdexcept>

using namespace std;


int main () {

	string email;

	do {
	cout << "Enter your email: ";
	cin >> email;
	try {
		check_email(email);
	}
	catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
	}
	break;
	}
	while (true);
	cout << "Valid email"<<endl;
	return 0;
}
