#pragma once
using namespace std;

template <class T>
class MergeSorter
{
public:
	void mergeSort(T*, int);
	void mergeSort(T*, T*, int, int);
	void copyArray(T*, T*);
	void copyArray(T*, T*, int, int);
	void mergeArray(T*, T*, int, int, int);
private:
};

template <typename T>
void MergeSorter<T>::mergeSort(T* input, int size)
{
	T* temp = new T[size];
	mergeSort(input, temp, 0, size);
	delete[] temp;
}

template <typename T>
void MergeSorter<T>::mergeSort(T* input, T* temp, int begin, int end)
{
	if (end - begin <= 1) return;

	int middle = (end + begin) / 2;
	mergeSort(input, temp, begin, middle); //Sort the left half between begin and end
	mergeSort(input, temp, middle, end); //Sort the right half between begin and end
	mergeArray(input, temp, begin, middle, end); //Merge the two halves
	copyArray(temp, input, begin, end); //Copy the temporary array's sorted values to the input array between begin and end
}


template <typename T>
void MergeSorter<T>::copyArray(T* input, T* output, int begin, int end)
{
	for (int i = begin; i < end; ++i) output[i] = input[i];
}

template <typename T>
void MergeSorter<T>::mergeArray(T* input, T* output, int begin, int middle, int end)
{
	int leftIndex = begin;
	int rightIndex = middle;
	for (int i = begin; i < end; ++i) //Loop through the data from begin to end, incrementing leftIndex or rightIndex when we use the left or right item in the data
	{
		if (leftIndex < middle && (rightIndex >= end || input[leftIndex] < input[rightIndex]))
		{
			output[i] = input[leftIndex]; //output[i] should be the item at input's left index because
			++leftIndex; //either rightIndex is off the end, or data at leftIndex is less than data at rightIndex
		}
		else
		{
			output[i] = input[rightIndex]; //output[i] should be the item at input's right index
			++rightIndex;
		}
	}
}