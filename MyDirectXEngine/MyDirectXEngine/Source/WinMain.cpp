#include "pch.h"
/*--------------------------------------
 *	Global Variables
 *-------------------------------------*/
#pragma region GlobalVarialbes
WCHAR	WindowClass[MAX_NAME_STRING];
WCHAR	WindowTitle[MAX_NAME_STRING];
INT		WindowWidth;
INT		WindowHeight;
HICON	hIcon;
/*-------------------------------------*/
#pragma endregion


#pragma region Pre-Declarations
VOID InitializeVariables();
VOID CreateWindowClass();
VOID InitializeWindow();
VOID MessageLoop();
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

int Run()
{
	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		// If there are Window messages then process them.
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		// Otherwise, do animation/game stuff.
		else
		{
			/*mTimer.Tick();

			if (!mAppPaused)
			{
				CalculateFrameStats();
				Update(mTimer);
				Draw(mTimer);
			}
			else
			{
				Sleep(100);
			}*/
		}
	}

	return (int)msg.wParam;
}
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{

	InitializeVariables();
	CreateWindowClass();
	InitializeWindow();
	MessageLoop();
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_PAINT:
	{
		break;
	}
	case WM_CREATE:
	{
		break;
	}
	case WM_COMMAND:
	{
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

VOID InitializeVariables()
{
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);
	//Initialize Global Variables

	WindowWidth = 1280;
	WindowHeight = 720;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

VOID CreateWindowClass()
{
	// Create Window Class
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = 0;

	wcex.hInstance = HInstance();


	wcex.hIcon = hIcon;
	wcex.hIconSm = hIcon;

	wcex.lpfnWndProc = static_cast<WNDPROC>(WndProc);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(0, L"RegisterClass Failed.", 0, 0);
		return;
	}
}

VOID InitializeWindow()
{
	//Create and Display our Window
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
	if (!hWnd)
	{
		MessageBox(0, L"CreateWindow Failed.", 0, 0);
		return;
	}
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}
VOID MessageLoop()
{
	//Listen for Message Events
	Run();
}