#include "pch.h"
#include <iostream>

using namespace std;

int main()
{	
	//문제 1
	float height = 179.5, weight = 75.0;

	if (height >= 187.5 && weight >= 80.0)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "Cancel" << endl << endl;
	}
	
	//문제 2
	int sum = 259, average = sum / 3;

	if (sum >= 259 && average >= 90) // 90 이상
	{
		cout << "A" << endl;
	}
	else if (sum >= 259 && average >= 80) // 80 이상 
	{
		cout << "B" << endl;
	}
	else if (sum >= 259 && average >= 70) // 70 이상
	{
		cout << "C" << endl;
	}
	else
	{
		cout << "F" << endl;
	}

	// hp 60 이하 경고 
	//	  30 이하 위험
	//	   0 이하 사망

	/*int hp = 0;

	if (hp <= 60 && hp >= 31) {
		cout << "경고" << endl;
	}
	else if (hp <= 30 && hp >= 1) {
		cout << "위험" << endl;
	}
	else {
		cout << "사망" << endl;
	}*/

	//반복문 - while
	int w = 0;
	while (w < 5) {
		w++;
		cout << "Be Happy!" << endl;
	}
	
	//반목문 - for
	for (int star = 1; star <= 15; star++)
	{
		cout << "*";
		if (star % 5 == 0) {
			cout << endl;
		}
	}
}
