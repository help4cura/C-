#include <iostream>

using namespace std;

int main()
{
	//문제 1
	int level = 0, difficulty = 0;

	cout << "던전에 입장합니다. 레벨을 입력해주세요." << endl;

	cin >> level;

	if (level < 0) {
		cout << "허용 범위 값이 아님! 게임을 종료합니다." << endl;
	}
	else if (level < 10) {
		cout << "초급던전에 입장합니다." << endl;
	}
	else if (level >= 10 && level < 99) {
		cout << "중급던전에 입장합니다." << endl;
		cout << "몬스터가 공격에 대한 적은 면역을 가집니다." << endl;
		difficulty = 1; //난이도 설정
	}
	else if (level >= 100) {
		cout << "엑스트라 던전에 입장합니다." << endl << endl;
		cout << "몬스터가 공격에 대한 많은 면역을 가집니다." << endl;
		difficulty = 2; //난이도 설정
	}

	//문제 2
	int mobHP = 0, damage = 0, defense = 0, attackType = 0;

	if (difficulty == 1) { 
		defense = 30; //난이도에 따른 공격 면역
	}
	else if (difficulty == 2) {
		defense = 100; //난이도에 따른 공격 면역
	}

	cout << "몬스터의 체력을 설정합니다. 설정할 값을 입력해주세요." << endl << endl;
	cin >> mobHP;
	cout << endl << "몬스터의 체력이 " << mobHP << "(으)로 설정되었습니다." << endl;

	for (int attackCount = 5; attackCount > 0 && attackCount <= 5; attackCount--)
	{
		cout << "기술을 선택해주세요." << endl << "1. 약공격" << endl << "2. 강공격" << endl << "3. 검기발산" << endl << endl;
		cout << "남은 공격 횟수 : " << attackCount << endl << endl;
		cin >> attackType;

		if (attackType == 1 && mobHP > 0) {
			damage = 100;
			if (damage - defense <= 0) {
				damage = 0;
				cout << "몬스터의 공격 면역에 의해 공격이 무효화 되었습니다." << endl << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << endl << endl;
			}
			else {
				mobHP -= damage - defense;
				cout << damage - defense << "만큼 피해를 입혔습니다." << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage - defense << ")" << endl << endl;
			}
		}
		else if (attackType == 2 && mobHP > 0) {
			damage = 200;
			if (damage - defense <= 0) {
				damage = 0;
				cout << "몬스터의 공격 면역에 의해 공격이 무효화 되었습니다." << endl << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << endl << endl;
			}
			else {
				mobHP -= damage - defense;
				cout << damage - defense << "만큼 피해를 입혔습니다." << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage - defense << ")" << endl << endl;
			}
		}
		else if (attackType == 3 && mobHP > 0) {
			damage = 877;
			if (damage - defense <= 0) {
				damage = 0;
				cout << "몬스터의 공격 면역에 의해 공격이 무효화 되었습니다." << endl << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << endl << endl;
			}
			else {
				mobHP -= damage - defense;
				cout << damage - defense << "만큼 피해를 입혔습니다." << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage - defense << ")" << endl << endl;
			}
		}
	}
	
	if (mobHP > 0) {
		cout << "몬스터의 HP가 " << mobHP << "만큼 남아, 패배하였습니다." << endl << endl;
	}
	else {
		cout << "승리하였습니다." << endl << endl;
	}
}