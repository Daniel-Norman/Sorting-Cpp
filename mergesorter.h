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
	int size;
};

template <typename T>
void MergeSorter<T>::mergeSort(T* input, int s)
{
	this->size = s;
	T* temp = new T[size];
	mergeSort(input, temp, 0, size);
	delete[] temp;
}

template <typename T>
void MergeSorter<T>::mergeSort(T* input, T* temp, int begin, int end)
{
	if (end - begin <= 1) return;

	int middle = (end + begin) / 2;
	mergeSort(input, temp, begin, middle);
	mergeSort(input, temp, middle, end);
	mergeArray(input, temp, begin, middle, end);
	copyArray(temp, input, begin, end);
}

template <typename T>
void MergeSorter<T>::copyArray(T* input, T* output)
{
	return copyArray(input, output, 0, size);
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
	for (int i = begin; i < end; ++i)
	{
		if (leftIndex < middle && (rightIndex >= end || input[leftIndex] < input[rightIndex]))
		{
			output[i] = input[leftIndex]; //output[i] should be the item at input's left index
			++leftIndex;
		}
		else
		{
			output[i] = input[rightIndex]; //output[i] should be the item at input's right index
			++rightIndex;
		}
	}
}