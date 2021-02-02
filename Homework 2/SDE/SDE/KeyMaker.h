#pragma once
#include <iostream>
#include <algorithm>
using std::swap;
using std::cout;
using std::endl;

class KeyMaker
{
public:
	KeyMaker() = default;
	void KeyOne(int input[10]);
	void KeyTwo(int lsOne[5], int lsTwo[5]);
	int* GetKeyOne();
	int* GetKeyTwo();
private:
	int keyOne[8] = { 0 };
	int keyTwo[8] = { 0 };
};

