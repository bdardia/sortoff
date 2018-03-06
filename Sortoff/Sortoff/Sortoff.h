#pragma once

#ifndef SORTOFF_H
#define SORTOFF_H

#include "resource.h"

const int SLEEP_TIME = 3;

HWND hWinMainWnd;
HWND hwndButton;
HWND hwndButton2;
HWND hwndButton3;
HWND hwndButton4;
HWND hwndButton5;
HWND hwndButton6;
HWND hwndButton7;
HWND hwndButton8;
HWND hwndButton9;
HWND hwndButton10;
HWND hwndButton11;
HWND hwndButton12;
HWND hwndButton13;
HWND hwndButton14;
HWND hwndButton15;
HWND hwndButton16;

void startTournament(HDC hdc);
void createBracket(HDC hdc);
void updateBracket(HDC hdc, LPCWSTR names[], LPCWSTR constNames[], LPCWSTR round2Names[], LPCWSTR round3Names[], LPCWSTR round4Names[], LPCWSTR winner, int winBy[]);

// algorithms

// slow
int * selectionSort(HDC hdc, int(&arr)[726]);

int * cocktailShaker(HDC hdc, int(&arr)[726]);

int * insertionSort(HDC hdc, int(&arr)[726]);

// medium
void heapify(HDC hdc, int arr[], int n, int i);
int * heapSort(HDC hdc, int(&arr)[726]);

void merge(HDC hdc, int arr[], int left, int mid, int right);
void mergeSort(HDC hdc, int arr[], int left, int right);
int * mergeSortMain(HDC hdc, int(&arr)[726]);

void bitonicMerge(HDC hdc, int arr[], int low, int n, bool ascending);
void bitonicSort(HDC hdc, int arr[], int low, int n, bool ascending);
int * bitonicSortMain(HDC hdc, int(&arr)[726]);

int * shellSort(HDC hdc, int(&arr)[726]);

// fast
int * quickSort(HDC hdc, int(&arr)[726], int low, int high);
int partition(HDC hdc, int arr[], int low, int high);
void quickSort2(HDC hdc, int arr[], int low, int high);

void radixMSD(HDC hdc, int arr[], int low, int high, int depth);
int * radixMSDMain(HDC hdc, int(&arr)[726]);

void dualPivot(HDC hdc, int arr[], int left, int right);
int * quickSortDualPivot(HDC hdc, int(&arr)[726]);

// fastest
int * flashSortMain(HDC hdc, int(&arr)[726]);
void flashSort(HDC hdc, int arr[], int n);

int * radixSort(HDC hdc, int(&arr)[726]);

int * pigeonholeSort(HDC hdc, int(&arr)[726]);

int * gravitySort(HDC hdc, int(&arr)[726]);

// other functions
void runAlgo(HDC hdc, int algo);
void destroyAllButtons();

#endif // !SORTOFF_H
