#include "ChallengeTwo.h"

#include <iostream>
#include <string>
#include <vector>

ChallengeTwo::ChallengeTwo()
{
}

ChallengeTwo::~ChallengeTwo()
{
}

//CHALLENGE 2
	/*
	Start by getting the line and adding each number to an array separated by the space
	loop through the array and check the following
	On the first run, check if the numbers are acsending or descending and set a bool accordingly, and if the difference between them is within 1-3

	For each concecutive run, check if each pair is ascending or descending accoring to the direction of the set, and if the difference between them is withing 1-3

	Break at any point if this doesn't work and move to the next report

	If it makes it to the end of the loops then add 1 to totalSafe
	*/

void ChallengeTwo::RunChallengeTwo(string fileName, bool part1)
{
	int numberOfReports = fileReader.GetLineCount(fileName);

	int safeReports = 0;

	for (int i = 1; i <= numberOfReports; i++)
	{
		string targetLine = fileReader.GetLineContentsAt(fileName, i);
		bool safe = ValidateArray(fileReader.ConvertStringToArray(targetLine), true);
		if (safe == 1)
		{
			safeReports++;
		}
	}
	cout << safeReports << endl;
	system("pause");
}

bool ChallengeTwo::ValidateArray(vector<int> myVector, bool safetyDampener)
{
	bool ascending = false;

	if (safetyDampener)
	{
		for (int i = 0; i < myVector.size(); i++)
		{
			if (ValidateArray(EraseFromVectorAt(myVector, i), false))
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		for (int i = 0; i < myVector.size(); i++)
		{
			if (i == 0)
			{
				int numberDifference = abs(myVector[i] - myVector[i + 1]);
				if (numberDifference < 1 || numberDifference > 3) return false;
				if (myVector[i] - myVector[i + 1] < 0) ascending = true; else ascending = false;
				continue;
			}
			if (i == myVector.size() - 1)
			{
				return true;
			}

			int numberDifference = abs(myVector[i] - myVector[i + 1]);

			if (numberDifference < 1 || numberDifference > 3) return false;

			if (ascending) { if (myVector[i] - myVector[i + 1] > 0) return false; }
			else { if (myVector[i] - myVector[i + 1] < 0) return false; }
		}
	}
}

//Remove a vector at specific numbered index, 
//if we ask for 4 it wont delete the fourth element, it will delete the one called 4, so fifth
vector<int> ChallengeTwo::EraseFromVectorAt(vector<int> myVector, int intToRemove)
{
	myVector.erase(myVector.begin() + intToRemove);

	return myVector;
}