#include "KeyMaker.h"

void KeyMaker::KeyOne(int input[10])
{
	int temp[10] = {0}; 

	//PART ONE SWAP AROUND 10-BIT KEY
	temp[0] = input[2];
	temp[1] = input[4];
	temp[2] = input[1];
	temp[3] = input[6];
	temp[4] = input[3];
	temp[5] = input[9];
	temp[6] = input[0];
	temp[7] = input[8];
	temp[8] = input[7];
	temp[9] = input[5];
	

	int lsOne[5];
	int lsTwo[5] = { 0 };

	//PART TWO SPLIT UP 10-BIT KEY INTO TWO ARRAYS
	for (int i = 0; i < 2; i++) {
		for (int y = 0; y < 5; y++) {
			if (i == 0) {
				lsOne[y] = temp[y];
			 }
			else {
				lsTwo[y] = temp[y + 5];
			}
		}
	}

	int tempLOne = lsOne[0];
	int tempLTwo = lsTwo[0];


	//PART THREE CICRULAR LEFT BIT SHIFT 
	for (int i = 0; i < 2; i++) {
		for (int y = 0; y < 4; y++) {
			if (i == 0) {

				lsOne[y] = lsOne[y + 1];
			}
			else {
				lsTwo[y] = lsTwo[y + 1];
			}
		}
	}
	
	lsOne[4] = tempLOne;
	lsTwo[4] = tempLTwo;

	KeyTwo(lsOne, lsTwo);

	//MERGE & DROP FRONT 2 BITS
	int keyOne_[8] = { 0 };

	keyOne_[0] = lsTwo[0];
	keyOne_[1] = lsOne[2];
	keyOne_[2] = lsTwo[1];
	keyOne_[3] = lsOne[3];
	keyOne_[4] = lsTwo[2];
	keyOne_[5] = lsOne[4];
	keyOne_[6] = lsTwo[4];
	keyOne_[7] = lsTwo[3];

	for (int i = 0; i < 8; i++) {
		keyOne[i] = keyOne_[i];
	}
	
}

void KeyMaker::KeyTwo(int tempOne[5], int tempTwo[5])
{
	//PART ONE SHUFFLE
	int lsOne[5] = { 0 };
	int lsTwo[5] = { 0 };

	lsOne[0] = tempOne[2];
	lsOne[1] = tempOne[3];
	lsOne[2] = tempOne[4];
	lsOne[3] = tempOne[0];
	lsOne[4] = tempOne[1];

	lsTwo[0] = tempTwo[2];
	lsTwo[1] = tempTwo[3];
	lsTwo[2] = tempTwo[4];
	lsTwo[3] = tempTwo[0];
	lsTwo[4] = tempTwo[1];

	//MERGE & DROP FRONT 2 BITS
	int keyTwo_[8] = { 0 };

	keyTwo_[0] = lsTwo[0];
	keyTwo_[1] = lsOne[2];
	keyTwo_[2] = lsTwo[1];
	keyTwo_[3] = lsOne[3];
	keyTwo_[4] = lsTwo[2];
	keyTwo_[5] = lsOne[4];
	keyTwo_[6] = lsTwo[4];
	keyTwo_[7] = lsTwo[3];

	for (int i = 0; i < 8; i++) {
		keyTwo[i] = keyTwo_[i];
	}
}

int* KeyMaker::GetKeyOne()
{
	//change to pointer
	return keyOne;
}


int* KeyMaker::GetKeyTwo()
{
	//change to pointer
	return keyTwo;
}
