#include "ChallengeOne.h"
#include "ChallengeTwo.h"
#include "ChallengeThree.h"
#include "ChallengeFour.h"
#include "ChallengeFive.h"
#include "FileReader.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ChallengeOne* challenge1{};
	ChallengeTwo* challenge2{};
	ChallengeThree* challenge3{};
	ChallengeFour* challenge4{};
	ChallengeFive* challenge5{};

	//true == 3569916, false == 26407426
	//challenge1->RunChallengeOne("Day1Input1.txt", "Day2Input2.txt", false);

	//true == 569, false == 524
	//challenge2->RunChallengeTwo("Day2Input.txt", true);

	//true == 173731097, false == 93729253
	//challenge3->RunChallengeThree("Day3Input.txt", false);

	//true == 2500, false == 1933
	//challenge4->RunChallengeFour("Day4Input.txt", "XMAS", true);
	//challenge4->RunChallengeFour("Day4Input.txt", "MAS", false);

	challenge5->RunChallengeFive("Day5Input1.txt", "Day5Input2.txt");
}