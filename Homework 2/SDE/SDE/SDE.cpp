#include "SDE.h"

void SDE::PartTwoSetters(int text[8], int* keyOne_, int* keyTwo_)
{
	//PART ONE with regular text
	leftHalf[0] = text[1];
	leftHalf[1] = text[5];
	leftHalf[2] = text[2];
	leftHalf[3] = text[0];

	rightHalf[0] = text[3];
	rightHalf[1] = text[7];
	rightHalf[2] = text[4];
	rightHalf[3] = text[6];

	for (int i = 0; i < 8; i++) {
		keyOne[i] = keyOne_[i];
		keyTwo[i] = keyTwo_[i];
	}

	MiddlePart();
}

void SDE::MiddlePart() {

	int temp[8] = { 0 };

	//RIGHT HALF into new 8 bit temp
	temp[0] = rightHalf[3];
	temp[1] = rightHalf[0];
	temp[2] = rightHalf[1];
	temp[3] = rightHalf[2];
	temp[4] = rightHalf[1];
	temp[5] = rightHalf[2];
	temp[6] = rightHalf[3];
	temp[7] = rightHalf[0];


	/*cout << "temp start: ";

	for (int i = 0; i < 8; i++) {
		cout << temp[i];
	}


	cout << endl << "keyOne: ";

	for (int i = 0; i < 8; i++) {
		cout << keyOne[i];
	}*/
	//XOR one

	/*	a	b	a^ b
		0	0	0
		0	1	1
		1	0	1
		1	1	0*/

	for (int i = 7; i >= 0; i--) {

		if (temp[i] == 0 && keyOne[i] == 0) {
			temp[i] = 0;
		}
		else if (temp[i] == 0 && keyOne[i] == 1) {
			temp[i] = 1;
		}
		else if (temp[i] == 1 && keyOne[i] == 0) {
			temp[i] = 1;
		}
		else {
			temp[i] = 0;
		}
	}

	//cout << endl << "xor: ";

	//for (int i = 0; i < 8; i++) {
	//	cout << temp[i];
	//}

	//S0

	//S1

	//MERGE

	//XOR two

}

void SDE::SetFinalText() {



}

int* SDE::GetFinalText()
{
	return finalText;
}
