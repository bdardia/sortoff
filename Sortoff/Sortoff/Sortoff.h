#pragma once

#ifndef SORTOFF_H
#define SORTOFF_H

#include "resource.h"

const int SLEEP_TIME = 3;

HWND hwndButton;
HWND hwndButton2;
HWND hwndButton3;
HWND hwndButton4;
HWND hwndButton5;
HWND hwndButton6;

// algorithms

int * selectionSort(HDC hdc, int(&arr)[726]);
int * insertionSort(HDC hdc, int(&arr)[726]);
int * shellSort(HDC hdc, int(&arr)[726]);
int * quickSort(HDC hdc, int(&arr)[726], int low, int high);
int partition(HDC hdc, int arr[], int low, int high);
void quickSort2(HDC hdc, int arr[], int low, int high);
int * gravitySort(HDC hdc, int(&arr)[726]);

void runAlgo(HDC hdc, int algo);
void destroyAllButtons();

#endif // !SORTOFF_H
