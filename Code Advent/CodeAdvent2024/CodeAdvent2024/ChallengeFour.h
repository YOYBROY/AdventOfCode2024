#pragma once
#include "FileReader.h"

#include <string>

using namespace std;

class ChallengeFour {
private:
	FileReader fileReader;
	string wordToSearch = "XMAS";
public:
	void RunChallengeFour(string fileName, string wordToFind);

	vector<vector<char>> Populate2DArray(vector<vector<char>> vecToPopulate, string fileToSourceFrom, int width, int height);
	int SearchForWord(vector<vector<char>> wordSearch, string wordToSearch);
	int CircleSearch(vector<vector<char>> wordSearch, string wordToSearch, int xPos, int yPos);
	bool DirectionSearch(vector<vector<char>> wordSearch, string wordToSearch, int posInWord, int xPos, int yPos, int xDir, int yDir);
};