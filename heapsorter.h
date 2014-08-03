#pragma once
using namespace std;

template <class T>
class HeapSorter
{
public:
	void heapSort(T*, int);

private:
	void heapify();
	void reheap_down(int, int);

	int size;
	T* data;
};


template <class T>
void HeapSorter<T>::heapSort(T* input, int size)
{
	this->size = size;
	this->data = input;

	heapify(); //Make sure the data follows the heap property

	int high = size - 1; //Store the last index of the unsorted data
	while (high > 0)
	{
		int temp = data[high];
		data[high] = data[0]; //Place max element (at data[0] after heapify) at our high index
		data[0] = temp; //Place the previous element at high index at index 0
		--high;
		reheap_down(0, high); //Ensure the unsorted data follows the heap property
	}
}

template <class T>
void HeapSorter<T>::heapify()
{
	int middle_index = (size - 2) / 2; //Last index's parent: (child - 1) / 2
	while (middle_index >= 0)
	{
		reheap_down(middle_index, size - 1);
		--middle_index;
	}
}

template <class T>
void HeapSorter<T>::reheap_down(int low, int high)
{
	int index = low;
	while (index * 2 + 1 <= high)
	{
		int left_child_index = index * 2 + 1;
		int right_child_index = index * 2 + 2;
		int swap_index = index;
		if (data[swap_index] < data[left_child_index])
		{
			swap_index = left_child_index;
		}
		if (right_child_index <= high && data[swap_index] < data[right_child_index])
		{
			swap_index = right_child_index;
		}
		if (swap_index != index)
		{
			T temp = data[index];
			data[index] = data[swap_index];
			data[swap_index] = temp;
			index = swap_index;
		}
		else break; //Found nothing to swap, so we stop this re-heaping
	}
}