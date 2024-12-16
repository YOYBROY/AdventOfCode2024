#include "ChallengeSix.h"

#include <chrono>
#include <iostream>
#include <vector>

vector<vector<char>> stableMap;
vector<vector<char>> activeMap;
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
	auto beg = chrono::high_resolution_clock::now();

	int result = 0;

	vector<vector<int>> guardPositions;

	//Set up map
	SetMap(input);
	ResetPosition();
	//get all the positions that the guard moves to in the unedited map.
	while (canMove)
	{
		CheckAction(true);
	}

	//cout << currentPosition[0] << " , " << currentPosition[1] << endl;
	for (int i = 0; i < activeMap.size(); i++)
	{
		for (int j = 0; j < activeMap[i].size(); j++)
		{
			if (activeMap[i][j] == 'X')
			{
				guardPositions.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i <= guardPositions.size(); i++)
	{
		//set activeMap to base input
		ResetMap(input);
		ResetPosition();
		vector<int> currentVec = guardPositions[i];
		activeMap[currentVec[0]][currentVec[1]] = 'O';
		int hitStopper = 0;
		int counter = 0;
		while (canMove)
		{
			hitStopper += CheckAction(true);
			if (hitStopper > 5) { result++; break; }
			counter++;
			if (counter > 15000) { result++; break; }
		}
		cout << i << endl;
	}
	cout << result << endl;

	//for (int i = 0; i < activeMap.size(); i++)
	//{
	//	for (int j = 0; j < activeMap[i].size(); j++)
	//	{
	//		if (activeMap[i][j] == 'X') result++;
	//		cout << activeMap[i][j];
	//	}
	//	cout << endl;
	//}

	//Print elapsed time
	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::seconds>(end - beg);

	// Displaying the elapsed time
	std::cout << "Elapsed Time: " << duration.count();
}

vector<int> ChallengeSix::FindFirstPosition(char startingCharacter)
{
	for (int i = 0; i < activeMap.size(); i++)
	{
		for (int j = 0; j < activeMap[i].size(); j++)
		{
			if (activeMap[i][j] == startingCharacter)
			{
				return { j, i };
			}
		}
	}
	return { 0, 0 };
}

bool ChallengeSix::CheckAction(bool notSimulation)
{
	//char currentChar = challengeFour.ReturnCharAtPos(activeMap, currentPosition[0], currentPosition[1], 0, 0);
	vector<int> tempVec = GetCurrentDirection();
	char nextChar = challengeFour.ReturnCharAtPos(activeMap, currentPosition[0], currentPosition[1], tempVec[0], tempVec[1]);

	if (nextChar == NULL)
	{
		MarkLocation(currentPosition[0], currentPosition[1], 'X');
		canMove = false;
	}
	if (nextChar == '.' || nextChar == 'X')
	{
		if (notSimulation) MarkLocation(currentPosition[0], currentPosition[1], 'X');
		MoveForward(notSimulation);
	}
	if (nextChar == '#')
	{
		ChangeDirection();
	}
	if (nextChar == 'O')
	{
		ChangeDirection();
		return true;
	}
	return false;
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
	activeMap[yPos][xPos] = toMark;
}

void ChallengeSix::MoveForward(bool notSimulation)
{
	vector<int> newPosition = { currentPosition[0] + GetCurrentDirection()[0], currentPosition[1] - GetCurrentDirection()[1] };
	currentPosition = newPosition;
	if (notSimulation)MarkLocation(currentPosition[0], currentPosition[1], '^');
}

void ChallengeSix::SimulateMapState(int numOfMoves)
{
	for (int i = 0; i < numOfMoves; i++)
	{
		CheckAction(false);
	}
	MarkLocation(currentPosition[0], currentPosition[1], 'O');
}

void ChallengeSix::SetMap(string input)
{
	stableMap = challengeFour.Create2DSearchArray(input);
	activeMap = challengeFour.Create2DSearchArray(input);
}

void ChallengeSix::ResetMap(string input)
{
	activeMap = stableMap;
}

void ChallengeSix::ResetPosition()
{
	currentPosition = FindFirstPosition('^');
	currentDirection = UP;
	canMove = true;
}

void ChallengeSix::PrintActiveMap()
{
	for (int i = 0; i < activeMap.size(); i++)
	{
		for (int j = 0; j < activeMap[i].size(); j++)
		{
			cout << activeMap[i][j];
		}
		cout << endl;
	}
}