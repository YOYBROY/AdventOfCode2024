#pragma once
#include "FileReader.h"

class ChallengeFive
{
private: 
	FileReader fileReader;
public:
	void RunChallengeFive(string ruleSetInput, string orderSetInput);
	vector<vector<int>> GetRuleList(string ruleSet);
	vector<vector<int>> GetOrderSet(string orderSetInput);
	bool ValidateLine(vector<vector<int>> ruleSet, vector<vector<int>> orderSet, int lineNum);
};