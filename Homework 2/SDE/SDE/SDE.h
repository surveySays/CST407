#pragma once
#include <iostream>
#include <algorithm>
using std::swap;
using std::cout;
using std::endl;

class SDE
{
public:
	SDE() = default;
	void PartTwoSetters(int text[8], int* keyOne_, int* keyTwo_);
	int* GetFinalText();
private:
	void MiddlePart();
	void SetFinalText();
	int rightHalf[4] = { 0 };
	int leftHalf[4] = { 0 };
	int keyOne[8] = { 0 };
	int keyTwo[8] = { 0 };
	int finalText[8] = { 0 };
};

