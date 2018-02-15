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
	int			 msgboxID;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		OnPaint(hdc);

		msgboxID = MessageBox(
			NULL,
			L"Selection sort?",
			L"",
			MB_ICONEXCLAMATION | MB_YESNOCANCEL
		);
		switch (msgboxID)
		{
		case IDYES:
			runAlgo(hdc, 1);
			break;
		case IDNO:
			runAlgo(hdc, 2);
			break;
		case IDCANCEL:
			runAlgo(hdc, 3);
			break;
		}
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
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
			bool flip = false;
			if (p[j] < p[min_idx])
			{
				for (int y = 0; y < p[min_idx]; y += 1)
				{
					SetPixel(hdc, min_idx, 726 - y, RGB(0, 0, 0));
				}
				min_idx = j;
				for (int y = 0; y < p[min_idx]; y += 1)
				{
					SetPixel(hdc, min_idx, 726 - y, RGB(0, 255, 0));
				}
				flip = true;
			}
				
			
			// add line
			if (!flip)
			{
				for (int y = 0; y < p[j]; y += 1)
				{
					SetPixel(hdc, j, 726 - y, RGB(255, 255, 255));
				}
				for (int y = 0; y < p[j]; y += 1)
				{
					SetPixel(hdc, j, 726 - y, RGB(0, 0, 0));
				}

			}
			flip = false;
			/*SetPixel(hdc, j - 1, p[j], RGB(0, 0, 255));
			SetPixel(hdc, j + 1, p[j], RGB(0, 0, 255));
			SetPixel(hdc, j, p[j] - 1, RGB(0, 0, 255));
			SetPixel(hdc, j, p[j] + 1, RGB(0, 0, 255));*/

			

			/*SetPixel(hdc, j - 1, p[j], RGB(0, 0, 0));
			SetPixel(hdc, j + 1, p[j], RGB(0, 0, 0));
			SetPixel(hdc, j, p[j] - 1, RGB(0, 0, 0));
			SetPixel(hdc, j, p[j] + 1, RGB(0, 0, 0));*/
		}
		


		// Swap the found minimum element with the first element
		// swap(&arr[min_idx], &arr[i]);
		int temp = p[min_idx];
		p[min_idx] = p[i];
		p[i] = temp;

		for (int y = 726; y > p[min_idx]; y -= 1)
		{
			SetPixel(hdc, min_idx, 726 - y, RGB(0, 0, 0));
		}

		//std::this_thread::sleep_for(std::chrono::nanoseconds(300));

		//for (int o = 0; o < 726; o += 1)
		//{
		//	SetPixel(hdc, i, 726 - o, RGB(0, 0, 0));
		//}

		SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));
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
				index += 1;
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

	return p2;
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
	
	std::this_thread::sleep_for(std::chrono::seconds(1));

	int * p;

	switch (algo)
	{
	case 1:
		p = selectionSort(hdc, data);
		break;
	case 2:
		p = quickSort(hdc, data, 0, 725);
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