#include <iostream>
#include <random>

int main()
{
	using namespace std;

	random_device generator;
	mt19937 engine(generator());
	uniform_int_distribution<int> random(1, 3);
	uniform_int_distribution<int> crandom(1, 2);

	int matchCount = 0;
	int player[3] = { 1,2,3 };
	int computer[3] = { 1,2,3 };
	int select, cselect = 0;

	bool isWin = false, firstGame = true; //isWin - 승리 체크, firstGame - 최초 게임 전용 문구 출력 변수
	//1 : 가위
	//2 : 바위
	//3 : 보

	while (isWin == false) { //isWin 값이 true가 될 때까지 반복

		computer[0] = random(engine);
		computer[1] = random(engine);

		if (firstGame == true) {
			firstGame = false;
			cout << "가위바위보 게임에 오신 것을 환영합니다. 무엇을 내시겠습니까?" << endl << endl;
			//cout << "1. 가위, 2. 바위, 3. 보자기 : ";
		}
		else {
			cout << "게임을 계속 진행합니다. 무엇을 내시겠습니까?" << endl << endl;
			//cout << "1. 가위, 2. 바위, 3. 보자기 : ";
		}
		cout << "1. 가위, 2. 바위, 3. 보자기 : ";
		cin >> player[0];

		cout << "다른 손으로는 무엇을 내시겠습니까?" << endl << endl;
		cout << "1. 가위, 2. 바위, 3. 보자기 : ";
		cin >> player[1];

		if (player[0] == 1) {
			cout << "왼손은 가위, ";
		}
		else if (player[0] == 2) {
			cout << "왼손은 바위, ";
		}
		else if (player[0] == 3) {
			cout << "왼손은 보자기, ";
		}
		if (player[1] == 1) {
			cout << "오른손은 가위를 내셨습니다." << endl << endl;
		}
		else if (player[1] == 2) {
			cout << "오른손은 바위를 내셨습니다." << endl << endl;
		}
		else if (player[1] == 3) {
			cout << "오른손은 보자기를 내셨습니다." << endl << endl;
		}

		if (computer[0] == 1) {
			cout << "컴퓨터는 가위와, ";
		}
		else if (computer[0] == 2) {
			cout << "컴퓨터는 바위와, ";
		}
		else if (computer[0] == 3) {
			cout << "컴퓨터는 보자기와, ";
		}
		if (computer[1] == 1) {
			cout << "가위를 냈습니다." << endl << endl;
		}
		else if (computer[1] == 2) {
			cout << "바위를 냈습니다." << endl << endl;
		}
		else if (computer[1] == 3) {
			cout << "보자기를 냈습니다." << endl << endl;
		}

		cout << "왼손과 오른손 중, 남길 손을 선택해주십시오." << endl;
		cout << "1. 왼손, 2. 오른손 : ";

		cin >> select;

			if (select == 1) {
				player[2] = player[0];
			}
			else if (select == 2) {
				player[2] = player[1];
			}
			else {
				cout << "허용하지 않는 값이네요. 게임을 종료합니다.";
				return 0;
			}

		cselect = crandom(engine);

		if (cselect == 1) {
			computer[2] = computer[0];
		}
		else if (cselect == 2) {
			computer[2] = computer[1];
		}

		if (player[2] == 1 && computer[2] == 1) {
			cout << "당신은 가위를 냈고, 컴퓨터는 가위를 냈습니다. - DRAW" << endl << endl;
			matchCount += 1;
		}
		else if (player[2] == 1 && computer[2] == 2) {
			cout << "당신은 가위를 냈고, 컴퓨터는 바위를 냈습니다. - LOSE :(" << endl << endl;
			matchCount += 1;
		}
		else if (player[2] == 1 && computer[2] == 3) {
			cout << "당신은 가위를 냈고, 컴퓨터는 보자기를 냈습니다. - WIN !!" << endl << endl;
			matchCount += 1;
			isWin = true;
		}
		else if (player[2] == 2 && computer[2] == 1) {
			cout << "당신은 바위를 냈고, 컴퓨터는 가위를 냈습니다. - WIN !!" << endl << endl;
			matchCount += 1;
			isWin = true;
		}
		else if (player[2] == 2 && computer[2] == 2) {
			cout << "당신은 바위를 냈고, 컴퓨터는 바위를 냈습니다. - DRAW" << endl << endl;
			matchCount += 1;
		}
		else if (player[2] == 2 && computer[2] == 3) {
			cout << "당신은 바위를 냈고, 컴퓨터는 보자기를 냈습니다. - LOSE :(" << endl << endl;
			matchCount += 1;
		}
		else if (player[2] == 3 && computer[2] == 1) {
			cout << "당신은 보자기를 냈고, 컴퓨터는 가위를 냈습니다. - LOSE :(" << endl << endl;
			matchCount += 1;
		}
		else if (player[2] == 3 && computer[2] == 2) {
			cout << "당신은 보자기를 냈고, 컴퓨터는 바위를 냈습니다. - WIN !!" << endl << endl;
			matchCount += 1;
			isWin = true;
		}
		else if (player[2] == 3 && computer[2] == 3) {
			cout << "당신은 보자기를 냈고, 컴퓨터는 보자기를 냈습니다. - DRAW" << endl << endl;
			matchCount += 1;
		}
		else {
			cout << "허용하지 않는 값이네요. 게임을 종료합니다.";
			return 0;
		}
	}

	cout << matchCount << "번 시도해서 승리하였습니다." << endl;
}