#include <iostream>
#include <string>

#include "KeyMaker.h"

int main() {

	std::string input;
	int tenBitKey[10];
	KeyMaker keymaker;

	int* keyOne;
	int* keyTwo;

	std::cout << "Please input your 10-bit key." << std::endl;
	std::getline(std::cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		tenBitKey[i] = input[i] - '0';
	}

	keymaker.KeyOne(tenBitKey);

	keyOne = keymaker.GetKeyOne();
	keyTwo = keymaker.GetKeyTwo();

	cout << "keyOne: ";

	for (int i = 0; i < 8; i++) {
		cout << keyOne[i];
	}

	cout << endl;

	cout << "keyTwo: ";

	for (int i = 0; i < 8; i++) {
		cout << keyTwo[i];
	}

	return 0;
}