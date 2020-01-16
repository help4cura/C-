#include <Windows.h>
#include <string.h>
HINSTANCE _hInstance;
HWND _hwnd;

LPSTR _lpszClass = TEXT((LPSTR)"Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

WNDCLASS wndClass;

wndClass.cbClsExtra = 0;
wndClass.cbWndExtra = 0;
wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
wndClass.hCursor = LoadCursor(NULL, IDI_APPLICATION);
wndClass.hInstance = hInstance;
wndClass.lpfnWndProc = (WNDPROC)WndProc;
wndClass.lpszClassName = _lpszClass;
wndClass.lpszMenuName = NULL;
wndClass.style = CS_HREDRAW | CS_VREDRAW;

RegisterClass(&wndClass);

_hwnd = CreateWindow(_lpszClass, _lpszClass, WS_OVERLAPPEDWINDOW, 400, 100, 800, 800, NULL, (HMENU)NULL, hInstance, NULL);

ShowWindow(_hwnd, nCmdShow);

MSG message;

	while (GetMessage(&message, 0, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}