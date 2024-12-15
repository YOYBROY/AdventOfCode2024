#pragma once
#include <iostream>

#include "FileReader.h"
#include "ChallengeFour.h"

using namespace std;

class ChallengeSix 
{
private:
	FileReader fileReader;
	ChallengeFour challengeFour;
public:
	void RunChallengeSix(string input);
	vector<int> FindFirstPosition(char startingCharacter);
	void CheckAction();
	void ChangeDirection();
	vector<int> GetCurrentDirection();
	void MoveForward();
	vector<vector<char>> SimulateMapPos(vector<vector<char>> stableMap, int numOfMoves);
	void MarkLocation(int xPos, int yPos, char toMark);
};
