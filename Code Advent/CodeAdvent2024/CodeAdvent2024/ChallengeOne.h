#pragma once
#include "FileReader.h"
#include <fstream>
#include <string>

using namespace std;

class ChallengeOne
{
private:
	FileReader fileReader;

	int GetDifferenceBetweenLists(int list1[], int list2[], int listSize);
	int GetSimilarityScore(int list1[], int list2[], int listSize);

public:
	ChallengeOne();
	~ChallengeOne();

	void RunChallengeOne(string set1, string set2, bool part1);
};