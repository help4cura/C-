#include <iostream>
#include <string> //string 클래스 이용

using namespace std;

//1.
struct book
{
	string title;
	string author;
	unsigned int page;
	unsigned int price;
};

//2.
struct snack {
	unsigned int price;
	float calories;
};

//3.
struct student {
	int number;
	string name;
	int score[5];
	float avg;
};

int main()
{
	//2.
	snack snackInfo;
	cin >> snackInfo.price;
	cin >> snackInfo.calories;
	cout << endl;
	cout << "과자 가격은 " << snackInfo.price << "원입니다." << endl;
	cout << "과자 칼로리는 " << snackInfo.calories << "kcal입니다." << endl << endl;

	//3.
	student studentScore;
	int sum = 0;

	for (int i = 0; i <= 4; i++)
	{
		cin >> studentScore.score[i];
		sum += studentScore.score[i];
	}

	studentScore.avg = (float) sum / 5;

	cout << fixed;
	cout.precision(2);
	cout << endl;

	cout << "국어 : " << studentScore.score[0] << ", 영어 : " << studentScore.score[1] << ", 수학 : " << studentScore.score[2] << ", 사회 : " << studentScore.score[3] << ", 과학 : " << studentScore.score[4] << endl << endl;
	cout << "평균 : " << studentScore.avg;
}
