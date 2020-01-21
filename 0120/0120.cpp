#include "setDefine.h"
#include "commonMacroFunction.h"

HINSTANCE _hInstance;
HWND _hWnd;

//윈도우 좌측 상단에 띄우는 프로그램명
LPTSTR _lpszClass = (LPTSTR)(TEXT("WINDOW API"));

//함수 전방 선언
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

	//윈도우를 화면에 출력하는 방법을 넘겨줌
	ShowWindow(_hWnd, nCmdShow);



	//메시지 구조체
	MSG message;

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

/*
	<윈도우 프로그래밍의 필수 4요소>
	1. WNDCLASS 정의 : 윈도우의 기반이 되는 클래스를 정의
	2. CreateWindow : 메모리상에 윈도우를 만듦
	3. ShowWindow : 윈도우를 화면에 표시
	4. 메시지 루프 : 사용자로부터의 메시지를 전달받아 처리
*/

//WndProc의 바깥에 전역변수로써
//RECT 구조체를 자료형으로 가지는 변수 _rc를 생성
RECT _rc = { 0, 0, 100, 100 };
RECT _rc2 = { 30, 10, 100, 80 };
RECT _rc3 = { 300,0,400,100 };
RECT _rcFin = { _rc3.left + 10,_rc2.top,_rc3.right - 10,_rc2.bottom };

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	/*
		<DC(Device Context)>
		출력에 필요한 모든 정보를 가지는 데이터 구조체.
		선의 색상이나 굵기, 채움 무늬와 색상, 출력 방법 등을 포함한다.
	*/
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
		case WM_CREATE:
			break;

		case WM_PAINT:
		{
			//그리기 시작
			hdc = BeginPaint(hWnd, &ps);
			
			Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
			//Rectangle(hdc, _rc.left, _rc.top, _rc.right - 150, _rc.bottom - 150);
			Rectangle(hdc, _rc2.left, _rc2.top, _rc2.right, _rc2.bottom);
			Rectangle(hdc, _rc3.left, _rc3.top, _rc3.right, _rc3.bottom);
			//Rectangle(hdc, _rcFin.left, _rcFin.top, _rcFin.right, _rcFin.bottom);
			//그리기 종료
			EndPaint(hWnd, &ps);
		}
		break;

		//키입력
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
					//화면에서 벗어나기 위한 예외처리
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
					//화면에서 벗어나기 위한 예외처리
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

			//지우고 새로고침
			InvalidateRect(hWnd, NULL, true);	//system("cls)
		}
		break;

		case WM_DESTROY:	//Alt+F4 혹은 시스템 메뉴 더블클릭으로 종료시 발생
			PostQuitMessage(0);
			return 0;
	}

	//DefWindowProc : WndProc에서 처리되지 않은 나머지 메시지를 처리
	//시스템 메뉴 더블 클릭시 프로그램 종료
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

/*
	<숙제☆>
	1. 사각형 하나 그리고 움직여보기
	2. API 화면 밖으로 안 나가게 만들기
*/
