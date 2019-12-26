#include <iostream>
#include <string> //string 클래스 이용

using namespace std;

//구조체

struct status
{
	//string 클래스
	string nickname;
	int level = 0;
	int hp = 0;
	int atk = 0;
	int def = 0;
};

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
	unsigned int calories;
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
	status playerStat;
	playerStat.level = 1;
	playerStat.hp = 30;

	//2.
	snack snackInfo;
	cin >> snackInfo.price;
	cin >> snackInfo.calories;
	cout << "과자 가격은 " << snackInfo.price << "원 입니다." << endl;
	cout << "과자 칼로리는 " << snackInfo.calories << " kcal 입니다." << endl << endl;

	student studentScore;
	for (int i = 0; i <= 4; i++)
	{
			cin >> studentScore.score[i];
			studentScore.avg = studentScore.score[i] += studentScore.score[i-1];
	}
	//studentScore.avg = (studentScore.score[0] + studentScore.score[1] + studentScore.score[2] + studentScore.score[3] + studentScore.score[4]) / 5;
	cout << fixed;
	cout.precision(2);
	cout << "국어 : " << studentScore.score[0] << ", 영어 : " << studentScore.score[1] << ", 수학 : " << studentScore.score[2] << ", 사회 : " << studentScore.score[3] << ", 과학 : " << studentScore.score[4] << endl << endl;
	cout << "평균 : " << studentScore.avg;




}

