#include "Board3x3.h"

Board3x3::Board3x3() 
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			aBoard[i][j] = '0';
		}
	}
}

void Board3x3::clearBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			aBoard[i][j] = ' ';
		}
	}
}

bool Board3x3::isFull() 
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (aBoard[i][j] == '0')
				return false;
		}
	}
	return true;
}

bool Board3x3::isEmpty() 
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (aBoard[i][j] != '0')
				return false;
		}
	}
	return true;
}

char Board3x3::getvalueAtIndex(int x, int y)
{
	return aBoard[x][y];
}

void Board3x3::setvalueAtIndex(int x, int y, char value)
{
	aBoard[x][y] = value;
}

char Board3x3::getSimilarPiecesHorizontally()
{
	for (int i = 0; i < 3; i++) {
		if (aBoard[i][0] != '0' && aBoard[i][0] == aBoard[i][1] && aBoard[i][0] == aBoard[i][2])
			return aBoard[i][0];
	}

	return '0';
}

char Board3x3::getSimilarPiecesVertically()
{
	for (int i = 0; i < 3; i++) {
		if (aBoard[0][i] != '0' && aBoard[0][i] == aBoard[1][i] && aBoard[0][i] == aBoard[2][i])
			return aBoard[0][i];
	}

	return '0';
}

char Board3x3::getSimilarPiecesDiagonally()
{
	if (aBoard[0][0] != '0' && aBoard[0][0] == aBoard[1][1] && aBoard[0][0] == aBoard[2][2]) 
	{
		return aBoard[0][0];
	}

	else if (aBoard[0][2] != '0' && aBoard[0][2] == aBoard[1][1] && aBoard[2][0] == aBoard[0][2])
	{
		return aBoard[0][2];
	}

	else {
		return 0;
	}
}