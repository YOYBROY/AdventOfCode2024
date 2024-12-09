#pragma once
#include "FileReader.h"

#include <iostream>
#include <string>

using namespace std;

class ChallengeThree {
private:
	FileReader fileReader;
public:
	void RunChallengeThree(string fileName, bool part1);
	vector<int> CreatePositionsVector(string inputString, string toSearchFor, int startPos);
	vector<vector<int>> Create2DPositionsVector(string inputString, string toSearchFor, int startPos, int yNum);
	vector<vector<int>> Combine2DVectors(vector<vector<int>> doPositions, vector<vector<int>> dontPositions);
	bool DontIsCloser(int positionInString, vector<int> doPositions, vector<int> dontPositions);
};


