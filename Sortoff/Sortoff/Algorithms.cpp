#include "stdafx.h"
#include "Algorithms.h"

/*
       .__                         .__                       .__  __  .__                    
  _____|  |   ______  _  __ _____  |  |    ____   ___________|__|/  |_|  |__   _____   ______
 /  ___/  |  /  _ \ \/ \/ / \__  \ |  |   / ___\ /  _ \_  __ \  \   __\  |  \ /     \ /  ___/
 \___ \|  |_(  <_> )     /   / __ \|  |__/ /_/  >  <_> )  | \/  ||  | |   Y  \  Y Y  \\___ \ 
/____  >____/\____/ \/\_/   (____  /____/\___  / \____/|__|  |__||__| |___|  /__|_|  /____  >
     \/                          \/     /_____/                            \/      \/     \/ 
*/
int * selectionSort(HDC hdc, int(&arr)[726]) // selection main
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

int * cocktailShaker(HDC hdc, int(&arr)[726]) // cocktail main
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

int * insertionSort(HDC hdc, int(&arr)[726]) // insertion main
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

void insertionSortIndex2(HDC hdc, int arr[], int start, int length) // insertion sort with start index and length
{
	for (int i = start + 1; i < length; ++i)
	{
		int key = arr[i];

		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			SetPixel(hdc, j, 726 - arr[j], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			int temp = arr[j];
			arr[j] = arr[j + 1];
			SetPixel(hdc, j, 726 - arr[j], RGB(255, 0, 0));
			SetPixel(hdc, j + 1, 726 - arr[j + 1], RGB(0, 0, 0));
			arr[j + 1] = temp;
			SetPixel(hdc, j + 1, 726 - arr[j + 1], RGB(255, 0, 0));
			j--;
		}
	}
}

void InsertionSortIndex(HDC hdc, int arr[], int length) // insertion sort with length only
{
	for (size_t i = 1; i < length; ++i)
	{
		int key = arr[i];

		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			SetPixel(hdc, j, 726 - arr[j], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			int temp = arr[j];
			arr[j] = arr[j + 1];
			SetPixel(hdc, j, 726 - arr[j], RGB(255, 0, 0));
			SetPixel(hdc, j + 1, 726 - arr[j + 1], RGB(0, 0, 0));
			arr[j + 1] = temp;
			SetPixel(hdc, j + 1, 726 - arr[j + 1], RGB(255, 0, 0));
			j--;
		}
	}
}

/*
                   .___.__                       .__                       .__  __  .__                    
  _____   ____   __| _/|__|__ __  _____   _____  |  |    ____   ___________|__|/  |_|  |__   _____   ______
 /     \_/ __ \ / __ | |  |  |  \/     \  \__  \ |  |   / ___\ /  _ \_  __ \  \   __\  |  \ /     \ /  ___/
|  Y Y  \  ___// /_/ | |  |  |  /  Y Y  \  / __ \|  |__/ /_/  >  <_> )  | \/  ||  | |   Y  \  Y Y  \\___ \ 
|__|_|  /\___  >____ | |__|____/|__|_|  / (____  /____/\___  / \____/|__|  |__||__| |___|  /__|_|  /____  >
      \/     \/     \/                \/       \/     /_____/                            \/      \/     \/ 
*/

extern "C" void prepareLibrarySort(HDC hdc, int epsilon, int n, int S[MAX2], int * sLen) // library sort helper
{
	int i;
	*sLen = (1 + epsilon)*n;
	for (i = 0; i<*sLen; i++) S[i] = NONE;
}

extern "C" int searchFree(HDC hdc, int e, int sorted[MAX2], int last) // library sort helper
{
	int first = 0;
	int middle;

	while (last >= 0 && IS_EMPTY(sorted[last])) last--;
	while (first <= last && IS_EMPTY(sorted[first])) first++;
	while (first <= last) {
		middle = (first + last) / 2;
		if (IS_EMPTY(sorted[middle])) {
			int tmp = middle + 1;
			//Look to the right
			while (tmp<last && IS_EMPTY(sorted[tmp])) tmp++;
			if (sorted[tmp]>e) {
				tmp = middle - 1;
				while (middle>first && IS_EMPTY(sorted[middle])) middle--;
				//Look to the left
				if (sorted[middle]<e)//Found intermediate position
					return middle;
				last = middle - 1;
			}
			else first = tmp + 1;
		}
		else if (sorted[middle]<e) {
			first = middle + 1;
		}
		else {
			last = middle - 1;
		}
	}
	//If no position was found return -1 or if a lower position was found, return that
	if (last >= 0 && IS_EMPTY(sorted[last])) last--;
	return last;
}

