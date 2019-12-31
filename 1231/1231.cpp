#include "mainGame.h"
#include "MonsterBase.h"
#include "Slime.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{

	mainGame* mGame = new mainGame;

	MonsterBase* MBase = new MonsterBase;

	MBase->MonsterInfo();
	mGame->openInformation(); //출력

	delete MBase;

	delete mGame;

	return 0;

}