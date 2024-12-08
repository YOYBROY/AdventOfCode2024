#pragma once
#include "FileReader.h"
#include <fstream>
#include <vector>
using namespace std;

class ChallengeTwo
{
private:
	FileReader fileReader;

	bool ValidateArray(vector<int> myVector, bool safetyDampener);
	vector<int> EraseFromVectorAt(vector<int> myVector, int intToRemove);

public:
	ChallengeTwo();
	~ChallengeTwo();

	void RunChallengeTwo(string fileName, bool part1);
};