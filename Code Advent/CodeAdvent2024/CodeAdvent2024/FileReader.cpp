#include "FileReader.h"

#include <fstream>
#include <string>
#include <vector>

using namespace std;

string FileReader::ReadFromFile(string fileName)
{
	string line;
	ifstream myFile(fileName);
	string result;
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			result += line;
		}
		myFile.close();
	}
	return result;
}

const int FileReader::GetLineCount(string fileName)
{
	string line;
	ifstream myFile(fileName);
	int lineCount = 0;

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			lineCount++;
		}
		myFile.close();
	}
	return lineCount;
}

int FileReader::GetColumnCountAt(string fileName, int lineNumber)
{
	string line;
	ifstream myFile(fileName);
	int listSize = 0;

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			listSize++;
			if (listSize == lineNumber)
			{
				return line.size();
				break;
			}
		}
		myFile.close();
	}
}

string FileReader::GetLineContentsAt(string fileName, int lineNumber)
{
	string line;
	ifstream myFile(fileName);
	int listSize = 0;

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			listSize++;
			if (listSize == lineNumber)
			{
				return line;
				break;
			}
		}
		myFile.close();
	}
}

vector<int> FileReader::ConvertStringToArray(string stringToConvert)
{
	//Puts numbers into vector
	vector<int> myVector;
	string runningString = "";
	for (int i = 0; i < stringToConvert.length(); i++)
	{
		if (i == stringToConvert.length() - 1)
		{
			runningString += stringToConvert[i];
			myVector.push_back(stoi(runningString));
			runningString = "";
		}

		if (isdigit(stringToConvert[i]))
		{
			runningString += stringToConvert[i];
			continue;
		}
		else
		{
			myVector.push_back(stoi(runningString));
			runningString = "";
		}
	}
	return myVector;
}