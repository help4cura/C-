#pragma once
#include "gameNode.h"

#define BOX_MAX 80
#define SPEED_MIN 5.0f
#define SPEED_MAX 20.0f

struct TagBox
{
	RECT rc; //렉트
	//bool isMole;	//이놈이 두더지냐
	//bool isDead;	//죽었나 안 죽었나
	bool isGameOver = false; //게임오버 판단
	int MutantChance; // 돌연변이 확률
};

class mainGame : public gameNode
{
private:
	//두더지 구조체 선언
	TagBox _monster[BOX_MAX];
	TagBox Player;

	//선택된 두더지
	//int _select[2];

	//딜레이를 주기 위한 카운터
	int _count;
	int score = 0;
	CHAR str[128];
	int r[BOX_MAX], g[BOX_MAX], b[BOX_MAX];

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