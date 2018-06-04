# pragma once
typedef unsigned int uint;
#include "amp.h"

namespace pal
{
	void radix_sort(HDC hdc, uint* start, uint num, int fake = 0);
	void radix_sort(HDC hdc, concurrency::array<uint>& arr);
	int * radix_sort(HDC hdc, int(&arr)[726]);
}

