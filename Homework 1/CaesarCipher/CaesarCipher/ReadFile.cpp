#include "ReadFile.h"



void ReadFile::FileReader()
{
	string filePath;

	cout << endl << "Please enter the name of the txt file: ";
	cin >> filePath;

	if (CheckFilePath(filePath)) {  //I DONT THINK YOU CAN DO THIS IN CONSTRUCTOR
		SetFileContents(filePath);
	}
	else {
		FileReader();
	}
}

bool ReadFile::CheckFilePath(string file)
{
	ifstream inFile;

	inFile.open(file);
	if (!inFile) {
		ErrorMessage();
		inFile.close();
		return false;
	}
	else {
		inFile.close();
		return true;
	}

}

string ReadFile::GetFileContents()
{
	return fileContents;
}

void ReadFile::ErrorMessage()
{
	cout << endl << "File path formatted poorly!" << endl;
}

void ReadFile::SetFileContents(string file)
{
	string line;
	string temp;
    ifstream inFile;

    inFile.open(file);
	if (!inFile) {
		ErrorMessage();
		inFile.close();
	}

    while (getline(inFile, temp)) {

		line.append(temp);
    }

	fileContents = line;

    inFile.close();

}


