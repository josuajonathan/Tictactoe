#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Board3x3.h"
#include "GameManager.h"
using namespace std;

int main()
{
	Board3x3* brd = new Board;
	
	Player playerOne("Player 1", 0, 0); //Membuat Objek bernama Player 1
	Player playerTwo("Player 2", 0, 0);	//Membuat Objek bernama Player 2

	GameManager game(playerOne, playerTwo, 'x', 'o', brd);
	game.play();
}