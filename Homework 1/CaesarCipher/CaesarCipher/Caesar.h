#pragma once

#include <iostream>
#include <string>
using std::string;

class Caesar
{
public:
	Caesar();
	~Caesar();
	string Encrypt();
	string Decrypt();
private:
	string word{ 0 };
};