extern "C" void libSort(HDC hdc, int A[MAX], int N, int S[MAX2], int EPSILON) // library sort helper
{
	if (N == 0) return;

	int j, k, step;

	// ------ BASE CASE ------
	//Goal: We want 'goal' elements to be inserted into S, for now..
	int goal = 1;
	//How many elements have already been inserted, its 1 for efficiency
	int pos = 1;

	S[0] = A[0];//We insert element 0 at position 0

				//Initial size of array S
	int sLen = max((1 + EPSILON), goal + 1);

	// ------ CONDITION -------
	//What has already been read must be less than the total array size
	while (pos<N) {
		// ------ ROUND ------
		//Each round i will end with goal=2^i sorted elements. i starts with 1
		for (j = 0; j<goal; j++) {
			//Search where to insert A[pos] (with binary search)
			int insPos = searchFree(hdc, A[pos], S, sLen - 1);

			//Because our binary search returns us the location of an smaller item than the one we search...
			insPos++;
			if (!IS_EMPTY(S[insPos])) {//There is no place where we wanted to insert that element
				int nextFree = insPos + 1;//Search a free space forward
				while (!IS_EMPTY(S[nextFree])) nextFree++;
				//At 'nextFree' there is a place, translate all elements one position to the right
				if (nextFree >= sLen) {//Wait! nextFree is out of bounds
					insPos--;
					if (!IS_EMPTY(S[insPos])) {
						//Search backward
						nextFree = insPos - 1;
						while (!IS_EMPTY(S[nextFree])) nextFree--;
						//Now we translate all the elements to the left
						while (nextFree<insPos) {
							SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(0, 0, 0));
							std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

							S[nextFree] = S[nextFree + 1];

							SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(255, 0, 0));

							nextFree++;
						}
					}
				}
				else {
					//Now we translate all the elements to the right
					while (nextFree>insPos) {
						SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(0, 0, 0));
						std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

						S[nextFree] = S[nextFree - 1];

						SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(255, 0, 0));

						nextFree--;
					}
				}
				//Now nextFree is insPos; in other words, insPos is free
			}
			else if (insPos >= sLen) {//insPos is out of bounds
									  //Search a free space backwards
				insPos--;//This place must be between the limits
				int nextFree = insPos - 1;
				while (!IS_EMPTY(S[nextFree])) nextFree--;
				//Now we translate all the elements to the left
				while (nextFree<insPos) {
					SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(0, 0, 0));
					std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

					S[nextFree] = S[nextFree + 1];

					SetPixel(hdc, nextFree, 726 - S[nextFree], RGB(255, 0, 0));

					nextFree++;
				}
				//Now nextFree is insPos; in other words insPos is free
			}

			SetPixel(hdc, insPos, 726 - S[insPos], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			S[insPos] = A[pos++];//We insert the element and increment our counter

			SetPixel(hdc, insPos, 726 - S[insPos], RGB(255, 0, 0));

			if (pos >= N)
				return;//That element was the last, return from the function
		}

		// ----- REBALANCE -----
		//It takes linear time. Tries to spread the elements as much as possible
		for (j = sLen - 1, k = min(goal*(2 + 2 * EPSILON), (1 + EPSILON)*N) - 1,
			step = (k + 1) / (j + 1); j >= 0; j--, k -= step) {

			SetPixel(hdc, k, 726 - S[k], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			S[k] = S[j];

			SetPixel(hdc, k, 726 - S[k], RGB(255, 0, 0));
			SetPixel(hdc, j, 726 - S[j], RGB(0, 0, 0));

			S[j] = NONE;
		}

		//In each round insert the double of elements to the sorted array
		// because there will be the double of free spaces after the rebalance
		sLen = min(goal*(2 + 2 * EPSILON), N*(1 + EPSILON));
		goal <<= 1;//We increment i
	}
}

extern "C" void librarySort(HDC hdc, int A[MAX], int n) // library sort helper
{
	int epsilon = 1;
	int S[MAX2];
	int sLen, i, j;
	//This takes linear time
	prepareLibrarySort(hdc, epsilon, n, S, &sLen);
	//O (n log n)
	libSort(hdc, A, n, S, epsilon);
	//This takes linear time
	for (i = 0, j = 0; i < sLen && j < n; i++)
	{
		if (!IS_EMPTY(S[i]))
		{
			SetPixel(hdc, j, 726 - A[j], RGB(0, 0, 0));
			SetPixel(hdc, i, 726 - S[i], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

			A[j++] = S[i];

			SetPixel(hdc, j - 1, 726 - A[j - 1], RGB(255, 0, 0));
		}
	}
}

int * librarySortMain(HDC hdc, int(&arr)[726]) // library sort main
{
	int p[726];

	const int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	librarySort(hdc, p, n);

	return p;
}

void heapify(HDC hdc, int arr[], int n, int i) // heap sort helper
{
	int largest = i;
	int left = (i * 2) + 1;
	int right = (i * 2) + 2;

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		int temp = arr[i];
		arr[i] = arr[largest];
		SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));
		SetPixel(hdc, largest, 726 - arr[largest], RGB(0, 0, 0));
		arr[largest] = temp;
		SetPixel(hdc, largest, 726 - arr[largest], RGB(255, 0, 0));

		heapify(hdc, arr, n, largest);
	}
}

