#include "stdafx.h"
#include <list>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <thread>
#include <vector>
#include <assert.h>
#include <numeric>
#include <ctime>
#include <atlstr.h>
#include "Sortoff.h"

using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

VOID OnPaint(HDC hdc)
{
	//SetBkMode(hdc, OPAQUE);
	
	/*for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 0; y < 726; y += 1)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}*/

	//runAlgo(hdc, 2);
	
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	HWND                hWnd;
	MSG                 msg;
	WNDCLASS            wndClass;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = TEXT("GettingStarted");

	RegisterClass(&wndClass);

	hWnd = CreateWindow(
		TEXT("GettingStarted"),   // window class name
		TEXT("Sortoff"),  // window caption
		WS_OVERLAPPEDWINDOW,      // window style
		CW_USEDEFAULT,            // initial x position
		CW_USEDEFAULT,            // initial y position
		CW_USEDEFAULT,            // initial x size
		CW_USEDEFAULT,            // initial y size
		NULL,                     // parent window handle
		NULL,                     // window menu handle
		hInstance,                // program instance handle
		NULL);                    // creation parameters

	hWinMainWnd = hWnd;

	SetWindowPos(hWnd, NULL, 100, 100, 745, 765, NULL);

	hwndButton4 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Choose an algorithm",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_DISABLED,  // Styles 
		0,         // x position 
		0,         // y position 
		745,        // Button width
		765,        // Button height
		hWnd,     // Parent window
		(HMENU)100000,       // No algorithm.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Slide sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		10,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 17,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton2 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Quicksort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		110,         // x position 
		10,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 2,       //Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton3 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Gravity sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		210,         // x position 
		10,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 0,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton5 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Insertion sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		310,         // x position 
		10,         // y position 
		110,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 18,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton6 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Shell sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		420,         // x position 
		10,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 4,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton7 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Cocktail shaker sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		520,         // x position 
		10,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 19,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton8 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Radix LSD",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		110,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 6,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton9 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Pigeonhole sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		110,         // x position 
		110,         // y position 
		110,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 7,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton10 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Flashsort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		220,         // x position 
		110,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 8,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton11 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Merge sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		320,         // x position 
		110,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 9,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton12 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Heap sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		420,         // x position 
		110,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 10,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton13 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Radix MSD",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		520,         // x position 
		110,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 11,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton14 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Dual pivot quicksort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		210,         // y position 
		160,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 12,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton15 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Bitonic sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		170,         // x position 
		210,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 13,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton16 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Tournament mode",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		0,         // x position 
		450,         // y position 
		735,        // Button width
		315,        // Button height
		hWnd,     // Parent window
		(HMENU) 999,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton17 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"3-way quicksort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		270,         // x position 
		210,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 14,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton18 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Library sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		420,         // x position 
		210,         // y position 
		110,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 20,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton19 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Strand sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		530,         // x position 
		210,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 16,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton20 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Patience sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		310,         // y position 
		110,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 1,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton21 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Tree sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		120,         // x position 
		310,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 3,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton22 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Histogram sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		220,         // x position 
		310,         // y position 
		120,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 5,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton25 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Set sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		340,         // x position 
		310,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 15,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton23 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Random data",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		440,         // x position 
		310,         // y position 
		110,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) RANDOM_INTS,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton24 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Mostly sorted",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		550,         // x position 
		310,         // y position 
		120,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) MOSTLY_SORTED,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.


	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GdiplusShutdown(gdiplusToken);
	return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC          hdc;
	PAINTSTRUCT  ps;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		OnPaint(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_COMMAND:
		if (wParam != RANDOM_INTS && wParam != MOSTLY_SORTED)
		{
			destroyAllButtons();
		}
		hdc = BeginPaint(hWnd, &ps);
		OnPaint(hdc);
		runAlgo(hdc, wParam);
		EndPaint(hWnd, &ps);
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
} // WndProc

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int * slideSort(HDC hdc, int(&arr)[726])
{
	int n = (sizeof(arr) / sizeof(arr[0]));

	int p[726];

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	bool ascending = false;
	int startIndex = 0, seqStartIndex = 0, originalIndex = 0, failedRuns = 0;
	int numSeqs = 0;

	for (int i = 1; i < n; i++)
	{
		if (p[i] > p[i - 1])
		{
			if (!ascending)
			{
				ascending = true;
				seqStartIndex = i - 1;
			}
		}
		else
		{
			if (i - seqStartIndex > 1)
			{
				numSeqs++;
				if (numSeqs == 1)
					originalIndex = i;
				if (numSeqs > 5)
				{
					merge(hdc, p, 0, originalIndex, i);
					numSeqs = 0;
				}
				else
				{
					mergeSort(hdc, p, originalIndex, i);
				}
			}
			else
			{
				failedRuns++;
				if (failedRuns == 2 && i + 1 < n)
				{
					int temp = p[i - 1];
					SetPixel(hdc, i - 1, 726 - p[i - 1], RGB(0, 0, 0));
					p[i - 1] = p[i + 1];
					SetPixel(hdc, i - 1, 726 - p[i - 1], RGB(255, 0, 0));
					SetPixel(hdc, i + 1, 726 - p[i + 1], RGB(0, 0, 0));
					p[i + 1] = temp;
					SetPixel(hdc, i + 1, 726 - p[i + 1], RGB(255, 0, 0));

					i--;

					failedRuns = 0;
				}
			}
			ascending = false;
			seqStartIndex = i;
		}
	}

	mergeSort(hdc, p, 0, n);

	InsertionSortIndex(hdc, p, n);

	return p;
}

int * setSort(HDC hdc, int(&arr)[726])
{
	int n = (sizeof(arr) / sizeof(arr[0]));

	int p[726];

	int max = arr[0];
	int maxIndex = 0;

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];

		if (p[i] > max)
		{
			max = p[i];
			maxIndex = i;
		}
			
	}

	SetPixel(hdc, maxIndex, 726 - max, RGB(0, 255, 0));

	std::vector<int> k;

	for (int i = 0; i < max; i++)
	{
		k.push_back(0);
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
	}

	for (int i = 0; i < n; i++)
	{
		k[p[i]] = 1;
		SetPixel(hdc, i, 726 - p[i], RGB(255, 255, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
	}

	int currentIndex = 0;

	for (int i = 0; i < max; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		if (k[i] == 1)
		{
			SetPixel(hdc, currentIndex, 726 - p[currentIndex], RGB(0, 0, 0));

			p[currentIndex] = i;

			SetPixel(hdc, currentIndex, 726 - p[currentIndex], RGB(255, 0, 0));

			currentIndex++;
		}
	}

	return p;
}

int * selectionSort(HDC hdc, int (&arr)[726])
{
	int i, j, min_idx;
	int n = (sizeof(arr) / sizeof(arr[0]));

	int p[726];

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (p[j] < p[min_idx])
			{
				min_idx = j;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		}
		int temp = p[min_idx];
		SetPixel(hdc, min_idx, 726 - p[min_idx], RGB(0, 0, 0));
		p[min_idx] = p[i];
		SetPixel(hdc, min_idx, 726 - p[min_idx], RGB(255, 0, 0));
		SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
		p[i] = temp;
		SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
	}

	return p;
}

int * cocktailShaker(HDC hdc, int(&arr)[726])
{
	int n = (sizeof(arr) / sizeof(arr[0]));
	int s = 0;

	int p[726];

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	bool changed = true;

	while (changed)
	{
		changed = false;
		for (int i = s; i < (n - 1); i += 1)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			if (p[i] > p[i + 1])
			{
				int temp = p[i];
				SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
				p[i] = p[i + 1];
				SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
				SetPixel(hdc, i + 1, 726 - p[i + 1], RGB(0, 0, 0));
				p[i + 1] = temp;
				SetPixel(hdc, i + 1, 726 - p[i + 1], RGB(255, 0, 0));
				changed = true;
			}
		}

		if (!changed)
		{
			return p;
		}

		changed = false;
		n -= 1;

		for (int i = n - 1; i > (s + 1); i -= 1)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			if (p[i] < p[i - 1])
			{
				int temp = p[i];
				SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
				p[i] = p[i - 1];
				SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
				SetPixel(hdc, i - 1, 726 - p[i - 1], RGB(0, 0, 0));
				p[i - 1] = temp;
				SetPixel(hdc, i - 1, 726 - p[i - 1], RGB(255, 0, 0));
				changed = true;
			}
		}

		s += 1;
	}

	return p;
}

int * insertionSort(HDC hdc, int(&arr)[726])
{
	int p[726];

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	for (int i = 1; i < n; i += 1)
	{
		int o = i - 1;
		int key = p[i];
		while (o >= 0 && p[o] > key)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			SetPixel(hdc, o + 1, 726 - p[o + 1], RGB(0, 0, 0));
			p[o + 1] = p[o];
			SetPixel(hdc, o + 1, 726 - p[o + 1], RGB(255, 0, 0));
			o -= 1;
		}
		SetPixel(hdc, o + 1, 726 - p[o + 1], RGB(0, 0, 0));
		p[o + 1] = key;
		SetPixel(hdc, o + 1, 726 - p[o + 1], RGB(255, 0, 0));
	}

	return p;
}

