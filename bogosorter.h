#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

template <class T>
class BogoSorter
{
public:
	void bogoSort(T*, int);
};

template <class T>
void BogoSorter<T>::bogoSort(T* input, int size)
{
	T* output = new T[size];
	srand(time(NULL));
	vector<int> freeIndices;
	bool sorted = false;
	while (!sorted)
	{
		for (int i = 0; i < size; ++i)
		{
			freeIndices.push_back(i);
		}

		for (int i = 0; i < size; ++i)
		{
			int random_index = (rand() * (RAND_MAX + 1) + rand()) % freeIndices.size();
			int index = freeIndices[random_index];
			freeIndices.erase(freeIndices.begin() + random_index);
			output[i] = input[index];
		}

		sorted = true;
		for (int i = 0; i < size - 1; ++i)
		{
			if (output[i] > output[i + 1])
			{
				sorted = false;
				break;
			}
		}
	}
	for (int i = 0; i < size; ++i)
	{
		input[i] = output[i];
	}
}