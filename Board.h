#pragma once

class Board
{
public:
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