void heapify(HDC hdc, int arr[], int n, int i)
{
	int largest = i;
	int left = (i * 2) + 1;
	int right = (i * 2) + 2;

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		int temp = arr[i];
		arr[i] = arr[largest];
		SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));
		SetPixel(hdc, largest, 726 - arr[largest], RGB(0, 0, 0));
		arr[largest] = temp;
		SetPixel(hdc, largest, 726 - arr[largest], RGB(255, 0, 0));

		heapify(hdc, arr, n, largest);
	}
}

int * heapSort(HDC hdc, int(&arr)[726])
{
	int p[726];

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	for (int i = (n / 2) - 1; i >= 0; i -= 1)
	{
		heapify(hdc, p, n, i);
	}

	for (int i = (n - 1); i >= 0; i -= 1)
	{
		SetPixel(hdc, 0, 726 - p[0], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		int temp = p[0];
		p[0] = p[i];
		SetPixel(hdc, 0, 726 - p[0], RGB(255, 0, 0));
		SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
		p[i] = temp;
		SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));

		heapify(hdc, p, i, 0);
	}

	return p;
}

void merge(HDC hdc, int arr[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	/* create temp arrays */
	int * Lt = new int[n1];
	int * Rt = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		Lt[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		Rt[j] = arr[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (Lt[i] <= Rt[j])
		{
			SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			arr[k] = Lt[i];
			SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
			i++;
		}
		else
		{
			SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			arr[k] = Rt[j];
			SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		arr[k] = Lt[i];
		SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		arr[k] = Rt[j];
		SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
		j++;
		k++;
	}

	delete[] Lt;
	delete[] Rt;
}

void mergeSort(HDC hdc, int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(hdc, arr, left, mid);
		mergeSort(hdc, arr, mid + 1, right);

		merge(hdc, arr, left, mid, right);
	}
}

int * mergeSortMain(HDC hdc, int(&arr)[726])
{
	int p[726];

	int n = 726;

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	mergeSort(hdc, p, 0, n - 1);

	return p;
}

void bitonicMerge(HDC hdc, int arr[], int low, int n, bool ascending)
{
	if (n > 1)
	{
		int k = 1;
		while (k < n) k = k << 1;
		int m = k >> 1;

		for (int i = low; i < (low + n - m); i += 1)
		{
			if (ascending == (arr[i] > arr[i + m]))
			{
				SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
				std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
				int temp = arr[i];
				arr[i] = arr[i + m];
				SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));
				SetPixel(hdc, i + m, 726 - arr[i + m], RGB(0, 0, 0));
				arr[i + m] = temp;
				SetPixel(hdc, i + m, 726 - arr[i + m], RGB(255, 0, 0));
			}
		}

		bitonicMerge(hdc, arr, low, m, ascending);
		bitonicMerge(hdc, arr, low + m, n - m, ascending);
	}
}

void bitonicSort(HDC hdc, int arr[], int low, int n, bool ascending)
{
	if (n > 1)
	{
		int m = (int)(n / 2);
		bitonicSort(hdc, arr, low, m, !ascending);
		bitonicSort(hdc, arr, low + m, n - m, ascending);
		bitonicMerge(hdc, arr, low, n, ascending);
	}
}

int * bitonicSortMain(HDC hdc, int(&arr)[726])
{
	int p[726];

	int n = 726;

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	bitonicSort(hdc, p, 0, n, true);

	return p;
}

int * shellSort(HDC hdc, int(&arr)[726])
{
	int p[726];
	int inc[16] = { 1391376, 463792, 198768, 86961, 33936,
		13776, 4592, 1968, 861, 336,
		112, 48, 21, 7, 3, 1 };

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	int i;

	for (int o = 0; o < 16; o += 1)
	{
		for (int u = inc[o], i = u; i < n; i += 1)
		{
			int currentItem = p[i];
			int j = i;

			while (j >= u && p[j - u] > currentItem)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
				SetPixel(hdc, j, 726 - p[j], RGB(0, 0, 0));
				p[j] = p[j - u];
				SetPixel(hdc, j, 726 - p[j], RGB(255, 0, 0));
				j -= u;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			SetPixel(hdc, j, 726 - p[j], RGB(0, 0, 0));
			p[j] = currentItem;
			SetPixel(hdc, j, 726 - p[j], RGB(255, 0, 0));
		}
	}
	
	return p;
}

int partition(HDC hdc, int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			int temp = arr[i];
			SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
			arr[i] = arr[j];
			SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));
			SetPixel(hdc, j, 726 - arr[j], RGB(0, 0, 0));
			arr[j] = temp;
			SetPixel(hdc, j, 726 - arr[j], RGB(255, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		}
	}

	// DISPLAY
	std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
	int temp = arr[i + 1];
	SetPixel(hdc, i + 1, 726 - arr[i + 1], RGB(0, 0, 0));
	arr[i + 1] = arr[high];
	SetPixel(hdc, i + 1, 726 - arr[i + 1], RGB(255, 0, 0));
	SetPixel(hdc, high, 726 - arr[high], RGB(0, 0, 0));
	arr[high] = temp;
	SetPixel(hdc, high, 726 - arr[high], RGB(255, 0, 0));

	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
int * quickSort(HDC hdc, int(&arr)[726], int low, int high)
{
	int p[726];

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	if (DATA_SET == MOSTLY_SORTED)
	{
		return strandSortMain(hdc, arr);
	}
	
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int part = partition(hdc, p, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort2(hdc, p, low, part - 1);
		quickSort2(hdc, p, part + 1, high);
	}

	return p;
}

void quickSort2(HDC hdc, int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int part = partition(hdc, arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort2(hdc, arr, low, part - 1);
		quickSort2(hdc, arr, part + 1, high);
	}
}

