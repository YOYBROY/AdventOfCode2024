#pragma once

#include <string>
#include <vector>

using namespace std;

class FileReader
{
private:

public:
	string ReadFromFile(string fileName);
	const int GetLineCount(string fileName);
	int GetColumnCountAt(string fileName, int lineNumber);
	string GetLineContentsAt(string fileName, int lineNumber);
	vector<int> ConvertStringToArray(string stringToConvert);
};