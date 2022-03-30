#pragma once
#include"Board.h"

class Board3x3:public Board
{
protected:
	char aBoard[3][3];

public:
	Board3x3();
	void clearBoard();
	void print();

	void setvalueAtIndex(int x, int y, char value);
	char getvalueAtIndex(int x, int y);

	char getSimilarPiecesVertically();
	char getSimilarPiecesHorizontally();
	char getSimilarPiecesDiagonally();

	bool isFull();
	bool isEmpty();
};