int * radixSort(HDC hdc, int(&arr)[726])
{
	int p[726];

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	int max = p[0];

	for (int i = 0; i < n; i += 1)
	{
		if (p[i] > max)
		{
			max = p[i];
		}
	}

	for (int place = 1; max / place > 0; place *= 10)
	{
		int temp[n];
		int count[10] = { 0 };

		for (int i = 0; i < n; i += 1)
		{
			count[(p[i] / place) % 10] += 1;
		}

		for (int i = 1; i < 10; i += 1)
		{
			count[i] += count[i - 1];
		}

		for (int i = n; i >= 0; i -= 1)
		{
			SetPixel(hdc, (count[((p[i]) / place) % 10]) - 1, 726 - temp[(count[((p[i]) / place) % 10]) - 1], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			temp[(count[((p[i]) / place) % 10]) - 1] = p[i];
			SetPixel(hdc, (count[((p[i]) / place) % 10]) - 1, 726 - temp[(count[((p[i]) / place) % 10]) - 1], RGB(255, 0, 0));
			count[(p[i] / place) % 10] -= 1;
		}

		for (int i = 0; i < n; i += 1)
		{
			SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
			p[i] = temp[i];
			SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
		}
	}

	return p;
}

void InsertionSortIndex(HDC hdc, int arr[], int length)
{
	for (size_t i = 1; i < length; ++i)
	{
		int key = arr[i];

		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			SetPixel(hdc, j, 726 - arr[j], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			int temp = arr[j];
			arr[j] = arr[j + 1];
			SetPixel(hdc, j, 726 - arr[j], RGB(255, 0, 0));
			SetPixel(hdc, j + 1, 726 - arr[j + 1], RGB(0, 0, 0));
			arr[j + 1] = temp;
			SetPixel(hdc, j + 1, 726 - arr[j + 1], RGB(255, 0, 0));
			j--;
		}
	}
}

void insertionSortIndex2(HDC hdc, int arr[], int start, int length)
{
	for (int i = start + 1; i < length; ++i)
	{
		int key = arr[i];

		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			SetPixel(hdc, j, 726 - arr[j], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			int temp = arr[j];
			arr[j] = arr[j + 1];
			SetPixel(hdc, j, 726 - arr[j], RGB(255, 0, 0));
			SetPixel(hdc, j + 1, 726 - arr[j + 1], RGB(0, 0, 0));
			arr[j + 1] = temp;
			SetPixel(hdc, j + 1, 726 - arr[j + 1], RGB(255, 0, 0));
			j--;
		}
	}
}

void radixMSD(HDC hdc, int arr[], int low, int high, int depth)
{
	const unsigned int RADIX = 4;

	int maxIndex = 0;

	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i += 1)
	{
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}

	unsigned int pmax = floor(log(726 + 1) / log(RADIX));
	assert(depth <= pmax);

	int base = pow(RADIX, pmax - depth);

	// count digits
	std::vector<int> count(RADIX, 0);

	for (int i = low; i < high; ++i)
	{
		int r = arr[i] / base % RADIX;
		assert(r < RADIX);
		count[r]++;
	}

	// inclusive prefix sum
	std::vector<int> bkt(RADIX, 0);
	std::partial_sum(count.begin(), count.end(), bkt.begin());

	// mark bucket boundaries
	for (int i = 0; i < bkt.size(); ++i) {
		if (bkt[i] == 0) continue;
	}

	// reorder items in-place by walking cycles
	for (int i = 0, j; i < (high - low); )
	{
		while ((j = --bkt[(arr[low + i] / base % RADIX)]) > i)
		{
			SetPixel(hdc, low + i, 726 - arr[low + i], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			int temp = arr[low + i];
			arr[low + i] = arr[low + j];
			SetPixel(hdc, low + i, 726 - arr[low + i], RGB(255, 0, 0));
			SetPixel(hdc, low + j, 726 - arr[low + j], RGB(0, 0, 0));
			arr[low + j] = temp;
			SetPixel(hdc, low + j, 726 - arr[low + j], RGB(255, 0, 0));
		}
		i += count[(arr[low + i] / base % RADIX)];
	}

	// no more depth to sort?
	if (depth + 1 > pmax) return;

	// recurse on buckets
	int sum = low;
	for (int i = 0; i < RADIX; ++i)
	{
		if (count[i] > 1)
			radixMSD(hdc, arr, sum, sum + count[i], depth + 1);
		sum += count[i];
	}
}

void patienceSort(HDC hdc, std::vector<int>& elements)
{
	int insertPos, currentPile, pileCount, emptyPileCount;
	std::vector<std::vector<int> > pileList;

	pileList.resize(elements.size());
	
	pileList.front().push_back(elements.front());

	pileCount = 1;
	
	for (insertPos = 1; insertPos < elements.size(); insertPos++)
	{
		int middle, left = 0, right = pileCount - 1;
		while (left <= right)
		{
			middle = (left + right) / 2;
			elements.at(insertPos) > pileList.at(middle).back() ? left = middle + 1 : right = middle - 1;
		}
		pileCount += (left >= pileCount);

		pileList.at(left).push_back(elements.at(insertPos));
	}

	emptyPileCount = 0;
	for (insertPos = 0; insertPos < elements.size(); insertPos++)
	{
		currentPile = emptyPileCount;

		SetPixel(hdc, insertPos, 726 - elements.at(insertPos), RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

		elements.at(insertPos) = pileList.at(currentPile).back();

		SetPixel(hdc, insertPos, 726 - elements.at(insertPos), RGB(255, 0, 0));

		pileList.at(currentPile).pop_back();

		if (pileList.at(currentPile).size() == 0)
		{
			emptyPileCount++;
			continue;
		}

		if (currentPile + 1 < pileCount && pileList.at(currentPile).back() > pileList.at(currentPile + 1).back())
		{
			int rightBound = pileCount - 1;

			int middle, left = currentPile + 1, right = pileCount - 1;
			while (left <= right)
			{
				middle = (left + right) / 2;
				pileList.at(currentPile).back() > pileList.at(middle).back() ? left = middle + 1 : right = middle - 1;
			}
			if (left >= pileCount)
			{
				left = pileCount - 1;
			}

			mergePiles(hdc, pileList.at(currentPile), pileList.at(left));
			emptyPileCount++;
		}
	}
	return;
}

void mergePiles(HDC hdc, std::vector<int>& sourcePile, std::vector<int>& destinationPile)
{
	std::vector<int> newPile;
	int sourceScanPos = 0, destinationScanPos = 0;

	int index = 0;
	while (sourceScanPos < sourcePile.size() && destinationScanPos < destinationPile.size())
	{
		if (sourcePile.at(sourceScanPos) > destinationPile.at(destinationScanPos))
		{
			newPile.push_back(sourcePile.at(sourceScanPos++));
		}
		else
		{
			newPile.push_back(destinationPile.at(destinationScanPos++));
		}
		SetPixel(hdc, index, 726 - newPile.back(), RGB(255, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		index++;
	}
	newPile.insert(newPile.end(), sourcePile.begin() + sourceScanPos, sourcePile.end());
	newPile.insert(newPile.end(), destinationPile.begin() + destinationScanPos, destinationPile.end());

	destinationPile = newPile;

	for (int i = 0; i < newPile.size(); i += 1)
	{
		SetPixel(hdc, i, 726 - newPile.at(i), RGB(0, 0, 0));
	}

	return;
}

int * patienceSortMain(HDC hdc, int(&arr)[726])
{
	int p[726];
	std::vector<int> input(726);

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		input[i] = arr[i];
	}

	patienceSort(hdc, input);

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = input[i];
	}

	return p;
}

struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void storeSorted(HDC hdc, Node *root, int arr[], int &i)
{
	if (root != NULL)
	{
		storeSorted(hdc, root->left, arr, i);

		SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

		arr[i++] = root->key;

		SetPixel(hdc, i - 1, 726 - arr[i - 1], RGB(255, 0, 0));

		storeSorted(hdc, root->right, arr, i);
	}
}

Node* insert(HDC hdc, Node* node, int key, int i)
{
	if (node == NULL)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		return newNode(key);
	}
	SetPixel(hdc, i, 726 - key, RGB(0, 0, 0));
	std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

	/* Otherwise, recur down the tree */
	if (key < node->key)
	{
		SetPixel(hdc, i, 726 - key, RGB(255, 0, 0));
		node->left = insert(hdc, node->left, key, i);
	}
	else if (key > node->key)
	{
		SetPixel(hdc, i, 726 - key, RGB(255, 255, 0));
		node->right = insert(hdc, node->right, key, i);
	}

	/* return the (unchanged) Node pointer */
	return node;
}

void treeSort(HDC hdc, int arr[], int n)
{
	struct Node *root = NULL;

	// Construct the BST
	root = insert(hdc, root, arr[0], 0);
	for (int i = 1; i < n; i++)
	{
		insert(hdc, root, arr[i], i);
	}

	// Store inoder traversal of the BST
	// in arr[]
	int i = 0;
	storeSorted(hdc, root, arr, i);
}

int * treeSortMain(HDC hdc, int(&arr)[726])
{
	int p[726];

	if (DATA_SET == MOSTLY_SORTED)
	{
		return cocktailShaker(hdc, arr);
	}

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	treeSort(hdc, p, n);

	return p;
}

int * radixMSDMain(HDC hdc, int(&arr)[726])
{
	int p[726];

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	radixMSD(hdc, p, 0, n, 0);

	return p;
}

void dualPivot(HDC hdc, int arr[], int left, int right)
{
	if (right > left)
	{
		if (arr[left] > arr[right]) 
		{
			SetPixel(hdc, left, 726 - arr[left], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			int temp = arr[left];
			arr[left] = arr[right];
			SetPixel(hdc, left, 726 - arr[left], RGB(255, 0, 0));
			SetPixel(hdc, right, 726 - arr[right], RGB(0, 0, 0));
			arr[right] = temp;
			SetPixel(hdc, right, 726 - arr[right], RGB(255, 0, 0));
		}

		const int p = arr[left];
		const int q = arr[right];

		volatile int l = left + 1;
		volatile int g = right - 1;
		volatile int k = l;

		while (k <= g)
		{
			if (arr[k] < p) 
			{
				SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
				std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
				int temp = arr[k];
				arr[k] = arr[l];
				SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
				SetPixel(hdc, l, 726 - arr[l], RGB(0, 0, 0));
				arr[l] = temp;
				SetPixel(hdc, l, 726 - arr[l], RGB(255, 0, 0));
				++l;
			}
			else if (arr[k] >= q) 
			{
				while (arr[g] > q && k < g)  --g;
				SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
				std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
				int temp = arr[k];
				arr[k] = arr[g];
				SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
				SetPixel(hdc, g, 726 - arr[g], RGB(0, 0, 0));
				arr[g] = temp;
				SetPixel(hdc, g, 726 - arr[g], RGB(255, 0, 0));
				--g;

				if (arr[k] < p) 
				{
					SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
					std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
					int temp = arr[k];
					arr[k] = arr[l];
					SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
					SetPixel(hdc, l, 726 - arr[l], RGB(0, 0, 0));
					arr[l] = temp;
					SetPixel(hdc, l, 726 - arr[l], RGB(255, 0, 0));
					++l;
				}
			}
			++k;
		}
		--l;
		++g;

		SetPixel(hdc, left, 726 - arr[left], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		int temp = arr[left];
		arr[left] = arr[l];
		SetPixel(hdc, left, 726 - arr[left], RGB(255, 0, 0));
		SetPixel(hdc, l, 726 - arr[l], RGB(0, 0, 0));
		arr[l] = temp;
		SetPixel(hdc, l, 726 - arr[l], RGB(255, 0, 0));
		
		SetPixel(hdc, right, 726 - arr[right], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		int temp2 = arr[right];
		arr[right] = arr[g];
		SetPixel(hdc, right, 726 - arr[right], RGB(255, 0, 0));
		SetPixel(hdc, g, 726 - arr[g], RGB(0, 0, 0));
		arr[g] = temp2;
		SetPixel(hdc, g, 726 - arr[g], RGB(255, 0, 0));

		dualPivot(hdc, arr, left, l - 1);
		dualPivot(hdc, arr, l + 1, g - 1);
		dualPivot(hdc, arr, g + 1, right);
	}
}

int * quickSortDualPivot(HDC hdc, int(&arr)[726])
{
	int p[726];

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	dualPivot(hdc, p, 0, n - 1);

	return p;
}

void flashSort(HDC hdc, int arr[], int n)
{
	if (n == 0) return;

	//20% of the number of elements or 0.2n classes will
	//be used to distribute the input data set into
	//there must be at least 2 classes (hence the addition)
	int m = (int)((0.2 * n) + 2);

	//-------CLASS FORMATION-------

	//O(n)
	//compute the max and min values of the input data
	int min, max;
	size_t maxIndex;
	min = max = arr[0];
	maxIndex = 0;

	for (size_t i = 1; i < n - 1; i += 2)
	{
		int smallNum;
		int big;
		size_t bigIndex;

		//which is bigger A(i) or A(i+1)
		if (arr[i] < arr[i + 1])
		{
			smallNum = arr[i];
			big = arr[i + 1];
			bigIndex = i + 1;
		}
		else
		{
			big = arr[i];
			bigIndex = i;
			smallNum = arr[i + 1];
		}

		if (big > max)
		{
			max = big;
			maxIndex = bigIndex;
		}

		if (smallNum < min)
		{
			min = smallNum;
		}
	}

	//do the last element
	if (arr[n - 1] < min)
	{
		min = arr[n - 1];
	}
	else if (arr[n - 1] > max)
	{
		max = arr[n - 1];
		maxIndex = n - 1;
	}

	if (max == min)
	{
		//all the elements are the same
		return;
	}

	//dynamically allocate the storage for L
	//note that L is in the range 1...m (hence
	//the extra 1)
	size_t* L = new size_t[m + 1];

	//O(m)
	//initialize L to contain all zeros (L[0] is unused)
	for (size_t t = 1; t <= m; t++)
	{
		L[t] = 0;
	}

	//O(n)
	//use the function K(A(i)) = 1 + INT((m-1)(A(i)-Amin)/(Amax-Amin))
	//to classify each A(i) into a number from 1...m
	//(note that this is mainly just a percentage calculation)
	//and then store a count of each distinct class K in L(K)
	//For instance, if there are 22 A(i) values that fall into class
	//K == 5 then the count in L(5) would be 22

	//IMPORTANT: note that the class K == m only has elements equal to Amax

	//precomputed constant
	double c = (m - 1.0) / (max - min);
	size_t K;
	for (size_t h = 0; h < n; h++)
	{
		//classify the A(i) value
		K = ((size_t)((arr[h] - min) * c)) + 1;

		//assert: K is in the range 1...m

		//add one to the count for this class
		L[K] += 1;
	}

	//O(m)
	//sum over each L(i) such that each L(i) contains
	//the number of A(i) values that are in the ith
	//class or lower (see counting sort for more details)
	for (K = 2; K <= m; K++)
	{
		L[K] = L[K] + L[K - 1];
	}

	//-------PERMUTATION-------

	//swap the max value with the first value in the array
	SetPixel(hdc, maxIndex, 726 - arr[maxIndex], RGB(0, 0, 0));
	std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
	int temp = arr[maxIndex];
	arr[maxIndex] = arr[0];
	SetPixel(hdc, maxIndex, 726 - arr[maxIndex], RGB(255, 0, 0));
	SetPixel(hdc, 0, 726 - arr[0], RGB(0, 0, 0));
	arr[0] = temp;
	SetPixel(hdc, 0, 726 - arr[0], RGB(255, 0, 0));

	//Except when being iterated upwards,
	//j always points to the first A(i) that starts
	//a new class boundary && that class hasn't yet
	//had all of its elements moved inside its borders;

	//This is called a cycle leader since you know 
	//that you can begin permuting again here. You know
	//this becuase it is the lowest index of the class
	//and as such A(j) must be out of place or else all
	//the elements of this class have already been placed
	//within the borders of the this class (which means
	//j wouldn't be pointing to this A(i) in the first place)
	int j = 0;

	//K is the class of an A(i) value. It is always in the range 1..m
	K = m;

	//the number of elements that have been moved
	//into their correct class
	size_t numMoves = 0;

	//O(n)
	//permute elements into their correct class; each
	//time the class that j is pointing to fills up
	//then iterate j to the next cycle leader
	//
	//do not use the n - 1 optimization because that last element
	//will not have its count decreased (this causes trouble with
	//determining the correct classSize in the last step)
	while (numMoves < n)
	{
		//if j does not point to the begining of a class
		//that has at least 1 element still needing to be
		//moved to within the borders of the class then iterate
		//j upward until such a class is found (such a class
		//must exist). In other words, find the next cycle leader
		while (j >= L[K])
		{
			j++;
			//classify the A(j) value
			K = ((int)((arr[j] - min) * c)) + 1;
		}

		//evicted always holds the value of an element whose location
		//in the array is free to be written into //aka FLASH
		int evicted = arr[j];

		//while j continues to meet the condition that it is
		//pointing to the start of a class that has at least one
		//element still outside its borders (the class isn't full)
		while (j < L[K])
		{
			//compute the class of the evicted value
			K = ((int)((evicted - min) * c)) + 1;

			//get a location that is inside the evicted
			//element's class boundaries
			size_t location = L[K] - 1;

			//swap the value currently residing at the new
			//location with the evicted value
			SetPixel(hdc, location, 726 - arr[location], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			int temp = arr[location];
			arr[location] = evicted;
			SetPixel(hdc, location, 726 - arr[location], RGB(255, 0, 0));
			evicted = temp;

			//decrease the count for this class
			//see counting sort for why this is done
			L[K] -= 1;

			//another element was moved
			numMoves++;
		}
	}

	//-------RECURSION or STRAIGHT INSERTION-------

	//if the classes do not have the A(i) values uniformly distributed
	//into each of them then insertion sort will not produce O(n) results;

	//look for classes that have too many elements; ideally each class
	//(except the topmost or K == m class) should have about n/m elements;
	//look for classes that exceed n/m elements by some threshold AND have
	//more than some minimum number of elements to flashsort recursively

	//if the class has 25% more elements than it should
	int threshold = (int)(1.25 * ((n / m) + 1));
	const int minElements = 30;

	//for each class decide whether to insertion sort its members
	//or recursively flashsort its members;
	//skip the K == m class because it is already sorted
	//since all of the elements have the same value
	for (K = m - 1; K >= 1; K--)
	{
		//determine the number of elments in the Kth class
		size_t classSize = L[K + 1] - L[K];

		//if the class size is larger than expected but not
		//so small that insertion sort could make quick work
		//of it then...
		if (classSize > threshold && classSize > minElements)
		{
			//...attempt to flashsort the class. This will work 
			//well if the elements inside the class are uniformly
			//distributed throughout the class otherwise it will 
			//perform badly, O(n^2) worst case, since we will have 
			//performed another classification and permutation step
			//and not succeeded in making the problem significantly
			//smaller for the next level of recursion. However,
			//progress is assured since at each level the elements
			//with the maximum value will get sorted.
			flashSort(hdc, arr, classSize);
		}
		else //perform insertion sort on the class
		{
			if (classSize > 1)
			{
				InsertionSortIndex(hdc, arr, n);
				return;
			}
		}
	}

	delete[] L;
}

void threeWayPartition(HDC hdc, int arr[], int left, int right, int &i, int &j)
{
	i = left - 1;
	j = right;
	int p = left - 1;
	int q = right;
	int v = arr[right];

	while (true)
	{
		while (arr[++i] < v);

		while (v < arr[--j])
		{
			if (j == left)
			{
				break;
			}	
		}

		if (i >= j)
		{
			break;
		}

		SetPixel(hdc, j, 726 - arr[j], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

		int temp = arr[j];
		arr[j] = arr[i];

		SetPixel(hdc, j, 726 - arr[j], RGB(255, 0, 0));
		SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));

		arr[i] = temp;

		SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));

		if (arr[i] == v)
		{
			p++;

			SetPixel(hdc, p, 726 - arr[p], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			temp = arr[p];
			arr[p] = arr[i];

			SetPixel(hdc, p, 726 - arr[p], RGB(255, 0, 0));
			SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));

			arr[i] = temp;

			SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));
		}

		if (arr[j] == v)
		{
			q--;

			SetPixel(hdc, j, 726 - arr[j], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			int temp = arr[j];
			arr[j] = arr[q];

			SetPixel(hdc, j, 726 - arr[j], RGB(255, 0, 0));
			SetPixel(hdc, q, 726 - arr[q], RGB(0, 0, 0));

			arr[q] = temp;

			SetPixel(hdc, q, 726 - arr[q], RGB(255, 0, 0));
		}
	}

	SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
	std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

	int temp = arr[i];
	arr[i] = arr[right];

	SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));
	SetPixel(hdc, right, 726 - arr[right], RGB(0, 0, 0));

	arr[right] = temp;

	SetPixel(hdc, right, 726 - arr[right], RGB(255, 0, 0));

	j = i - 1;
	for (int k = left; k < p; k++, j--)
	{
		SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

		int temp = arr[k];
		arr[k] = arr[j];

		SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
		SetPixel(hdc, j, 726 - arr[j], RGB(0, 0, 0));

		arr[j] = temp;

		SetPixel(hdc, j, 726 - arr[j], RGB(255, 0, 0));
	}
		
	i = i + 1;

	for (int k = right - 1; k > q; k--, i++)
	{
		SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

		int temp = arr[i];
		arr[i] = arr[k];

		SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));
		SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));

		arr[k] = temp;

		SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
	}
}
void threeWayQuicksort(HDC hdc, int arr[], int left, int right)
{
	if (right <= left)
	{
		return;
	}

	int i;
	int j;

	threeWayPartition(hdc, arr, left, right, i, j);

	threeWayQuicksort(hdc, arr, left, j);
	threeWayQuicksort(hdc, arr, i, right);
}
int * threeWayQuicksortMain(HDC hdc, int(&arr)[726])
{
	int p[726];

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	threeWayQuicksort(hdc, p, 0, n - 1);

	return p;
}

