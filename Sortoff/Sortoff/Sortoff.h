#pragma once

#ifndef SORTOFF_H
#define SORTOFF_H

#define MAX 10000
#define MAX2 20000

#define IS_EMPTY(e) (e<0)
#define NONE -1

const int RANDOM_INTS = 1000;
const int MOSTLY_SORTED = 1001;
int DATA_SET = RANDOM_INTS;
bool setData = false;
int data[726];

struct Node
{
	int key;
	struct Node *left, *right;
};

struct Node *newNode(int item);

class Upset
{
	LPCWSTR winner;
	LPCWSTR loser;
	int winnerRank;
	int loserRank;
	int winDifference;
public:
	void setValues(LPCWSTR winner, LPCWSTR loser, int winnerRank, int loserRank, int winDifference);
	LPCWSTR getWinner();
	LPCWSTR getLoser();
	int getWinnerRank();
	int getLoserRank();
	int getWinDifference();
};

void Upset::setValues(LPCWSTR w, LPCWSTR l, int wr, int lr, int d)
{
	winner = w;
	loser = l;
	winnerRank = wr;
	loserRank = lr;
	winDifference = d;
}

LPCWSTR Upset::getWinner()
{
	return winner;
}
LPCWSTR Upset::getLoser()
{
	return loser;
}
int Upset::getWinDifference()
{
	return winDifference;
}

int Upset::getWinnerRank()
{
	return winnerRank;
}

int Upset::getLoserRank()
{
	return loserRank;
}

#include "resource.h"

const int SLEEP_TIME = 2;
const int RUN = 32;

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
HWND hwndButton17;
HWND hwndButton18;
HWND hwndButton19;
HWND hwndButton20;
HWND hwndButton21;
HWND hwndButton22;
HWND hwndButton23;
HWND hwndButton24;
HWND hwndButton25;

void startTournament(HDC hdc);
void createBracket(HDC hdc);
void updateBracket(HDC hdc, LPCWSTR names[], LPCWSTR constNames[], LPCWSTR round2Names[], LPCWSTR round3Names[], LPCWSTR round4Names[], LPCWSTR winner, int winBy[][16], int fastestTime);
void drawUpsets(HDC hdc, std::vector<Upset> upsets);

// algorithms

// slow
int * selectionSort(HDC hdc, int(&arr)[726]);

int * cocktailShaker(HDC hdc, int(&arr)[726]);

int * insertionSort(HDC hdc, int(&arr)[726]);

void insertionSortIndex2(HDC hdc, int arr[], int start, int length);
void InsertionSortIndex(HDC hdc, int arr[], int length);

// medium
extern "C" void prepareLibrarySort(HDC hdc, int epsilon, int n, int S[MAX2], int * sLen);
extern "C" int searchFree(HDC hdc, int e, int sorted[MAX2], int last);
extern "C" void libSort(HDC hdc, int A[MAX], int N, int S[MAX2], int EPSILON);
extern "C" void librarySort(HDC hdc, int A[MAX], int n);
int * librarySortMain(HDC hdc, int(&arr)[726]);

void heapify(HDC hdc, int arr[], int n, int i);
int * heapSort(HDC hdc, int(&arr)[726]);

void merge(HDC hdc, int arr[], int left, int mid, int right);
void mergeSort(HDC hdc, int arr[], int left, int right);
int * mergeSortMain(HDC hdc, int(&arr)[726]);

void bitonicMerge(HDC hdc, int arr[], int low, int n, bool ascending);
void bitonicSort(HDC hdc, int arr[], int low, int n, bool ascending);
int * bitonicSortMain(HDC hdc, int(&arr)[726]);

int * shellSort(HDC hdc, int(&arr)[726]);

void storeSorted(HDC hdc, Node *root, int arr[], int &i);
Node* insert(HDC hdc, Node* node, int key, int i);
void treeSort(HDC hdc, int arr[], int n);
int * treeSortMain(HDC hdc, int(&arr)[726]);

int * setSort(HDC hdc, int(&arr)[726]);

// fast
int * quickSort(HDC hdc, int(&arr)[726], int low, int high);
int partition(HDC hdc, int arr[], int low, int high);
void quickSort2(HDC hdc, int arr[], int low, int high);

void radixMSD(HDC hdc, int arr[], int low, int high, int depth);
int * radixMSDMain(HDC hdc, int(&arr)[726]);

void dualPivot(HDC hdc, int arr[], int left, int right);
int * quickSortDualPivot(HDC hdc, int(&arr)[726]);

void strandSort(HDC hdc, std::list<int> &ip, std::list<int> &op);
int * strandSortMain(HDC hdc, int(&arr)[726]);

void patienceSort(HDC hdc, std::vector<int>& elements);
void mergePiles(HDC hdc, std::vector<int>& sourcePile, std::vector<int>& destinationPile);
int * patienceSortMain(HDC hdc, int(&arr)[726]);

int * slideSort(HDC hdc, int(&arr)[726]);

// fastest
void threeWayPartition(HDC hdc, int arr[], int left, int right, int &i, int &j);
void threeWayQuicksort(HDC hdc, int arr[], int left, int right);
int * threeWayQuicksortMain(HDC hdc, int(&arr)[726]);

int * flashSortMain(HDC hdc, int(&arr)[726]);
void flashSort(HDC hdc, int arr[], int n);

int * radixSort(HDC hdc, int(&arr)[726]);

int * pigeonholeSort(HDC hdc, int(&arr)[726]);

int * gravitySort(HDC hdc, int(&arr)[726]);

int * histogramSort(HDC hdc, int(&arr)[726]);

// other functions
void runAlgo(HDC hdc, int algo);
void destroyAllButtons();

#endif // !SORTOFF_H
