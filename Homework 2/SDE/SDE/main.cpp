#include <iostream>
#include <string>

#include "KeyMaker.h"
#include "SDE.h"

int main() {

	int* keyOne;
	int* keyTwo;
	int* finalText;
	KeyMaker keymaker;
	SDE partTwo;
	std::string input{""};
	int tenBitKey[10] = {0};
	int text[8] = {0};

	cout << "Please input your 10-bit key:" << std::endl;
	std::getline(std::cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		tenBitKey[i] = input[i] - '0';
	}

	keymaker.KeyOne(tenBitKey);

	keyOne = keymaker.GetKeyOne();
	keyTwo = keymaker.GetKeyTwo();

	cout << "Please input your 8-bit text: " << std::endl;
	std::getline(std::cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		text[i] = input[i] - '0';
	}

	char choice;
	cout << "Please choose 'e' for encryption or 'd' for decryption: ";
	std::cin >> choice;

	//change to user option
	bool flag { true };
	
	if (choice == 'e' || choice == 'E') {
		flag = true;
	} 
	else {
		flag = false;
	}

	partTwo.PartTwoSetters(text, keyOne, keyTwo, flag);

	finalText = partTwo.GetFinalText();

	cout << "New word: ";

	for (int i = 0; i < 8; i++) {
		cout << finalText[i];
	}

	cout << endl;


	return 0;
}