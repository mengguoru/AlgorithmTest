#include "希尔排序.h"

void ShellSort(vector<int> &arr)
{
	for (int gap = arr.size() / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < arr.size(); i++)
		{
			int j = i;
			int key = arr[i];
			for (; j >= gap && key < arr[j - gap];j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = key;
		}
	}
}
