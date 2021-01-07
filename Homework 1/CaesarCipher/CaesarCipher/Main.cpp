#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Caesar.h"
#include "ReadFile.h"

void Welcome();
void ErrorMessage();
char cipherChoice();
int keyChoice();

int main() {

	Welcome();
	keyChoice();

	Caesar caeser;
	
	if (cipherChoice() == 'E') {
		ReadFile reader;
		caeser.Encrypt(reader.GetFileContents());

		cout << "Encrypted string: " << caeser.GetWord();
	} 
	else {
		ReadFile reader;
		caeser.Decrypt(reader.GetFileContents());
		
		cout << "Decrypted string: " << caeser.GetWord();
	}
	

	return 0;
}

void Welcome() {

	cout << "**********************************" << endl;
	cout << "WELCOME to Caesar Cipher Program" << endl;
	cout << "**********************************" << endl;
}

void ErrorMessage() {

	cout << endl << "Please choose the correct option!" << endl;
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

int keyChoice() {

	int key{ 0 };

	cout << "Please enter a key with the value being 1-25: ";
	cin >> key;

	if (key > 25 || key < 1) {
		ErrorMessage();
		keyChoice();
	}
	else {
		return key;
	}
}


