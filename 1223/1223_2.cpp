#include <iostream>
#include <random>

int main()

{
    using namespace std;

    int yourNumber[6];
    int rotto[6];
    int tmp = 0, count = 0;

    random_device generator;
    mt19937 engine(generator());
    uniform_int_distribution<int> random (1, 45);

    for (int i = 0; i < 6; i++) 
    {
        rotto[i] = random(engine);
        for (int j = 0; j < i; j++)
        {
            if (rotto[i] == rotto[j]) {
                i--;
                break;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        cin >> yourNumber[i];
        if (yourNumber[count] > 45) {
            cout << "45보다는 작은 수를 입력해주세요." << endl;
            i--;
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (rotto[i] == yourNumber[j]) {
                count += 1;
            }
        }
    }
    
    cout << "로또 번호 : " << rotto[0] << ", " << rotto[1] << ", " << rotto[2] << ", " << rotto[3] << ", " << rotto[4] << ", " << rotto[5] << endl;
    cout << "당신이 고른 번호 : " << yourNumber[0] << ", " << yourNumber[1] << ", " << yourNumber[2] << ", " << yourNumber[3] << ", " << yourNumber[4] << ", " << yourNumber[5] << endl << endl;

    cout << "맞추신 번호는 총 " << count << "개 입니다." << endl;

    switch (count)
    {
    case 3:
        cout << "축하합니다! 4등입니다.";
        break;
    case 4:
        cout << "축하합니다! 3등입니다.";
        break;
    case 5:
        cout << "축하합니다! 2등입니다.";
        break;
    case 6:
        cout << "축하합니다! 1등입니다.";
        break;
    default:
        cout << "아쉽지만, 등수 내에 들지 못했습니다."  << endl;
        break;
    }
}

