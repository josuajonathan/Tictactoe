#pragma once
#include "Board3x3.h"
#include "Player.h"
using namespace std;

class GameManager
{
private:
	Player players[2];
	char symbol[2];
	Board3x3* board;

public:
	GameManager(Player plyr1, Player plyr2, char sym1, char sym2, Board3x3* brd);
	
	void setPlayer(Player plyrx, char symx, int PlayerNum);
	Player getPlayer(int PlayerNum);
	char getSymbol(int PlayerNum);

	void setBoard(Board3x3* brd);
	Board3x3* getBoard();

	void DisplayBoard();
	void TurnPlayer(int PlayerNum);

	bool isWin(int PlayerNum);
	Player getWinner();
	void AnnounceWinner();
	void NotifyPlayer();

	void play();
	void reset();
	void init();
};

