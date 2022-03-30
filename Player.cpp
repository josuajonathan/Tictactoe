#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player()
{
	nama       = ' ';
	jmlhmenang = 0;
	jmlhmatch  = 0;
}

Player::Player(string uname, int menang, int match)
{
	nama       = uname;
	jmlhmenang = menang;
	jmlhmatch  = match;
}

void Player::setnama(string uname)
{
	nama = uname;
}

string Player::getnama()
{
	return nama;
}

void Player::setjmlhmenang(int menang)
{
	jmlhmenang = menang;
}


int Player::getjmlhmenang()
{
	return jmlhmenang;
}

void Player::setjmlhmatch(int match)
{
	jmlhmatch = match;
}

int Player::getjmlhmatch()
{
	return jmlhmatch;
}
