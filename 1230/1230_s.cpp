#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//포인터 - 주소 연산자(&)

	int a;
	double b;
	string c;

	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl << endl;

	//포인터 - 간접참조 연산자(*)

	int *pa;

	pa = &a;
	*pa = 10;

	printf("%d\n", *pa);
	printf("%d", a);
	
	return 0;
}
