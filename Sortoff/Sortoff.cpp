#include "stdafx.h"
#include <list>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <ctime>
#include "Algorithms.h"
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
		(HMENU) 21,       // Algorithm number.
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
		550,         // y position 
		735,        // Button width
		215,        // Button height
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

	hwndButton26 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Adaptive left radix",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		410,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 4,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton27 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Already sorted",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		460,         // x position 
		410,         // y position 
		120,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) ALREADY_SORTED,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton28 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Reverse order",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		580,         // x position 
		410,         // y position 
		120,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) REVERSE_ORDER,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton29 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Skewed distribution",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		310,         // x position 
		410,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) CUBIC_SKEWED,       // Algorithm number.
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
		if (wParam != RANDOM_INTS && wParam != MOSTLY_SORTED && wParam != ALREADY_SORTED && wParam != REVERSE_ORDER && wParam != CUBIC_SKEWED)
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

void runAlgo(HDC hdc, int algo)
{
	std::srand(time(NULL));

	if (algo >= RANDOM_INTS)
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
			for (int x = 0; x < 109; x++)
			{
				int randIndex = (std::rand() % 726) + 1;
				int randIndex2 = (std::rand() % 726) + 1;
				int temp = data[randIndex];
				data[randIndex] = data[randIndex2];
				data[randIndex2] = temp;
			}
			return;
		}
		case ALREADY_SORTED:
		{
			for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++)
				data[i] = i;
			return;
		}
		case REVERSE_ORDER:
		{
			for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++)
				data[i] = 726 - i;
			return;
		}
		case CUBIC_SKEWED:
		{
			for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) // skew data
			{
				double x = (2.0 * (double)i / (sizeof(data) / sizeof(data[0]))) - 1.0;
				double v = x * x * x;
				double w = (v + 1.0) / 2.0 * (sizeof(data) / sizeof(data[0])) + 1;
				data[i] = w;
			}

			for (int i = 0; i < (sizeof(data) / sizeof(data[0])) * 2; i += 1) // randomize order
			{
				int randIndex = (std::rand() % 726) + 1;
				int randIndex2 = (std::rand() % 726) + 1;
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
	p = adaptiveRadixLeft(hdc, data);
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
case 21:
	p = shellSort(hdc, data);
	break;
//case 22:
//	p = pal::radix_sort(hdc, data); // parallel radix
//	break;
case 999:
	startTournament(hdc);
	std::this_thread::sleep_for(std::chrono::seconds(100000));
default:
	p = gravitySort(hdc, data);
	break;
}

for (int i = 1; i < 726; i += 1)
{
	if (p[i] >= p[i - 1])
	{
		SetPixel(hdc, i, 726 - p[i], RGB(0, 255, 0));
	}
	else
	{
		SetPixel(hdc, i, 726 - p[i], RGB(0, 255, 255));
	}
}

}

void startTournament(HDC hdc)
{
	createBracket(hdc);

	std::this_thread::sleep_for(std::chrono::seconds(10000000000000000000));

	//std::clock_t start;

	//start = std::clock();
	//double ms = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
}

