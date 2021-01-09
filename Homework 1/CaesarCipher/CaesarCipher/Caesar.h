#pragma once

#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::ofstream;
using std::cout;
using std::endl;

class Caesar
{
public:
	Caesar() = default;
	void Encrypt(string, int);
	void Decrypt(string, int);
	void DecryptNoKey(string);
	string GetWord();
private:
	void SetWord(string);
	void WriteToFile();
	string newWord{ 0 };
	int key{ 0 };
};

