#include "ReadFile.h"


ReadFile::ReadFile()
{
	string filePath;

	cout << endl << "Please enter the name of the txt file: ";
	cin >> filePath;

	if (CheckFilePath(filePath)) { //if true, then setFilePath
		SetFileContents(filePath);
	} 
	else {
		ErrorMessage();
		ReadFile();
	}
}

bool ReadFile::CheckFilePath(string)
{
	return true;
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
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (getline(inFile, temp)) {

		line.append(temp);
    }

	fileContents = line;

    inFile.close();

}


