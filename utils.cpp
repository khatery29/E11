#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

using namespace std;

bool check_email (string email) {

	regex pattern(R"(.+@.+\..+)");

	if (!(regex_match(email, pattern))) {
		throw invalid_argument("This is an invalid email");
		return false;
	}
	else {
		return true;
	}
}
