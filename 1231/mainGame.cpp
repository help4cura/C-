#include "mainGame.h"

mainGame::mainGame()
{
	_slime = new Slime;
	_zombie = new Zombie;
	_yeti = new Yeti;
	_degos = new Degos;
	_veska = new Veska;

	_player = new Player;

	cout << "�÷��̾��� �̸��� �������ּ���." << endl;
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
	cout << _slime->getName() << "�� ����" << endl;
	cout << "���� : " << _slime->getLevel() << endl << "ü�� : " << _slime->getHP() << endl << "���ݷ� : " << _slime->getATK() << endl << "���� : " << _slime->getDEF() << endl;
}

void mainGame::zombie()
{
	cout << _zombie->getName() << "�� ����" << endl;
	cout << "���� : " << _zombie->getLevel() << endl << "ü�� : " << _zombie->getHP() << endl << "���ݷ� : " << _zombie->getATK() << endl << "���� : " << _zombie->getDEF() << endl;
}

void mainGame::yeti()
{
	cout << _yeti->getName() << "�� ����" << endl;
	cout << "���� : " << _yeti->getLevel() << endl << "ü�� : " << _yeti->getHP() << endl << "���ݷ� : " << _yeti->getATK() << endl << "���� : " << _yeti->getDEF() << endl;
}

void mainGame::degos()
{
	cout << _degos->getName() << "�� ����" << endl;
	cout << "���� : " << _degos->getLevel() << endl << "ü�� : " << _degos->getHP() << endl << "���ݷ� : " << _degos->getATK() << endl << "���� : " << _degos->getDEF() << endl;
}

void mainGame::veska()
{
	cout << _veska->getName() << "�� ����" << endl;
	cout << "���� : " << _veska->getLevel() << endl << "ü�� : " << _veska->getHP() << endl << "���ݷ� : " << _veska->getATK() << endl << "���� : " << _veska->getDEF() << endl;
}

void mainGame::player()
{
	cout << _player->getName() << "�� ����" << endl;
	cout << "���� : " << _player->getLevel() << endl << "ü�� : " << _player->getHP() << endl << "���ݷ� : " << _player->getATK() << endl << "���� : " << _player->getDEF() << endl;
}
