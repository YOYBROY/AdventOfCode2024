#pragma once
#include "FileReader.h"

#include <string>

using namespace std;

class ChallengeFour
{
private:
	FileReader fileReader;
public:
	void RunChallengeFour(string fileName, string wordToFind, bool part1);
	vector<vector<char>> Create2DSearchArray(string fileToSourceFrom);
	int SearchForWord(vector<vector<char>> wordSearch, string wordToSearch, bool part1);
	int CircleSearch(vector<vector<char>> wordSearch, string wordToSearch, int xPos, int yPos);
	bool XSearch(vector<vector<char>> wordSearch, string wordToSearch, int xPos, int yPos);
	bool DirectionSearch(vector<vector<char>> wordSearch, string wordToSearch, int posInWord, int xPos, int yPos, int xDir, int yDir);
	char ReturnCharAtPos(vector<vector<char>> wordSearch, int xPos, int yPos, int xDir, int yDir);
};