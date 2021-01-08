#pragma once

#include <iostream>
#include <string>
using std::string;

class Caesar
{
public:
	Caesar() = default;
	void Encrypt(string);
	void Decrypt(string);
	string GetWord();
private:
	void SetWord(string);
	string newWord{ 0 };
};

