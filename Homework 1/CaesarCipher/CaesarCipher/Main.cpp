#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Caesar.h"

void Welcome();
void ErrorMessage();
char cipherChoice();

//TODO: Implement Ceasar class stuff

int main() {

	Welcome();
	Caesar caeser;

	if (cipherChoice() == 'E') {
		caeser.Encrypt();
	} 
	else {
		caeser.Decrypt();
	}
	

	return 0;
}

void Welcome() {

	cout << "**********************************" << endl;
	cout << "WELCOME to Caesar Cipher Program" << endl;
	cout << "**********************************" << endl;
}

void ErrorMessage() {

	cout << endl << "Please choose the correct option" << endl;
}

char cipherChoice() {

	char choice{ 0 };

	cout << "Please enter 'e' for Encryption or 'd' for Decryption: ";
	cin >> choice;

	if (choice == 'E' || choice == 'e') {
		return 'E';
	}
	else if (choice == 'D' || choice == 'd') {
		return 'D';
	}
	else {
		ErrorMessage();
		cipherChoice();
	}
}

