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
	bool CheckAction(bool markX);
	void ChangeDirection();
	vector<int> GetCurrentDirection();
	void MoveForward(bool markX);
	void SimulateMapState(int numOfMoves);
	void SetMap(string input);
	void ResetMap(string input);
	void ResetPosition();
	void PrintActiveMap();
	void MarkLocation(int xPos, int yPos, char toMark);
};
