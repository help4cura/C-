#pragma once
#include "gameNode.h"

#define BOX_MAX 80
#define SPEED_MIN 5.0f
#define SPEED_MAX 20.0f

struct TagBox
{
	RECT rc; //��Ʈ
	//bool isMole;	//�̳��� �δ�����
	//bool isDead;	//�׾��� �� �׾���
	bool isGameOver = false; //���ӿ��� �Ǵ�
	int MutantChance; // �������� Ȯ��
};

class mainGame : public gameNode
{
private:
	//�δ��� ����ü ����
	TagBox _monster[BOX_MAX];
	TagBox Player;

	//���õ� �δ���
	//int _select[2];

	//�����̸� �ֱ� ���� ī����
	int _count;
	int score = 0;
	CHAR str[128];
	int r[BOX_MAX], g[BOX_MAX], b[BOX_MAX];

	//���ǵ�
	float SetSpeed[BOX_MAX];

public:
	
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	mainGame() {}
	~mainGame() {}
};