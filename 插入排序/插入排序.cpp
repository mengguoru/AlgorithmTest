#include "插入排序.h"

void InsertionSort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		int key = arr[i];
		int preIndex = i - 1;
		while (preIndex >= 0 && arr[preIndex] > key)
		{
			arr[preIndex + 1] = arr[preIndex];
			preIndex--;
		}
		arr[preIndex + 1] = key;
	}
}
