#include <iostream>
#include <windows.h>

using namespace std;

float average(float a, float b) 
{
    float res;
    res = a / b;

    return res;
}

int main()
{
    float a, b;
    cin >> a;
    cin >> b;
    
    cout << fixed;
    cout.precision(3);

    cout << a << " / " << b << " = " << average(a,b) << endl << endl;

    Sleep(1000);
    cout << "1" << endl;
    Sleep(1000);
    cout << "2" << endl;
    Sleep(1000);
    cout << "3" << endl;
    Sleep(1000);
    cout << "4" << endl;
    Sleep(1000);
    cout << "5";

    system("cls");

    return 0;
}