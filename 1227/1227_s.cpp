#include "pch.h"
#include <iostream>

//함수

using namespace std;

int sum(int a, int b)
{
	int result;
	result = a + b;

	return result;
}

int sub(int a, int b)
{
	int result;
	result = a - b;

	return result;
}

int multi(int a, int b)
{
	int result;
	result = a * b;

	return result;
}

int divi(int a, int b) 
{
	int result;
	result = a / b;
	
	return result;
}

int main()
{
	//셔플 알고리즘

	int a = 0, b = 0;
	cin >> a;
	cin >> b;

	cout << a << " + " << b << " = " << sum(a, b) << endl;
	cout << a << " - " << b << " = " << sub(a, b) << endl;
	cout << a << " x " << b << " = " << multi(a, b) << endl;
	cout << a << " ÷ " << b << " = " << divi(a, b) << endl;

	//난수 초기화
	srand(time(NULL));

	int number[10];				//배열 선언
	int temp, index1, index2;	//셔플에 필요한 변수

	//배열 초기화
	for (int i = 0; i < 10; i++)
	{
		number[i] = i;
	}

	//몇 번 섞을 것인가? (100번)
	for (int i = 0; i < 100; i++)
	{
		index1 = rand() % 10;
		index2 = rand() % 10;

		temp = number[index1];				//임시저장소 = number[7]
		number[index1] = number[index2];	//number[7] = number[9]
		number[index2] = temp;				//number[9] = 임시저장소
	}

	//결과 출력
	for (int i = 0; i < 10; i++)
	{
		cout << number[i] << endl;
	}
}

