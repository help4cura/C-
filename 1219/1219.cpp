// 1219.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
	//문제 1
	int level = 0;

	cin >> level;

	if (level < 0) {
		cout << "허용 범위 값이 아님! 게임을 종료합니다." << endl;
	}
	else if (level < 10) {
		cout << "초급던전 입장." << endl;
	}
	else if (level >= 10 && level < 99) {
		cout << "중급던전 입장." << endl;
	}
	else if (level >= 100) {
		cout << "엑스트라 던전 입장." << endl << endl;
	}

	//문제 2
	int mobHP = 0, attackType = 0, damage = 0;

	cout << "몬스터의 체력을 설정합니다. 설정할 값을 입력해주세요." << endl;
	cin >> mobHP;
	cout << "몬스터의 체력이 " << mobHP << "로 설정되었습니다." << endl;

	cout << "기술을 선택해주세요." << endl << "1. 약공격" << endl << "2. 강공격" << endl << "3. 검기발산" << endl << endl;
	cin >> attackType;

	for (int attackCount = 5; attackCount > 0 && attackCount <= 5; attackCount--) 
		if (attackType == 1 && mobHP > 0) {
			damage = 100;
			mobHP -= damage;
			cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage << ")" << endl;
		}
		else if (attackType == 2 && mobHP > 0) {
			damage = 200;
			mobHP -= damage;
			cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage << ")" << endl;
		}
		else if (attackType == 3 && mobHP > 0) {
			damage = 300;
			mobHP -= damage;
			cout << "몬스터의 남은 체력 : " << mobHP << "(-" << damage << ")" << endl;
		}
	
	if (mobHP > 0) {
		cout << "몬스터의 HP가 " << mobHP << "만큼 남아, 패배하였습니다.";
	}
	else {
		cout << "승리하였습니다.";
	}
}