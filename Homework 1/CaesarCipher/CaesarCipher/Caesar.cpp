#include "Caesar.h"


void Caesar::Encrypt(string oldWord, int key_)
{
	key = key_; //set private key variable to key from main

	char* char_arr;
	string str_obj(oldWord);
	char_arr = &str_obj[0];
	string temp;

	for (int i = 0; i < oldWord.length(); i++) {
		
		if (char_arr[i] + key_ > 122) {  //z ascii = 122
			char_arr[i] = (char_arr[i] + key_) - 26;
			temp.push_back(char_arr[i]);
		}
		else {
			char_arr[i] = char_arr[i] + key_;
			temp.push_back(char_arr[i]);
		}
	}

	SetWord(temp);

	WriteToFile();
}

void Caesar::Decrypt(string oldWord)
{
	//Decrypt stuff
	//
	//


	SetWord(oldWord);

	WriteToFile();
}

string Caesar::GetWord()
{
	return newWord;
}

void Caesar::SetWord(string oldWord)
{
	newWord = oldWord;
}

void Caesar::WriteToFile()
{
	cout << "Sucess writing new word to file." << endl;

	ofstream out("output.txt");
	out << newWord;
	out.close();
}
