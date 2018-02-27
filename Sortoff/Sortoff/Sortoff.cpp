#include "stdafx.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include "Sortoff.h"
#include <thread>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

VOID OnPaint(HDC hdc)
{
	SetBkMode(hdc, OPAQUE);
	
	for (int x = 0; x < 1441; x += 1)
	{
		for (int y = 0; y < 726; y += 1)
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}

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
		L"Selection sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		10,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 1,       // Algorithm number.
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
		(HMENU) 3,       // Algorithm number.
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
		switch(LOWORD(wParam))
		{
		case 1:
		{
			destroyAllButtons();
			hdc = BeginPaint(hWnd, &ps);
			OnPaint(hdc);

			runAlgo(hdc, wParam);

			EndPaint(hWnd, &ps);
			return 0;
		}
		case 2:
		{
			destroyAllButtons();
			hdc = BeginPaint(hWnd, &ps);
			OnPaint(hdc);

			runAlgo(hdc, wParam);

			EndPaint(hWnd, &ps);
			return 0;
		}
		case 3:
		{
			destroyAllButtons();
			hdc = BeginPaint(hWnd, &ps);
			OnPaint(hdc);

			runAlgo(hdc, wParam);

			EndPaint(hWnd, &ps);
			return 0;
		}
		default:
		{
			destroyAllButtons();
			hdc = BeginPaint(hWnd, &ps);
			OnPaint(hdc);

			runAlgo(hdc, wParam);

			EndPaint(hWnd, &ps);
			return 0;
		}
		}
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
			arr[i] = arr[j];
			arr[j] = temp;
			for (int y = 0; y < 726; y += 1)
			{
				if (y != arr[i])
				{
					SetPixel(hdc, i, 726 - y, RGB(0, 0, 0));
				}
				else
				{
					SetPixel(hdc, i, 726 - y, RGB(255, 0, 0));
				}
			}
			for (int y = 0; y < 726; y += 1)
			{
				if (y != arr[j])
				{
					SetPixel(hdc, j, 726 - y, RGB(0, 0, 0));
				}
				else
				{
					SetPixel(hdc, j, 726 - y, RGB(255, 0, 0));
				}
			}
		}
	}

	// DISPLAY

	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	for (int y = 0; y < 726; y += 1)
	{
		if (y != arr[i])
		{
			SetPixel(hdc, i, 726 - y, RGB(0, 0, 0));
		}
		else
		{
			SetPixel(hdc, i, 726 - y, RGB(255, 0, 0));
		}
	}

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
	
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int part = partition(hdc, p, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort2(hdc, p, low, part - 1);
		quickSort2(hdc, p, part + 1, high);
		/*for (int i = low - 1; i <= high; i += 1)
		{
			for (int y = 0; y < 726; y += 1)
			{
				if (y != arr[i])
				{
					SetPixel(hdc, i, 726 - y, RGB(0, 0, 0));
				}
			}
		}*/
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
		for (int i = low - 1; i <= part + 1; i += 1)
		{
			for (int y = 0; y < 726; y += 1)
			{
				if (y != arr[i])
				{
					if ((GetPixel(hdc, i, 726 - y) == RGB(255, 0, 0)))
					{
						SetPixel(hdc, i, 726 - y, RGB(0, 0, 0));
					}
				}
				else
				{
					SetPixel(hdc, i, 726 - y, RGB(255, 0, 0));
					continue;
				}
			}
		}
	}
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
			p[i] -= 1;
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

void runAlgo(HDC hdc, int algo)
{
	int data[726];

	std::srand(time(NULL));

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

	for (int i = 0; i < 726; i += 1)
	{
		SetPixel(hdc, i, 726 - data[i], RGB(255, 0, 0));
	}
	
	std::this_thread::sleep_for(std::chrono::seconds(SLEEP_TIME));

	int * p;

	switch (algo)
	{
	case 1:
		p = selectionSort(hdc, data);
		break;
	case 2:
		p = quickSort(hdc, data, 0, 725);
		break;
	case 3:
		p = insertionSort(hdc, data);
		break;
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

void destroyAllButtons()
{
	DestroyWindow(hwndButton);
	DestroyWindow(hwndButton2);
	DestroyWindow(hwndButton3);
	DestroyWindow(hwndButton4);
	DestroyWindow(hwndButton5);
}