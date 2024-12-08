#include "ChallengeThree.h"

using namespace std;

void ChallengeThree::RunChallengeThree(string fileName)
{
	/*
	Challenge 3:
	Get input as a string
	Iterate through the string and look for the letters "m", this would signify the start of a 
	check if the next 3 chars are "ul("
	
	if ("mul(")
		sort through each and check if they are digits or a comma, if they are anything else then break the loop and move on

		if we get digits, there needs to be a maximum number that can happen because there is only allowed to be 3 digits per number.
		add the digits to two separate arrays, use the comma to toggle a bool

		multiply each array element with its corresponding one in the other array
		Add all of these together for the final result.
	*/

	//Get the whole input file as a string
	string inputString = fileReader.ReadFromFile(fileName);

	//define what to search for
	string toSearchFor = "mul(";
	string doSearchPhrase = "do()";
	string dontSearchPhrase = "don't()";
	

	//search through the inputString for each instance of mul( and add that position to the positions vector, 
	//	the +4 is so the position is the next element after mul( to make things easier down the line
	
	int searchDo = inputString.find(doSearchPhrase, 0);
	int searchDont = inputString.find(dontSearchPhrase, 0);

	vector<int> positions     = CreatePositionsVector(inputString, toSearchFor, 0);
	vector<int> doPositions   = CreatePositionsVector(inputString, doSearchPhrase, 0);
	vector<int> dontPositions = CreatePositionsVector(inputString, dontSearchPhrase, 0);

	for (int i = 0; i < doPositions.size(); i++)
	{
			cout << doPositions[i] << endl;
	}

	vector<int> columnA;
	vector<int> columnB;

	//run through each element of the positions vector
	for (int i = 0; i < positions.size(); i++)
	{
		bool firstColumn = true;
		string runningNum = "";
		int bufferA = 0;
		int bufferB = 0;

		if(!DoIsCloser(positions[i], doPositions, dontPositions))
		{
			continue;
		}

		//checking the 8 elements after the position
		for (int j = 0; j < 8; j++)
		{
			if (positions[i] + j < inputString.size())
			{
				//update current position
				int currentPosition = positions[i] + j;
				//check if the current position is a digit
				if (isdigit(inputString[currentPosition]))
				{
					runningNum += inputString[currentPosition];
				}
				//check if the current position is a comma
				else if (inputString[currentPosition] == ',')
				{
					if (firstColumn)
					{
						bufferA = stoi(runningNum);
						runningNum = "";
					}
					else break;
				}
				//check if the current position is a close bracket
				else if (inputString[currentPosition] == ')' && bufferA != 0 && runningNum != "")
				{
					//store running num into bufferB
					bufferB = stoi(runningNum);
					runningNum = "";
					//add the buffer numbers to their respective arrays
					columnA.push_back(bufferA);
					columnB.push_back(bufferB);
					break;
				}
			}
		}
	}
	
	//initialize result
	int result = 0;

	//Multiply columbs together and add them to the result
	for (int i = 0; i < columnA.size(); i++)
	{
		result += columnA[i] * columnB[i];
	}

	cout << result;
}

vector<int> ChallengeThree::CreatePositionsVector(string inputString, string toSearchFor, int startPos)
{
	vector<int> positionsVector;
	int currentPos = inputString.find(toSearchFor, 0);
	while (currentPos != string::npos)
	{
		positionsVector.push_back(currentPos + 4);
		currentPos = inputString.find(toSearchFor, currentPos + 1);
	}
	return positionsVector;
}

vector<vector<int>> ChallengeThree::Create2DPositionsVector(string inputString, string toSearchFor, int startPos, int yNum)
{
	vector<vector<int>> positionsVector;
	int currentPos = inputString.find(toSearchFor, 0);
	while (currentPos != string::npos)
	{
		positionsVector.push_back({ currentPos + 4, yNum });
		currentPos = inputString.find(toSearchFor, currentPos + 1);
	}
	return positionsVector;
}

vector<vector<int>> ChallengeThree::Combine2DVectors(vector<vector<int>> doPositions, vector<vector<int>> dontPositions)
{
	vector<vector<int>> newVector = doPositions;
	for (int i = 0; i < doPositions.size(); i++)
	{
		for (int j = 0; j < doPositions[i].size(); j++)
		{
			newVector.push_back({ dontPositions[i][j] });
		}
	}
	return newVector;
}

bool ChallengeThree::DoIsCloser(int positionInString, vector<int> doPositions, vector<int> dontPositions)
{
	int doPositionsClosest = 0;
	int dontPositionsClosest = 0;

	for (int i : doPositions)
	{
		if (i < positionInString)
		{
			doPositionsClosest = i;
		}
		else break;
	}

	for (int i : dontPositions)
	{
		if (i < positionInString)
		{
			dontPositionsClosest = i;
		}
		else break;
	}

	int temp = max(doPositionsClosest, dontPositionsClosest);

	//check which is higher
	if (max(doPositionsClosest, dontPositionsClosest) == 0) return true;
	else if (max(doPositionsClosest, dontPositionsClosest) == dontPositionsClosest) return false;
	else return true;
}