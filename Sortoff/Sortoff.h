#pragma once

#ifndef SORTOFF_H
#define SORTOFF_H

const int RANDOM_INTS = 1000;
const int MOSTLY_SORTED = 1001;
const int ALREADY_SORTED = 1002;
const int REVERSE_ORDER = 1003;
const int CUBIC_SKEWED = 1004;
int DATA_SET = RANDOM_INTS;
bool setData = false;
int data[726];

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
HWND hwndButton26;
HWND hwndButton27;
HWND hwndButton28;
HWND hwndButton29;

void startTournament(HDC hdc);
void createBracket(HDC hdc);
void updateBracket(HDC hdc, LPCWSTR names[], LPCWSTR constNames[], LPCWSTR round2Names[], LPCWSTR round3Names[], LPCWSTR round4Names[], LPCWSTR winner, int winBy[][16], int fastestTime);
void drawUpsets(HDC hdc, std::vector<Upset> upsets);

void runAlgo(HDC hdc, int algo);
void destroyAllButtons();
bool cStrEquals(LPCWSTR strOne, LPCWSTR strTwo);

#endif // !SORTOFF_H
