#pragma once

#ifndef SORTOFF_H
#define SORTOFF_H

#include "resource.h"

int * selectionSort(HDC hdc, int(&arr)[726]);
int * quickSort(HDC hdc, int(&arr)[726], int low, int high);
int partition(HDC hdc, int arr[], int low, int high);
void quickSort2(HDC hdc, int arr[], int low, int high);

#endif // !SORTOFF_H
