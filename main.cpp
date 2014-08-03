#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "mergesorter.h"
#include "selectionsorter.h"
#include "heapsorter.h"

#define ARRAY_SIZE 1000000

using namespace std;

void sort();
void search(int*);

int main()
{
	sort();
	system("PAUSE");
	return 0;
}

void sort()
{
	srand(time(NULL));
	clock_t before, after;
	int size;
	int* list;

	//Merge Sort
	size = 1 << 20;
	MergeSorter<int> merge_sorter;
	list = new int[size];
	for (int i = 0; i < size; ++i)
	{
		list[i] = (rand() * (RAND_MAX + 1) + rand()) % size;
	}
	before = clock();
	merge_sorter.mergeSort(list, size);
	after = clock();
	cout << "Merge Sorting " << size << " elements took: " << (float)(after - before) / CLOCKS_PER_SEC << "s. O(nlogn)\n";

	//Heap Sort
	size = 1 << 20;
	HeapSorter<int> heap_sorter;
	list = new int[size];
	for (int i = 0; i < size; ++i)
	{
		list[i] = (rand() * (RAND_MAX + 1) + rand()) % size;
	}
	before = clock();
	heap_sorter.heapSort(list, size);
	after = clock();
	cout << "Heap Sorting " << size << " elements took: " << (float)(after - before) / CLOCKS_PER_SEC << "s. O(nlogn)\n";

	//Selection Sort
	size = 1 << 15;
	SelectionSorter<int> selection_sorter;
	list = new int[size];
	for (int i = 0; i < size; ++i)
	{
		list[i] = rand() % size;
	}
	before = clock();
	selection_sorter.selectionSort(list, size);
	after = clock();
	cout << "Selection Sorting " << size << " elements took: " << (float)(after - before) / CLOCKS_PER_SEC << "s. O(n^2)\n";


}

template <typename T>
int binarySearch(T* input, T item, int size)
{
	return binarySearch<T>(input, item, 0, size - 1);
}

void search(int* list)
{
	srand(time(NULL));
	clock_t before, after;

	int randNumber = (rand() * (RAND_MAX + 1) + rand()) % (ARRAY_SIZE / 10);
	cout << "Trying to find " << randNumber << "...\n";
	before = clock();
	int foundIndex = binarySearch<int>(list, randNumber, ARRAY_SIZE);
	after = clock();
	if (foundIndex != -1)
	{
		cout << "Found at index " << foundIndex << endl;
	}
	else
	{
		cout << randNumber << " not in array.\n";
	}
	cout << "Binary search took " << (float)(after - before) / CLOCKS_PER_SEC << "s\n";
}



template <typename T>
int binarySearch(T* input, T item, int leftIndex, int rightIndex)
{
	if (leftIndex >= rightIndex) return -1;
	int middleIndex = (leftIndex + rightIndex) / 2;
	if (input[middleIndex] == item)
	{
		return middleIndex;
	}
	else if (input[middleIndex] > item)
	{
		return binarySearch<T>(input, item, leftIndex, middleIndex - 1);
	}
	else
	{
		return binarySearch<T>(input, item, middleIndex + 1, rightIndex);
	}
}
