#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iterator> 
#include <map>
#include <vector>

using std::string;
using std::ofstream;
using std::cout;
using std::endl;
using std::map;

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
	void PrintMap();
	void WriteToFile();
	bool vowelCheck(string, int);
	void DictionarySearch(string, int);
	string newWord{ 0 };
	int key{ 0 };
	int count{ 0 };
	std::vector<string> wordsFound;
	map<int, string> successWords;
};

