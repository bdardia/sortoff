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
		(HMENU) 5,       // Algorithm number.
		(HINSTANCE)GetWindowLong(hWnd, (int)hInstance),
		NULL);      // Pointer not needed.

	hwndButton8 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Radix sort",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		110,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU) 6,       // Algorithm number.
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
		destroyAllButtons();
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
			temp[(count[((p[i]) / place) % 10]) - 1] = p[i];
			count[(p[i] / place) % 10] -= 1;
		}

		for (int i = 0; i < n; i += 1)
		{
			SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
			p[i] = temp[i];
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
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
	case 4:
		p = shellSort(hdc, data);
		break;
	case 5:
		p = cocktailShaker(hdc, data);
		break;
	case 6:
		p = radixSort(hdc, data);
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
	DestroyWindow(hwndButton6);
	DestroyWindow(hwndButton7);
	DestroyWindow(hwndButton8);
}