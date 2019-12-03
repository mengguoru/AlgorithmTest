#include "快速排序.h"

void QuickSort(vector<int> &arr, int left, int right)
{
	if (left < right)
	{
		int i = left, j = right, key = arr[left];
		while (i < j)
		{
			while (i < j && arr[j] > key)
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (i < j && arr[i] < key)
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = key;
		QuickSort(arr, left, i - 1);
		QuickSort(arr, i + 1, right);
	}
}
