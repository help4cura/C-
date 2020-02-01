#pragma once
#include "gameNode.h"

#define BOX_MAX 80
#define SPEED_MIN 5.0f
#define SPEED_MAX 20.0f

struct TagBox
{
	RECT rc; //RECT
	bool isGameOver = false; //게임오버 판단
	int MutantChance; // 돌연변이 확률
};

class mainGame : public gameNode
{
private:
	//두더지 구조체 선언
	TagBox _monster[BOX_MAX];
	TagBox Player;

	//딜레이를 주기 위한 카운터
	int _count;
	//점수
	int score = 0;
	//메시지용 저장 변수
	CHAR str[128];

	//스피드
	float SetSpeed[BOX_MAX];

public:	
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	mainGame() {}
	~mainGame() {}
};
