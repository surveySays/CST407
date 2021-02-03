#include <iostream>
#include <string>

#include "KeyMaker.h"
#include "SDE.h"

int main() {

	std::string input;
	int tenBitKey[10];
	int text[8];
	KeyMaker keymaker;
	SDE partTwo;

	int* keyOne;
	int* keyTwo;
	int* finalText;

	std::cout << "Please input your 10-bit key." << std::endl;
	std::getline(std::cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		tenBitKey[i] = input[i] - '0';
	}

	keymaker.KeyOne(tenBitKey);

	keyOne = keymaker.GetKeyOne();
	keyTwo = keymaker.GetKeyTwo();

	std::cout << "Please input your 8-bit text: " << std::endl;
	std::getline(std::cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		text[i] = input[i] - '0';
	}

	char choice;
	std::cout << "Please choose 'e' for encryption or 'd' for decryption: ";
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