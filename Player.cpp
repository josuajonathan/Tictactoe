#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player()
{
	nama           = ' ';
	jumlahmenang   = 0;
	jumlahmatch    = 0;
}

Player::Player(string uname, int menang, int match)
{
	nama         = uname;
	jumlahmenang = menang;
	jumlahmatch  = match;
}

void Player::setnama(string nama) {
	this->nama = nama;
}

string Player::getnama() {
	return nama;
}

void Player::setjumlahmenang(int jumlahmenang) {
	this->jumlahmenang = jumlahmenang;
}

int Player::getjumlahmenang() {
	return jumlahmenang;
}

void Player::setjumlahmatch(int jumlahmatch) {
	this->jumlahmatch = jumlahmatch;
}

int Player::getjumlahmatch() {
	return jumlahmatch;
}