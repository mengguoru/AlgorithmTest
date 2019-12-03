#include "冒泡排序.h"

vector<int> BubbleSort(vector<int> arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return arr;
}
