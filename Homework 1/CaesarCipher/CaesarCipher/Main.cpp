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
int keyOption();

int main() {

	Welcome();
	
	char again = 'y';

	while (again == 'y' || again == 'Y') {

		int key = keyOption();

		Caesar caeser;

		if (key == 0) {

			ReadFile reader;
			reader.FileReader();
			caeser.DecryptNoKey(reader.GetFileContents());
		}
		else {

			if (cipherChoice() == 'E') {
				ReadFile reader;
				reader.FileReader();
				caeser.Encrypt(reader.GetFileContents(), key);

				cout << "Encrypted string: " << caeser.GetWord() << endl;
			}
			else {
				ReadFile reader;
				reader.FileReader();
				caeser.Decrypt(reader.GetFileContents(), key);

				cout << "Decrypted string: " << caeser.GetWord() << endl;
			}
		}

		cout << endl << "Again? Enter 'y': ";
		cin >> again;
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

int keyOption() {

	string option{ 0 };

	cout << "Please type 'n' if no key or type 'y' if you want to use a key: ";
	cin >> option;

	if (option == "n" || option == "N") {
		return 0;
	}
	else if (option == "y" || option == "Y") {
		return keyChoice();
	}
	else {
		ErrorMessage();
		keyOption();
	}
}


