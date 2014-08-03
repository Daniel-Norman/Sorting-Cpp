#pragma once
using namespace std;

template <class T>
class HeapSorter
{
public:
	void heapSort(T*, int);

private:
	bool reheap_up(int, bool = false);

	void heapify();
	void reheap_down(int, int);

	int size;
	T* data;
};

//template <class T>
//void HeapSorter<T>::heapSort(T* input, int s)
//{
//	size = s;
//	data = input;
//
//	
//	bool made_swaps = false;
//	do
//	{
//		made_swaps = false;
//		for (int i = size - 1; i >= 0; --i)
//		{
//			if (reheap_up(i)) made_swaps = true;
//		}
//	} while (made_swaps);
//	
//
//
//	for (int i = size - 1; i >= 0; --i)
//	{
//		T temp = data[i];
//		data[i] = data[0];
//		data[0] = temp;
//		reheap_down(0, i - 1);
//	}
//}

template <class T>
bool HeapSorter<T>::reheap_up(int index, bool made_swap)
{
	int parent_index = (index == 0) ? -1 : (index - 1) / 2;
	if (parent_index >= 0 && data[index] > data[parent_index])
	{
		T temp = data[parent_index];
		data[parent_index] = data[index];
		data[index] = temp;
		return reheap_up(parent_index, true);
	}
	return made_swap;
}

//template <class T>
//void HeapSorter<T>::reheap_down(int index, int last_index)
//{
//	int left_child_index = index * 2 + 1;
//	int right_child_index = index * 2 + 2;
//	int child_index = -1;
//	if (right_child_index <= last_index)
//	{
//		child_index = (data[left_child_index] > data[right_child_index]) ? left_child_index : right_child_index;
//	}
//	else if (left_child_index <= last_index)
//	{
//		child_index = left_child_index;
//	}
//
//	if (child_index > 0 && data[child_index] > data[index])
//	{
//		T temp = data[index];
//		data[index] = data[child_index];
//		data[child_index] = temp;
//		reheap_down(child_index, last_index);
//	}
//}

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