int * americanFlagSort(HDC hdc, int(&arr)[726])
{
	int p[726];

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}
	
	int max = p[0];
	for (int i = 1; i < n; i++) {
		if (p[i] > max)
		{
			max = p[i];
		}
	}

	int bucket[10];
	int bucket_max_index[10];
	int exp = 1;

	while (max / exp > 0) {
		memset(&bucket, 0, sizeof(bucket));
		memset(&bucket_max_index, 0, sizeof(bucket_max_index));
		for (int i = 0; i < n; i++) 
		{
			bucket[(p[i] / exp) % 10]++;
		}

		int index = n;
		for (int i = 9; i >= 0; i--) 
		{
			index -= bucket[i];
			bucket_max_index[i] = index + bucket[i];
			bucket[i] = index;
		}

		index = 0;
		std::vector<int> temp(n);
		for (int i = 0; i < n; i++) 
		{
			int digit = (p[i] / exp) % 10;
			temp[bucket[digit]] = p[i];
			bucket[digit]++;
		}

		for (int i = 0; i < n; i++) 
		{
			SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			p[i] = temp[i];

			SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
		}

		exp *= 10;
	}

	return p;
}

extern "C" void prepareLibrarySort(HDC hdc, int epsilon, int n, int S[MAX2], int * sLen)
{
	int i;
	*sLen = (1 + epsilon)*n;
	for (i = 0; i<*sLen; i++) S[i] = NONE;
}
extern "C" int searchFree(HDC hdc, int e, int sorted[MAX2], int last)
{
	int first = 0;
	int middle;

	while (last >= 0 && IS_EMPTY(sorted[last])) last--;
	while (first <= last && IS_EMPTY(sorted[first])) first++;
	while (first <= last) {
		middle = (first + last) / 2;
		if (IS_EMPTY(sorted[middle])) {
			int tmp = middle + 1;
			//Look to the right
			while (tmp<last && IS_EMPTY(sorted[tmp])) tmp++;
			if (sorted[tmp]>e) {
				tmp = middle - 1;
				while (middle>first && IS_EMPTY(sorted[middle])) middle--;
				//Look to the left
				if (sorted[middle]<e)//Found intermediate position
					return middle;
				last = middle - 1;
			}
			else first = tmp + 1;
		}
		else if (sorted[middle]<e) {
			first = middle + 1;
		}
		else {
			last = middle - 1;
		}
	}
	//If no position was found return -1 or if a lower position was found, return that
	if (last >= 0 && IS_EMPTY(sorted[last])) last--;
	return last;
}
extern "C" void libSort(HDC hdc, int A[MAX], int N, int S[MAX2], int EPSILON)
{
	if (N == 0) return;

	int j, k, step;

	// ------ BASE CASE ------
	//Goal: We want 'goal' elements to be inserted into S, for now..
	int goal = 1;
	//How many elements have already been inserted, its 1 for efficiency
	int pos = 1;

	S[0] = A[0];//We insert element 0 at position 0

				//Initial size of array S
	int sLen = max((1 + EPSILON), goal + 1);

	// ------ CONDITION -------
	//What has already been read must be less than the total array size
	while (pos<N) {
		// ------ ROUND ------
		//Each round i will end with goal=2^i sorted elements. i starts with 1
		for (j = 0; j<goal; j++) {
			//Search where to insert A[pos] (with binary search)
			int insPos = searchFree(hdc, A[pos], S, sLen - 1);

			//Because our binary search returns us the location of an smaller item than the one we search...
			insPos++;
			if (!IS_EMPTY(S[insPos])) {//There is no place where we wanted to insert that element
				int nextFree = insPos + 1;//Search a free space forward
				while (!IS_EMPTY(S[nextFree])) nextFree++;
				//At 'nextFree' there is a place, translate all elements one position to the right
				if (nextFree >= sLen) {//Wait! nextFree is out of bounds
					insPos--;
					if (!IS_EMPTY(S[insPos])) {
						//Search backward
						nextFree = insPos - 1;
						while (!IS_EMPTY(S[nextFree])) nextFree--;
						//Now we translate all the elements to the left
						while (nextFree<insPos) {
							SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(0, 0, 0));
							std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

							S[nextFree] = S[nextFree + 1];

							SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(255, 0, 0));

							nextFree++;
						}
					}
				}
				else {
					//Now we translate all the elements to the right
					while (nextFree>insPos) {
						SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(0, 0, 0));
						std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

						S[nextFree] = S[nextFree - 1];

						SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(255, 0, 0));

						nextFree--;
					}
				}
				//Now nextFree is insPos; in other words, insPos is free
			}
			else if (insPos >= sLen) {//insPos is out of bounds
									  //Search a free space backwards
				insPos--;//This place must be between the limits
				int nextFree = insPos - 1;
				while (!IS_EMPTY(S[nextFree])) nextFree--;
				//Now we translate all the elements to the left
				while (nextFree<insPos) {
					SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(0, 0, 0));
					std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

					S[nextFree] = S[nextFree + 1];

					SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(255, 0, 0));

					nextFree++;
				}
				//Now nextFree is insPos; in other words insPos is free
			}

			SetPixel(hdc, insPos, 726 - S[insPos], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			S[insPos] = A[pos++];//We insert the element and increment our counter

			SetPixel(hdc, insPos, 726 - S[insPos], RGB(255, 0, 0));

			if (pos >= N)
				return;//That element was the last, return from the function
		}

		// ----- REBALANCE -----
		//It takes linear time. Tries to spread the elements as much as possible
		for (j = sLen - 1, k = min(goal*(2 + 2 * EPSILON), (1 + EPSILON)*N) - 1,
			step = (k + 1) / (j + 1); j >= 0; j--, k -= step) {

			SetPixel(hdc, k, 726 - S[k], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			S[k] = S[j];

			SetPixel(hdc, k, 726 - S[k], RGB(255, 0, 0));
			SetPixel(hdc, j, 726 - S[j], RGB(0, 0, 0));

			S[j] = NONE;
		}

		//In each round insert the double of elements to the sorted array
		// because there will be the double of free spaces after the rebalance
		sLen = min(goal*(2 + 2 * EPSILON), N*(1 + EPSILON));
		goal <<= 1;//We increment i
	}
}
extern "C" void librarySort(HDC hdc, int A[MAX], int n)
{
	int epsilon = 1;
	int S[MAX2];
	int sLen, i, j;
	//This takes linear time
	prepareLibrarySort(hdc, epsilon, n, S, &sLen);
	//O (n log n)
	libSort(hdc, A, n, S, epsilon);
	//This takes linear time
	for (i = 0, j = 0; i < sLen && j < n; i++)
	{
		if (!IS_EMPTY(S[i]))
		{
			SetPixel(hdc, j, 726 - A[j], RGB(0, 0, 0));
			SetPixel(hdc, i, 726 - S[i], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			A[j++] = S[i];

			SetPixel(hdc, j - 1, 726 - A[j - 1], RGB(255, 0, 0));
		}
	}
}
int * librarySortMain(HDC hdc, int(&arr)[726])
{
	int p[726];

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	if (setData && DATA_SET == MOSTLY_SORTED)
	{
		InsertionSortIndex(hdc, p, n);
	}
	else
	{
		librarySort(hdc, p, n);
	}
	
	return p;
}

int * flashSortMain(HDC hdc, int(&arr)[726])
{
	int p[726];

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	flashSort(hdc, p, n);
	return p;
}

void strandSort(HDC hdc, std::list<int> &ip, std::list<int> &op)
{
	if (ip.empty())
		return;

	// Create a sorted sublist with
	// first item of input list as
	// first item of the sublist
	std::list<int> sublist;
	sublist.push_back(ip.front());
	ip.pop_front();

	// Traverse remaining items of ip list
	for (auto it = ip.begin(); it != ip.end(); ) {

		// If current item of input list
		// is greater than last added item
		// to sublist, move current item
		// to sublist as sorted order is
		// maintained.
		if (*it > sublist.back()) {
			sublist.push_back(*it);

			SetPixel(hdc, sublist.size() - 1, 726 - sublist.back(), RGB(255, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			// erase() on list removes an
			// item and returns iterator to
			// next of removed item.
			it = ip.erase(it);
		}

		// Otherwise ignore current element
		else
			it++;
	}

	// Merge current sublist into output
	op.merge(sublist);

	// Recur for remaining items in
	// input and current items in op.
	strandSort(hdc, ip, op);
}

int * strandSortMain(HDC hdc, int(&arr)[726])
{
	int p[726];
	std::list<int> ip(726);
	std::list<int> op;

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		ip.push_back(i);
	}

	strandSort(hdc, ip, op);
	
	int index = 0;
	for (int x: op)
	{
		p[index] = x;
		index++;
	}

	return p;
}

int * pigeonholeSort(HDC hdc, int(&arr)[726])
{
	int p[726];

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	int min = p[0], max = p[0];
	for (int i = 1; i < n; i++)
	{
		if (p[i] < min)
			min = p[i];
		if (p[i] > max)
			max = p[i];
	}
	int range = max - min + 1; // Find range

							   // Create an array of vectors. Size of array
							   // range. Each vector represents a hole that
							   // is going to contain matching elements.
	std::vector<int> holes[726];

	// Traverse through input array and put every
	// element in its respective hole
	for (int i = 0; i < n; i++)
	{
		SetPixel(hdc, p[i] - min, 726 - p[i], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		holes[p[i] - min].push_back(p[i]);
		SetPixel(hdc, p[i] - min, 726 - p[i], RGB(255, 0, 0));
	}
		

	// Traverse through all holes one by one. For
	// every hole, take its elements and put in
	// array.
	int index = 0;  // index in sorted array
	for (int i = 0; i < range; i++)
	{
		std::vector<int>::iterator it; std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		for (it = holes[i].begin(); it != holes[i].end(); ++it)
		{
			SetPixel(hdc, index, 726 - p[index], RGB(0, 0, 0));
			p[index++] = *it;
			SetPixel(hdc, index - 1, 726 - p[index - 1], RGB(255, 0, 0));
		}
	}

	return p;
}

int * gravitySort(HDC hdc, int(&arr)[726])
{
	int p[726];
	int p2[726];
	int p3[726];

	int max = 0;
	int length = (sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
		p2[i] = arr[i];
		p3[i] == arr[i];
		if (p[i] > p[max])
		{
			max = i;
		}
	}

	int index = 0;

	while (p[max] > 0)
	{
		for (int i = 0; i < length; i += 1)
		{
			SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
			p[i] -= 1;
			SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
			if (p[i] == 0)
			{
				p3[index] = p2[i];
				std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
				SetPixel(hdc, i, 726 - p2[i], RGB(0, 0, 0));
				SetPixel(hdc, index, 726 - p3[index], RGB(255, 0, 0));
				index += 1;
			}

		}
	}

	for (int i = 1; i < 726; i += 1)
	{
		if (p3[i] > p3[i - 1])
		{
			SetPixel(hdc, i, 726 - p3[i], RGB(0, 255, 0));
		}
		else
		{
			SetPixel(hdc, i, 726 - p3[i], RGB(255, 0, 0));
		}
	}

	return p3;
}

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

int phi(unsigned int n)
{
	unsigned int result = 1;
	for (int i = 2; i < 726; i++)
		if (gcd(i, n) == 1)
			result++;
	return result;
}

int * histogramSort(HDC hdc, int(&arr)[726])
{
	int p[726];

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	int low, high, tempr, j;

	int out[726];
	int iwk[726];

	low = 0;
	high = n;
	j = 0;
	
	for (int i = low + 1; i < high; i++)
	{
		iwk[i] = 0;
	}

	iwk[low] = low - 1;

	for (int i = low; i < high; i++)
	{
		iwk[phi(p[i])]++;
	}
	for (int i = low; i < high - 1; i++)
	{
		iwk[i + 1] += iwk[i];
	}
	for (int i = high - 1; i >= low; i--)
	{
		SetPixel(hdc, iwk[phi(p[i])], 726 - out[iwk[phi(p[i])]], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

		out[iwk[phi(p[i])]--] = p[i];

		SetPixel(hdc, iwk[phi(p[i])] + 1, 726 - out[iwk[phi(p[i])] + 1], RGB(255, 0, 0));
	}
	for (int i = low; i < high; i++)
	{
		SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));

		p[i] = out[i];
	
		SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
	}
	for (int i = high - 2; i >= low; i--)
	{
		tempr = p[i];
		for (j = i + 1; j < high && (tempr > p[j]); j++)
		{
			SetPixel(hdc, j - 1, 726 - p[j - 1], RGB(0, 0, 0));
			//std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			p[j - 1] = p[j];
		
			SetPixel(hdc, j - 1, 726 - p[j - 1], RGB(255, 0, 0));
		}
		SetPixel(hdc, j - 1, 726 - p[j - 1], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

		p[j - 1] = tempr;

		SetPixel(hdc, j - 1, 726 - p[j - 1], RGB(255, 0, 0));
	}
	return p;
}

void runAlgo(HDC hdc, int algo)
{
	std::srand(time(NULL));

	if (algo == RANDOM_INTS || algo == MOSTLY_SORTED)
	{
		DATA_SET = algo;
		setData = true;
		switch (DATA_SET)
		{
		case MOSTLY_SORTED:
		{
			for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++)
			{
				data[i] = i;
			}
			for (int x = 0; x < 726; x++)
			{
				int randIndex = (std::rand() % 726) + 1;
				int randIndex2 = randIndex + 1;
				int temp = data[randIndex];
				data[randIndex] = data[randIndex2];
				data[randIndex2] = temp;
			}
			return;
		}
		default:
		{
			for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i += 1)
			{
				data[i] = (std::rand() % 726) + 1;
				for (int x = 0; x < i; x += 1)
				{
					if (data[i] == data[x])
					{
						i -= 1;
						continue;
					}
				}
			}
			return;
		}
		}
		
	}

	if (!setData)
	{
		setData = true;
		for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i += 1)
		{
			data[i] = (std::rand() % 726) + 1;
			for (int x = 0; x < i; x += 1)
			{
				if (data[i] == data[x])
				{
					i -= 1;
					continue;
				}
			}
		}
	}

	for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 0; y < 726; y += 1)
		{
		SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}

	for (int i = 0; i < 726; i += 1)
	{
		SetPixel(hdc, i, 726 - data[i], RGB(255, 0, 0));
	}
	
