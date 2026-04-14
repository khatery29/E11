#include <iostream>
#include <string>
#include "utils.hpp"
#include <stdexcept>
#include <map>
using namespace std;



struct user {
	string email;
	string password;
	bool logged_in = false;
};

map<int, user> users;

void sign_up (map<int, user>& u, int& i);
void login (map <int,user> &u, bool& l);



int main () {


	int id = 0;
	string choice;
	
	bool logged_in = false;
	while(true) {
	cout << endl << "________Options________" << endl;
	if (logged_in == false) {
		cout << "Sign up (S)" << endl;
		cout << "Login (L)" << endl;
	}
	
	if (logged_in == true) {
	cout << "Logout (O)" << endl;
	}
	cout << "Exit (E)" << endl;
	cout << "Choose: ";
	cin >> choice;
	if (choice == "S") {
		sign_up(users, id);
	}
	else if (choice == "L") {
		login(users, logged_in);
	}
	else if (choice == "O") {
		logged_in = false;
		cout << "You are logged out" << endl;
	}
	else if (choice == "E") {
		return 0;
	}
	else {
		cout << "Invalid choice" << endl;}
	}
	return 0;
}

void sign_up (map<int, user>& u, int& i)
{
	string t_email;
	string t_password;
	bool check = false;
	do {
	cout << "Enter your email: ";
	cin >> t_email;
	try {
		check = check_email(t_email);
		check = true;
	}
	catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
		check = false;
	}
	}
	while (!check);
	u[i].email = t_email;
	cout << "Enter password: ";
	cin >> t_password;
	u[i].password = t_password;
	i++;
}

void login (map<int, user>& u, bool& l)
{
	string t_email;
	string t_password;
	cout << "Enter your email: ";
	cin >> t_email;
	cout << "Enter password: ";
	cin >> t_password;
	for(int i = 0; i < u.size(); i++) {
		if (u[i].email == t_email && u[i].password == t_password) {
			l = true;
			break;
		}}
		if (l == true)
			cout << "You are logged in" << endl;
		else {
			cout << "Invalid email or password" << endl;
		}
	}
