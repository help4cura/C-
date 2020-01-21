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

//����
wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//Ŀ��
wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//������
wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//���α׷� ��ȣ
wndClass.hInstance = hInstance;
//�޽��� ó�� �Լ�
wndClass.lpfnWndProc = (WNDPROC)WndProc;
wndClass.lpszClassName = _lpszClass;
wndClass.lpszMenuName = NULL;
//������ ��Ÿ�� ���� (���� | ����)
wndClass.style = CS_HREDRAW | CS_VREDRAW;
//Ư���� ���� �����츦 ����ϴ� ����
//wndClass�� �ּҰ��� �Ѱ���
RegisterClass(&wndClass);
//CreateWindow�� ���� 
_hwnd = CreateWindow(_lpszClass, _lpszClass, WS_OVERLAPPEDWINDOW, 
	//����� ���� (400, 100) ��ǥ���� �����ϴ� (800 x 800) â�� ����
	400, //X
	100, //Y
	800, //width
	800, //height
	
	//�θ� �����찡 ���� ���, �θ� �������� �ڵ� ����
	NULL, 

	//�����쿡�� ����� �޴��� �ڵ� ����
	(HMENU)NULL, 

	//�����츦 ����� ��ü, ���α׷� �ڵ��� ����
	//�ַ� WinMain�� �μ��� ���޵� hInstance�� ������ �ȴ�.
	hInstance, 

	NULL
);

ShowWindow(_hwnd, nCmdShow);

MSG message;

	//GetMessage �ý����� �����ϰ� �ִ� �޽��� ��⿭���� �޽����� �޾Ƶ��δ�.
	//��⿭�� �߻��ϱ� �������� while���� ��� �����.	
	while (GetMessage(&message, 0, 0, 0)) 
	{
		TranslateMessage(&message);

		//WndProc�� �����ϴ� ������ ��
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//DC : Device Contact
	//��¿� �ʿ��� ������ ��� �ִ� ������ ����ü

	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		break;

	case WM_PAINT:
	{
		//����Ʈ ����
		hdc = BeginPaint(hwnd, &ps);

		//Line �׸���
		MoveToEx(hdc, 50, 100, NULL);
		//LineTo(hdc, 200, 200);
		//LineTo(hdc, 400, 400);

		//�簢���� ��
		Rectangle(hdc, 10, 10, 200, 200);
		Ellipse(hdc, 10, 10, 200, 200);

		//HDC, X, Y, ���ڿ�, ���ڿ��� ����
		TextOut(hdc, 100, 50, "�׽�Ʈ", strlen("�׽�Ʈ"));



		//����Ʈ ����
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

		//����� ���ΰ�ħ
		InvalidateRect(hwnd, NULL, true);
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}