int * heapSort(HDC hdc, int(&arr)[726]) // heap sort main
{
	int p[726];

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	for (int i = (n / 2) - 1; i >= 0; i -= 1)
	{
		heapify(hdc, p, n, i);
	}

	for (int i = (n - 1); i >= 0; i -= 1)
	{
		SetPixel(hdc, 0, 726 - p[0], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		int temp = p[0];
		p[0] = p[i];
		SetPixel(hdc, 0, 726 - p[0], RGB(255, 0, 0));
		SetPixel(hdc, i, 726 - p[i], RGB(0, 0, 0));
		p[i] = temp;
		SetPixel(hdc, i, 726 - p[i], RGB(255, 0, 0));

		heapify(hdc, p, i, 0);
	}

	return p;
}

void merge(HDC hdc, int arr[], int left, int mid, int right) // merge sort helper
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	/* create temp arrays */
	int * Lt = new int[n1];
	int * Rt = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		Lt[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		Rt[j] = arr[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (Lt[i] <= Rt[j])
		{
			SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			arr[k] = Lt[i];
			SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
			i++;
		}
		else
		{
			SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
			arr[k] = Rt[j];
			SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		arr[k] = Lt[i];
		SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		SetPixel(hdc, k, 726 - arr[k], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		arr[k] = Rt[j];
		SetPixel(hdc, k, 726 - arr[k], RGB(255, 0, 0));
		j++;
		k++;
	}

	delete[] Lt;
	delete[] Rt;
}

void mergeSort(HDC hdc, int arr[], int left, int right) // merge sort helper
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(hdc, arr, left, mid);
		mergeSort(hdc, arr, mid + 1, right);

		merge(hdc, arr, left, mid, right);
	}
}

int * mergeSortMain(HDC hdc, int(&arr)[726]) // merge sort main
{
	int p[726];

	int n = 726;

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	mergeSort(hdc, p, 0, n - 1);

	return p;
}

void bitonicMerge(HDC hdc, int arr[], int low, int n, bool ascending) // bitonic helper
{
	if (n > 1)
	{
		int k = 1;
		while (k < n) k = k << 1;
		int m = k >> 1;

		for (int i = low; i < (low + n - m); i += 1)
		{
			if (ascending == (arr[i] > arr[i + m]))
			{
				SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
				std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
				int temp = arr[i];
				arr[i] = arr[i + m];
				SetPixel(hdc, i, 726 - arr[i], RGB(255, 0, 0));
				SetPixel(hdc, i + m, 726 - arr[i + m], RGB(0, 0, 0));
				arr[i + m] = temp;
				SetPixel(hdc, i + m, 726 - arr[i + m], RGB(255, 0, 0));
			}
		}

		bitonicMerge(hdc, arr, low, m, ascending);
		bitonicMerge(hdc, arr, low + m, n - m, ascending);
	}
}

void bitonicSort(HDC hdc, int arr[], int low, int n, bool ascending) // bitonic helper
{
	if (n > 1)
	{
		int m = (int)(n / 2);
		bitonicSort(hdc, arr, low, m, !ascending);
		bitonicSort(hdc, arr, low + m, n - m, ascending);
		bitonicMerge(hdc, arr, low, n, ascending);
	}
}

int * bitonicSortMain(HDC hdc, int(&arr)[726]) // bitonic main
{
	int p[726];

	int n = 726;

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	bitonicSort(hdc, p, 0, n, true);

	return p;
}

int * shellSort(HDC hdc, int(&arr)[726]) // shell main
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

struct Node *newNode(int item) // tree helper
{
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void storeSorted(HDC hdc, Node *root, int arr[], int &i) // tree helper
{
	if (root != NULL)
	{
		storeSorted(hdc, root->left, arr, i);

		SetPixel(hdc, i, 726 - arr[i], RGB(0, 0, 0));
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

		arr[i++] = root->key;

		SetPixel(hdc, i - 1, 726 - arr[i - 1], RGB(255, 0, 0));

		storeSorted(hdc, root->right, arr, i);
	}
}

Node* insert(HDC hdc, Node* node, int key, int i) // tree helper
{
	if (node == NULL)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
		return newNode(key);
	}
	SetPixel(hdc, i, 726 - key, RGB(0, 0, 0));
	std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

	/* Otherwise, recur down the tree */
	if (key < node->key)
	{
		SetPixel(hdc, i, 726 - key, RGB(255, 0, 0));
		node->left = insert(hdc, node->left, key, i);
	}
	else if (key > node->key)
	{
		SetPixel(hdc, i, 726 - key, RGB(255, 255, 0));
		node->right = insert(hdc, node->right, key, i);
	}

	/* return the (unchanged) Node pointer */
	return node;
}

void treeSort(HDC hdc, int arr[], int n) // tree helper
{
	struct Node *root = NULL;

	// Construct the BST
	root = insert(hdc, root, arr[0], 0);
	for (int i = 1; i < n; i++)
	{
		insert(hdc, root, arr[i], i);
	}

	// Store inoder traversal of the BST
	// in arr[]
	int i = 0;
	storeSorted(hdc, root, arr, i);
}

int * treeSortMain(HDC hdc, int(&arr)[726]) // tree main
{
	int p[726];

	int n = (sizeof(p) / sizeof(p[0]));

	for (int i = 0; i < 726; i += 1)
	{
		p[i] = arr[i];
	}

	treeSort(hdc, p, n);

	return p;
}