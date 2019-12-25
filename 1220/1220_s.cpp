#include "pch.h"
#include <iostream>
#include <time.h> // 난수 생성 필요

using namespace std;

int main()
{
	//정수 배열 
	int player[3] = { 1,2,3 };
	int str[3] = { 10,20,30 };

	for (int i = 0; i < 3; i++) {
		cout << player[i] << endl;
		cout << str[i] << endl;
	}

	cout << endl;

	//실수 배열 - 역순
	float floatAry[5] = { 1.1,2.1,3.1,4.1,5.1 };

	for (int i = 4; i >= 0; i--) { // -> 4 3 2 1 0
		cout << floatAry[i] << endl; // -> 4 3 2 1 0
	}

	cout << endl;

	/*
	for (int i = 0; i < 5; i++) { -> 0 1 2 3 4
		cout << floatAry[4-i] << endl; -> 4 3 2 1 0
	}

	위 구문이랑 아래 구문은 표현은 다르지만 같은 값을 출력.
	*/

	//반복문 - 심화

	for (int x = 1; x <= 9; x++) { // 아래 구문이 거짓이 될 때(더 이상, 참이 아닐 때)
								   // 변수 값이 상승

		for (int y = 1; y <= 9; y++) {
			cout << x << " * " << y << " = " << x * y << endl;
		}
	}

	//난수 - C Style

	srand(time(NULL)); 

	int randomValue = 0;
	randomValue = rand() % 11 + 1;

	cout << randomValue;


}