std::this_thread::sleep_for(std::chrono::seconds(SLEEP_TIME));

int * p;

switch (algo)
{
case 1:
	p = patienceSortMain(hdc, data);
	break;
case 2:
	p = quickSort(hdc, data, 0, 725);
	break;
case 3:
	p = treeSortMain(hdc, data);
	break;
case 4:
	p = shellSort(hdc, data);
	break;
case 5:
	p = histogramSort(hdc, data);
	break;
case 6:
	p = radixSort(hdc, data);
	break;
case 7:
	p = pigeonholeSort(hdc, data);
	break;
case 8:
	p = flashSortMain(hdc, data);
	break;
case 9:
	p = mergeSortMain(hdc, data);
	break;
case 10:
	p = heapSort(hdc, data);
	break;
case 11:
	p = radixMSDMain(hdc, data);
	break;
case 12:
	p = quickSortDualPivot(hdc, data);
	break;
case 13:
	p = bitonicSortMain(hdc, data);
	break;
case 14:
	p = threeWayQuicksortMain(hdc, data);
	break;
case 15:
	p = setSort(hdc, data);
	break;
case 16:
	p = strandSortMain(hdc, data);
	break;
case 17:
	p = slideSort(hdc, data);
	break;
case 18:
	p = insertionSort(hdc, data);
	break;
case 19:
	p = cocktailShaker(hdc, data);
	break;
case 20:
	p = librarySortMain(hdc, data);
	break;
case 999:
	startTournament(hdc);
default:
	p = gravitySort(hdc, data);
	break;
}

