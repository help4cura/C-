#include <Windows.h>
#include <string.h>
HINSTANCE _hInstance;
HWND _hwnd;

LPSTR _lpszClass = TEXT((LPSTR)"Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

WNDCLASS wndClass;

wndClass.cbClsExtra = 0;
wndClass.cbWndExtra = 0;

//배경색
wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//커서
wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//아이콘
wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//프로그램 번호
wndClass.hInstance = hInstance;
//메시지 처리 함수
wndClass.lpfnWndProc = (WNDPROC)WndProc;
wndClass.lpszClassName = _lpszClass;
wndClass.lpszMenuName = NULL;
//윈도우 스타일 정의 (수직 | 수평)
wndClass.style = CS_HREDRAW | CS_VREDRAW;
//특성을 가진 윈도우를 등록하는 과정
//wndClass의 주소값을 넘겨줌
RegisterClass(&wndClass);
//CreateWindow로 생성 
_hwnd = CreateWindow(_lpszClass, _lpszClass, WS_OVERLAPPEDWINDOW, 
	//모니터 상의 (400, 100) 좌표에서 시작하는 (800 x 800) 창을 생성
	400, //X
	100, //Y
	800, //width
	800, //height
	
	//부모 윈도우가 있을 경우, 부모 윈도우의 핸들 지정
	NULL, 

	//윈도우에서 사용할 메뉴의 핸들 지정
	(HMENU)NULL, 

	//윈도우를 만드는 주체, 프로그램 핸들을 지정
	//주로 WinMain의 인수로 전달된 hInstance를 넣으면 된다.
	hInstance, 

	NULL
);

ShowWindow(_hwnd, nCmdShow);

MSG message;

	//GetMessage 시스템이 유지하고 있는 메시지 대기열에서 메시지를 받아들인다.
	//대기열이 발생하기 전까지는 while문이 계속 실행됨.	
	while (GetMessage(&message, 0, 0, 0)) 
	{
		TranslateMessage(&message);

		//WndProc에 전달하는 역할을 함
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//DC : Device Contact
	//출력에 필요한 정보를 담고 있는 데이터 구조체

	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		break;

	case WM_PAINT:
	{
		//페인트 시작
		hdc = BeginPaint(hwnd, &ps);

		//Line 그리기
		MoveToEx(hdc, 50, 100, NULL);
		//LineTo(hdc, 200, 200);
		//LineTo(hdc, 400, 400);

		//사각형과 원
		Rectangle(hdc, 10, 10, 200, 200);
		Ellipse(hdc, 10, 10, 200, 200);

		//HDC, X, Y, 문자열, 문자열의 길이
		TextOut(hdc, 100, 50, "테스트", strlen("테스트"));



		//페인트 종료
		EndPaint(hwnd, &ps);
	}
		
	break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{

		case VK_LEFT:
			break;

		case VK_RIGHT:
			break;

		}

		//지우고 새로고침
		InvalidateRect(hwnd, NULL, true);
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}