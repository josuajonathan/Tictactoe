#pragma once
#include <string>
using namespace std;

class Player
{
private:
	string nama;
	int jumlahmenang;
	int jumlahmatch;

public :
	Player();
	Player(string uname, int menang, int match);

	void setnama(string uname);
	string getnama();

	void setjumlahmenang(int menang);
	int getjumlahmenang();

	void setjumlahmatch(int match);
	int getjumlahmatch();
};