for (int i = 1; i < 726; i += 1)
{
	if (p[i] > p[i - 1])
	{
		SetPixel(hdc, i, 726 - p[i], RGB(0, 255, 0));
	}
	else
	{
		SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
	}
}

}

void startTournament(HDC hdc)
{
	createBracket(hdc);

	std::this_thread::sleep_for(std::chrono::seconds(5));

	//std::clock_t start;

	//start = std::clock();
	//double ms = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
}

void createBracket(HDC hdc)
{
	LPCWSTR names[] = { L"Gravity", L"Pigeonhole", L"Radix LSD", L"Flashsort", L"Dual pivot QS", L"Radix MSD", L"Quicksort", L"Shell", L"Bitonic", L"Merge", L"Heap", L"3-way QS", L"Set", L"Patience", L"Tree", L"Histogram" };
	LPCWSTR constNames[] = { L"Gravity", L"Patience", L"Quicksort", L"Tree", L"Shell", L"Histogram", L"Radix LSD", L"Pigeonhole", L"Flashsort", L"Merge", L"Heap", L"Radix MSD", L"Dual pivot QS", L"Bitonic", L"3-way QS", L"Set" };
	LPCWSTR round2Names[] = { L"", L"", L"", L"", L"", L"", L"", L"" };
	LPCWSTR round3Names[] = { L"", L"", L"", L""};
	LPCWSTR round4Names[] = { L"", L"" };
	LPCWSTR winner = L"";
	LPCWSTR upsets[] = { L"", L"", L"", L"", L"", L"", L"", L"", L"", L"", L"", L"", L"", L"", L"" };

	const int rankings[] = { 5, 13, 10, 16, 7, 4, 1, 2, 11, 12, 14, 8, 9, 15, 3, 6};

	int winBy[3][16];
	int round = 0;
	int fastestTime = 10000000;
	int upsetIndex = 0;

	if (DATA_SET == MOSTLY_SORTED)
	{
		LPCWSTR names[] = { L"Gravity", L"Pigeonhole", L"Radix LSD", L"Flashsort", L"Dual pivot QS", L"Radix MSD", L"Strand", L"Shell", L"Bitonic", L"Merge", L"Heap", L"3-way QS", L"Insertion", L"Patience", L"Cocktail", L"Histogram" };
		LPCWSTR constNames[] = { L"Gravity", L"Patience", L"Strand", L"Cocktail", L"Shell", L"Histogram", L"Radix LSD", L"Pigeonhole", L"Flashsort", L"Merge", L"Heap", L"Radix MSD", L"Dual pivot QS", L"Bitonic", L"3-way QS", L"Insertion" };

	}

	for (int i = 0; i < 3; i += 1)
	{
		for (int o = 0; o < 16; o += 1)
		{
			winBy[i][o] = 0;
		}
	}
	
	for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 0; y < 726; y += 1)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}

	std::srand(time(NULL));

	for (int i = 0; i < 16; i += 1)
	{
		int randIndex = (std::rand() % 15);
		LPCWSTR temp = names[i];
		names[i] = names[randIndex];
		names[randIndex] = temp;
	}

	int currentIndex = 0;

	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkMode(hdc, OPAQUE);

	for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 100; y < 726; y += 1)
		{
			if ((x < 160 && x > 0) && (y % 25 == 0) && y < 500)
			{
				SetPixel(hdc, x, y, RGB(255, 255, 255));
				if (currentIndex < 16)
				{
					TextOut(hdc, 0, y - 20, names[currentIndex], wcslen(names[currentIndex]));
					currentIndex += 1;
				}
				if (x == 159 && (y + 25) < 500 && (y % 50) == 0)
				{
					for (int i = 0; i < 25; i += 1)
					{
						SetPixel(hdc, x, y + i, RGB(255, 255, 255));
					}
				}
			}
			else if ((x < 320 && x > 160) && (y % 50 == 0) && y < 500)
			{
				SetPixel(hdc, x, y + 12, RGB(255, 255, 255));
				if (x == 319 && (y + 62) < 500 && (y % 100) == 0)
				{
					for (int i = 0; i < 50; i += 1)
					{
						SetPixel(hdc, x, y + 12 + i, RGB(255, 255, 255));
					}
				}
			}
			else if ((x < 480 && x > 320) && (y % 100 == 0) && y < 500)
			{
				SetPixel(hdc, x, y + 37, RGB(255, 255, 255));
				if (x == 479 && (y + 137) < 500 && ((y + 100) % 200) == 0)
				{
					for (int i = 0; i < 100; i += 1)
					{
						SetPixel(hdc, x, y + 37 + i, RGB(255, 255, 255));
					}
				}
			}
			else if ((x < 640 && x > 480) && (y % 200 == 0) && y < 500)
			{
				SetPixel(hdc, x, y - 12, RGB(255, 255, 255));
				if (x == 639 && (y + 188) < 500 && (y % 400) == 0)
				{
					for (int i = 0; i < 200; i += 1)
					{
						SetPixel(hdc, x, y - 12 + i, RGB(255, 255, 255));
					}
				}
			}
		}
	}

	std::this_thread::sleep_for(std::chrono::seconds(4));

	int round2Index = 0;
	double ms1 = 0;
	double ms2 = 0;
	LPCWSTR m1 = L"";
	LPCWSTR m2 = L"";
	std::clock_t start;

	int constNamesIndex1, constNamesIndex2;

	for (int i = 0; i < 15; i += 2)
	{
		for (int o = 0; o < 16; o += 1)
		{
			if (names[i] == constNames[o])
			{
				constNamesIndex1 = o;
				start = std::clock();
				runAlgo(hdc, o);
				ms1 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m1 = constNames[o];
			}
			if (names[i + 1] == constNames[o])
			{
				constNamesIndex2 = o;
				start = std::clock();
				runAlgo(hdc, o);
				ms2 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m2 = constNames[o];
			}
		}
		if (ms1 > 0 && ms2 > 0)
		{
			if (ms1 > ms2)
			{
				round2Names[round2Index] = m2;
				winBy[round][round2Index] = ms1 - ms2;

				round2Index += 1;

				if (ms2 < fastestTime)
					fastestTime = ms2;

				if (rankings[constNamesIndex2] > rankings[constNamesIndex1])
				{
					Upset currentUpset;

					upsets[upsetIndex] = concatted;
					upsetIndex++;
				}
			}
			else
			{
				round2Names[round2Index] = m1;
				winBy[round][round2Index] = ms2 - ms1;

				round2Index += 1;
				if (ms1 < fastestTime)
					fastestTime = ms1;

				if (rankings[constNamesIndex1] > rankings[constNamesIndex2])
				{
					std::wstring m1String(m1);
					std::wstring m2String(m2);

					std::wstring concatted_stdstr = m1String + L" over " + m2String + L" by " + tempWinString;
					LPCWSTR concatted = m1;

					upsets[upsetIndex] = concatted;
					upsetIndex++;
				}
			}
		}
		updateBracket(hdc, names, constNames, round2Names, round3Names, round4Names, winner, winBy, fastestTime);
		std::this_thread::sleep_for(std::chrono::seconds(4));
	}

	int round3Index = 0;
	ms1 = 0;
	ms2 = 0;
	m1 = L"";
	m2 = L"";
	round += 1;

	for (int i = 0; i < 7; i += 2)
	{
		for (int o = 0; o < 16; o += 1)
		{
			if (round2Names[i] == constNames[o])
			{
				constNamesIndex1 = o;
				start = std::clock();
				runAlgo(hdc, o);
				ms1 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m1 = constNames[o];
			}
			if (round2Names[i + 1] == constNames[o])
			{
				constNamesIndex2 = 0;
				start = std::clock();
				runAlgo(hdc, o);
				ms2 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m2 = constNames[o];
			}
		}
		if (ms1 > 0 && ms2 > 0)
		{
			if (ms1 > ms2)
			{
				round3Names[round3Index] = m2;
				winBy[round][round3Index] = ms1 - ms2;

				round3Index += 1;
				if (ms2 < fastestTime)
					fastestTime = ms2;

				if (rankings[constNamesIndex2] > rankings[constNamesIndex1])
				{
					std::wstring m1String(m1);
					std::wstring m2String(m2);

					std::wstring concatted_stdstr = m2String + L" over " + m1String + L" by " + tempWinString;
					LPCWSTR concatted = m2;

					upsets[upsetIndex] = concatted;
					upsetIndex++;
				}
			}
			else
			{
				round3Names[round3Index] = m1;
				winBy[round][round3Index] = ms2 - ms1;

				round3Index += 1;
				if (ms1 < fastestTime)
					fastestTime = ms1;

				if (rankings[constNamesIndex1] > rankings[constNamesIndex2])
				{
					std::wstring m1String(m1);
					std::wstring m2String(m2);

					std::wstring concatted_stdstr = m1String + L" over " + m2String + L" by " + tempWinString;
					LPCWSTR concatted = m1;

					upsets[upsetIndex] = concatted;
					upsetIndex++;
				}
			}
		}
		updateBracket(hdc, names, constNames, round2Names, round3Names, round4Names, winner, winBy, fastestTime);
		std::this_thread::sleep_for(std::chrono::seconds(4));
	}

	int round4Index = 0;
	ms1 = 0;
	ms2 = 0;
	m1 = L"";
	m2 = L"";
	round += 1;

	for (int i = 0; i < 3; i += 2)
	{
		for (int o = 0; o < 16; o += 1)
		{
			if (round3Names[i] == constNames[o])
			{
				start = std::clock();
				runAlgo(hdc, o);
				ms1 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m1 = constNames[o];
			}
			if (round3Names[i + 1] == constNames[o])
			{
				start = std::clock();
				runAlgo(hdc, o);
				ms2 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m2 = constNames[o];
			}
		}
		if (ms1 > 0 && ms2 > 0)
		{
			if (ms1 > ms2)
			{
				round4Names[round4Index] = m2;
				winBy[round][round4Index] = ms1 - ms2;
				round4Index += 1;
				if (ms2 < fastestTime)
					fastestTime = ms2;
			}
			else
			{
				round4Names[round4Index] = m1;
				winBy[round][round4Index] = ms2 - ms1;
				round4Index += 1;
				if (ms1 < fastestTime)
					fastestTime = ms1;
			}
		}
		updateBracket(hdc, names, constNames, round2Names, round3Names, round4Names, winner, winBy, fastestTime);
		std::this_thread::sleep_for(std::chrono::seconds(4));
	}

	ms1 = 0;
	ms2 = 0;
	m1 = L"";
	m2 = L"";

	for (int o = 0; o < 16; o += 1)
	{
		if (round4Names[0] == constNames[o])
		{
			start = std::clock();
			runAlgo(hdc, o);
			ms1 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
			m1 = constNames[o];
		}
		if (round4Names[1] == constNames[o])
		{
			start = std::clock();
			runAlgo(hdc, o);
			ms2 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
			m2 = constNames[o];
		}
	}
	if (ms1 > 0 && ms2 > 0)
	{
		if (ms1 > ms2)
		{
			winner = m2;
			winBy[2][10] = ms1 - ms2;
			if (ms2 < fastestTime)
				fastestTime = ms2;
		}
		else
		{
			winner = m1;
			winBy[2][10] = ms2 - ms1;
			if (ms1 < fastestTime)
				fastestTime = ms1;
		}
	}
	updateBracket(hdc, names, constNames, round2Names, round3Names, round4Names, winner, winBy, fastestTime);
	std::this_thread::sleep_for(std::chrono::seconds(60));
	drawUpsets(hdc, upsets);
}

