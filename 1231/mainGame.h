#pragma once
#include <iostream>

#include "Slime.h"
#include "Zombie.h"
#include "Yeti.h"
#include "Degos.h"
#include "Veska.h"

#include "Player.h"

using namespace std;

class mainGame
{
public: 

	mainGame();
	~mainGame();

	int select;
	void openInformation();
	void slime(), zombie(), yeti(), degos(), veska(), player();
	
private: 

	Slime* _slime;
	Zombie* _zombie;
	Yeti* _yeti;
	Degos* _degos;
	Veska* _veska;

	Player* _player;

protected: 

};
