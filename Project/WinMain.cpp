// Following the "Create traditional Windows Desktop Application (C++) to learn the Win32 API for C++
// https://learn.microsoft.com/en-us/cpp/windows/walkthrough-creating-windows-desktop-applications-cpp?view=msvc-170

// Include the Win32 API
#include <Windows.h>
// Handles ANSI and Unicode strings
#include <tchar.h>

// Global Variables
static TCHAR szWindowClass[] = _T("TestApp");
static TCHAR szTitle[] = _T("Win32 Test Application");
HINSTANCE hInst;

// Forward Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// The windows equivalent of main in c/c++ apps 
// _In_ is part of Microsoft's Source Code Annotation Language (SAL, for short)
// _In_ indicates to the program that the Input parameter must have a valid value
// _In_opt_ indicates that the Input parameter can be NULL
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,			// Handler of the current instance of the application
	_In_opt_ HINSTANCE hPrevInstance,	// Handler of the previous instance of the application (NO LONGER USED)
	_In_ LPSTR lpCmdLine,				// The application's Command Line
	_In_ int nCmdShow					// Controls how the windows of the application is to be shown
) {
	// Setup the window information
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);					// cbSize - Size of this structure (in bytes)
	wcex.style = CS_HREDRAW | CS_VREDRAW;				// style - Class Style (see: https://learn.microsoft.com/en-us/windows/win32/winmsg/window-class-styles)
	wcex.lpfnWndProc = WndProc;							// lpfnWndProc - Pointer to Window Procedure Function
	wcex.cbClsExtra = 0;								// cbClsExtra - Number of extra bytes to allocate following the window-class structure
	wcex.cbWndExtra = 0;								// cbWndExtra - Number of extra bytes to allocate following the window instance
	wcex.hInstance = hInstance;							// hInstance - Handle to the instance that contains the windows procedure for the class
	wcex.hIcon = NULL;									// hIcon - Handle to the class icon.
	wcex.hCursor = NULL;								// hCursor - Handle to the class cursor.
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	// hBrush - Handle to the background brush, used for painting the background.
	wcex.lpszMenuName = nullptr;						// lpszMenuName - Pointer to null-terminated character string that specifies the resource name of the class menu (as the name appears in the resource file)
	wcex.lpszClassName = szWindowClass;					// lpszClassName - Pointer to null-terminated string or atom. (see: https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassexw)
	wcex.hIconSm = NULL;								// hIconSm - Handle to the small icon

	// Throws an error if a registered class for wcex doesn't exist 
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,
			_T("Call to RegisteredClassEx failed!"),
			_T("Window Setup"),
			NULL);
		return 1;
	}

	HWND hWnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,			// Extended window style
		szWindowClass,					// The name of the application
		szTitle,						// The text on the title bar
		WS_OVERLAPPEDWINDOW,			// Type of window to create (see: https://learn.microsoft.com/en-us/windows/win32/winmsg/window-styles)
		CW_USEDEFAULT, CW_USEDEFAULT,	// Initial position (x,y)
		500, 100,						// Initial size (width, length)
		NULL,							// Parent of window
		NULL,							// Handle to a menu, or specifies a child-windor identifier
		hInstance,						// WinMain instance of hInstance
		NULL							// Pointer to a value to be passed to the window through CREATESTRUCT structure
	);
	
	// Throws an error if window handler couldn't be created
	if (!hWnd) {
		MessageBox(NULL,
			_T("Call to CreateWindowEx failed!"),
			_T("Window Setup"),
			NULL);

		return 1;
	}

	// hWnd - The window handler we create above
	// nCmdShow - The command line from WinMain
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Message Loop
	// Listens to messages that windows sends
	// Sends the messages to WndProc to handle
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

// Window Procedure Function
// This function handles messages windows sends out
// for example if the user clicks on an "OK" button, you write the logic within WndProc to handle that
LRESULT CALLBACK WndProc(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR text[] = _T("Hello World!");

	switch (message) {
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		TextOut(hdc, 5, 5, text, _tcslen(text));

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}