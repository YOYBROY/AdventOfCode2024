#include "ChallengeFour.h"

#include <iostream>
#include <vector>

vector<vector<int>> testingVector;

void ChallengeFour::RunChallengeFour(string fileName, string wordToFind, bool part1)
{
	/*
	Challenge 4:
	Create a 2D Vector and store every column and row in it

	iterate through the 2D vector and find every "X",
	then iterate in all directions around it to search for M,
	if one is found then search again in the same direction
	*/

	//Initialize word searcg input into a 2D vector
	vector<vector<char>> wordSearch = Create2DSearchArray(fileName);

	//Find number of times word exists in wordSearch
	cout << SearchForWord(wordSearch, wordToFind, part1) << endl;
}

//Adds all elements of a 2D array into one given a specific string
vector<vector<char>> ChallengeFour::Create2DSearchArray(string sourceFile)
{
	//Get width and height of the input file
	int height = fileReader.GetLineCount(sourceFile);
	int width = fileReader.GetColumnCountAt(sourceFile, 1);

	//create 2D vector with specified width and height
	vector<vector<char>>myVector(height, vector<char>(width, 0));

	//2Dvectors do height first and then width vector[height][width]
	for (int i = 0; i < height; i++)
	{
		string currentLine = fileReader.GetLineContentsAt(sourceFile, i + 1);
		for (int j = 0; j < width; j++)
		{
			myVector[i][j] = currentLine[j];
			// cout << myVector[i][j];
		}
		// cout << endl;
	}
	return myVector;
}

//Begin searching by finding all starting letters and checking the rest of the word
int ChallengeFour::SearchForWord(vector<vector<char>> wordSearch, string wordToSearch, bool part1)
{
	int count = 0;
	for (int i = 0; i < wordSearch.size(); i++)
	{
		for (int j = 0; j < wordSearch[0].size(); j++)
		{
			//Searches for a word in the word search if true, if else then search for X formation of a word
			if (wordSearch[i][j] == wordToSearch[1 - part1] && part1) count += CircleSearch(wordSearch, wordToSearch, j, i);
			else if (wordSearch[i][j] == wordToSearch[1] && !part1) count += XSearch(wordSearch, wordToSearch, j, i);
		}
	}
	return count;
}

//search all 8 positions around the given coordinate and then continue a search in that direction if you hit desired character ("M")
int ChallengeFour::CircleSearch(vector<vector<char>> wordSearch, string wordToSearch, int xPos, int yPos)
{
	int result = 0;
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

//searches for x formation around a given letter
bool ChallengeFour::XSearch(vector<vector<char>> wordSearch, string wordToSearch, int xPos, int yPos)
{
	//Cull the edges off the search
	if (yPos == 0 || yPos == wordSearch.size() - 1) return false;
	if (xPos == 0 || xPos == wordSearch[0].size() - 1) return false;

	int result = 0;
	int stopCount = 0;

	//search top left and top right
	for (int y = -1; y <= 1; y++)
	{
		if (y == 0) continue;
		//if the letter found is equal to the firt or last letters of the searching word
		char foundChar = ReturnCharAtPos(wordSearch, xPos, yPos, -1, y);
		if (foundChar == wordToSearch[0])
		{
			//check opposite side
			int reverseY = y * -1;
			char otherFoundChar = ReturnCharAtPos(wordSearch, xPos, yPos, 1, reverseY);
			if (otherFoundChar == wordToSearch[2]) result++;
			stopCount++;
		}
		else if (foundChar == wordToSearch[2])
		{
			//check opposite side
			int reverseY = y * -1;
			char otherFoundChar = ReturnCharAtPos(wordSearch, xPos, yPos, 1, reverseY);
			if (otherFoundChar == wordToSearch[0]) result++;
			stopCount++;
		}
		else return false;
	}
	if (result == 2) return true;
	else return false;
}

bool ChallengeFour::DirectionSearch(vector<vector<char>> wordSearch, string wordToSearch, int posInWord, int xPos, int yPos, int xDir, int yDir)
{
	//calculate new Coordinate
	int newYPos = yPos - yDir;
	int newXPos = xPos + xDir;

	//Check that direction is valid in vector
	if (newYPos < 0 || newYPos >= wordSearch.size()) { return false; }
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

char ChallengeFour::ReturnCharAtPos(vector<vector<char>> wordSearch, int xPos, int yPos, int xDir, int yDir)
{
	//calculate new Coordinate
	int newYPos = yPos - yDir;
	int newXPos = xPos + xDir;

	//Check that direction is valid in vector
	if (newYPos < 0 || newYPos >= wordSearch.size()) { return false; }
	if (newXPos < 0 || newXPos >= wordSearch[0].size()) { return false; }

	//Search in a specific direction for a specific letter
	return wordSearch[newYPos][newXPos];
}