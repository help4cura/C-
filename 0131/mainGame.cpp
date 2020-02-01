#include "setDefine.h"
#include "mainGame.h"

//�ʱ�ȭ = WM_CREATE
HRESULT mainGame::init()
{
	gameNode::init();

	//�δ��� �����
	for (int i = 0; i < BOX_MAX; i++)
	{
		//��������
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

//�޸𸮿��� ����
void mainGame::release()
{
	gameNode::release();
}

//�ǽð� ����
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

//�̹��� �׸���
void mainGame::render(HDC hdc)
{

	//�÷��̾� ����
	RectangleMake(hdc, Player.rc);

	HBRUSH brush = CreateSolidBrush(RGB(230, 35, 35));
	FillRect(hdc, &Player.rc, brush);
	DeleteObject(brush);

	wsprintf(str, TEXT("SCORE : %d"), score);
	TextOut(hdc, WINSIZE_X / 2 - 50, 50,
		str, strlen(str));


	//���� ���� - ���� ������ �ƴ� ��
	if (Player.isGameOver == false) {

		for (int i = 0; i < BOX_MAX; i++)
		{
			RectangleMake(hdc, _monster[i].rc);
		}
	}
	
	//���� ���� �޽��� ���
	if (Player.isGameOver == true) {
		TextOut(hdc, WINSIZE_X / 2 - 180, WINSIZE_Y / 2 - 50,
			"���� ���� : ����� �Ϸ��� �����̽� Ű�� �Է��Ͻÿ�.", strlen("���� ���� : ����� �Ϸ��� �����̽� Ű�� �Է��Ͻÿ�."));
	}
}
