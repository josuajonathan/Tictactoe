#include "GameManager.h"
#include "Board3x3.h"
#include "Player.h"
#include <iostream>
using namespace std;

GameManager::GameManager(Player p1, Player p2, char s1, char s2) {
	this->p1 = p1;
	this->p2 = p2;
	this->s1 = s1;
	this->s2 = s2;
}

void GameManager::init() {
	s1 = 'x';
	s2 = 'o';
	bo->clearBoard();
	p1.setjmlhmatch(p1.getjmlhmatch() + 1);
	p2.setjmlhmatch(p2.getjmlhmatch() + 1);
}

void GameManager::turnPlayer(char sym) {
	int x, y;
	cout << "Insert position (x, y) : ";
	cin >> x >> y;

	if (x > 2 || y > 2) {
		cout << "Error: Invalid square index. Try Again" << endl;
		turnPlayer(sym);
	}

	if (bo->getvalueAtIndex(x, y) == '0')
		bo->setvalueAtIndex(x, y, sym);

	else {
		cout << "Square is filled. Try insert another position." << endl;
		turnPlayer(sym);
	}
}

void GameManager::play()
{
	int step = 0;
	while (!bo->isFull() && checkwin() == 'a')
	{
		step++;
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (bo->getvalueAtIndex(x, y) != '0')
					cout << bo->getvalueAtIndex(x, y) << "\t";

				else
					cout << "_\t";
			}
			cout << endl << endl;
		}

		if (step % 2 == 1) //Giliran Player 1
		{
			cout << p1.getnama() << "'s Turn" << endl;
			turnPlayer(s1);
		}

		else //Giliran Player 2
		{
			cout << p2.getnama() << "'s Turn" << endl;
			turnPlayer(s2);
		}
	}

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (bo->getvalueAtIndex(x, y) != '0')
				cout << bo->getvalueAtIndex(x, y) << "\t";
			else
				cout<<"_\t";
		}
		cout << endl << endl;
	}

	if (checkwin() != 'a')
	{
		if (checkwin() == s1)
		{
			cout << p1.getnama();
			p1.setjmlhmenang(p1.getjmlhmenang() + 1);
		}

		if (checkwin() == s2)
		{
			cout << p1.getnama();
			p2.setjmlhmenang(p2.getjmlhmenang() + 1);
		}
	}

	else
		cout << "PERTANDINGAN SERI" << endl;

	cout << "Statistik Pemain :" << endl;
	cout << "Player 1 \n" << "Username : " << p1.getnama() << "\n" << "Win : " << p1.getjmlhmenang() << "\n" << "Match : " << p1.getjmlhmatch() << endl;
	cout << "Player 2 \n" << "Username : " << p2.getnama() << "\n" << "Win : " << p2.getjmlhmenang() << "\n" << "Match : " << p2.getjmlhmatch() << endl;
}

char GameManager::checkwin()
{
	if (bo->getSimilarPiecesHorizontally() != '0')
		return bo->getSimilarPiecesHorizontally();

	else if (bo->getSimilarPiecesDiagonally() != '0')
		return bo->getSimilarPiecesDiagonally();

	else if (bo->getSimilarPiecesVertically() != '0')
		return bo->getSimilarPiecesVertically();

	else
		return 'a';
}
















/*
GameManager::GameManager(Player p1, Player p2, char s1, char s2, Board *brd)
{
	setPlayer(p1, s2, 0);
	setPlayer(p2, s2, 1);

	setBoard(brd);
}

void GameManager::setPlayer(Player px, char sx, int PNum) {
	players[PNum] = px;
	symbol[PNum] = sx;
}

Player GameManager::getPlayer(int PNum) {
	return players[PNum];
}

char GameManager::getSymbol(int PNum) {
	return symbol[PNum];
}

void GameManager::setBoard(Board* brd) {
	board = brd;
}

Board* GameManager::getBoard() {
	return board;
}

Board* GameManager::displayBoard() {
	board->print();
	return board->print();
}
Board* GameManager::reset() {
	return board->clearBoard();
}
*/

/*
GameManager::GameManager(Board *brd, Player p1, Player p2, char s1, char s2)
{
	this->brd = brd;
	players[0] = p1;
	players[1] = p2
	symbol[0] = s1;
	symbol[1] = s2;
}

void GameManager::setPlayer(Player px, char sx, int PNum)
{
	players[PNum] = px;
	symbol[PNum] = sx;
}

Player GameManager::getPlayer(int PNum) {
	return players[PNum];
}

char GameManager::getSymbol(int PNum) {
	return symbol[PNum];
}

void GameManager::setBoard(Board* brd) {
	this->brd = brd;
}

Board* GameManager::getBoard() {
	return brd;
}


void GameManager::DisplayBoard() {
	brd->print();
}


void GameManager::reset() {
	brd->clearBoard();
}


char GameManager::checkWin() {
	if (brd->getSimilarPiecesHorizontally() != '0')
		return brd->getSimilarPiecesHorizontally();

	else if (brd->getSimilarPiecesVertically() != '0')
		return brd->getSimilarPiecesVertically();

	else if (brd->getSimilarPiecesDiagonally() != '0')
		return brd->getSimilarPiecesDiagonally();

	else
		return 'f';
}

Player GameManager::getWinner() {
	for (int i = 0; i < 2; i++) {
		if (isWin(i) == true)
			return getPlayer(i);
	}
}

void GameManager::AnnounceWinner() {
	cout << "Selamat " << getWinner().getnama() << "Kamu Menang!" << endl;
}

void GameManager::turnPlayer(char symbol) {
	int x, y;
	cout << players[PNum].getnama() << "Input Koordinat (x y): " << endl;
	cin >> x >> y;

	if (x > 2 || y > 2) {
		cout << "Invalid square Index, Try Again";
		turnPlayer(symbol);
	}

	if (board->getvalueAtIndex(x, y) == '0')
	{
		board->setvalueAtIndex(x, y, symbol);
	}

	else {
		cout << "Squere is filled. Please insert another position." << endl;
		turnPlayer(symbol);
	}
}

void GameManager::Play() {
	int step = 0;
	while (!board->isFull()) {
		step++;
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++)
			{
				if (board->getvalueAtIndex(x, y) != '0')
					cout << board->getvalueAtIndex(x, y) << "\t";
				else
					cout << "-\t";
			}
		}
	}
}
*/