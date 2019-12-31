#pragma once
#include <iostream>

using namespace std;

class Player 
{
public:

	Player();
	~Player();

	const char* getName() { return _name; }
	void setName(const char* name) { _name = name; }

	int getLevel() { return _level; }
	void setLevel(int level) { _level = level; }

	int getHP() { return _hp; }
	void setHP(int hp) { _hp = hp; }

	int getATK() { return _atk; }
	void setATK(int atk) { _atk = atk; }

	int getDEF() { return _def; };
	void setDEF(int def) { _def = def; }

private:

	int _level, _hp, _atk, _def;
	const char* _name;

};