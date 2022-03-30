#pragma once
#include <string>
using namespace std;

class Player
{
private:
	string nama;
	int jmlhmenang;
	int jmlhmatch;

public:
	Player();
	Player(string uname, int menang, int match);

	void setnama(string uname);
	string getnama();

	void setjmlhmenang(int menang);
	int getjmlhmenang();

	void setjmlhmatch(int match);
	int getjmlhmatch();
};