void updateBracket(HDC hdc, LPCWSTR names[], LPCWSTR constNames[], LPCWSTR round2Names[], LPCWSTR round3Names[], LPCWSTR round4Names[], LPCWSTR winner, int winBy[][16], int fastestTime)
{
	int currentIndex = 0;
	int currentIndex2 = 0;
	int currentIndex3 = 0;
	int currentIndex4 = 0;

	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkMode(hdc, OPAQUE);
	
	for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 100; y < 726; y += 1)
		{
			if ((x < 160 && x > 0) && (y % 25 == 0) && y < 500)
			{
				SetPixel(hdc, x, y, RGB(255, 255, 255));
				if (currentIndex < 16)
				{
					TextOut(hdc, 0, y - 20, names[currentIndex], wcslen(names[currentIndex]));
					currentIndex += 1;
				}
				if (x == 159 && (y + 25) < 500 && (y % 50) == 0)
				{
					for (int i = 0; i < 25; i += 1)
					{
						SetPixel(hdc, x, y + i, RGB(255, 255, 255));
					}
				}
			}
			else if ((x < 320 && x > 160) && (y % 50 == 0) && y < 500)
			{
				SetPixel(hdc, x, y + 12, RGB(255, 255, 255));
				if (currentIndex2 < 8)
				{
					TextOut(hdc, 160, y - 5, round2Names[currentIndex2], wcslen(round2Names[currentIndex2]));
					if (winBy[0][currentIndex2] > 0)
					{
						wchar_t buffer[256];
						wsprintfW(buffer, L"%d", winBy[0][currentIndex2]);
						LPCWSTR winByString = buffer;
						TextOut(hdc, 160, y + 15, winByString, wcslen(winByString));
					}
					currentIndex2 += 1;
				}
				if (x == 319 && (y + 62) < 500 && (y % 100) == 0)
				{
					for (int i = 0; i < 50; i += 1)
					{
						SetPixel(hdc, x, y + 12 + i, RGB(255, 255, 255));
					}
				}
			}
			else if ((x < 480 && x > 320) && (y % 100 == 0) && y < 500)
			{
				SetPixel(hdc, x, y + 37, RGB(255, 255, 255));
				if (currentIndex3 < 4)
				{
					TextOut(hdc, 320, y + 20, round3Names[currentIndex3], wcslen(round3Names[currentIndex3]));
					if (winBy[1][currentIndex3] > 0)
					{
						wchar_t buffer[256];
						wsprintfW(buffer, L"%d", winBy[1][currentIndex3]);
						LPCWSTR winByString = buffer;
						TextOut(hdc, 320, y + 35, winByString, wcslen(winByString));
					}
					currentIndex3 += 1;
				}
				if (x == 479 && (y + 137) < 500 && ((y + 100) % 200) == 0)
				{
					for (int i = 0; i < 100; i += 1)
					{
						SetPixel(hdc, x, y + 37 + i, RGB(255, 255, 255));
					}
				}
			}
			else if ((x < 640 && x > 480) && (y % 200 == 0) && y < 500)
			{
				SetPixel(hdc, x, y - 12, RGB(255, 255, 255));
				if (currentIndex4 < 2)
				{
					TextOut(hdc, 480, y - 27, round4Names[currentIndex4], wcslen(round4Names[currentIndex4]));
					if (winBy[2][currentIndex4] > 0)
					{
						wchar_t buffer[256];
						wsprintfW(buffer, L"%d", winBy[2][currentIndex4]);
						LPCWSTR winByString = buffer;
						TextOut(hdc, 480, y - 7, winByString, wcslen(winByString));
					}
					currentIndex4 += 1;
				}
				if (x == 639 && (y + 188) < 500 && (y % 400) == 0)
				{
					for (int i = 0; i < 200; i += 1)
					{
						SetPixel(hdc, x, y - 12 + i, RGB(255, 255, 255));
					}
				}
			}
		}
		if (winBy[2][10] > 0)
		{
			TextOut(hdc, 10, 600, winner, wcslen(winner));
			wchar_t buffer[256];
			wsprintfW(buffer, L"%d", winBy[2][10]);
			LPCWSTR winByString = buffer;
			TextOut(hdc, 10, 630, winByString, wcslen(winByString));

			int maxWin = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (winBy[i][j] > maxWin)
						maxWin = winBy[i][j];
				}
			}

			TextOut(hdc, 190, 600, L"Biggest win difference:", wcslen(L"Biggest win difference:"));
			wchar_t buffer2[256];
			wsprintfW(buffer2, L"%d", maxWin);
			LPCWSTR winByString2 = buffer2;
			TextOut(hdc, 190, 630, winByString2, wcslen(winByString2));

			int minWin = 10000000000;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (winBy[i][j] != 0 && winBy[i][j] < minWin)
						minWin = winBy[i][j];
				}
			}

			TextOut(hdc, 350, 600, L"Smallest win difference:", wcslen(L"Smallest win difference:"));
			wchar_t buffer3[256];
			wsprintfW(buffer3, L"%d", minWin);
			LPCWSTR winByString3 = buffer3;
			TextOut(hdc, 350, 630, winByString3, wcslen(winByString3));
		}
		TextOut(hdc, 550, 600, L"Best time so far:", wcslen(L"Best time so far:"));
		wchar_t buffer4[256];
		wsprintfW(buffer4, L"%d", fastestTime);
		LPCWSTR winByString4 = buffer4;
		TextOut(hdc, 550, 630, winByString4, wcslen(winByString4));
	}
}

