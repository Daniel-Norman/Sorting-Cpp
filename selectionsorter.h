#pragma once
using namespace std;

template <class T>
class SelectionSorter
{
public:
	void selectionSort(T*, int);
};

template <typename T>
void SelectionSorter<T>::selectionSort(T* input, int size)
{

	for (int i = 0; i < size - 1; ++i)
	{
		T oldItem = input[i];
		T smallestItem = input[i];
		int smallestIndex = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (input[j] < smallestItem)
			{
				smallestItem = input[j];
				smallestIndex = j;
			}
		}
		input[i] = smallestItem;
		input[smallestIndex] = oldItem;
	}
}