void createBracket(HDC hdc)
{
	// unseeded
	LPCWSTR names[] = { L"Gravity", L"Patience", L"Quicksort", L"Tree", L"Adaptive left radix", L"Histogram", L"Radix LSD", L"Pigeonhole", L"Flashsort", L"Merge", L"Heap", L"Radix MSD", L"Dual pivot QS", L"Bitonic", L"3-way QS", L"Set" };
	// seeded
	//LPCWSTR names[] = { L"Pigeonhole", L"Tree", L"Dual pivot QS", L"Radix MSD", L"Set", L"Merge", L"Heap", L"Radix LSD", L"3-way QS", L"Patience", L"Gravity", L"Quicksort", L"Histogram", L"Bitonic", L"Shell", L"Flashsort" };
	LPCWSTR constNames[] = { L"Gravity", L"Patience", L"Quicksort", L"Tree", L"Adaptive left radix", L"Histogram", L"Radix LSD", L"Pigeonhole", L"Flashsort", L"Merge", L"Heap", L"Radix MSD", L"Dual pivot QS", L"Bitonic", L"3-way QS", L"Set" };
	LPCWSTR round2Names[] = { L"", L"", L"", L"", L"", L"", L"", L"" };
	LPCWSTR round3Names[] = { L"", L"", L"", L""};
	LPCWSTR round4Names[] = { L"", L"" };
	LPCWSTR winner = L"";
	std::vector<Upset> upsets;

	const int rankings[] = { 7, 15, 12, 16, 1, 8, 5, 2, 3, 13, 14, 9, 10, 11, 4, 6};

	int winBy[3][16];
	int round = 0;
	int fastestTime = 10000000;
	int standardTime = 430000; // ~430000 for 2ms sleep time

	//if (DATA_SET == MOSTLY_SORTED)
	//{
	//	LPCWSTR names[] = { L"Pigeonhole", L"Tree", L"Dual pivot QS", L"Radix MSD", L"Set", L"Merge", L"Heap", L"Radix LSD", L"3-way QS", L"Patience", L"Gravity", L"Quicksort", L"Histogram", L"Bitonic", L"Shell", L"Flashsort" };
	//	LPCWSTR constNames[] = { L"Gravity", L"Patience", L"Strand", L"Cocktail", L"Adaptive left radix", L"Histogram", L"Radix LSD", L"Pigeonhole", L"Flashsort", L"Merge", L"Heap", L"Radix MSD", L"Dual pivot QS", L"Bitonic", L"3-way QS", L"Insertion" };

	//}

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

	// comment out for a seeded tournament
	for (int i = 0; i < 16; i += 1)
	{
		int randindex = (std::rand() % 15);
		LPCWSTR temp = names[i];
		names[i] = names[randindex];
		names[randindex] = temp;
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
	std::clock_t mainStart = std::clock();

	int constNamesIndex1, constNamesIndex2;

	for (int i = 0; i < 15; i += 2)
	{
		for (int o = 0; o < 16; o += 1)
		{
			if (cStrEquals(names[i], constNames[o]))
			{
				constNamesIndex1 = o;
				start = std::clock();
				runAlgo(hdc, o);
				ms1 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m1 = constNames[o];
				if ((cStrEquals(L"Set", names[i]) || cStrEquals(L"Tree", names[i])) && DATA_SET == CUBIC_SKEWED)
					ms1 = INT_MAX;
			}
			if (cStrEquals(names[i + 1], constNames[o]))
			{
				constNamesIndex2 = o;
				start = std::clock();
				runAlgo(hdc, o);
				ms2 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m2 = constNames[o];
				if ((cStrEquals(L"Set", names[i]) || cStrEquals(L"Tree", names[i])) && DATA_SET == CUBIC_SKEWED)
					ms2 = INT_MAX;
			}
		}
		if (ms1 > 0 && ms2 > 0)
		{
			if (ms1 > ms2)
			{
				round2Names[round2Index] = m2;
				winBy[round][round2Index] = ms1 - ms2;

				if (ms1 == INT_MAX)
					winBy[round][round2Index] = 99999;

				round2Index += 1;

				if (ms2 < fastestTime)
					fastestTime = ms2;

				if (rankings[constNamesIndex2] > rankings[constNamesIndex1])
				{
					Upset upset;
					upsets.push_back(upset);
					upsets.back().setValues(m2, m1, rankings[constNamesIndex2], rankings[constNamesIndex1], ms1 - ms2);
				}
			}
			else
			{
				round2Names[round2Index] = m1;
				winBy[round][round2Index] = ms2 - ms1;

				if (ms2 == INT_MAX)
					winBy[round][round2Index] = 99999;

				round2Index += 1;
				if (ms1 < fastestTime)
					fastestTime = ms1;

				if (rankings[constNamesIndex1] > rankings[constNamesIndex2])
				{
					Upset upset;
					upsets.push_back(upset);
					upsets.back().setValues(m1, m2, rankings[constNamesIndex1], rankings[constNamesIndex2], ms2 - ms1);
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
			if (cStrEquals(round2Names[i], constNames[o]))
			{
				constNamesIndex1 = o;
				start = std::clock();
				runAlgo(hdc, o);
				ms1 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m1 = constNames[o];
			}
			if (cStrEquals(round2Names[i + 1], constNames[o]))
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
				round3Names[round3Index] = m2;
				winBy[round][round3Index] = ms1 - ms2;

				round3Index += 1;
				if (ms2 < fastestTime)
					fastestTime = ms2;

				if (rankings[constNamesIndex2] > rankings[constNamesIndex1])
				{
					Upset upset;
					upsets.push_back(upset);
					upsets.back().setValues(m2, m1, rankings[constNamesIndex2], rankings[constNamesIndex1], ms1 - ms2);
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
					Upset upset;
					upsets.push_back(upset);
					upsets.back().setValues(m1, m2, rankings[constNamesIndex1], rankings[constNamesIndex2], ms2 - ms1);
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
			if (cStrEquals(round3Names[i], constNames[o]))
			{
				constNamesIndex1 = o;
				start = std::clock();
				runAlgo(hdc, o);
				ms1 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
				m1 = constNames[o];
			}
			if (cStrEquals(round3Names[i + 1], constNames[o]))
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
				round4Names[round4Index] = m2;
				winBy[round][round4Index] = ms1 - ms2;

				round4Index += 1;
				if (ms2 < fastestTime)
					fastestTime = ms2;

				if (rankings[constNamesIndex2] > rankings[constNamesIndex1])
				{
					Upset upset;
					upsets.push_back(upset);
					upsets.back().setValues(m2, m1, rankings[constNamesIndex2], rankings[constNamesIndex1], ms1 - ms2);
				}
			}
			else
			{
				round4Names[round4Index] = m1;
				winBy[round][round4Index] = ms2 - ms1;
				round4Index += 1;
				if (ms1 < fastestTime)
					fastestTime = ms1;

				if (rankings[constNamesIndex1] > rankings[constNamesIndex2])
				{
					Upset upset;
					upsets.push_back(upset);
					upsets.back().setValues(m1, m2, rankings[constNamesIndex1], rankings[constNamesIndex2], ms2 - ms1);
				}
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
		if (cStrEquals(round4Names[0], constNames[o]))
		{
			constNamesIndex1 = o;
			start = std::clock();
			runAlgo(hdc, o);
			ms1 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
			m1 = constNames[o];
		}
		if (cStrEquals(round4Names[1], constNames[o]))
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
			winner = m2;
			winBy[2][10] = ms1 - ms2;

			if (ms2 < fastestTime)
				fastestTime = ms2;

			if (rankings[constNamesIndex2] > rankings[constNamesIndex1])
			{
				Upset upset;
				upsets.push_back(upset);
				upsets.back().setValues(m2, m1, rankings[constNamesIndex2], rankings[constNamesIndex1], ms1 - ms2);
			}
		}
		else
		{
			winner = m1;
			winBy[2][10] = ms2 - ms1;
			if (ms1 < fastestTime)
				fastestTime = ms1;

			if (rankings[constNamesIndex1] > rankings[constNamesIndex2])
			{
				Upset upset;
				upsets.push_back(upset);
				upsets.back().setValues(m1, m2, rankings[constNamesIndex1], rankings[constNamesIndex2], ms2 - ms1);
			}
		}
	}

	int mainTime = ((std::clock() - mainStart) / (double)(CLOCKS_PER_SEC / 1000));
	int deviation = abs(mainTime - standardTime);
	deviation = (((double)(deviation)) / ((double)(standardTime))) * 100;

	wchar_t devBuffer[256];
	wsprintfW(devBuffer, L"%d", deviation);
	LPCWSTR devString = devBuffer;

	updateBracket(hdc, names, constNames, round2Names, round3Names, round4Names, winner, winBy, fastestTime);
	std::this_thread::sleep_for(std::chrono::seconds(20));
	drawUpsets(hdc, upsets);
	std::this_thread::sleep_for(std::chrono::seconds(15));
	for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 0; y < 726; y += 1)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}
	updateBracket(hdc, names, constNames, round2Names, round3Names, round4Names, winner, winBy, fastestTime);

	TextOut(hdc, 400, 500, L"Seeding deviation: ", wcslen(L"Seeding deviation: "));
	TextOut(hdc, 550, 500, devString, wcslen(devString));
	TextOut(hdc, 580, 500, L"%", wcslen(L"%"));
	// last textout doesnt show for whatever reason
	TextOut(hdc, 0, 0, L" ", wcslen(L" "));

	std::this_thread::sleep_for(std::chrono::seconds(100000));
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
					if (winBy[i][j] > maxWin && winBy[i][j] != 99999)
						maxWin = winBy[i][j];
				}
			}

			TextOut(hdc, 190, 600, L"Biggest win difference:", wcslen(L"Biggest win difference:"));
			wchar_t buffer2[256];
			wsprintfW(buffer2, L"%d", maxWin);
			LPCWSTR winByString2 = buffer2;
			TextOut(hdc, 190, 630, winByString2, wcslen(winByString2));

			int minWin = INT_MAX;
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

void drawUpsets(HDC hdc, std::vector<Upset> upsets)
{
	for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 0; y < 726; y += 1)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}
	
	int y = 10;

	for (int i = 0; i < upsets.size(); i++)
	{
		wchar_t buffer1[256];
		wsprintfW(buffer1, L"%d", upsets[i].getWinnerRank());
		LPCWSTR winByStringW = buffer1;

		wchar_t buffer2[256];
		wsprintfW(buffer2, L"%d", upsets[i].getLoserRank());
		LPCWSTR winByStringL = buffer2;

		wchar_t buffer3[256];
		wsprintfW(buffer3, L"%d", upsets[i].getWinDifference());
		LPCWSTR winByStringT = buffer3;

		TextOut(hdc, 50, y, upsets[i].getWinner(), wcslen(upsets[i].getWinner()));
		TextOut(hdc, 150, y, winByStringW, wcslen(winByStringW));
		TextOut(hdc, 200, y, L" over ", wcslen(L" over "));
		TextOut(hdc, 300, y, upsets[i].getLoser(), wcslen(upsets[i].getLoser()));
		TextOut(hdc, 450, y, winByStringL, wcslen(winByStringL));
		TextOut(hdc, 500, y, L" by ", wcslen(L" by "));
		TextOut(hdc, 550, y, winByStringT, wcslen(winByStringT));

		// last textout doesnt show for whatever reason
		TextOut(hdc, 0, 0, L" ", wcslen(L" "));

		y += 30;
	}
}

bool cStrEquals(LPCWSTR strOne, LPCWSTR strTwo)
{
	if (lstrlen(strOne) == lstrlen(strTwo))
	{
		for (int i = 0; i < lstrlen(strOne); i++)
		{
			if (!(strOne[i] == strTwo[i]))
				return false;
		}

		return true;
	}

	return false;
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
	DestroyWindow(hwndButton26);
	DestroyWindow(hwndButton27);
	DestroyWindow(hwndButton28);
	DestroyWindow(hwndButton29);
}
