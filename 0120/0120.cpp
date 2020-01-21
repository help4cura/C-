#include "setDefine.h"
#include "commonMacroFunction.h"

HINSTANCE _hInstance;
HWND _hWnd;

//������ ���� ��ܿ� ���� ���α׷���
LPTSTR _lpszClass = (LPTSTR)(TEXT("WINDOW API"));

//�Լ� ���� ����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = _lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = WINSTYLE;

	RegisterClass(&wndClass);




	_hWnd = CreateWindow(

		WIN_NAME,
		WIN_NAME,
		WS_OVERLAPPEDWINDOW,
		WINSTART_X,
		WINSTART_Y,
		WINSIZE_X,
		WINSIZE_Y,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL

		);

	//�����츦 ȭ�鿡 ����ϴ� ����� �Ѱ���
	ShowWindow(_hWnd, nCmdShow);



	//�޽��� ����ü
	MSG message;

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

/*
	<������ ���α׷����� �ʼ� 4���>
	1. WNDCLASS ���� : �������� ����� �Ǵ� Ŭ������ ����
	2. CreateWindow : �޸𸮻� �����츦 ����
	3. ShowWindow : �����츦 ȭ�鿡 ǥ��
	4. �޽��� ���� : ����ڷκ����� �޽����� ���޹޾� ó��
*/

//WndProc�� �ٱ��� ���������ν�
//RECT ����ü�� �ڷ������� ������ ���� _rc�� ����
RECT _rc = { 0, 0, 100, 100 };
RECT _rc2 = { 30, 10, 100, 80 };
RECT _rc3 = { 300,0,400,100 };
RECT _rcFin = { _rc3.left + 10,_rc2.top,_rc3.right - 10,_rc2.bottom };

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	/*
		<DC(Device Context)>
		��¿� �ʿ��� ��� ������ ������ ������ ����ü.
		���� �����̳� ����, ä�� ���̿� ����, ��� ��� ���� �����Ѵ�.
	*/
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
		case WM_CREATE:
			break;

		case WM_PAINT:
		{
			//�׸��� ����
			hdc = BeginPaint(hWnd, &ps);
			
			Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
			//Rectangle(hdc, _rc.left, _rc.top, _rc.right - 150, _rc.bottom - 150);
			Rectangle(hdc, _rc2.left, _rc2.top, _rc2.right, _rc2.bottom);
			Rectangle(hdc, _rc3.left, _rc3.top, _rc3.right, _rc3.bottom);
			//Rectangle(hdc, _rcFin.left, _rcFin.top, _rcFin.right, _rcFin.bottom);
			//�׸��� ����
			EndPaint(hWnd, &ps);
		}
		break;

		//Ű�Է�
		case WM_KEYUP:
		{
		}
		break;

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_LEFT:
				{
					//ȭ�鿡�� ����� ���� ����ó��
					if (_rc.left <= 0) break;
					/*if (_rc.right == _rc3.left) {
						_rc.left += 10;
						_rc.right += 10;
						_rc2.left = _rc.left;
						_rc2.right += 10;
						_rc3.left = _rc.right;
						_rc3.right += 10;
					}*/
					else if (_rc2.right == _rc.right) {
						_rc.left -= 10;
						_rc.right -= 10;
						_rc2.right = _rc.right;

						_rc2.left -= 10;
					}
					else if (_rc2.right != _rc.right) {
						_rc.left -= 10;
						_rc.right -= 10;
						_rc2.left -= 5;
						_rc2.right -= 5;
					}
				}
					break;
				case VK_RIGHT:
				{
					//ȭ�鿡�� ����� ���� ����ó��
					if (_rc.right >= 775) break;
					if (_rc.right == _rc3.left) {
						_rc.left += 10;
						_rc.right += 10;
						_rc2.left = _rc.left;
						_rc2.right += 10;
						_rc3.left = _rc.right;
						_rc3.right += 10;
					}
					else if (_rc2.left == _rc.left) {
						_rc.left += 10;
						_rc.right += 10;
						_rc2.left = _rc.left;

						_rc2.right += 10;
					}
					else if (_rc2.left != _rc.left) {
						_rc.left += 10;
						_rc.right += 10;
						_rc2.left += 5;
						_rc2.right += 5;
					}
				}
					break;
				case VK_UP:
				{
					if (_rc.top <= 0) break;
					_rc.top -= 10;
					_rc.bottom -= 10;
				}
					break;
				case VK_DOWN:
				{
					if (_rc.bottom >= 775) break;
					_rc.top += 10;
					_rc.bottom += 10;
				}
					break;
			}

			//����� ���ΰ�ħ
			InvalidateRect(hWnd, NULL, true);	//system("cls)
		}
		break;

		case WM_DESTROY:	//Alt+F4 Ȥ�� �ý��� �޴� ����Ŭ������ ����� �߻�
			PostQuitMessage(0);
			return 0;
	}

	//DefWindowProc : WndProc���� ó������ ���� ������ �޽����� ó��
	//�ý��� �޴� ���� Ŭ���� ���α׷� ����
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

/*
	<������>
	1. �簢�� �ϳ� �׸��� ����������
	2. API ȭ�� ������ �� ������ �����
*/