void drawUpsets(HDC hdc, Upset upsets[])
{
	for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 0; y < 726; y += 1)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}
	
	int y = 10;

	for (int i = 0; i < 16; i++)
	{
		if (upsets[i] != L"")
		{
			TextOut(hdc, 200, y, upsets[i], wcslen(upsets[i]));
			y += 30;
		}
	}

	std::this_thread::sleep_for(std::chrono::seconds(5000));
}
void destroyAllButtons()
{
	DestroyWindow(hwndButton);
	DestroyWindow(hwndButton2);
	DestroyWindow(hwndButton3);
	DestroyWindow(hwndButton4);
	DestroyWindow(hwndButton5);
	DestroyWindow(hwndButton6);
	DestroyWindow(hwndButton7);
	DestroyWindow(hwndButton8);
	DestroyWindow(hwndButton9);
	DestroyWindow(hwndButton10);
	DestroyWindow(hwndButton11);
	DestroyWindow(hwndButton12);
	DestroyWindow(hwndButton13);
	DestroyWindow(hwndButton14);
	DestroyWindow(hwndButton15);
	DestroyWindow(hwndButton16);
	DestroyWindow(hwndButton17);
	DestroyWindow(hwndButton18);
	DestroyWindow(hwndButton19);
	DestroyWindow(hwndButton20);
	DestroyWindow(hwndButton21);
	DestroyWindow(hwndButton22);
	DestroyWindow(hwndButton23);
	DestroyWindow(hwndButton24);
	DestroyWindow(hwndButton25);
}