#include "pch.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
	//C++ 난수 생성

	random_device generator; //하드웨어를 이용한 난수 생성

	uniform_int_distribution<int> random(1, 100); //정수 값을 출력

	mt19937 engine(generator());
	mt19937 no_device_engine((unsigned int)time(NULL)); 

	cout << random(engine) << endl;
	cout << random(no_device_engine) << endl;

	//return 0;

	//Switch 문

	int rank = 1;

	switch (rank)
	{
	case 1:
		cout << "Rank : " << rank << endl;
		rank = 2;
	case 2:
		cout << "Reward!" << endl << endl;
	default: //조건식과 일치하는 case 값이 없으면 default로 점프 
		break;

	}

	//삼항 연산자

	int level = 0;
	int num1 = 100, num2 = 200, result = 0;

	cin >> level;

	level >= 20 ? cout << "100" << endl : cout << "200" << endl;
	result = (num1 < num2) ? num2 : num1;

}


