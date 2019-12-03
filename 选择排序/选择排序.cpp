#include "选择排序.h"

void SelectionSort(vector<int> &arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		int tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}
