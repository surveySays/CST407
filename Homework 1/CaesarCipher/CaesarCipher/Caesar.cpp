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

void Caesar::Decrypt(string oldWord, int key_)
{
	key = key_; //set private key variable to key from main

	char* char_arr;
	string str_obj(oldWord);
	char_arr = &str_obj[0];
	string temp;

	for (int i = 0; i < oldWord.length(); i++) {

		if (char_arr[i] - key_ < 97) {  //a ascii = 97
			char_arr[i] = (char_arr[i] - key_) + 26;
			temp.push_back(char_arr[i]);
		}
		else {
			char_arr[i] = char_arr[i] - key_;
			temp.push_back(char_arr[i]);
		}
	}

	SetWord(temp);

	WriteToFile();
}

void Caesar::DecryptNoKey(string oldWord)
{
	char* char_arr = &oldWord[0];
	string stringHolder = oldWord;

	string temp;

	for (int y = 1; y < 26; y++) { //gotta do this 26 times because alphabet is 26 letters

		//changing value of caesar here
		for (int i = 0; i < oldWord.length(); i++) {

			if (char_arr[i] - y < 97) {  //a ascii = 97
				char_arr[i] = (char_arr[i] - y) + 26;	//using y as key because it will keep incrementing
				temp.push_back(char_arr[i]);
			}
			else {
				char_arr[i] = char_arr[i] - y;
				temp.push_back(char_arr[i]);
			}
		}

		//parsing dictionary here
		if (vowelCheck(temp, oldWord.size())) { //if there is a vowel then lets search the word, else lets skip it

			DictionarySearch(temp, y);
		}

		temp = "";
		oldWord = stringHolder;
		char* char_arr = &oldWord[0];
	}

	PrintMap();
}

bool Caesar::vowelCheck(string word, int size)
{
	const string vowels[] = { "a", "e", "i", "o", "u", "y" };

	for (int i = 0; i < 6; ++i) {

		if (word.find(vowels[i]) != std::string::npos) {  //need to see if word contains any vowels before we start searching dictionary
			return true;
		}
	}
	
	return false;
}

void Caesar::DictionarySearch(string word, int key)
{
	const string wordsTest[] = { "hello", "there" };

	for (int i = 0; i < 1; ++i) {

		if (word.find(wordsTest[i]) != std::string::npos) {  //need to see if word contains any vowels before we start searching dictionary
			successWords.insert(std::pair<int, string>(key, word));
		}
	}

	//successWords.insert(std::pair<int, string>(key, word));
}

void Caesar::PrintMap()
{

	if (successWords.empty()) {

		cout << "No solutions found." << endl;
	}
	else
	{
		cout << endl << "Possible options below:" << endl;

		for (auto it = successWords.cbegin(); it != successWords.cend(); ++it)
		{
			cout << "Decrypted word: " << it->second << endl;
			cout << "Key: " << it->first << endl << endl;
		}
	}
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


