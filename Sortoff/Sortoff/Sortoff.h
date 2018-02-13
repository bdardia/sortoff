#pragma once

#ifndef SORTOFF_H
#define SORTOFF_H

#include "resource.h"

int * selectionSort(HDC hdc, int(&arr)[726]);
int * quickSort(int(&arr)[], int low, int high);
int partition(int arr[], int low, int high);
void quickSort2(int arr[], int low, int high);

#endif // !SORTOFF_H
