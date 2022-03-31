#pragma once

class Board
{
public:
	virtual void clearBoard();

	virtual void setvalueAtIndex(int, int, char);
	virtual char getvalueAtIndex(int, int);

	virtual char getSimilarPiecesVertically();
	virtual char getSimilarPiecesHorizontally();
	virtual char getSimilarPiecesDiagonally();

	virtual bool isFull();
	virtual bool isEmpty();
};
