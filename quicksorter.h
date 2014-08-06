#pragma once
using namespace std;

template <class T>
class QuickSorter
{
public:
	void quickSort(T*, int);

private:
	void sort(T*, int, int);
	int partition(T*, int, int);
};

template <class T>
void QuickSorter<T>::quickSort(T* data, int size)
{
	sort(data, 0, size - 1);
}

template <class T>
void QuickSorter<T>::sort(T* data, int left, int right)
{
	if (left < right)
	{
		int pivot_index = partition(data, left, right);

		sort(data, left, pivot_index - 1);
		sort(data, pivot_index + 1, right);
	}
}

template <class T>
int QuickSorter<T>::partition(T* data, int left, int right)
{
	int pivot_index = left + (right - left) / 2;

	//Arrange the data at left, pivot, and right before comparing the rest of the partition to the pivot
	//(Median of 3)
	if (data[left] > data[right])
	{
		T tmp = data[left];
		data[left] = data[right];
		data[right] = tmp;
	}
	if (data[pivot_index] > data[right])
	{
		T tmp = data[pivot_index];
		data[pivot_index] = data[right];
		data[right] = tmp;
	}
	if (data[pivot_index] < data[left])
	{
		T tmp = data[pivot_index];
		data[pivot_index] = data[left];
		data[left] = tmp;
	}

	T pivot = data[pivot_index];

	while (left < right)
	{
		while (data[left] < pivot) ++left; //Left now holds first item >= pivot from left (should be on right)
		while (data[right] > pivot) --right; //Right now holds first item <= pivot from right (should be on left)

		if (data[left] == data[right]) // If data at left and at right are equal (and therefore equal to pivot),
		{
			++left; //Skip over the left one to prevent infinite swapping of left and right
		}
		else if (left < right)
		{
			T tmp = data[left];
			data[left] = data[right];
			data[right] = tmp;
		}
		
	}
	return right;
}