#include "ChallengeSix.h"


#include <iostream>
#include <vector>

vector<vector<char>> stableMap;
vector<int> currentPosition{0, 0};
bool canMove = true;

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

enum Direction currentDirection = UP;

void ChallengeSix::RunChallengeSix(string input)
{
	/*
	Challenge Six:
	-Create a 2D vector of the input string to represent the map
	-find the position of the guard ^
	-Check the position in front of the guard
	If it is an empty space "." or "X" then call the move function
	replace the spot you moved from with X to say they have been there
	If it is a filled space # then call the turn function
	If it is an invalid location on the map then that is the final position of the guard
	count up the number of X's in the final list.
	*/

	stableMap = challengeFour.Create2DSearchArray(input);
	currentPosition = FindFirstPosition('^');

	vector<vector<char>> activeMap = SimulateMapPos(stableMap, 2);

	//while (canMove)
	//{
	//	CheckAction();
	//}

	int result = 0;

	//cout << currentPosition[0] << " , " << currentPosition[1] << endl;
	for (int i = 0; i < activeMap.size(); i++)
	{
		for (int j = 0; j < activeMap[i].size(); j++)
		{
			if (activeMap[i][j] == 'X') result++;
			cout << activeMap[i][j];
		}
		cout << endl;
	}
	cout << result << endl;
}

vector<int> ChallengeSix::FindFirstPosition(char startingCharacter)
{
	for (int i = 0; i < stableMap.size(); i++)
	{
		for (int j = 0; j < stableMap[i].size(); j++)
		{
			if (stableMap[i][j] == startingCharacter)
			{
				return { j, i };
			}
		}
	}
	return { 0, 0 };
}

void ChallengeSix::CheckAction()
{
	char nextChar = challengeFour.ReturnCharAtPos(stableMap, currentPosition[0], currentPosition[1], GetCurrentDirection()[0], GetCurrentDirection()[1]);
	if (nextChar == NULL)
	{
		MarkLocation(currentPosition[0], currentPosition[1], 'X');
		canMove = false;
	}
	if (nextChar == '.' || nextChar == 'X')
	{
		MoveForward();
	}
	if (nextChar == '#')
	{
		ChangeDirection();
	}

}

void ChallengeSix::ChangeDirection()
{
	switch (currentDirection)
	{
	case UP:
		currentDirection = RIGHT;
		break;
	case RIGHT:
		currentDirection = DOWN;
		break;
	case DOWN:
		currentDirection = LEFT;
		break;
	case LEFT:
		currentDirection = UP;
	}
}

vector<int> ChallengeSix::GetCurrentDirection()
{
	vector<int> returnVec { 0, 0 };

	switch (currentDirection)
	{
	case UP:
		returnVec = { 0,1 };
		return returnVec;
	case RIGHT:
		returnVec = { 1,0 };
		return returnVec;
	case DOWN:
		returnVec = { 0,-1 };
		return returnVec;
	case LEFT:
		returnVec = { -1,0 };
		return returnVec;
	}
}

void ChallengeSix::MarkLocation(int xPos, int yPos, char toMark)
{
	stableMap[yPos][xPos] = toMark;
}

void ChallengeSix::MoveForward()
{
	MarkLocation(currentPosition[0], currentPosition[1], 'X');
	vector<int> newPosition = { currentPosition[0] + GetCurrentDirection()[0], currentPosition[1] - GetCurrentDirection()[1] };
	currentPosition = newPosition;
	MarkLocation(currentPosition[0], currentPosition[1], '^');
}

vector<vector<char>> ChallengeSix::SimulateMapPos(vector<vector<char>> stableMap, int numOfMoves)
{
	for (int i = 0; i < numOfMoves; i++)
	{
		CheckAction();
		MarkLocation(currentPosition[0], currentPosition[1], 'O');
	}
	return 
}