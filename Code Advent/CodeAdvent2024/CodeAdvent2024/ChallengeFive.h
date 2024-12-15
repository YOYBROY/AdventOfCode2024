#pragma once
#include "FileReader.h"

class ChallengeFive
{
private: 
	FileReader fileReader;
public:
	void RunChallengeFive(string ruleSetInput, string orderSetInput, bool part1);
	vector<vector<int>> GetRuleList(string ruleSet);
	vector<vector<int>> GetOrderSet(string orderSetInput);
	int ValidateLine(vector<vector<int>> ruleSet, vector<int> lineToCheck, bool part1);
	vector<int> SwitchSpots(vector<int> currentLine, int itemAPos, int itemBPos, int itemAVal, int itemBVal);
};