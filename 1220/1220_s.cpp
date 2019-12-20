#include "pch.h"
#include <iostream>

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

	/*
	for (int i = 0; i < 5; i++) { -> 0 1 2 3 4
		cout << floatAry[4-i] << endl; -> 4 3 2 1 0
	}

	위 구문이랑 아래 구문은 표현은 다르지만 같은 값을 출력.
	*/
}
