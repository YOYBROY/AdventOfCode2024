#include "ChallengeFour.h"

#include <iostream>
#include <vector>

void ChallengeFour::RunChallengeFour(string fileName, string wordToFind)
{
	/*
	Challenge 4:
	Create a 2D Vector and store every column and row in it

	iterate through the 2D vector and find every "X", then iterate in all directions around it to search for M, if one is found then store the direction and go again etc.

	X=0
	M=1
	A=2
	S=3
	*/

	int numOfRows = fileReader.GetLineCount(fileName);
	int numOfColumns = fileReader.GetColumnCountAt(fileName, 1);

	vector<vector<char>>wordSearch(numOfRows, vector<char>(numOfColumns, 0));

	wordSearch = Populate2DArray(wordSearch, fileName, numOfColumns, numOfRows);

	cout << SearchForWord(wordSearch, wordToFind) << endl;
	system("pause");
	//cout << wordSearch[3][0] << endl;

	//DirectionSearch(wordSearch, 'M', 0, 1, 2, 1);
}

vector<vector<char>> ChallengeFour::Populate2DArray(vector<vector<char>> vecToPopulate, string fileToSourceFrom, int width, int height)
{
	//2Dvectors do height first and then width vector[height][width]
	for (int i = 0; i < height; i++)
	{
		string currentLine = fileReader.GetLineContentsAt(fileToSourceFrom, i + 1);
		for (int j = 0; j < width; j++)
		{
			vecToPopulate[i][j] = currentLine[j];
			cout << vecToPopulate[i][j];
		}
		cout << endl;
	}
	return vecToPopulate;
}

int ChallengeFour::SearchForWord(vector<vector<char>> wordSearch, string wordToSearch) 
{
	//Go through every element to get a positions vector that stores all positions of the letter 'X'
	vector<vector<int>> xPositions;
	
	int count = 0;

	for (int i = 0; i < wordSearch.size(); i++)
	{
		for (int j = 0; j < wordSearch[0].size(); j++)
		{
			if (wordSearch[i][j] == wordToSearch[0])
			{
				count += CircleSearch(wordSearch, wordToSearch, j, i);
			}
		}
	}

	return count;
}

int ChallengeFour::CircleSearch(vector<vector<char>> wordSearch, string wordToSearch, int xPos, int yPos) 
{
	int result = 0;
	//search all 8 positions around the given coordinate and then continue a search in that direction if you hit desired character ("M")
	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			if (x == 0 && y == 0) continue;
			result += DirectionSearch(wordSearch, wordToSearch, 1, xPos, yPos, x, y);
		}
	}
	return result;
}

bool ChallengeFour::DirectionSearch(vector<vector<char>> wordSearch, string wordToSearch, int posInWord, int xPos, int yPos, int xDir, int yDir)
{
	//cout << "xPos: " << xPos << endl;
	//cout << "yPos: " << yPos << endl;
	//cout << "xDir: " << xDir << endl;
	//cout << "yDir: " << yDir << endl;
	//cout << wordSearch[yPos - yDir][xPos - xDir];
	//cout << "newYPos: " << newYPos << endl;
	//cout << "newXPos: " << newXPos << endl;

	//calculate new Coordinate
	int newYPos = yPos - yDir;
	int newXPos = xPos + xDir;

	if (newXPos == 0 && newYPos == 1)
	{
		newXPos = newXPos;
	}

	//Check that direction is valid in vector
	if (newYPos < 0 || newYPos >= wordSearch.size())    { return false; }
	if (newXPos < 0 || newXPos >= wordSearch[0].size()) { return false; }

	if (posInWord < wordToSearch.size())
	{
		//Search in a specific direction for a specific letter
		if (wordSearch[newYPos][newXPos] == wordToSearch[posInWord])
		{
			if (posInWord == wordToSearch.size() - 1) { return true; }
			return DirectionSearch(wordSearch, wordToSearch, posInWord + 1, newXPos, newYPos, xDir, yDir);
		}
	}
	return false;
}
