#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::getline;


class ReadFile
{
public:
	ReadFile();
	bool CheckFilePath(string);
	string GetFileContents();
	void ErrorMessage();

private:
	void SetFileContents(string);
	string fileContents{ 0 };
};

