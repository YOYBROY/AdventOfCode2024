#include "ChallengeFive.h"

#include <iostream>

using namespace std;

void ChallengeFive::RunChallengeFive(string ruleSetInput, string orderSetInput)
{
	/*
	Challenge Five:
	-Get each rule column in a vector each rulSetA and ruleSetB
	-Go through each line in the orderSet and check that each pair follows the rules outlined for them
	-If they do follow the rules then find the middle number in the order set (ruleSetLine.size / 2)
		and return the middle value
	-Add up all of the middle values on the orders that are valid
	*/

	//Create Rule list Array
	vector<vector<int>> ruleSet = GetRuleList(ruleSetInput);
	//Create Order list Array
	vector<vector<int>> orderSet = GetOrderSet(orderSetInput);
	
	int result = 0;

	for (int i = 0; i < orderSet.size(); i++)
	{
		if(!ValidateLine(ruleSet, orderSet, i)) continue;
		int positionOfMiddle = orderSet[i].size() * 0.5f;
		result += orderSet[i][positionOfMiddle];
		cout << result << endl;
	}

	//for (int i = 0; i < orderSet.size(); i++)
	//{
	//	for (int j = 0; j < orderSet[i].size(); j++)
	//	{
	//		cout << orderSet[i][j];
	//	}
	//	cout << endl;
	//}
}

vector<vector<int>> ChallengeFive::GetRuleList(string ruleSet)
{
	//Get width and height of the input file
	int height = fileReader.GetLineCount(ruleSet);

	//create 2D vector with specified width and height
	vector<vector<int>>myVector;

	//run through each element of the positions vector
	for (int i = 0; i < height; i++)
	{
		string runningNum = "";
		bool firstColumn = true;

		int bufferA = 0;
		int bufferB = 0;

		string currentLine = fileReader.GetLineContentsAt(ruleSet, i + 1);
		for (int j = 0; j < currentLine.size(); j++)
		{
			if (isdigit(currentLine[j]))
			{
				runningNum += currentLine[j];
			}
			else if (!isdigit(currentLine[j]))
			{
				bufferA = stoi(runningNum);
				runningNum = "";
				firstColumn = false;
			}
			if (j == currentLine.size() - 1)
			{
				bufferB = stoi(runningNum);
				vector<int> tempVec;
				tempVec.push_back(bufferA);
				tempVec.push_back(bufferB);
				myVector.push_back(tempVec);
			}
		}
	}
	return myVector;
}

vector<vector<int>> ChallengeFive::GetOrderSet(string orderSet) 
{
	//Get width and height of the input file
	int height = fileReader.GetLineCount(orderSet);

	//create 2D vector with specified width and height
	vector<vector<int>>return2DVector;
	
	//2Dvectors do height first and then width vector[height][width]
	for (int i = 0; i < height; i++)
	{
		string runningNum = "";
		vector<int> tempVector;

		string currentLine = fileReader.GetLineContentsAt(orderSet, i + 1);
		for (int j = 0; j < currentLine.size(); j++)
		{
			if (isdigit(currentLine[j]))
			{
				runningNum += currentLine[j];
			}
			else if (!isdigit(currentLine[j]))
			{
				tempVector.push_back(stoi(runningNum));
				runningNum = "";
			}
			if (j == currentLine.size() - 1)
			{
				tempVector.push_back(stoi(runningNum));
				return2DVector.push_back(tempVector);
			}
		}
	}
	return return2DVector;
}

bool ChallengeFive::ValidateLine(vector<vector<int>> ruleSet, vector<vector<int>> orderSet, int lineNum)
{
	/*
	foreach pair
	check if they match the rule sets they are associated with
	search backwards, search for the last number in the first column of the rule set,
	for time the last number shows up in the first column, check each of column 2 against each number in the line
	
	return true
	*/
	vector<int> lineToCheck = orderSet[lineNum];

	for (int i = lineToCheck.size() - 1; i > 0; i--) {
		for (int j = 0; j < ruleSet.size(); j++) {
			if (lineToCheck[i] == ruleSet[j][0]) {
				for (int s = 0; s < i; s++) {
					if (lineToCheck[s] == ruleSet[j][1]) {
						return false;
					}
				}
			}
		}
	}
	return true;
}