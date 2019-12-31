#include "mainGame.h"

mainGame::mainGame()
{
	_slime = new Slime;
	_zombie = new Zombie;
	_yeti = new Yeti;
	_degos = new Degos;
	_veska = new Veska;

	_player = new Player;

	cout << "플레이어의 이름을 설정해주세요." << endl;
	cout << "->";

	char* name = new char;

	cin >> name;
	cout << endl;

	_player->setName(name);
}

mainGame::~mainGame()
{
	delete _slime;
	delete _zombie;
	delete _yeti;
	delete _degos;
	delete _veska;

	delete _player;
}

void mainGame::openInformation()
{
	cin >> select;
	cout << endl;

	switch (select)
	{
	case 1:
		slime();
		break;
	case 2:
		zombie();
		break;
	case 3:
		yeti();
		break;
	case 4:
		degos();
		break;
	case 5:
		veska();
		break;
	case 6:
		player();
		break;
	default:
		break;
	}
}

void mainGame::slime()
{
	cout << _slime->getName() << "의 정보" << endl;
	cout << "레벨 : " << _slime->getLevel() << endl << "체력 : " << _slime->getHP() << endl << "공격력 : " << _slime->getATK() << endl << "방어력 : " << _slime->getDEF() << endl;
}

void mainGame::zombie()
{
	cout << _zombie->getName() << "의 정보" << endl;
	cout << "레벨 : " << _zombie->getLevel() << endl << "체력 : " << _zombie->getHP() << endl << "공격력 : " << _zombie->getATK() << endl << "방어력 : " << _zombie->getDEF() << endl;
}

void mainGame::yeti()
{
	cout << _yeti->getName() << "의 정보" << endl;
	cout << "레벨 : " << _yeti->getLevel() << endl << "체력 : " << _yeti->getHP() << endl << "공격력 : " << _yeti->getATK() << endl << "방어력 : " << _yeti->getDEF() << endl;
}

void mainGame::degos()
{
	cout << _degos->getName() << "의 정보" << endl;
	cout << "레벨 : " << _degos->getLevel() << endl << "체력 : " << _degos->getHP() << endl << "공격력 : " << _degos->getATK() << endl << "방어력 : " << _degos->getDEF() << endl;
}

void mainGame::veska()
{
	cout << _veska->getName() << "의 정보" << endl;
	cout << "레벨 : " << _veska->getLevel() << endl << "체력 : " << _veska->getHP() << endl << "공격력 : " << _veska->getATK() << endl << "방어력 : " << _veska->getDEF() << endl;
}

void mainGame::player()
{
	cout << _player->getName() << "의 정보" << endl;
	cout << "레벨 : " << _player->getLevel() << endl << "체력 : " << _player->getHP() << endl << "공격력 : " << _player->getATK() << endl << "방어력 : " << _player->getDEF() << endl;
}
