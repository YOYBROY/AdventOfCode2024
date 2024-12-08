#include "ChallengeOne.h"

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

ChallengeOne::ChallengeOne()
{
}

ChallengeOne::~ChallengeOne()
{
}

void ChallengeOne::RunChallengeOne(string set1, string set2, bool part1)
{
	int list1Size = fileReader.GetLineCount(set1);
	int list2Size = fileReader.GetLineCount(set2);

	int* list1 = new int[list1Size];
	int* list2 = new int[list2Size];

	for (int i = 0; i < list1Size; i++)
	{
		list1[i] = stoi(fileReader.GetLineContentsAt(set1, i + 1));
	}

	for (int i = 0; i < list2Size; i++)
	{
		list2[i] = stoi(fileReader.GetLineContentsAt(set2, i + 1));
	}

	if (part1)
	{
		int listDifference = GetDifferenceBetweenLists(list1, list2, list1Size);
		cout << listDifference << endl;
	}
	else {
		int similarityScore = GetSimilarityScore(list1, list2, list1Size);
		cout << similarityScore << endl;
	}
}

int ChallengeOne::GetDifferenceBetweenLists(int list1[], int list2[], int listSize)
{
	sort(list1, list1 + listSize);
	sort(list2, list2 + listSize);

	int result = 0;

	for (int j = 0; j < listSize; j++)
	{
		result += abs(list1[j] - list2[j]);
	}

	return result;
}

int ChallengeOne::GetSimilarityScore(int list1[], int list2[], int listSize)
{
	int result = 0;

	for (int i = 0; i < listSize; i++)
	{
		int numberOfTimesPresent = 0;
		for (int j = 0; j < listSize; j++)
		{
			if (list1[i] == list2[j])
			{
				numberOfTimesPresent++;
			}
		}
		result += list1[i] * numberOfTimesPresent;
	}
	return result;
}