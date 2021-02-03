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
	string Szero[4][4] = { 
	"01","00","11","10",
	"11","10","01","00",
	"00","10","01","11",
	"11","01","11","10"
	};
				
	string column = to_string(temp[1]) + to_string(temp[2]);
	string row = to_string(temp[0]) + to_string(temp[3]);

	const char* bitOption[] = { "00", "01", "10", "11" };

	int rowIndex{ 0 };
	int columnIndex{ 0 };

	for (int i = 0; i < 4; i++) {

		if (bitOption[i] == row) {
			rowIndex = i;
		}

		if (bitOption[i] == column) {
			columnIndex = i;
		}
	}

	string outputSzero = Szero[rowIndex][columnIndex];


	//S1
	string Sone[4][4] = {
	"00","01","10","11",
	"10","00","01","11",
	"11","00","01","00",
	"10","01","00","11"
	};
	
	column = to_string(temp[5]) + to_string(temp[6]);
	row = to_string(temp[4]) + to_string(temp[7]);

	for (int i = 0; i < 4; i++) {

		if (bitOption[i] == row) {
			rowIndex = i;
		}

		if (bitOption[i] == column) {
			columnIndex = i;
		}
	}

	string outputSone = Sone[rowIndex][columnIndex];


	//cout << "output: " << outputSzero << " " << outputSone << endl;


	//MERGE

	//XOR two

}

void SDE::SetFinalText() {



}

int* SDE::GetFinalText()
{
	return finalText;
}
