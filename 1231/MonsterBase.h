#pragma once
#include <iostream>
#include <string>

using namespace std;

class MonsterBase
{
public :

	MonsterBase();
	~MonsterBase();

	void MonsterInfo();

	string getName() { return _name; }
	void setName(string name) { _name = name; }

	int getLevel() { return _level; }
	void setLevel(int level) {_level = level; }

	int getHP() { return _hp; }
	void setHP(int hp) { _hp = hp; }

	int getATK() { return _atk; }
	void setATK(int atk) { _atk = atk; }

	int getDEF() { return _def; };
	void setDEF(int def) { _def = def; }

private :

	int _hp = 0, _level = 0, _atk = 0, _def = 0;
	string _name;

};