#include "ReadFile.h"


ReadFile::ReadFile()
{
	string filePath;

	cout << endl << "Please paste the path of the .txt file: ";
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

void ReadFile::SetFileContents(string filePath)
{
	string contents;

	ifstream myfile(filePath);

	if (myfile.is_open())
	{
		while (getline(myfile, contents))
		{
			contents += contents;
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	cout << contents;

}


