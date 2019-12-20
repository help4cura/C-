#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//문제 1
	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			cout << x << " * " << y << " = " << x * y << endl;
		}
	}

	cout << endl;

	//문제 2

	srand(time(NULL));

	int player = 0, computer = 0, matchCount = 0;
	bool isWin = false; //승리 체크 변수
	//1 : 가위
	//2 : 바위
	//3 : 보

	while (isWin == false) { //isWin 값이 true가 될 때까지 반복

		computer = rand() % 3 + 1;

		cout << "가위바위보 게임에 오신 것을 환영합니다. 무엇을 내시겠습니까?" << endl << endl;
		cout << "1. 가위, 2. 바위, 3. 보자기 : ";

		cin >> player;

		if (player == 1 && computer == 1) {
			cout << "당신은 가위를 냈고, 컴퓨터는 가위를 냈습니다. - DRAW" << endl << endl;
			matchCount += 1; 
		}
		else if (player == 1 && computer == 2) {
			cout << "당신은 가위를 냈고, 컴퓨터는 바위를 냈습니다. - LOSE :(" << endl << endl;
			matchCount += 1;
		}
		else if (player == 1 && computer == 3) {
			cout << "당신은 가위를 냈고, 컴퓨터는 보자기를 냈습니다. - WIN !!" << endl << endl;
			matchCount += 1;
			isWin = true;
		}
		else if (player == 2 && computer == 1) {
			cout << "당신은 바위를 냈고, 컴퓨터는 가위를 냈습니다. - WIN !!" << endl << endl;
			matchCount += 1;
			isWin = true;
		}
		else if (player == 2 && computer == 2) {
			cout << "당신은 바위를 냈고, 컴퓨터는 바위를 냈습니다. - DRAW" << endl << endl;
			matchCount += 1;
		}
		else if (player == 2 && computer == 3) {
			cout << "당신은 바위를 냈고, 컴퓨터는 보자기를 냈습니다. - LOSE :(" << endl << endl;
			matchCount += 1;
		}
		else if (player == 3 && computer == 1) {
			cout << "당신은 보자기를 냈고, 컴퓨터는 가위를 냈습니다. - LOSE :(" << endl << endl;
			matchCount += 1;
		}
		else if (player == 3 && computer == 2) {
			cout << "당신은 보자기를 냈고, 컴퓨터는 바위를 냈습니다. - WIN !!" << endl << endl;
			matchCount += 1;
			isWin = true;
		}
		else if (player == 3 && computer == 3) {
			cout << "당신은 보자기를 냈고, 컴퓨터는 보자기를 냈습니다. - DRAW" << endl << endl;
			matchCount += 1;
		}
		else {
			cout << "허용하지 않는 값이네요. 게임을 종료합니다.";
			return 0;
		}
	}

	cout << matchCount << "번 시도해서 승리하였습니다." << endl << endl;

	//문제 3
	int level = 0, difficulty = 0;

	cout << "던전에 입장합니다. 레벨을 입력해주세요. : ";

	cin >> level;

	if (level < 0) {
		cout << "허용 범위 값이 아님! 게임을 종료합니다." << endl;
		return 0;
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

	int mobHP = 0, damage = 0, minDamage = 0, maxDamage = 0, defense = 0, attackType = 0;

	if (difficulty == 1) {
		defense = 30; //난이도에 따른 공격 면역
	}
	else if (difficulty == 2) {
		defense = 100; //난이도에 따른 공격 면역
	}

	cout << "몬스터의 체력을 설정합니다. 설정할 값을 입력해주세요. : ";
	cin >> mobHP;
	cout << endl;
	cout << "몬스터의 체력이 " << mobHP << "(으)로 설정되었습니다." << endl << endl;

	for (int attackCount = 5; attackCount > 0 && attackCount <= 5; attackCount--)
	{
		if (mobHP <= 0) {
			break;
		}

		cout << "남은 공격 횟수 : " << attackCount << endl;

		cout << endl << "1. 약공격" << endl << "2. 강공격" << endl << "3. 루드 버스터" << endl << endl;
		cout << "기술을 선택해주세요. : ";
		cin >> attackType;
		cout << endl;

		if (attackType == 1)
		{
			minDamage = 50;
			maxDamage = 200;
			damage = rand() % (maxDamage - minDamage + 1) + minDamage;
			if (damage - defense <= 0) {
				cout << "몬스터의 공격 면역에 의해 공격이 무효화 되었습니다." << endl << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << endl << endl;
			}
			else {
				mobHP -= damage - defense;
				cout << "True Damage : " << damage << endl;
				cout << damage - defense << "만큼 피해를 입혔습니다." << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage - defense << ")" << endl << endl;
			}
		}
		else if (attackType == 2) {
			minDamage = 80;
			maxDamage = 300;
			damage = rand() % (maxDamage - minDamage + 1) + minDamage;
			if (damage - defense <= 0) {
				cout << "몬스터의 공격 면역에 의해 공격이 무효화 되었습니다." << endl << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << endl << endl;
			}
			else {
				mobHP -= damage - defense;
				cout << "True Damage : " << damage << endl;
				cout << damage - defense << "만큼 피해를 입혔습니다." << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage - defense << ")" << endl << endl;
			}
		}
		else if (attackType == 3) {
			minDamage = 250;
			maxDamage = 800;
			damage = rand() % (maxDamage - minDamage + 1) + minDamage;
			if (damage - defense <= 0) {
				cout << "몬스터의 공격 면역에 의해 공격이 무효화 되었습니다." << endl << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << endl << endl;
			}
			else {
				mobHP -= damage - defense;
				cout << "True Damage : " << damage << endl;
				cout << damage - defense << "만큼 피해를 입혔습니다." << endl;
				cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage - defense << ")" << endl << endl;
			}
		}
	}

	if (mobHP > 0) {
		cout << "몬스터의 체력이 " << mobHP << "만큼 남아, 패배하였습니다." << endl;
	}
	else if (mobHP <= 0) {
		cout << "몬스터가 처치되어, 승리하였습니다." << endl;
	}
}