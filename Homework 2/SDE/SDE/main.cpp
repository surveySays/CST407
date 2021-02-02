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

	partTwo.PartTwoSetters(text, keyOne, keyTwo);

	finalText = partTwo.GetFinalText();

	cout << "New word: ";

	for (int i = 0; i < 8; i++) {
		cout << finalText[i];
	}

	cout << endl;

	/*cout << "keyOne: ";

	for (int i = 0; i < 8; i++) {
		cout << keyOne[i];
	}

	cout << endl;

	cout << "keyTwo: ";

	for (int i = 0; i < 8; i++) {
		cout << keyTwo[i];
	}*/

	return 0;
}