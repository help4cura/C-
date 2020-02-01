#include "setDefine.h"
#include "mainGame.h"

//초기화 = WM_CREATE
HRESULT mainGame::init()
{
	gameNode::init();

	//두더지 만들기
	for (int i = 0; i < BOX_MAX; i++)
	{
		//돌연변이
		_monster[i].MutantChance = RND->getFromIntTo(1, 777);

		if (_monster[i].MutantChance == 1)
		{
			_monster[i].rc = RectMake
			(
				RND->getFromIntTo(10, WINSIZE_X),
				RND->getFromIntTo(-500, 30),
				RND->getFromIntTo(300, 500),
				RND->getFromIntTo(100, 300)
			);
		}
		else {
		_monster[i].rc = RectMake
		(
			RND->getFromIntTo(10, WINSIZE_X),
			RND->getFromIntTo(-500, 30),
			RND->getFromIntTo(10, 20),
			RND->getFromIntTo(10, 30)
		);
		}
	}

	Player.rc = RectMake
	(
		WINSIZE_X / 2, // 400
		740,
		15,
		15
	);

	for (int i = 0; i < BOX_MAX; i++) 
	{
		SetSpeed[i] = RND->getFromIntTo(SPEED_MIN, SPEED_MAX);
	}
	
	return S_OK;
}

//메모리에서 해제
void mainGame::release()
{
	gameNode::release();
}

//실시간 갱신
void mainGame::update()
{
	gameNode::update();

	if (Player.isGameOver == true) {
		
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			Player.isGameOver = false;
			for (int i = 0; i < BOX_MAX; i++)
			{
				if (_monster[i].MutantChance == 1)
				{
					_monster[i].rc = RectMake
					(
						RND->getFromIntTo(10, WINSIZE_X),
						RND->getFromIntTo(-500, 30),
						RND->getFromIntTo(300, 500),
						RND->getFromIntTo(100, 300)
					);
				}
				else {
					_monster[i].rc = RectMake
					(
						RND->getFromIntTo(10, WINSIZE_X),
						RND->getFromIntTo(-500, 30),
						RND->getFromIntTo(10, 20),
						RND->getFromIntTo(10, 30)
					);
				}
			}
			score = 0;
			return;
		}
	}

	_count++;

	if (_count % 2 == 0)
	{
		for (int i = 0; i < BOX_MAX; i++)
		{
			if (Player.rc.left+5 < _monster[i].rc.right &&
				Player.rc.top-5 < _monster[i].rc.bottom &&
				Player.rc.right-5 > _monster[i].rc.left)
			{
					Player.isGameOver = true;
			}

			if (_monster[i].rc.bottom >= WINSIZE_Y && Player.isGameOver == false) 
			{
				_monster[i].MutantChance = RND->getFromIntTo(1, 777);

				if (_monster[i].MutantChance == 1)
				{
					_monster[i].rc = RectMake
					(
						RND->getFromIntTo(10, WINSIZE_X),
						RND->getFromIntTo(-500, 30),
						RND->getFromIntTo(300, 500),
						RND->getFromIntTo(100, 300)
					);
					SetSpeed[i] = 1;
				}
				else {
					_monster[i].rc = RectMake
					(
						RND->getFromIntTo(10, WINSIZE_X),
						RND->getFromIntTo(-500, 30),
						RND->getFromIntTo(10, 20),
						RND->getFromIntTo(10, 30)
					);
				}
				score++;
			}
			_monster[i].rc.top += SetSpeed[i];
			_monster[i].rc.bottom += SetSpeed[i];
		}
		_count = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		Player.rc.left -= 3;
		Player.rc.right -= 3;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		Player.rc.left += 3;
		Player.rc.right += 3;
	}
}

//이미지 그리기
void mainGame::render(HDC hdc)
{

	//플레이어 생성
	RectangleMake(hdc, Player.rc);

	HBRUSH brush = CreateSolidBrush(RGB(230, 35, 35));
	FillRect(hdc, &Player.rc, brush);
	DeleteObject(brush);

	//플레이 메시지 출력
	wsprintf(str, TEXT("SCORE : %d"), score);
	TextOut(hdc, WINSIZE_X / 2 - 50, 50,
		str, strlen(str));


	//몬스터 생성 - 게임 오버가 아닐 때
	if (Player.isGameOver == false) {

		for (int i = 0; i < BOX_MAX; i++)
		{
			RectangleMake(hdc, _monster[i].rc);
		}
	}
	
	//게임 오버 메시지 출력
	if (Player.isGameOver == true) {
		TextOut(hdc, WINSIZE_X / 2 - 180, WINSIZE_Y / 2 - 50,
			"게임 오버 : 재시작 하려면 스페이스 키를 입력하시오.", strlen("게임 오버 : 재시작 하려면 스페이스 키를 입력하시오."));
	}
}
